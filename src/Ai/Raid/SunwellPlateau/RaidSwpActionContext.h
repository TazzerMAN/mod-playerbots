#ifndef _PLAYERBOT_RAIDSWPACTIONCONTEXT_H
#define _PLAYERBOT_RAIDSWPACTIONCONTEXT_H

#include "RaidSwpActions.h"
#include "NamedObjectContext.h"

class RaidSwpActionContext : public NamedObjectContext<Action>
{
public:
    RaidSwpActionContext()
    {
        // Brutallus
        creators["brutallus burn spread"] =
            &RaidSwpActionContext::brutallus_burn_spread;
        creators["brutallus position behind boss"] =
            &RaidSwpActionContext::brutallus_position_behind_boss;
        creators["brutallus spread from cursed ally"] =
            &RaidSwpActionContext::brutallus_spread_from_cursed_ally;

        // Felmyst
        creators["felmyst encapsulate flee"] =
            &RaidSwpActionContext::felmyst_encapsulate_flee;
        creators["felmyst pre-landing position"] =
            &RaidSwpActionContext::felmyst_pre_landing_position;

        // Eredar Twins
        creators["eredar twins conflagration flee"] =
            &RaidSwpActionContext::eredar_twins_conflagration_flee;
        creators["eredar twins taunt other sister"] =
            &RaidSwpActionContext::eredar_twins_taunt_other_sister;

        // Kalecgos
        creators["kalecgos focus sathrovarr"] =
            &RaidSwpActionContext::kalecgos_focus_sathrovarr;

        // Kil'jaeden
        creators["kiljaeden fire bloom flee"] =
            &RaidSwpActionContext::kiljaeden_fire_bloom_flee;
    }

private:
    static Action* brutallus_burn_spread(PlayerbotAI* botAI)
    {
        return new BrutallusBurnSpreadAction(botAI);
    }
    static Action* brutallus_position_behind_boss(PlayerbotAI* botAI)
    {
        return new BrutallusPositionBehindBossAction(botAI);
    }
    static Action* brutallus_spread_from_cursed_ally(PlayerbotAI* botAI)
    {
        return new BrutallusSpreadFromCursedAllyAction(botAI);
    }
    static Action* felmyst_encapsulate_flee(PlayerbotAI* botAI)
    {
        return new FelmystEncapsulateFleeAction(botAI);
    }
    static Action* felmyst_pre_landing_position(PlayerbotAI* botAI)
    {
        return new FelmystPreLandingPositionAction(botAI);
    }
    static Action* eredar_twins_conflagration_flee(PlayerbotAI* botAI)
    {
        return new EredarTwinsConflagrationFleeAction(botAI);
    }
    static Action* eredar_twins_taunt_other_sister(PlayerbotAI* botAI)
    {
        return new EredarTwinsTauntOtherSisterAction(botAI);
    }
    static Action* kalecgos_focus_sathrovarr(PlayerbotAI* botAI)
    {
        return new KalecgosFocusSathrovarrAction(botAI);
    }
    static Action* kiljaeden_fire_bloom_flee(PlayerbotAI* botAI)
    {
        return new KiljaedenFireBloomFleeAction(botAI);
    }
};

#endif
