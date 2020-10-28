//
//  ButOSX.cpp
//  ButOSX
//
//  Created by Can Destan on 29.10.2020.
//  Copyright © 2020 VersteckteKrone. All rights reserved.
//

#include <iostream>
#include "ButOSX.hpp"
#include "ButOSXPriv.hpp"

void ButOSX::HelloWorld(const char * s)
{
    ButOSXPriv *theObj = new ButOSXPriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void ButOSXPriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

