#pragma once
#pragma comment(lib, "src\\inc\\libs\\LiteUnzip\\LiteUnzip.lib")

#include "inc/defines.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <filesystem>
#ifdef _WIN32
#include <direct.h>
#else
#include <unistd.h>
#endif
#include <curl/curl.h>
#ifndef CURLINC_CURL_H
#error You need to install curl using vcpkg, you can use the following instructions to do so. https://github.com/sanikdah/DOS-Simulator/wiki/%5BError%5D-Cannot-open-include-file:-'curl-curl.h'-OR--You-need-to-install-curl-using-vcpkg
#endif

using std::string;
using std::cout;
using std::cerr;
using std::ofstream;