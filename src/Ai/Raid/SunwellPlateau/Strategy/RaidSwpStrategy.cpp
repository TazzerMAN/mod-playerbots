#include "RaidSwpStrategy.h"

#include "RaidSwpMultipliers.h"

void RaidSwpStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    // Brutallus
    triggers.push_back(new TriggerNode("brutallus bot has burn",
        { NextAction("brutallus burn spread", ACTION_EMERGENCY + 6) }));

    triggers.push_back(new TriggerNode("brutallus ally has burn",
        { NextAction("brutallus spread from cursed ally", ACTION_EMERGENCY + 5) }));

    triggers.push_back(new TriggerNode("brutallus bot in meteor slash cone",
        { NextAction("brutallus position behind boss", ACTION_RAID + 1) }));

    // Felmyst
    triggers.push_back(new TriggerNode("felmyst bot has encapsulate",
        { NextAction("felmyst encapsulate flee", ACTION_EMERGENCY + 6) }));

    triggers.push_back(new TriggerNode("felmyst boss is flying",
        { NextAction("felmyst pre-landing position", ACTION_RAID + 1) }));

    // Eredar Twins
    triggers.push_back(new TriggerNode("eredar twins bot has conflagration",
        { NextAction("eredar twins conflagration flee", ACTION_EMERGENCY + 6) }));

    triggers.push_back(new TriggerNode("eredar twins bot needs tank swap",
        { NextAction("eredar twins taunt other sister", ACTION_EMERGENCY + 8) }));

    // Kalecgos
    triggers.push_back(new TriggerNode("kalecgos bot in spectral realm",
        { NextAction("kalecgos focus sathrovarr", ACTION_EMERGENCY + 7) }));

    triggers.push_back(new TriggerNode("kalecgos boss is banished",
        { NextAction("kalecgos focus sathrovarr", ACTION_EMERGENCY + 7) }));

    // Kil'jaeden
    triggers.push_back(new TriggerNode("kiljaeden bot has fire bloom",
        { NextAction("kiljaeden fire bloom flee", ACTION_EMERGENCY + 6) }));
}

void RaidSwpStrategy::InitMultipliers(std::vector<Multiplier*>& multipliers)
{
    // Kalecgos
    multipliers.push_back(new KalecgosHpBalanceMultiplier(botAI));

    // Kil'jaeden
    multipliers.push_back(new KiljaedenFocusHandsMultiplier(botAI));
}
