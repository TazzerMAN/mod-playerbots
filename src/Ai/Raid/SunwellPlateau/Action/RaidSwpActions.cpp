#include "RaidSwpActions.h"

#include <cmath>
#include <limits>

#include "Group.h"
#include "Playerbots.h"
#include "RaidSwpHelpers.h"
#include "Unit.h"

using namespace SunwellHelpers;

bool BrutallusBurnSpreadAction::Execute(Event /*event*/)
{
    return MoveFromGroup(BURN_SPREAD_DISTANCE);
}

bool BrutallusPositionBehindBossAction::Execute(Event /*event*/)
{
    Unit* brutallus = AI_VALUE2(Unit*, "find target", "brutallus");
    if (!brutallus)
        return false;

    float reach = botAI->IsMelee(bot) ? brutallus->GetCombatReach() : 25.0f;

    // Disperse non-tanks across an arc behind Brutallus rather than collapsing
    // to a single point. The bot picks a deterministic angular slot from its
    // GUID so the same bot always heads to the same offset and the raid does
    // not churn back-and-forth between picks.
    uint32 slot = bot->GetGUID().GetCounter() % METEOR_SLASH_DISPERSE_SLOTS;
    float slotFraction = static_cast<float>(slot) /
        static_cast<float>(METEOR_SLASH_DISPERSE_SLOTS - 1);
    float arcOffset = (slotFraction - 0.5f) * METEOR_SLASH_FRONT_ARC;
    float angle = brutallus->GetOrientation() + M_PI + arcOffset;

    float x = brutallus->GetPositionX() + std::cos(angle) * reach;
    float y = brutallus->GetPositionY() + std::sin(angle) * reach;
    float z = brutallus->GetPositionZ();

    return MoveTo(brutallus->GetMapId(), x, y, z, false, false, false, false,
                  MovementPriority::MOVEMENT_COMBAT);
}

bool BrutallusSpreadFromCursedAllyAction::Execute(Event /*event*/)
{
    // Tanks must hold aggro on Brutallus; if they happen to be near a cursed
    // ally, the cursed ally moves away (handled by `brutallus burn spread`).
    if (botAI->IsTank(bot))
        return false;

    Group* group = bot->GetGroup();
    if (!group)
        return false;

    Player* nearestCursed = nullptr;
    float nearestDist = std::numeric_limits<float>::max();

    for (GroupReference* ref = group->GetFirstMember(); ref != nullptr; ref = ref->next())
    {
        Player* member = ref->GetSource();
        if (!member || !member->IsAlive() || member == bot)
            continue;
        if (!member->HasAura(SPELL_BURN_DAMAGE))
            continue;

        float dist = bot->GetDistance(member);
        if (dist < nearestDist)
        {
            nearestDist = dist;
            nearestCursed = member;
        }
    }

    if (!nearestCursed)
        return false;

    float distToTravel = BURN_SPREAD_DISTANCE - nearestDist + 2.0f;
    if (distToTravel <= 0.0f)
        return false;

    return MoveAway(nearestCursed, distToTravel);
}
