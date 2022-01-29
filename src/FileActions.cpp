#include "inc/FileActions.h"
string pathString = "";
string origPath = "";
string SIM_WORKING_DIR = "";
bool MAIN_DIR_GOOD = false;
bool A_DRIVE_GOOD = false;
bool B_DRIVE_GOOD = false;
bool C_DRIVE_GOOD = false;
bool CONFIG_DIR_GOOD = false;
bool ASSETS_DOWNLOADED = false;
struct stat b;

USI checkDataDir(string arg1) {
	string username;
#ifdef _WIN32
	pathString = "C:\\Temp";
	if (stat(pathString.c_str(), &b) != 0) {
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
	if (stat(pathString.c_str(), &b) != 0) {
		string cmd = "mkdir \"" + pathString + "\"";
		system(cmd.c_str());
	}
	pathString.append("\\DOS Simulator");
	if (stat(pathString.c_str(), &b) != 0) {
		string cmd = "mkdir \"" + pathString + "\"";
		system(cmd.c_str());
	}
	origPath = pathString;
	pathString = origPath + "\\A_DRIVE";
	if (stat(pathString.c_str(), &b) != 0) {
		string cmd = "mkdir \"" + pathString + "\"";
		system(cmd.c_str());
	}
	pathString = origPath + "\\B_DRIVE";
	if (stat(pathString.c_str(), &b) != 0) {
		string cmd = "mkdir \"" + pathString + "\"";
		system(cmd.c_str());
	}
	pathString = origPath + "\\C_DRIVE";
	if (stat(pathString.c_str(), &b) != 0) {
		string cmd = "mkdir \"" + pathString + "\"";
		system(cmd.c_str());
	}
	pathString = origPath + "\\CONFIG";
	if (stat(pathString.c_str(), &b) != 0) {
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
		pathString.append(username + "Sanikdah Software/DOS Simulator");
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


	pathString = origPath + "\\B_DRIVE";
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

	pathString = origPath + "\\C_DRIVE";
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

	pathString = origPath + "\\CONFIG";
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
		if (downloadAssets() == SUCCESS) {
			// Assets are now downloaded, so set the file in the config dir.
			string assetsFileLoc = origPath + "\\CONFIG\\ASSETSDOWNLOADED";
			ofstream assetsDownloadedFile(assetsFileLoc, std::ios::out);
			assetsDownloadedFile.close();
			ASSETS_DOWNLOADED = true;
		}
	}
	if (!MAIN_DIR_GOOD) {
		return ERROR_MAIN_DIR_CORRUPT;
	}
	if (!(A_DRIVE_GOOD && B_DRIVE_GOOD && C_DRIVE_GOOD)) {
		return ERROR_DRIVE_DIRS_CORRUPT;
	}
	if (!ASSETS_DOWNLOADED) {
		return ERROR_ASSETS_NOT_DOWNLOADED;
	}
	return SUCCESS;
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
		pathToLook.append("\\A_DRIVE\\" + SIM_WORKING_DIR);
	}
	if (firstCharPrompt == "B") {
		pathToLook.append("\\B_DRIVE\\" + SIM_WORKING_DIR);
	}
	if (firstCharPrompt == "C") {
		pathToLook.append("\\C_DRIVE\\" + SIM_WORKING_DIR);
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
		string fullPathStr = "";
		if (SIM_WORKING_DIR == "") {
			fullPathStr = pathSubStr;
		}
		else {
			pos = pathSubStr.find(SIM_WORKING_DIR);
			pathSubStr = pathSubStr.substr(pos + SIM_WORKING_DIR.length());
			pathSubStr = pathSubStr.substr(1); // Cut off initial forward slash
			fullPathStr = pathSubStr;
		}
		cout << fullPathStr;
		if (isDir) {
			cout << "    <DIR>\r\n"; // TODO: Make this appear always 4 characters after the
								     // longest file or directory name
		}
		else {
			cout << "\r\n";
		}
	}
}

USI ChangeDir(string dir, string *prompt) {
	bool changedDir = false;
	string firstCharPrompt = prompt->substr(0, 1);
	string CD_DIR = "";
	//if (prompt->length() >= 5) {
	//	size_t a = prompt->find(">");
	//	SIM_WORKING_DIR = prompt->substr(4, a - 1);
	//}

#ifdef _WIN32
	if (SIM_WORKING_DIR == "") {
		CD_DIR = origPath + "\\" + firstCharPrompt + "_DRIVE\\" + dir;
	}
	else {
		CD_DIR = origPath + "\\" + firstCharPrompt + "_DRIVE\\" + SIM_WORKING_DIR + "\\" + dir;
	}
	if (stat(CD_DIR.c_str(), &b) != 0) {
		// doesn't exist, throw error
		return WARNING_NONEXISTENT_DIRECTORY;
	}
	(void)_chdir(CD_DIR.c_str());
	changedDir = true;
#else
	if (SIM_WORKING_DIR == "") {
		CD_DIR = origPath + "/" + firstCharPrompt + "_DRIVE/" + dir;
	}
	else {
		CD_DIR = origPath + "/" + firstCharPrompt + "_DRIVE/" + SIM_WORKING_DIR + "/" + dir;
	}
	if (stat(CD_DIR.c_str(), &b) != 0) {
		// doesn't exist, throw error
		return WARNING_NONEXISTENT_DIRECTORY;
}
	}
	(void)chdir(CD_DIR.c_str());
	changedDir = true;
#endif
	if (changedDir) {
		if (SIM_WORKING_DIR == "") {
			if (dir == "..") {
				*prompt = firstCharPrompt + ":\\" + ">";
				SIM_WORKING_DIR = SIM_WORKING_DIR + "\\";
			}
			else {
				*prompt = firstCharPrompt + ":\\" + dir + ">";
				SIM_WORKING_DIR = SIM_WORKING_DIR + "\\" + dir;
			}
		}
		else {
			if (dir == "..") {
				*prompt = firstCharPrompt + ":" + SIM_WORKING_DIR + "\\" + ">";
				SIM_WORKING_DIR = SIM_WORKING_DIR + "\\";
			}
			else {
				*prompt = firstCharPrompt + ":" + SIM_WORKING_DIR + "\\" + dir + ">";
				SIM_WORKING_DIR = SIM_WORKING_DIR + "\\" + dir;
			}
		}
		return SUCCESS;
	}
	else {
		return ERROR_DIRECTORY_NOT_CHANGED;
	}
	return ERROR_FELL_THROUGH_IF_ELSE;
}


USI makeDir(string dir, string prompt) {
	string firstCharPrompt = prompt.substr(0, 1);
	//Creating File
	string a = origPath + "\\" + firstCharPrompt + "_DRIVE\\" + dir;
#ifdef _WIN32
	if (_mkdir(a.c_str()) == -1) {
#else
	if (mkdir(a.c_str()) == -1) {
#endif

		if (errno == 17) {
			return ERROR_FILE_FOLDER_EXISTS;
		}
		return GENERIC_FAIL;
	}

	else {
		return SUCCESS;
	}
}

USI removeDir(string dir, string prompt) {
	string firstCharPrompt = prompt.substr(0, 1);
	string a = "";
	bool empty = is_empty(dir);
	if (empty) {
#ifdef _WIN32
		if (SIM_WORKING_DIR != "") {
			a = origPath + "\\" + firstCharPrompt + "_DRIVE\\" + SIM_WORKING_DIR + "\\" + dir;
		}
		else {
			a = origPath + "\\" + firstCharPrompt + "_DRIVE\\" + dir;
		}
#else
		if (SIM_WORKING_DIR != "") {
			a = origPath + "/" + firstCharPrompt + "_DRIVE/" + SIM_WORKING_DIR + "/" + dir;
		}
		else {
			a = origPath + "/" + firstCharPrompt + "_DRIVE/" + dir;
		}
#endif
		remove(a);
	}
	else {
		return ERROR_DIRECTORY_NOT_EMPTY;
	}
}
