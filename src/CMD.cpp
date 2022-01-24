#include "inc/CMD.h"

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
	else if (command == "cd") {
		// take argument and run cd
	}
	// handle misspellings of cd
	else if (command == "cf" || command == "vd" || command == "vf" || command == "cs" || command == "xd") {
		cout << "Unknown command!  Did you mean \"cd\"?\r\n";
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
		std::exit(0);
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

	else {
		cout << "Unknown command, " << command << "!\r\n";
	}
}