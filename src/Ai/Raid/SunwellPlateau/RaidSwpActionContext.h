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
};

#endif
