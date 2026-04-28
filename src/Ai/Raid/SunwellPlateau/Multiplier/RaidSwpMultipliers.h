#ifndef _PLAYERBOT_RAIDSWPMULTIPLIERS_H
#define _PLAYERBOT_RAIDSWPMULTIPLIERS_H

#include "Multiplier.h"

// Kalecgos
//
// Pauses bots' offensive actions on whichever boss is too far ahead so that
// Kalecgos and Sathrovarr reach the simultaneous 1% banish at the same time.
class KalecgosHpBalanceMultiplier : public Multiplier
{
public:
    KalecgosHpBalanceMultiplier(PlayerbotAI* botAI)
        : Multiplier(botAI, "kalecgos hp balance multiplier") {}
    float GetValue(Action* action) override;
};

#endif
