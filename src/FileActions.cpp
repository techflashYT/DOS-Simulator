#include "inc/FileActions.h"
string pathString = "";
string origPath = "";
bool MAIN_DIR_GOOD = false;
bool A_DRIVE_GOOD = false;
bool B_DRIVE_GOOD = false;
bool C_DRIVE_GOOD = false;
bool CONFIG_DIR_GOOD = false;
bool ASSETS_DOWNLOADED = false;

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
	pathString = "C:\\Users\\" + username + "\\Appdata\\Roaming\\Sanikdah Software";
	a = pathString;
	if (stat(a.c_str(), &b) != 0) {
		string cmd = "mkdir \"" + pathString + "\"";
		system(cmd.c_str());
	}
	pathString.append("\\DOS Simulator");
	a = pathString;
	if (stat(a.c_str(), &b) != 0) {
		string cmd = "mkdir \"" + pathString + "\"";
		system(cmd.c_str());
	}
	origPath = pathString;
	pathString.append("\\A_DRIVE");
	a = pathString;
	if (stat(a.c_str(), &b) != 0) {
		string cmd = "mkdir \"" + pathString + "\"";
		system(cmd.c_str());
	}
	pathString = origPath;
	pathString.append("\\B_DRIVE");
	a = pathString;
	if (stat(a.c_str(), &b) != 0) {
		string cmd = "mkdir \"" + pathString + "\"";
		system(cmd.c_str());
	}
	pathString = origPath;
	pathString.append("\\C_DRIVE");
	a = pathString;
	if (stat(a.c_str(), &b) != 0) {
		string cmd = "mkdir \"" + pathString + "\"";
		system(cmd.c_str());
	}
	pathString = origPath;
	pathString.append("\\CONFIG");
	a = pathString;
	if (stat(a.c_str(), &b) != 0) {
		string cmd = "mkdir \"" + pathString + "\"";
		system(cmd.c_str());
	}
	pathString = origPath;
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
		pathString.append(username + "Sanikdah Software");
	}
#endif

	path path(pathString); // Constructing the path from a string is possible.
	error_code ec; // For using the non-throwing overloads of functions below.
	if (is_directory(path, ec)) {
		MAIN_DIR_GOOD = true;
	}
	if (is_regular_file(path, ec)) {
		cerr << "The data directory is a file!  Deleting it...\r\n";
#ifdef _WIN32
		string cmd = "del \"" + pathString + "\"";
		system(cmd.c_str());
		cout << "Done!  Please restart the program!\r\n";
		system("pause");
		std::exit(0);
#else
		string cmd = "rm \"" + pathString + "\"";
		system(cmd.c_str());
		cout << "Done!  Please restart the program!\r\nPress any key to continue...";
		system("read -n1 key");
		std::exit(0);
#endif
	}
	if (ec) { // Optional handling of possible errors. Usage of the same ec object works since fs functions are calling ec.clear() if no errors occur.
		cerr << "An unknown error occurred reading the data directory, the error is:\r\n" << ec.message() << "\r\nexiting...";
		std::exit(1);
	}


	pathString.append("\\A_DRIVE");
	path = pathString; // Constructing the path from a string is possible.
	if (is_directory(path, ec)) {
		A_DRIVE_GOOD = true;
	}
	if (is_regular_file(path, ec)) {
		cerr << "The A drive directory is a file!  Deleting it...\r\n";
#ifdef _WIN32
		string cmd = "del \"" + pathString + "\"";
		system(cmd.c_str());
		cout << "Done!  Please restart the program!\r\n";
		system("pause");
		std::exit(0);
#else
		string cmd = "rm \"" + pathString + "\"";
		system(cmd.c_str());
		cout << "Done!  Please restart the program!\r\nPress any key to continue...";
		system("read -n1 key");
		std::exit(0);
#endif
	}
	if (ec) { // Optional handling of possible errors. Usage of the same ec object works since fs functions are calling ec.clear() if no errors occur.
		cerr << "An unknown error occurred reading the A Drive directory, the error is:\r\n" << ec.message() << "\r\nexiting...";
		std::exit(1);
	}


	pathString = origPath;
	pathString.append("\\B_DRIVE");
	path = pathString; // Constructing the path from a string is possible.
	if (is_directory(path, ec)) {
		B_DRIVE_GOOD = true;
	}
	if (is_regular_file(path, ec)) {
		cerr << "The B drive directory is a file!  Deleting it...\r\n";
#ifdef _WIN32
		string cmd = "del \"" + pathString + "\"";
		system(cmd.c_str());
		cout << "Done!  Please restart the program!\r\n";
		system("pause");
		std::exit(0);
#else
		string cmd = "rm \"" + pathString + "\"";
		system(cmd.c_str());
		cout << "Done!  Please restart the program!\r\nPress any key to continue...";
		system("read -n1 key");
		std::exit(0);
#endif
	}
	if (ec) { // Optional handling of possible errors. Usage of the same ec object works since fs functions are calling ec.clear() if no errors occur.
		cerr << "An unknown error occurred reading the B Drive directory, the error is:\r\n" << ec.message() << "\r\nexiting...";
		std::exit(1);
	}

	pathString = origPath;
	pathString.append("\\C_DRIVE");
	path = pathString; // Constructing the path from a string is possible.
	if (is_directory(path, ec)) {
		C_DRIVE_GOOD = true;
	}
	if (is_regular_file(path, ec)) {
		cerr << "The C drive directory is a file!  Deleting it...\r\n";
#ifdef _WIN32
		string cmd = "del \"" + pathString + "\"";
		system(cmd.c_str());
		cout << "Done!  Please restart the program!\r\n";
		system("pause");
		std::exit(0);
#else
		string cmd = "rm \"" + pathString + "\"";
		system(cmd.c_str());
		cout << "Done!  Please restart the program!\r\nPress any key to continue...";
		system("read -n1 key");
		std::exit(0);
#endif
	}
	if (ec) { // Optional handling of possible errors. Usage of the same ec object works since fs functions are calling ec.clear() if no errors occur.
		cerr << "An unknown error occurred reading the C Drive directory, the error is:\r\n" << ec.message() << "\r\nexiting...";
		std::exit(1);
	}

	pathString = origPath;
	pathString.append("\\CONFIG");
	path = pathString; // Constructing the path from a string is possible.
	if (is_directory(path, ec)) {
		CONFIG_DIR_GOOD = true;
	}
	if (is_regular_file(path, ec)) {
		cerr << "The config directory is a file!  Deleting it...\r\n";
#ifdef _WIN32
		string cmd = "del \"" + pathString + "\"";
		system(cmd.c_str());
		cout << "Done!  Please restart the program!\r\n";
		system("pause");
		std::exit(0);
#else
		string cmd = "rm \"" + pathString + "\"";
		system(cmd.c_str());
		cout << "Done!  Please restart the program!\r\nPress any key to continue...";
		system("read -n1 key");
		std::exit(0);
#endif
	}
	if (ec) { // Optional handling of possible errors. Usage of the same ec object works since fs functions are calling ec.clear() if no errors occur.
		cerr << "An unknown error occurred reading the config directory, the error is:\r\n" << ec.message() << "\r\nexiting...";
		std::exit(1);
	}

	if (MAIN_DIR_GOOD && CONFIG_DIR_GOOD) {
		// Check for ASSETSDOWNLOADED file
		pathString = origPath + "\\CONFIG\\ASSETSDOWNLOADED";
		path = pathString; // Constructing the path from a string is possible.
		if (is_directory(path, ec)) {
			cerr << "A config file is a directory!  Deleting it...\r\n";
#ifdef _WIN32
			string cmd = "rmdir \"" + pathString + "\"";
			system(cmd.c_str());
			cout << "Done!  Please restart the program!\r\n";
			system("pause");
			std::exit(0);
#else
			string cmd = "rm -rf \"" + pathString + "\"";
			system(cmd.c_str());
			cout << "Done!  Please restart the program!\r\nPress any key to continue...";
			system("read -n1 key");
			std::exit(0);
#endif
		}
		if (is_regular_file(path, ec)) {
			ASSETS_DOWNLOADED = true;
		}
		if (ec) { // Optional handling of possible errors. Usage of the same ec object works since fs functions are calling ec.clear() if no errors occur.
			if (ec.message() == "The system cannot find the file specified.") {
				ASSETS_DOWNLOADED = false;
			}
			else {
				cerr << "An unknown error occurred reading a file in the config directory, the error is:\r\n" << ec.message() << "\r\nexiting...";
				std::exit(1);
			}
		}

	}
	if (!ASSETS_DOWNLOADED) {
		ASSETS_DOWNLOADED = downloadAssets();
		if (ASSETS_DOWNLOADED) {
			// Assets are now downloaded, so set the file in the config dir.
			string assetsFileLoc = origPath + "\\CONFIG\\ASSETSDOWNLOADED";
			ofstream assetsDownloadedFile(assetsFileLoc, std::ios::out);
			assetsDownloadedFile.close();
		}
	}
	if (MAIN_DIR_GOOD && A_DRIVE_GOOD && B_DRIVE_GOOD && C_DRIVE_GOOD && ASSETS_DOWNLOADED) {
		return true;
	}
	return false;
}


void ListDir(string prompt) {
	string firstCharPrompt = prompt.substr(0, 1);
	path files[100];
	int i1 = 0;
	string pathToLook = pathString;
	string find = "DRIVE";
	size_t pos = pathToLook.find(find);
#ifdef _WIN32
	void(_chdir(origPath.c_str()));
	char tempPath[100];
	void(_getcwd(tempPath, 100));
	pathString = tempPath;
	pathToLook = pathString;
#else
	void(chdir(origPath.c_str()));
	char tempPath[100];
	void(getcwd(tempPath, 100));
	pathString = tempPath;
	pathToLook = pathString;
#endif
	pos = pathToLook.find(find);
	if (firstCharPrompt == "A") {
		pathToLook.append("\\A_DRIVE");
	}
	if (firstCharPrompt == "B") {
		pathToLook.append("\\B_DRIVE");
	}
	if (firstCharPrompt == "C") {
		pathToLook.append("\\C_DRIVE");
	}

	for (const auto& entry : directory_iterator(pathToLook)) {
		files[i1] = entry.path();
		i1++;
	}
	for (int i = 0; i < i1; i++) {
		string pathStr = files[i].string();
		bool isDir = false;
		if (!(pathStr.contains("."))) {
			// Might be a directory, lets check
			error_code ec;
			if (is_directory(pathStr, ec)) {
				isDir = true;
			}
		}
		string find;
		if (firstCharPrompt == "A") {
			find = "A_DRIVE";
		}
		if (firstCharPrompt == "B") {
			find = "B_DRIVE";
		}
		if (firstCharPrompt == "C") {
			find = "C_DRIVE";
		}
		size_t pos = pathStr.find(find);
		string pathSubStr = pathStr.substr(pos + 8);
		string fullPathStr = pathSubStr;
		cout << fullPathStr;
		if (isDir) {
			cout << "  <DIR>\r\n";
		}
		else {
			cout << "\r\n";
		}
	}
}