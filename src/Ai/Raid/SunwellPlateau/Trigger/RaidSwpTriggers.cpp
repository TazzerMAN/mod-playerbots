#include "RaidSwpTriggers.h"

#include "Group.h"
#include "Playerbots.h"
#include "RaidSwpHelpers.h"
#include "Unit.h"

using namespace SunwellHelpers;

// Brutallus

bool BrutallusBotHasBurnTrigger::IsActive()
{
    if (botAI->IsTank(bot))
        return false;
    return bot->HasAura(SPELL_BURN_DAMAGE);
}

bool BrutallusAllyHasBurnTrigger::IsActive()
{
    // The bot itself being cursed is handled by `bot has burn`.
    if (bot->HasAura(SPELL_BURN_DAMAGE))
        return false;

    Group* group = bot->GetGroup();
    if (!group)
        return false;

    for (GroupReference* ref = group->GetFirstMember(); ref != nullptr; ref = ref->next())
    {
        Player* member = ref->GetSource();
        if (!member || !member->IsAlive() || member == bot)
            continue;
        if (!member->HasAura(SPELL_BURN_DAMAGE))
            continue;
        if (bot->GetDistance(member) < BURN_SPREAD_DISTANCE)
            return true;
    }
    return false;
}

bool BrutallusBotInMeteorSlashConeTrigger::IsActive()
{
    if (botAI->IsMainTank(bot))
        return false;

    Unit* brutallus = AI_VALUE2(Unit*, "find target", "brutallus");
    if (!brutallus || !brutallus->IsAlive() || !brutallus->IsInCombat())
        return false;

    if (bot->GetDistance(brutallus) > METEOR_SLASH_AVOID_RADIUS)
        return false;

    return brutallus->HasInArc(METEOR_SLASH_FRONT_ARC, bot);
}

// Felmyst

bool FelmystBotHasEncapsulateTrigger::IsActive()
{
    if (botAI->IsTank(bot))
        return false;
    return bot->HasAura(SPELL_ENCAPSULATE_CHANNEL);
}

bool FelmystBossIsFlyingTrigger::IsActive()
{
    Unit* felmyst = AI_VALUE2(Unit*, "find target", "felmyst");
    if (!felmyst || !felmyst->IsAlive())
        return false;

    // boss_felmyst.cpp toggles MOVEMENTFLAG_DISABLE_GRAVITY on takeoff and
    // back off on landing, so this flag is the single reliable signal.
    return felmyst->HasUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);
}
