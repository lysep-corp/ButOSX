//
//  ButOSX.cpp
//  ButOSX
//
//  Created by Can on 29.10.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//


//AND IT IS NOT A F*CKIN MICROWAVE FORK.

#include <iostream>
#include "ButOSX.hpp"

int __attribute__((constructor))
attach() //Main attach function which executes when library loads.
{
    //Call ButOSX Initializer
    ButOSX::Initalize();
}
