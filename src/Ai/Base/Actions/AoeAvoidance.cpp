#include "AoeAvoidance.h"

#include <algorithm>

#include "Timer.h"

namespace AoeAvoidance
{
    std::unordered_map<uint32, std::vector<DangerZone>> dangerZones;

    void RegisterDangerZone(uint32 instanceId, Position const& pos, float radius,
                            uint32 ttlMs, uint32 sourceSpellId, TankPolicy tankPolicy)
    {
        if (instanceId == 0 || radius <= 0.0f || ttlMs == 0)
            return;

        PruneExpiredDangerZones(instanceId);

        DangerZone zone;
        zone.pos = pos;
        zone.radius = radius;
        zone.expireMs = getMSTime() + ttlMs;
        zone.sourceSpellId = sourceSpellId;
        zone.tankPolicy = tankPolicy;
        dangerZones[instanceId].push_back(zone);
    }

    void PruneExpiredDangerZones(uint32 instanceId)
    {
        auto it = dangerZones.find(instanceId);
        if (it == dangerZones.end())
            return;

        uint32 nowMs = getMSTime();
        auto& zones = it->second;
        zones.erase(std::remove_if(zones.begin(), zones.end(),
                                   [nowMs](DangerZone const& z)
                                   { return z.expireMs <= nowMs; }),
                    zones.end());

        if (zones.empty())
            dangerZones.erase(it);
    }

    void ClearInstanceDangerZones(uint32 instanceId)
    {
        dangerZones.erase(instanceId);
    }
}
