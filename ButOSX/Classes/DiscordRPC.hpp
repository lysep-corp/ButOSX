//
//  DiscordRPC.hpp
//  ButOSX
//
//  Created by Can on 31.03.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//

#ifndef DiscordRPC_hpp
#define DiscordRPC_hpp

#include <stdio.h>
#include "../Thirdparty/discord-rpc/include/discord_rpc.h"
#include "../Thirdparty/discord-rpc/include/discord_register.h"

namespace DiscordRPC {
    void StartDiscordRPC();
    void UpdateDiscordRPC();
}

#endif /* DiscordRPC_hpp */
