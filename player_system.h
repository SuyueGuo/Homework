#ifndef PLAYER_SYSTEM_H
#define PLAYER_SYSTEM_H

#include"system.h"
#include"player.h"

class player_system:public system, public player
{
public:
    player_system();
};

#endif // PLAYER_SYSTEM_H
