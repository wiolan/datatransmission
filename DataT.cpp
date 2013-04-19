#include "DataT.h"


Data_Transmission::Data_Transmission(std::string hostIP, std::string user, std::string password, std::string database) {
	this->hostIP = hostIP;
	this->user = user;

	this->password = password;
	this->database = database;

	this->hasConnection = false;
	this->hasSQLscript = false;
	this->SQLquery = "";

	this->res = NULL;

	this->connection = mysql_init(NULL);
}


Data_Transmission::~Data_Transmission() {
	 this->close();
}

bool Data_Transmission::getConnectionStatus() {
	return this->hasConnection;
}

bool Data_Transmission::getQueryStatus() {
	return this->hasSQLscript;
}


void Data_Transmission::connectToDB() {
	//TODO: make a connection to the database, set hasConnection to true if successful

	if (mysql_real_connect(this->connection,
							this->hostIP.c_str(),
							this->user.c_str(),
							this->password.c_str(),
							this->database.c_str(),
							0,
							NULL,
							0) == NULL) {
		std::cout << "ERROR: " << mysql_error(this->connection) << std::endl;
	}
	else {
		this->hasConnection = true;
		std::cout << "successfully connected to database" << std::endl;
	}
	
}


void Data_Transmission::storeQuery(std::string query) {
	//TODO: retrieve the data (and maybe restructure it), then send it to SQLformat()

	if(query.size() > 0) {
		this->SQLquery = "";
		this->hasSQLscript = true;
		this->SQLquery = query;
	}
}


int Data_Transmission::sendQuery() {
	int outcome = 0;
	
	if(this->getConnectionStatus() && this->getQueryStatus()) { // we have a connection and there is data to send

		if(mysql_query(this->connection, this->SQLquery.c_str())) {
			outcome = -1;
			std::cout << "ERROR: " << mysql_error(this->connection) << std::endl;
		} else {
			outcome = 1;
			res = mysql_store_result(this->connection);
		}

	} else {
		std::cout << "ERROR: no connection or no SQL-script" << std::endl;
	}

	return outcome;
}


void Data_Transmission::close() {
	if(this->res != NULL) mysql_free_result(this->res);
	mysql_close(this->connection);
	
	std::cout << "connection closed" << std::endl;
}


void Data_Transmission::reset() {
	if(this->res != NULL) mysql_free_result(this->res);
	mysql_close(this->connection);

	this->hasConnection = false;
	this->hasSQLscript = false;
	this->SQLquery = "";
	
	this->res = NULL;
	
	this->connection = mysql_init(NULL);
}



void Data_Transmission::writeData() {

	MYSQL_ROW row;
	int num_columns = mysql_num_fields(this->res);
	int num_rows = mysql_num_rows(this->res);

	std::cout << "col: " << num_columns << " row: " << num_rows << std::endl;

	/*
	for(int i=0;i<num_rows;i++)
	{
		row = mysql_fetch_row(this->res);
		
		for(int j=0;j<num_columns;j++)
		{
			std::cout << row[j] << std::endl;
			std::cout << "test " << num_columns << " - " << j << std::endl;
		}

		std::cout << std::endl;
		std::cout << std::endl;
	}*/


	while((row = mysql_fetch_row(this->res)) != NULL) {
		
		for(int j=0;j<num_columns;j++)
		{
			std::cout << row[j] << std::endl;
		}
		
	}






	
}