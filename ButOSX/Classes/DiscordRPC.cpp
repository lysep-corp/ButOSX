//
//  DiscordRPC.cpp
//  ButOSX
//
//  Created by Can on 31.03.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//

#include <string.h>
#include "DiscordRPC.hpp"
#include "../SDK/ValveSDK/Classes/Valve-DiscordRPC.h"

void DiscordRPC::StartDiscordRPC(){
    DiscordEventHandlers event_handler;
    memset(&event_handler, 0, sizeof(event_handler));
    Discord_Initialize("826773765341052949", &event_handler, 1, "730");
    UpdateDiscordRPC();
}

void DiscordRPC::UpdateDiscordRPC()
{
    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));
    discordPresence.state = "by github.com/Lyceion";
    discordPresence.details = "Game: CSGO";
    discordPresence.largeImageKey = "butosxmax";
    discordPresence.largeImageText = "ButOSX - CSGO";
    discordPresence.partyId = "ae488379-351d-4a4f-ad32-2b9b01c91657";
    discordPresence.joinSecret = "MTI4NzM0OjFpMmhuZToxMjMxMjM= ";
    Discord_UpdatePresence(&discordPresence);
}
