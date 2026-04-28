#include "RaidSwpHelpers.h"

namespace SunwellHelpers
{
    // Mirrored from boss_felmyst.cpp (LandingLeftPos / LandingRightPos).
    const Position FELMYST_LANDING_LEFT  = { 1476.77f, 665.094f,  20.6423f };
    const Position FELMYST_LANDING_RIGHT = { 1469.93f, 557.009f,  22.6317f };
    // Midpoint between the two pads — equidistant regroup during flight.
    const Position FELMYST_ROOM_CENTER   = { 1473.35f, 611.0515f, 21.6f };
}
