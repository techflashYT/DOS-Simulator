#pragma once


#include "defines.h"

#include <iostream>
#include <string>

using std::cout;
using std::cerr;
using std::string;


string initCommandLine();
void loop(string *prompt);
USI checkDataDir(string arg1);

#ifdef debugMode
void debugModeSelect();
#endif
