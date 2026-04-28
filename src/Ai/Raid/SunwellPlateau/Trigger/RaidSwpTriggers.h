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

// Felmyst

class FelmystBotHasEncapsulateTrigger : public Trigger
{
public:
    FelmystBotHasEncapsulateTrigger(PlayerbotAI* botAI)
        : Trigger(botAI, "felmyst bot has encapsulate") {}
    bool IsActive() override;
};

class FelmystBossIsFlyingTrigger : public Trigger
{
public:
    FelmystBossIsFlyingTrigger(PlayerbotAI* botAI)
        : Trigger(botAI, "felmyst boss is flying") {}
    bool IsActive() override;
};

// Eredar Twins

class EredarTwinsBotHasConflagrationTrigger : public Trigger
{
public:
    EredarTwinsBotHasConflagrationTrigger(PlayerbotAI* botAI)
        : Trigger(botAI, "eredar twins bot has conflagration") {}
    bool IsActive() override;
};

class EredarTwinsBotNeedsTankSwapTrigger : public Trigger
{
public:
    EredarTwinsBotNeedsTankSwapTrigger(PlayerbotAI* botAI)
        : Trigger(botAI, "eredar twins bot needs tank swap") {}
    bool IsActive() override;
};

// Kalecgos

class KalecgosBotInSpectralRealmTrigger : public Trigger
{
public:
    KalecgosBotInSpectralRealmTrigger(PlayerbotAI* botAI)
        : Trigger(botAI, "kalecgos bot in spectral realm") {}
    bool IsActive() override;
};

class KalecgosBossIsBanishedTrigger : public Trigger
{
public:
    KalecgosBossIsBanishedTrigger(PlayerbotAI* botAI)
        : Trigger(botAI, "kalecgos boss is banished") {}
    bool IsActive() override;
};

#endif
