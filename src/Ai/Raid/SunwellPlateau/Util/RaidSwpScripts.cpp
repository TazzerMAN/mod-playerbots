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
    }
};

void AddSC_SunwellPlateauBotScripts()
{
    new SunwellBossListenerScript();
}
