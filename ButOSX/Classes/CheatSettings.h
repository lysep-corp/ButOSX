//
//  CheatSettings.h
//  ButOSX
//
//  Created by Can on 30.10.2020.
//  Copyright © 2020 VersteckteKrone. All rights reserved.
//

#ifndef CheatSettings_h
#define CheatSettings_h
class CheatSettings {
public:
    struct Visuals {
        struct EaslySpotPlayer {
            bool enabled = false;
        } ESP;
    } Visuals;
};
inline std::unique_ptr<CheatSettings> CheatSettings;
#endif /* CheatSettings_h */
