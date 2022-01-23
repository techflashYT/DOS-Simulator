#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::cerr;
using std::string;


bool initKbd();
bool initMouse();
string initCommandLine();
void loop(string prompt);