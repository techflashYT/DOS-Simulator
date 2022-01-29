#pragma once

#include "defines.h"

#include <string>
#include <iostream>

using std::string;
using std::cout;

void ListDir(string prompt);
USI ChangeDir(string dir, string *prompt);
USI makeDir(string dir, string prompt);

using std::cerr;
