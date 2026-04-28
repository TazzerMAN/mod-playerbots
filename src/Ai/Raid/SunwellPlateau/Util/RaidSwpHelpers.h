#ifndef _PLAYERBOT_RAIDSWPHELPERS_H_
#define _PLAYERBOT_RAIDSWPHELPERS_H_

#include "Define.h"

namespace SunwellHelpers
{
    enum SwpSpells
    {
        // Brutallus
        SPELL_METEOR_SLASH      = 45150,
        SPELL_BURN              = 45141,
        SPELL_BURN_DAMAGE       = 46394,
        SPELL_STOMP             = 45185,
    };

    enum SwpNPCs
    {
        // Brutallus
        NPC_BRUTALLUS           = 24882,
    };

    constexpr uint32 SUNWELL_PLATEAU_MAP_ID = 580;

    // Brutallus tuning
    // Burn cast spreads its DoT to allies within ~7y at the cast moment;
    // 10y leaves a small safety buffer.
    constexpr float BURN_SPREAD_DISTANCE      = 10.0f;
    constexpr float METEOR_SLASH_AVOID_RADIUS = 50.0f;
    constexpr float METEOR_SLASH_FRONT_ARC    = 2.0f * M_PI / 3.0f; // ±60°
    // Number of angular slots used to disperse non-tanks behind Brutallus
    // when the Meteor Slash cone trigger fires (prevents stacking at a
    // single point which would chain-cleave the dispersers).
    constexpr uint32 METEOR_SLASH_DISPERSE_SLOTS = 8;
    // Stomp is a frontal melee AoE; ~10y range. Cast is short (~1.5s) but
    // the danger zone TTL is held a bit longer to cover cast-to-impact.
    constexpr float STOMP_RADIUS              = 10.0f;
    constexpr uint32 STOMP_TTL_MS             = 2500;
}

#endif
