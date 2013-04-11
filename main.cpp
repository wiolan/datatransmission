#include "DataT.h"



// g++ main.cpp DataT.cpp -L/usr/include/mysql -lmysqlclient -I/user/include/mysql
// http://www.cyberciti.biz/tips/linux-unix-connect-mysql-c-api-program.html
// http://zetcode.com/tutorials/mysqlcapitutorial
// http://sandeepghai.wordpress.com/2011/08/07/linking-of-mysql-database-with-c-on-linux-machine/
// http://dev.mysql.com/doc/refman/5.0/en/c-api-building-clients.html
// http://tangentsoft.net/mysql++/

int main() {

	Data_Transmission dt("localhost", "ymaknie", "", "test");

	dt.connectToDB();
	dt.prepareData("hejbajs");
	dt.sendQuery();

	dt.writeData();
	

}