#include "RaidSwpScripts.h"

#include "AoeAvoidance.h"
#include "Map.h"
#include "RaidSwpHelpers.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellScript.h"

using namespace SunwellHelpers;

// Listens for AoE casts on Sunwell Plateau encounters and registers the
// resulting damage zones with AoeAvoidance so bots can dodge them via
// AvoidAoeAction's danger-zones branch (added in step 1).
//
// Filters by mapId so the listener does not run any logic when bosses cast
// the same spell IDs in unrelated content (defensive: SWP IDs are unique
// today but this future-proofs against ID reuse).
class SunwellBossListenerScript : public AllSpellScript
{
public:
    SunwellBossListenerScript() : AllSpellScript("SunwellBossListenerScript") {}

    void OnSpellCast(Spell* /*spell*/, Unit* caster, SpellInfo const* spellInfo,
                     bool /*skipCheck*/) override
    {
        if (!caster || !caster->GetMap())
            return;
        if (caster->GetMapId() != SUNWELL_PLATEAU_MAP_ID)
            return;

        uint32 instanceId = caster->GetMap()->GetInstanceId();

        // Brutallus — Stomp is a frontal melee AoE the tank must absorb to
        // hold aggro. Tank policy = STAY so the tank does not flee while
        // non-tank melee bots reposition out of range.
        if (spellInfo->Id == SPELL_STOMP)
        {
            AoeAvoidance::RegisterDangerZone(
                instanceId,
                caster->GetPosition(),
                STOMP_RADIUS,
                STOMP_TTL_MS,
                spellInfo->Id,
                AoeAvoidance::TANK_POLICY_STAY);
            return;
        }

        // Felmyst — Demonic Vapor trail clouds. Each `npc_demonic_vapor_trail`
        // casts SPELL_DEMONIC_VAPOR_TRAIL_PERIODIC on itself when it spawns,
        // then despawns after 20s. Register the spawn position so bots avoid
        // it for the cloud's lifetime.
        if (spellInfo->Id == SPELL_DEMONIC_VAPOR_TRAIL_PERIODIC)
        {
            AoeAvoidance::RegisterDangerZone(
                instanceId,
                caster->GetPosition(),
                DEMONIC_VAPOR_TRAIL_RADIUS,
                DEMONIC_VAPOR_TRAIL_TTL_MS,
                spellInfo->Id,
                AoeAvoidance::TANK_POLICY_FLEE);
            return;
        }

        // Felmyst — flight-phase breath. Boss casts SPELL_STRAFE_*
        // 16 times along a lane (250ms apart); each cast lays down one
        // tile of the corridor, building a continuous danger path the
        // raid must clear. Tank policy is FLEE: during the breath the
        // boss is unreachable anyway, so no aggro to drop.
        if (spellInfo->Id == SPELL_STRAFE_TOP    ||
            spellInfo->Id == SPELL_STRAFE_MIDDLE ||
            spellInfo->Id == SPELL_STRAFE_BOTTOM)
        {
            AoeAvoidance::RegisterDangerZone(
                instanceId,
                caster->GetPosition(),
                STRAFE_RADIUS,
                STRAFE_TTL_MS,
                spellInfo->Id,
                AoeAvoidance::TANK_POLICY_FLEE);
            return;
        }

        // Felmyst — Gas Nova is a self-cast AoE that ticks around the boss
        // during the ground phase. Tank policy is STAY (tank holds aggro
        // and eats it); ranged DPS / healers step to max range.
        if (spellInfo->Id == SPELL_GAS_NOVA)
        {
            AoeAvoidance::RegisterDangerZone(
                instanceId,
                caster->GetPosition(),
                GAS_NOVA_RADIUS,
                GAS_NOVA_TTL_MS,
                spellInfo->Id,
                AoeAvoidance::TANK_POLICY_STAY);
            return;
        }

        // Eredar Twins — Blaze flame patches. Alythess casts SPELL_BLAZE on
        // her victim every ~3.8s, which script-effects into SPELL_BLAZE_SUMMON
        // cast by the victim on themselves; the summon spawns the patch at
        // that ground position. Register it so bots dodge.
        if (spellInfo->Id == SPELL_BLAZE_SUMMON)
        {
            AoeAvoidance::RegisterDangerZone(
                instanceId,
                caster->GetPosition(),
                BLAZE_RADIUS,
                BLAZE_TTL_MS,
                spellInfo->Id,
                AoeAvoidance::TANK_POLICY_FLEE);
            return;
        }
    }
};

void AddSC_SunwellPlateauBotScripts()
{
    new SunwellBossListenerScript();
}
