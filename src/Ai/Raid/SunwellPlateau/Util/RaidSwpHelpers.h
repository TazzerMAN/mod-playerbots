#ifndef _PLAYERBOT_RAIDSWPHELPERS_H_
#define _PLAYERBOT_RAIDSWPHELPERS_H_

#include "Define.h"
#include "Position.h"

namespace SunwellHelpers
{
    enum SwpSpells
    {
        // Brutallus
        SPELL_METEOR_SLASH                  = 45150,
        SPELL_BURN                          = 45141,
        SPELL_BURN_DAMAGE                   = 46394,
        SPELL_STOMP                         = 45185,

        // Felmyst
        SPELL_GAS_NOVA                      = 45855,
        SPELL_ENCAPSULATE_CHANNEL           = 45661,
        SPELL_FOG_OF_CORRUPTION             = 45582,
        SPELL_DEMONIC_VAPOR_TRAIL_PERIODIC  = 45399,
        SPELL_STRAFE_TOP                    = 45585,
        SPELL_STRAFE_MIDDLE                 = 45633,
        SPELL_STRAFE_BOTTOM                 = 45635,

        // Eredar Twins
        SPELL_DARK_TOUCHED                  = 45347,
        SPELL_FLAME_TOUCHED                 = 45348,
        SPELL_SHADOW_NOVA                   = 45329,
        SPELL_PYROGENICS                    = 45230,
        SPELL_CONFLAGRATION                 = 45342,
        SPELL_BLAZE_SUMMON                  = 45236,

        // M'uru / Entropius
        SPELL_DARK_FIEND_APPEARANCE         = 45934,
        SPELL_DARK_FIEND_TRIGGER            = 45944,
    };

    enum SwpNPCs
    {
        // Brutallus
        NPC_BRUTALLUS                       = 24882,
    };

    constexpr uint32 SUNWELL_PLATEAU_MAP_ID = 580;

    // Brutallus tuning
    // Burn cast spreads its DoT to allies within ~7y at the cast moment;
    // 10y leaves a small safety buffer.
    constexpr float BURN_SPREAD_DISTANCE          = 10.0f;
    constexpr float METEOR_SLASH_AVOID_RADIUS     = 50.0f;
    constexpr float METEOR_SLASH_FRONT_ARC        = 2.0f * M_PI / 3.0f; // ±60°
    // Number of angular slots used to disperse non-tanks behind Brutallus
    // when the Meteor Slash cone trigger fires (prevents stacking at a
    // single point which would chain-cleave the dispersers).
    constexpr uint32 METEOR_SLASH_DISPERSE_SLOTS  = 8;
    // Stomp is a frontal melee AoE; ~10y range. Cast is short (~1.5s) but
    // the danger zone TTL is held a bit longer to cover cast-to-impact.
    constexpr float STOMP_RADIUS                  = 10.0f;
    constexpr uint32 STOMP_TTL_MS                 = 2500;

    // Felmyst tuning
    // Encapsulate channels on a single target, Healers cleave-heal them; flee
    // far enough from the raid that the channel beam doesn't catch others.
    constexpr float ENCAPSULATE_FLEE_DISTANCE     = 15.0f;
    // Demonic Vapor trail clouds despawn after 20s; small safety margin.
    constexpr uint32 DEMONIC_VAPOR_TRAIL_TTL_MS   = 20000;
    constexpr float DEMONIC_VAPOR_TRAIL_RADIUS    = 6.0f;
    // Felmyst breath strafes a lane in 16 ticks (250ms apart). Each tick
    // registers a small zone at her current position; chained, the zones
    // tile the breath corridor. TTL covers a couple of ticks of slack.
    constexpr float STRAFE_RADIUS                 = 8.0f;
    constexpr uint32 STRAFE_TTL_MS                = 4000;
    // Gas Nova is a melee-proximity AoE; tank stays in to keep aggro while
    // ranged step out. ~30y is a generous radius matching the canonical
    // 25-man strategy "ranged at max range during ground phase".
    constexpr float GAS_NOVA_RADIUS               = 30.0f;
    constexpr uint32 GAS_NOVA_TTL_MS              = 3000;

    // Landing pads where Felmyst sets down at the end of the flight phase
    // (boss_felmyst.cpp lines 111-112). The center of the room sits halfway
    // between them and is the safest regroup point during flight, since the
    // raid is equidistant to whichever side she ends up choosing.
    extern const Position FELMYST_LANDING_LEFT;
    extern const Position FELMYST_LANDING_RIGHT;
    extern const Position FELMYST_ROOM_CENTER;

    // Eredar Twins tuning
    // Conflagration is a stacking fire DoT that spreads to allies within ~6y;
    // 15y matches the canonical 25-man strategy.
    constexpr float CONFLAGRATION_FLEE_DISTANCE   = 15.0f;
    // Blaze flame patches persist for ~30s on the ground.
    constexpr uint32 BLAZE_TTL_MS                 = 30000;
    constexpr float BLAZE_RADIUS                  = 6.0f;
    // Tank swap threshold: above this stack count of Dark/Flame Touched the
    // tank's damage taken from that school spirals; canonical strat swaps at 5.
    constexpr uint8 EREDAR_SWAP_STACK_THRESHOLD   = 5;

    // M'uru tuning
    // Dark Fiends spawn in a small radius and explode ~3s later. Window of
    // 4s gives a small safety margin before the registry auto-prunes.
    constexpr uint32 DARK_FIEND_TTL_MS            = 4000;
    constexpr float DARK_FIEND_RADIUS             = 5.0f;
}

#endif
