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

// Eredar Twins

bool EredarTwinsBotHasConflagrationTrigger::IsActive()
{
    return bot->HasAura(SPELL_CONFLAGRATION);
}

bool EredarTwinsBotNeedsTankSwapTrigger::IsActive()
{
    if (!botAI->IsTank(bot))
        return false;

    Unit* victim = bot->GetVictim();
    if (!victim)
        return false;

    Aura* darkTouched = bot->GetAura(SPELL_DARK_TOUCHED);
    Aura* flameTouched = bot->GetAura(SPELL_FLAME_TOUCHED);

    // Sacrolash hits give Dark Touched. Once they pile up, the tank that is
    // engaging Sacrolash should taunt Alythess so the off-tank's stacks
    // (Flame Touched) start dropping while their own bleed off.
    if (darkTouched && darkTouched->GetStackAmount() >= EREDAR_SWAP_STACK_THRESHOLD)
    {
        Unit* sacrolash = AI_VALUE2(Unit*, "find target", "lady sacrolash");
        if (sacrolash && victim == sacrolash)
            return true;
    }
    if (flameTouched && flameTouched->GetStackAmount() >= EREDAR_SWAP_STACK_THRESHOLD)
    {
        Unit* alythess = AI_VALUE2(Unit*, "find target", "grand warlock alythess");
        if (alythess && victim == alythess)
            return true;
    }
    return false;
}

// Kalecgos

bool KalecgosBotInSpectralRealmTrigger::IsActive()
{
    if (!bot->HasAura(SPELL_SPECTRAL_REALM))
        return false;

    Unit* sath = AI_VALUE2(Unit*, "find target", "sathrovarr the corruptor");
    if (!sath || !sath->IsAlive())
        return false;

    return bot->GetVictim() != sath;
}

bool KalecgosBossIsBanishedTrigger::IsActive()
{
    Unit* kalecgos = AI_VALUE2(Unit*, "find target", "kalecgos");
    if (!kalecgos)
        return false;
    if (!kalecgos->HasAura(SPELL_BANISH))
        return false;

    // Spectral-realm bots already attack Sathrovarr.
    if (bot->HasAura(SPELL_SPECTRAL_REALM))
        return false;

    Unit* sath = AI_VALUE2(Unit*, "find target", "sathrovarr the corruptor");
    if (!sath || !sath->IsAlive())
        return false;

    return bot->GetVictim() == kalecgos;
}
