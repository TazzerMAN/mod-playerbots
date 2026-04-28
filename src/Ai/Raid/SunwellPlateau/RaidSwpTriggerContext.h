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

        // Felmyst
        creators["felmyst bot has encapsulate"] =
            &RaidSwpTriggerContext::felmyst_bot_has_encapsulate;
        creators["felmyst boss is flying"] =
            &RaidSwpTriggerContext::felmyst_boss_is_flying;
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
    static Trigger* felmyst_bot_has_encapsulate(PlayerbotAI* botAI)
    {
        return new FelmystBotHasEncapsulateTrigger(botAI);
    }
    static Trigger* felmyst_boss_is_flying(PlayerbotAI* botAI)
    {
        return new FelmystBossIsFlyingTrigger(botAI);
    }
};

#endif
