#pragma once

#include "defines.h"


#include <filesystem>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <fstream>
#include <sstream>

#ifdef _WIN32
#include <direct.h>
#else
#include <unistd.h>
#endif

USI downloadAssets();

using std::string;
using std::filesystem::path;
using std::error_code;
using std::filesystem::is_directory;
using std::cerr;
using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::filesystem::directory_iterator;
using std::stringstream;