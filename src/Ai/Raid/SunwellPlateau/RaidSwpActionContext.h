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
};

#endif
