#include <iostream>
#include <string>

#include <mysql/mysql.h>


	/*	USAGE:
		the Data_Transmission class is used for connecting to a database and to make queries,
		connection details are passed to the constructor and then used in the connectToDB-method.
		The prepareData-method expects data which it structures into SQL-script using the private method SQLformat.
		Once there is a connection and a SQL-scrips has been properly formatted the sendQuery-method can be used to
		send the query to the database.
		
		compilation flags: -L/usr/lib/mysql -lmysqlclient
	*/

class Data_Transmission {
private:

	MYSQL *connection;
	MYSQL_RES *res;
	
	std::string hostIP;
	std::string user;
	std::string password;
	std::string database;

	bool hasConnection;
	bool hasSQLscript;
	std::string SQLquery;

public:
	// constructor
	Data_Transmission(std::string hostIP, std::string user, std::string password, std::string database);
	// destructor
	~Data_Transmission();

	bool getConnectionStatus();
	bool getQueryStatus();

	
	
	// connecting to the database
	void connectToDB();
	// stores a SQL query
	void storeQuery(std::string query);

	
	/*	sends the SQL query to the database (should only be callable if there's a query to send)
		returns value depending on outcome, 1 for successful, 0 for no update, -1 for failiure */
	int sendQuery(); 

	
	// resets the connection and all flags (keeps the connection details)
	void reset();
	// closes the connection, used in destructor
	void close();




	
	//test method, will probably be removed later
	void writeData(); 
};