#pragma once

#define ver 0.1

#define MAX_SHELLS 25
#define MAX_COMMAND_LENGTH 100

#define SUCCESS							0
// Errors
#define GENERIC_FAIL					1


#define ERROR_INIT			          101
#define ERROR_CURL_SETUP_FAIL         102
#define ERROR_ASSET_DOWNLOAD          103
#define ERROR_MAIN_DIR_CORRUPT        104
#define ERROR_DRIVE_DIRS_CORRUPT      105
#define ERROR_ASSETS_NOT_DOWNLOADED   106
#define ERROR_DIRECTORY_NOT_CHANGED   107
#define ERROR_FELL_THROUGH_IF_ELSE    108




// Warnings
#define WARNING_NONEXISTENT_DIRECTORY 209





// Error Strings
#define ERROR_DIRECTORY_NOT_FOUND  "The directory does not exist.\r\n"
#ifdef _WIN32
#define ERROR_MAIN_DIR_CORRUPT_STR "The main data directory is corrupted!  Please delete it.  You can find it in %appdata%\\Sanikdah Software\\DOS Simulator"
#else
#define ERROR_MAIN_DIR_CORRUPT_STR "The main data directory is corrupted!  Please delete it.  You can find it in ~/Sanikdah Software/DOS Simulator"
#endif

typedef unsigned short int USI;
