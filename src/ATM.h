/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
The ATM model is used for simulating the disturbance of thermokarst dynamics on arctic and boreal ecosystems.
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////

#ifndef ATM_H_
	#define ATM_H_

	#include <string>
	#include <iostream>
	#include <fstream>
	#include <sstream>
	#include <cstdlib>
	#include <exception>

	using namespace std;

	#include "./processes/Runner.h"
	#include "./processes/IOdata.h"

	IOdata* ptr;

	//void ATMrun(IOdata* ptr, string dir);

#endif /*ATM_H_*/

