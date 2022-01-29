#include "inc/CMD.h"

short int shells = 0;
string shellWorkingDirs[MAX_SHELLS];


string initCommandLine() {
	string prompt = "";
	try {
		prompt = "C:\\>";
	}
	catch (...) {
		return "";
	}
	return prompt;
}


void interpretCommand(string command, string *prompt) {
	if (command == "dir") {
		ListDir(*prompt);
	}
	else if (command == "ls") {
		cout << "Unknown command!  Did you mean \"dir\"?\r\n";
	}

	else if (command.starts_with("cd")) { // If finds "cd" at the beginning of the string
		string dirToCD_to = command.substr(3);
		USI ret = ChangeDir(dirToCD_to, prompt);
		if (ret == SUCCESS) {
			return;
		}
		else if (ret == WARNING_NONEXISTENT_DIRECTORY) {
			cerr << ERROR_DIRECTORY_NOT_FOUND;
		}
	}
	else if (command.starts_with("chdir")) { // If finds "chdir" at the beginning of the string
		string dirToCD_to = command.substr(6);
		USI ret = ChangeDir(dirToCD_to, prompt);
		if (ret == SUCCESS) {
			return;
		}
		else if (ret == WARNING_NONEXISTENT_DIRECTORY) {
			cerr << ERROR_DIRECTORY_NOT_FOUND;
		}
	}
	// handle misspellings of cd
	else if (command == "cf" || command == "vd" || command == "vf" || command == "cs" || command == "xd") {
		cout << "Unknown command!  Did you mean \"cd\"?\r\n";
	}
	else if (command.starts_with("md")) {
		string dirToMake = command.substr(3);
		USI ret = makeDir(dirToMake, *prompt);
		if (ret == SUCCESS) {
			return;
		}
		else if (ret == GENERIC_FAIL) {
			cerr << "Error";
			return;
		}
		else if (ret == ERROR_FILE_FOLDER_EXISTS) {
			cerr << ERROR_FILE_FOLDER_EXISTS_STR;
		}
	}
	else if (command.starts_with("mkdir")) {
		string dirToMake = command.substr(6);
		USI ret = makeDir(dirToMake, *prompt);
		if (ret == SUCCESS) {
			return;
		}
		else if (ret == GENERIC_FAIL) {
			cerr << "Error";
			return;
		}
		else if (ret == ERROR_FILE_FOLDER_EXISTS) {
			cerr << ERROR_FILE_FOLDER_EXISTS_STR;
		}
	}

	else if (command == "cls") {
#ifdef _WIN32
		system("cls");
#else
		system("clear");
#endif
	}
	else if (command == "clear") {
		cout << "Unknown command!  Did you mean \"cls\"?\r\n";
	}
	else if (command == "exit") {
		shells--;
		if (shells == -1) {
			std::exit(0);
		}
		*prompt = shellWorkingDirs[shells];
	}
	else if (command == "ver") {
		cout << "DOS Simulator v" << ver << "\r\n";
	}

	else if (command == "A:") {
		*prompt = "A:\\>";
	}
	else if (command == "B:") {
		*prompt = "B:\\>";
	}
	else if (command == "C:") {
		*prompt = "C:\\>";
	}

	else if (command == "command" || (command == "command.com" && prompt->contains((string)"C:\\"))) {
		shells++;
		shellWorkingDirs[shells] = *prompt;
		*prompt = "C:\\>";
	}

	else {
		cout << "Unknown command, " << command << "!\r\n";
	}
}