#include "DataT.h"

int main() {

	Data_Transmission dt("localhost", "ymaknie", "", "test");

	dt.connectToDB();
	dt.storeQuery("SELECT * FROM player;");
	dt.sendQuery();

	dt.writeData();
}