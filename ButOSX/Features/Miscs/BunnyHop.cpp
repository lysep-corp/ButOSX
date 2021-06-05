//
//  BunnyHop.cpp
//  ButOSX
//
//  Created by Can on 5.06.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//

#include "Miscs.hpp"

bool bLastJumped;
bool bShouldFake;
void Miscs::Movement::BunnyHop(CUserCmd* cmd){ //Credits: AimTux team.
    if(!miscButton_BunnyHop->state)
        return;
    if(!pEngine->IsInGame())
        return;
    static unique_ptr<C_BasePlayer>pLocal((C_BasePlayer*)pEntList->GetClientEntity(pEngine->GetLocalPlayer()));
    if (!pLocal || !pLocal.get() || !pLocal->IsAlive())
        return;

    if (pLocal->GetMoveType() == MOVETYPE_LADDER || pLocal->GetMoveType() == MOVETYPE_NOCLIP)
        return;

    if (!bLastJumped && bShouldFake)
    {
        bShouldFake = false;
        cmd->buttons |= IN_JUMP;
    }
    else if (cmd->buttons & IN_JUMP)
    {
        if (pLocal->GetFlags() & FL_ONGROUND)
        {
            bLastJumped = true;
            bShouldFake = true;
        }
        else
        {
            cmd->buttons &= ~IN_JUMP;
            bLastJumped = false;
        }
    }
    else
    {
        bLastJumped = false;
        bShouldFake = false;
    }
}
