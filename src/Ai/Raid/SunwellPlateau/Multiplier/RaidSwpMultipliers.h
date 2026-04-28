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

// Kil'jaeden
//
// While Hands of the Deceiver are alive (Phase 2), pauses any offensive
// action that targets Kil'jaeden himself so DPS bots roll onto the Hands.
// The Hands gate Phase 3 transition; killing Kil'jaeden too early without
// using a Hand to absorb Darkness of a Thousand Souls wipes the raid.
class KiljaedenFocusHandsMultiplier : public Multiplier
{
public:
    KiljaedenFocusHandsMultiplier(PlayerbotAI* botAI)
        : Multiplier(botAI, "kiljaeden focus hands multiplier") {}
    float GetValue(Action* action) override;
};

#endif
