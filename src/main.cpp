#include "inc/main.h"

int main(int argc, char** argv) {

	cout << "===========DOS SIMULATOR LOADING===========\r\n";
	string prompt = "";
	string arg1 = "";

	if (argc >= 2) { // 1 argument
		arg1 = argv[1];
	}
	bool AllReady;
	bool DataDirExists;
	int tries;


	DataDirExists = AllReady = false;

	tries = 0;


	while (!AllReady) {
		if (!(tries >= 3)) {
			prompt = initCommandLine();
			USI retValue = checkDataDir(arg1);
			if (retValue == SUCCESS) {
				DataDirExists = true;
			}
			else if (retValue == ERROR_MAIN_DIR_CORRUPT) {
				cerr << ERROR_MAIN_DIR_CORRUPT_STR;
			}
			else if (retValue == ERROR_DRIVE_DIRS_CORRUPT) {
				cerr << ERROR_DRIVE_DIRS_CORRUPT_STR;
			}
			else if (retValue == ERROR_ASSETS_NOT_DOWNLOADED) {
				cerr << ERROR_ASSETS_NOT_DOWNLOADED_STR;
			}
			tries++;
		}
		else {
			cerr << "Tried to init simulator 3 times and failed on each, exiting...";
			return ERROR_INIT;
		}

		if (DataDirExists && prompt != "") {
			AllReady = true;
		}
	}
#ifdef debugMode
	debugModeSelect();
#endif
	loop(&prompt);
	return GENERIC_FAIL;
}
