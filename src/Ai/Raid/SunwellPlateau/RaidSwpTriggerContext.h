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

        // Eredar Twins
        creators["eredar twins bot has conflagration"] =
            &RaidSwpTriggerContext::eredar_twins_bot_has_conflagration;
        creators["eredar twins bot needs tank swap"] =
            &RaidSwpTriggerContext::eredar_twins_bot_needs_tank_swap;
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
    static Trigger* eredar_twins_bot_has_conflagration(PlayerbotAI* botAI)
    {
        return new EredarTwinsBotHasConflagrationTrigger(botAI);
    }
    static Trigger* eredar_twins_bot_needs_tank_swap(PlayerbotAI* botAI)
    {
        return new EredarTwinsBotNeedsTankSwapTrigger(botAI);
    }
};

#endif
