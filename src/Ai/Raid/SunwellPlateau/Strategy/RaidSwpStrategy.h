#ifndef _PLAYERBOT_RAIDSWPSTRATEGY_H_
#define _PLAYERBOT_RAIDSWPSTRATEGY_H_

#include "Strategy.h"
#include "Multiplier.h"

class RaidSwpStrategy : public Strategy
{
public:
    RaidSwpStrategy(PlayerbotAI* botAI) : Strategy(botAI) {}

    std::string const getName() override { return "sunwell"; }

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    void InitMultipliers(std::vector<Multiplier*>& multipliers) override;
};

#endif
