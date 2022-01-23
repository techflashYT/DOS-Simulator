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


void interpretCommand(string command) {
	if (command == "dir") {
		// run dir command
	}
	if (command == "ls") {
		// alias of dir
	}
	if (command == "cd") {
		// take argument and run cd
	}

	if (command == "exit") {
		std::exit(0);
	}
}