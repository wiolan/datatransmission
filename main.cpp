#include "DataT.h"

int main() {

	Data_Transmission dt("localhost", "ymaknie", "", "test");

	dt.connectToDB();
	dt.prepareData("test");
	dt.sendQuery();

	dt.writeData();
	

}