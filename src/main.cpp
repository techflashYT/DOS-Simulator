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
			if (checkDataDir(arg1) == SUCCESS) {
				DataDirExists = true;
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
	loop(&prompt);
}