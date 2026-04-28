#ifndef _PLAYERBOT_RAIDSWPTRIGGERS_H
#define _PLAYERBOT_RAIDSWPTRIGGERS_H

#include "Trigger.h"

// Brutallus

class BrutallusBotHasBurnTrigger : public Trigger
{
public:
    BrutallusBotHasBurnTrigger(PlayerbotAI* botAI)
        : Trigger(botAI, "brutallus bot has burn") {}
    bool IsActive() override;
};

class BrutallusBotInMeteorSlashConeTrigger : public Trigger
{
public:
    BrutallusBotInMeteorSlashConeTrigger(PlayerbotAI* botAI)
        : Trigger(botAI, "brutallus bot in meteor slash cone") {}
    bool IsActive() override;
};

class BrutallusAllyHasBurnTrigger : public Trigger
{
public:
    BrutallusAllyHasBurnTrigger(PlayerbotAI* botAI)
        : Trigger(botAI, "brutallus ally has burn") {}
    bool IsActive() override;
};

#endif
