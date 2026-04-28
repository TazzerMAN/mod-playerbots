#ifndef _PLAYERBOT_AOEAVOIDANCE_H_
#define _PLAYERBOT_AOEAVOIDANCE_H_

#include <cstdint>
#include <unordered_map>
#include <vector>

#include "Position.h"

namespace AoeAvoidance
{
    enum TankPolicy : uint8_t
    {
        TANK_POLICY_FLEE       = 0,
        TANK_POLICY_STAY       = 1,
        TANK_POLICY_SHORT_STEP = 2
    };

    struct DangerZone
    {
        Position pos;
        float radius = 0.0f;
        uint32 expireMs = 0;
        uint32 sourceSpellId = 0;
        TankPolicy tankPolicy = TANK_POLICY_FLEE;
    };

    extern std::unordered_map<uint32 /*instanceId*/, std::vector<DangerZone>> dangerZones;

    // Register a transient AoE zone the bots should avoid. Typically called from
    // an AllSpellScript-derived listener on a boss cast. The zone's radius is
    // used as-is (it bypasses sPlayerbotAIConfig.maxAoeAvoidRadius) so callers
    // own their own validation.
    //
    // Note: if the same physical AoE is also detected by one of the generic
    // branches (DynamicObject aura, GameObject trap, NPC trigger), the generic
    // branch will still flee even when this branch's tank policy is STAY. Add
    // the spell ID to AiPlayerbot.AoeAvoidSpellWhitelist if you need the
    // generic branches to defer entirely to the registered zone.
    void RegisterDangerZone(uint32 instanceId, Position const& pos, float radius,
                            uint32 ttlMs, uint32 sourceSpellId,
                            TankPolicy tankPolicy = TANK_POLICY_FLEE);
    void PruneExpiredDangerZones(uint32 instanceId);
    void ClearInstanceDangerZones(uint32 instanceId);
}

#endif
