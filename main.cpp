#include "DataT.h"

#include "stdlib.h"

int main() {

	std::string host = "";
	std::string user = "";
	std::string pw = "";
	std::string db = "";

	int i;

	std::cout << "1. use default" << std::endl;
	std::cout << "2. enter your own connection details" << std::endl;
	std::cout << ">> ";
	std::cin >> i;

	if(i == 1) {
		host = "pingu.ha.ax";
		user = "pop2013";
		pw = "m1cr0Trans8";
		db = "pop2013";
	}
	else {
		std::cout << "Enter host IP" << std::endl;
		std::cout << ">> ";
		std::cin >> host;
		std::cout << "Enter username" << std::endl;
		std::cout << ">> ";
		std::cin >> user;
		std::cout << "Enter password" << std::endl;
		std::cout << ">> ";
		std::cin >> pw;
		std::cout << "Enter database to connect to"<< std::endl;
		std::cout << ">> ";
		std::cin >> db;
	}

	if(host.size() == 0 || user.size() == 0 || pw.size() == 0 || db.size() == 0) {
		std::cout << "no connection details entered" << std::endl;
		exit(0);
	}
		Data_Transmission dt(host, user, pw, db);
		
		dt.connectToDB();
		
		dt.storeQuery("SELECT * FROM gps_information;");
// 		dt.storeQuery("INSERT INTO gps_information (x_coord, y_coord) values ('60.0999', 19.9495)");
		dt.sendQuery();
		dt.writeData();
		
	
	
}