#include "inc/debugMode.h"
#ifdef debugMode


void debugModeSelect() {
	char choice[2];
	cout << boolalpha << "Hello!  This version of the program was compiled with debug mode set to " << debugMode << "!\r\nWould you like to jump to a specific function in the program? (y/n)";
	cin.getline(choice, 2);
	cin.clear();
	cin.sync();
	string funcs[10]{ "a(type1 name1, type2 name2)" };
	char funcTo[]{"\0"};
	if (strcmp(choice, "y") == 0) {
		cout << "Please type the name of the function you want.\r\nPossible values are:\r\n";
		for (int i = 0; i < 10; i++) {
			cout << funcs[i] << "\r\n";
		}
		cin.getline(funcTo, 100);
	}
}

#endif
