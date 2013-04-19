#include "DataT.h"

#include "stdlib.h"

int main() {

	std::string host = "";
	std::string user = "";
	std::string pw = "";
	std::string db = "";

	int i;

	std::cout << "Make choice for entering connection details" << std::endl;
	std::cout << "1. use default" << std::endl;
	std::cout << "2. enter your own connection details" << std::endl;
	std::cout << ">> ";
	std::cin >> i;

	if(i == 2) {
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
	else {
		host = "pingu.ha.ax";
		user = "pop2013";
		pw = "m1cr0Trans8";
		db = "pop2013";
	}

	if(host.size() == 0 || user.size() == 0 || pw.size() == 0 || db.size() == 0) {
		std::cout << "no connection details entered" << std::endl;
		exit(0);
	}
		Data_Transmission dt(host, user, pw, db);
		
		dt.connectToDB();

		i = 0;
		std::cout << "Make choice for entering query" << std::endl;
		std::cout << "1. use default (SELECT * FROM gps_information;)" << std::endl;
		std::cout << "2. enter your own query" << std::endl;
		std::cout << ">> ";
		std::cin >> i;

		std::string query = "";
		
		if(i == 2) {
			std::cin >> query;
		} else {
			query = "SELECT * FROM gps_information;";
		}
		
		dt.storeQuery(query);
		dt.sendQuery();
		dt.writeData();
		
	
	
}