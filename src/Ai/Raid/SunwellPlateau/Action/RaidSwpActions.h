#ifndef _PLAYERBOT_RAIDSWPACTIONS_H
#define _PLAYERBOT_RAIDSWPACTIONS_H

#include "MovementActions.h"

// Brutallus

class BrutallusBurnSpreadAction : public MovementAction
{
public:
    BrutallusBurnSpreadAction(PlayerbotAI* botAI)
        : MovementAction(botAI, "brutallus burn spread") {}
    bool Execute(Event event) override;
};

class BrutallusPositionBehindBossAction : public MovementAction
{
public:
    BrutallusPositionBehindBossAction(PlayerbotAI* botAI)
        : MovementAction(botAI, "brutallus position behind boss") {}
    bool Execute(Event event) override;
};

class BrutallusSpreadFromCursedAllyAction : public MovementAction
{
public:
    BrutallusSpreadFromCursedAllyAction(PlayerbotAI* botAI)
        : MovementAction(botAI, "brutallus spread from cursed ally") {}
    bool Execute(Event event) override;
};

// Felmyst

class FelmystEncapsulateFleeAction : public MovementAction
{
public:
    FelmystEncapsulateFleeAction(PlayerbotAI* botAI)
        : MovementAction(botAI, "felmyst encapsulate flee") {}
    bool Execute(Event event) override;
};

class FelmystPreLandingPositionAction : public MovementAction
{
public:
    FelmystPreLandingPositionAction(PlayerbotAI* botAI)
        : MovementAction(botAI, "felmyst pre-landing position") {}
    bool Execute(Event event) override;
};

// Eredar Twins

class EredarTwinsConflagrationFleeAction : public MovementAction
{
public:
    EredarTwinsConflagrationFleeAction(PlayerbotAI* botAI)
        : MovementAction(botAI, "eredar twins conflagration flee") {}
    bool Execute(Event event) override;
};

class EredarTwinsTauntOtherSisterAction : public Action
{
public:
    EredarTwinsTauntOtherSisterAction(PlayerbotAI* botAI)
        : Action(botAI, "eredar twins taunt other sister") {}
    bool Execute(Event event) override;
};

// Kalecgos

class KalecgosFocusSathrovarrAction : public Action
{
public:
    KalecgosFocusSathrovarrAction(PlayerbotAI* botAI)
        : Action(botAI, "kalecgos focus sathrovarr") {}
    bool Execute(Event event) override;
};

#endif
