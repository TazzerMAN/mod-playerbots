#include "RaidSwpMultipliers.h"

#include "AttackAction.h"
#include "GenericSpellActions.h"
#include "Playerbots.h"
#include "RaidSwpHelpers.h"
#include "Unit.h"

using namespace SunwellHelpers;

float KalecgosHpBalanceMultiplier::GetValue(Action* action)
{
    Unit* kalecgos = AI_VALUE2(Unit*, "find target", "kalecgos");
    Unit* sath = AI_VALUE2(Unit*, "find target", "sathrovarr the corruptor");
    if (!kalecgos || !sath)
        return 1.0f;
    if (!kalecgos->IsAlive() || !sath->IsAlive())
        return 1.0f;

    float kalecgosHp = kalecgos->GetHealthPct();
    float sathHp = sath->GetHealthPct();

    bool botInSpectralRealm = bot->HasAura(SPELL_SPECTRAL_REALM);

    // The boss the bot can damage in their current realm.
    float ourBossHp   = botInSpectralRealm ? sathHp     : kalecgosHp;
    float otherBossHp = botInSpectralRealm ? kalecgosHp : sathHp;

    // We are ahead — our boss has noticeably less HP. Pause offensive
    // actions until the other realm catches up.
    if (ourBossHp + KALECGOS_HP_BALANCE_THRESHOLD < otherBossHp)
    {
        if (dynamic_cast<AttackAction*>(action) ||
            dynamic_cast<CastSpellAction*>(action))
            return 0.0f;
    }

    return 1.0f;
}
