#include "inc/FileActions.h"

bool checkDataDir() {
#ifdef _WIN32
    string username = getenv("USERNAME");
    string pathString = "C:\\Users\\";
    pathString.append(username);
    pathString.append("\\Sanikdah Software\\DOS-Simulator");
#endif

    path path(pathString); // Constructing the path from a string is possible.
    error_code ec; // For using the non-throwing overloads of functions below.
    if (is_directory(path, ec)) {
        // Process a directory.
    }
    if (ec) { // Optional handling of possible errors
        cerr << "Error in is_directory: " << ec.message();
    }
    if (is_regular_file(path, ec)) {
        // Process a regular file.
    }
    if (ec) { // Optional handling of possible errors. Usage of the same ec object works since fs functions are calling ec.clear() if no errors occur.
        cerr << "Error in is_regular_file: " << ec.message();
    }
}