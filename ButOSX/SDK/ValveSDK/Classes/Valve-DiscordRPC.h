//
//  Valve-DiscordRPC.h
//  ButOSX
//
//  Created by Can on 31.03.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//

#ifndef Valve_DiscordRPC_h
#define Valve_DiscordRPC_h

//GOT FROM: https://developer.valvesoftware.com/wiki/Implementing_Discord_RPC

//-----------------------------------------------------------------------------
// Discord RPC
//-----------------------------------------------------------------------------
static void HandleDiscordReady(const DiscordUser* connectedUser)
{
    printf("Discord: Connected to user %s#%s - %s\n",
        connectedUser->username,
        connectedUser->discriminator,
        connectedUser->userId);
}

static void HandleDiscordDisconnected(int errcode, const char* message)
{
    printf("Discord: Disconnected (%d: %s)\n", errcode, message);
}

static void HandleDiscordError(int errcode, const char* message)
{
    printf("Discord: Error (%d: %s)\n", errcode, message);
}

static void HandleDiscordJoin(const char* secret)
{
    // Not implemented
}

static void HandleDiscordSpectate(const char* secret)
{
    // Not implemented
}

static void HandleDiscordJoinRequest(const DiscordUser* request)
{
    // Not implemented
}

#endif /* Valve_DiscordRPC_h */
