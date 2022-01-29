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
#define ERROR_FILE_FOLDER_EXISTS	  109
#define ERROR_DIRECTORY_NOT_EMPTY	  110




// Warnings
#define WARNING_NONEXISTENT_DIRECTORY 209





// Error Strings
#define ERROR_DIRECTORY_NOT_FOUND		"The directory does not exist.\r\n"
#ifdef _WIN32
#define ERROR_MAIN_DIR_CORRUPT_STR		"The main data directory is corrupted!  Please delete it.  You can find it in %appdata%\\Sanikdah Software\\DOS Simulator"
#define ERROR_DRIVE_DIRS_CORRUPT_STR	"The A, B, or C drive directories are corrupted!  Please delete them.  You can find them in %appdata%\\Sanikdah Software\\DOS Simulator"
#else
#define ERROR_MAIN_DIR_CORRUPT_STR		"The main data directory is corrupted!  Please delete it.  You can find it in ~/Sanikdah Software/DOS Simulator"
#define ERROR_DRIVE_DIRS_CORRUPT_STR	"The A, B, or C drive directories are corrupted!  Please delete them.  You can find them in ~/Sanikdah Software/DOS Simulator"
#endif

#define ERROR_ASSETS_NOT_DOWNLOADED_STR "The assets for the program could not be downloaded due to an unknown error.  Please report this along with any additional errors in your console to the developer, here: "
#define ERROR_FILE_FOLDER_EXISTS_STR    "The specified file or folder already exists."

typedef unsigned short int USI;


#define debugMode true
