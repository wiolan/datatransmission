#include <iostream>
#include <string>

#include <mysql/mysql.h>

/* compilation flags: -L/usr/lib/mysql -lmysqlclient */


class Data_Transmission {
private:

	MYSQL *connection;
	MYSQL_RES *res;
	MYSQL_ROW row;
	
	std::string hostIP;
	std::string user;
	std::string password;
	std::string database;

	bool hasConnection;
	std::string dataToSend;
	std::string SQLquery; //the SQL-script
	
	std::string SQLformat(std::string data); //formats the data into SQL-script (input might be something other than a string)
	
public:
	Data_Transmission(std::string hostIP, std::string user, std::string password, std::string database); // constructor
	~Data_Transmission(); //destructor

	void connectToDB();
	void prepareData(std::string data); // retrieves data from Data Collection and prepares it
	int sendQuery(); // sends the SQL query to the database (should only be callable if there's a query to send)

	void close();

	void writeData(); //test method
};