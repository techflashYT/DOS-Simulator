#include "inc/loop.h"

char commandChars[101] = "";


void loop(string *prompt) {
	while (true) {
		cout << *prompt;
		cin.clear();
		cin.sync();
		cin.getline(commandChars, MAX_COMMAND_LENGTH);
		// Before we do anything with that command, convert it to an std::string
		string command = commandChars;
		interpretCommand(command, prompt);
	}
}