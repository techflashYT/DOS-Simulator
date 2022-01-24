#include "inc/main.h"

int main(int argc, char** argv) {

	cout << "===========DOS SIMULATOR LOADING===========\r\n";
	string prompt = "";
	string arg1 = "";

	if (argc >= 2) { // 1 argument
		arg1 = argv[1];
	}
	bool KbdReady;
	bool MouseReady;
	bool AllReady;
	bool DataDirExists;
	int tries;


	KbdReady = MouseReady = DataDirExists = AllReady = false;

	tries = 0;

	DataDirExists = checkDataDir(arg1);

	while (!AllReady) {
		if (!(tries >= 3)) {
			KbdReady = initKbd();
			MouseReady = initMouse();
			prompt = initCommandLine();
			tries++;
		}
		else {
			cerr << "Tried to init simulator 3 times and failed on each, exiting...";
			return 1;
		}

		if (KbdReady && MouseReady && prompt != "") {
			AllReady = true;
		}
	}
	loop(prompt);
}