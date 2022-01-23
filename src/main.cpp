#include "inc/main.h"

string prompt = "";


int main() {
	cout << "===========DOS SIMULATOR LOADING===========\r\n";

	bool KbdReady;
	bool MouseReady;
	bool AllReady;
	bool DataDirExists;
	int tries = 0;


	KbdReady = MouseReady = DataDirExists = AllReady = false;

	DataDirExists = checkDataDir();

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