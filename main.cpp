#include "DataT.h"

int main() {

	Data_Transmission dt("pingu.ha.ax", "pop2013", "m1cr0Trans8", "pop2013");

	dt.connectToDB();
	dt.storeQuery("");
	//dt.sendQuery();

	//dt.writeData();
}