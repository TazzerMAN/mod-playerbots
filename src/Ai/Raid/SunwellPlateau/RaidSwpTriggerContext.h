#ifndef _PLAYERBOT_RAIDSWPTRIGGERCONTEXT_H
#define _PLAYERBOT_RAIDSWPTRIGGERCONTEXT_H

#include "RaidSwpTriggers.h"
#include "AiObjectContext.h"

class RaidSwpTriggerContext : public NamedObjectContext<Trigger>
{
public:
    RaidSwpTriggerContext()
    {
        // Brutallus
        creators["brutallus bot has burn"] =
            &RaidSwpTriggerContext::brutallus_bot_has_burn;
        creators["brutallus bot in meteor slash cone"] =
            &RaidSwpTriggerContext::brutallus_bot_in_meteor_slash_cone;
        creators["brutallus ally has burn"] =
            &RaidSwpTriggerContext::brutallus_ally_has_burn;
    }

private:
    static Trigger* brutallus_bot_has_burn(PlayerbotAI* botAI)
    {
        return new BrutallusBotHasBurnTrigger(botAI);
    }
    static Trigger* brutallus_bot_in_meteor_slash_cone(PlayerbotAI* botAI)
    {
        return new BrutallusBotInMeteorSlashConeTrigger(botAI);
    }
    static Trigger* brutallus_ally_has_burn(PlayerbotAI* botAI)
    {
        return new BrutallusAllyHasBurnTrigger(botAI);
    }
};

#endif
