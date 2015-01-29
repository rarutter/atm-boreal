//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* 
The ATM model is used for simulating the disturbance of thermokarst dynamics on arctic and boreal ecosystems.
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//

#include "ATM.h"

int main(){

	//Initializing I/O variables
	cout<<"initializing model data!"<<endl;
	IOdata iodata;
	iodata.initlz();
	ptr = &iodata;

	cout<<endl<<"ptr = "<<ptr<<endl;

	//Predisposition and expansion/initiation sub-model

	string dir;
	dir = "./";

	cout<<"Start modeling!"<<endl;

	Runner runner;
	runner.SetPointer(ptr);
	runner.Run(ptr, dir);

	//Running is over
	cout<<endl<<"Model done!"<<endl;

 	return 1;

};

