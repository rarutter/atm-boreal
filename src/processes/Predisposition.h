/////////////////////////////////////////////////////////
/*
The submodule is used for the predisposition for ATM model
*/

/////////////////////////////////////////////////////////

#ifndef PREDISPOSITION_H_
	#define PREDISPOSITION_H_

	#include "./IOdata.h"

	#include <string>
	#include <iostream>
	#include <sstream>

	#include "../netcdf/includes/netcdfcpp.h"
	#include "../inc/ErrorCode.h"
	#include "../inc/Exception.h"

	using namespace std;

	class Predisposition{

		public:
			Predisposition();
			~Predisposition();

			void InitiPred(string dir);
			void Predisposed(int grdid);
			void OutPred(int grdid);
			void SetPointer(IOdata* pt);

			IOdata* iopt;
			float predprop;

			NcFile* PredFile;
			NcDim* grdD;
			NcVar* predV;
			NcBool nb1;

		private:

};
#endif /*PREDISPOSITION_H_*/

