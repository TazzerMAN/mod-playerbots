#include "RaidSwpStrategy.h"

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
}
