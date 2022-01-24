#include "inc/FileActions.h"
string pathString = "";


bool checkDataDir(string arg1) {
	string username;
#ifdef _WIN32
	struct stat b;
	string a = "C:\\Temp";
	if (stat(a.c_str(), &b) != 0) {
		system("mkdir C:\\Temp");
	}
	ofstream script("C:\\Temp\\script.bat");
	script << "@echo off\r\necho %username% > C:\\Temp\\username.txt";
	script.close();
	system("C:\\Temp\\script.bat");
	ifstream unamefile("C:\\Temp\\username.txt");
	if (unamefile.is_open()) {
		unamefile >> username;
	}
	unamefile.close();
	system("rmdir /Q /S C:\\Temp");
	pathString = "C:\\Users\\";
	pathString.append(username);
	pathString.append("\\Appdata\\Roaming\\Sanikdah Software");
	a = pathString;
	if (stat(a.c_str(), &b) != 0) {
		string cmd = "mkdir \"";
		cmd.append(pathString);
		cmd.append("\"");
		char cmd1[100];
		strcpy_s(cmd1, cmd.c_str());
		system(cmd1);
	}
	pathString.append("\\DOS Simulator");
	a = pathString;
	if (stat(a.c_str(), &b) != 0) {
		string cmd = "mkdir \"";
		cmd.append(pathString);
		cmd.append("\"");
		char cmd1[100];
		strcpy_s(cmd1, cmd.c_str());
		system(cmd1);
	}
#else
	pathString = "/home/";
	cout << "What is your usermame?\r\n";
	cin >> username;
	if (username == "root" && !(arg1 == "--use-root")) {
		cerr << "\r\nIt is highly recommended not to run the application as root.  For more information, see https://https://github.com/sanikdah/DOS-Simulator/wiki/%5BLinux%5D-Running-as-root .  \r\n \
		If it is absolutely necessary, run with the --use-root command line flag.  Exiting...\r\n";
		std::exit(1);
	}
	else if (username == "root" && arg1 == "--use-root") {
		cerr << "\r\nIt is highly recommended not to run the application as root.  For more information, see https://https://github.com/sanikdah/DOS-Simulator/wiki/%5BLinux%5D-Running-as-root . \r\n \
		since the --use-root flag is present, we will use this anyways, despite the risks.";
		pathString = "/root/Sanikdah Software/";
	}
	else {
		pathString.append(username);
		pathString.append("/Sanikdah Software/");
	}
#endif

	path path(pathString); // Constructing the path from a string is possible.
	error_code ec; // For using the non-throwing overloads of functions below.
	if (is_directory(path, ec)) {
		return true;
	}
	if (is_regular_file(path, ec)) {
		cerr << "The data directory is a file!  Deleting it...\r\n";
#ifdef _WIN32
		string cmd = "del \"";
		cmd.append(pathString);
		cmd.append("\"");
		char cmd1[100];
		strcpy_s(cmd1, cmd.c_str());
		system(cmd1);
		cout << "Done!  Please restart the program!\r\n";
		system("pause");
		std::exit(0);
#else
		string cmd = "rm \"";
		cmd.append(pathString);
		cmd.append("\"");
		char cmd1[100];
		strcpy_s(cmd1, cmd.c_str());
		system(cmd1);
		cout << "Done!  Please restart the program!\r\nPress any key to continue...";
		system("read -n1 key");
		std::exit(0);
#endif
	}
	if (ec) { // Optional handling of possible errors. Usage of the same ec object works since fs functions are calling ec.clear() if no errors occur.
		cerr << "An unknown error occurred reading the data directory, the error is:\r\n" << ec.message() << "\r\nexiting...";
		std::exit(1);
	}
}