/*
 * Outputer.h
 *
 *  Created on: Jan 13, 2014
 *      Author: yujin_admin
 */

#ifndef OUTPUTER_H_
#define OUTPUTER_H_

#include <iostream>
#include <string>
#include <sstream>

#include "../processes/IOdata.h"
#include "../processes/LNode.h"

#include "../netcdf/includes/netcdfcpp.h"
#include "../inc/ErrorCode.h"
#include "../inc/Exception.h"

using namespace std;

class Outputer{

public:
	Outputer();
	~Outputer();

	void InitOutputCht(string dir,int grdit, int year);
	void OutputCht(string dir,int grdid, int year, Nodes* list, long trecrd);


	NcFile* ChtFile;

	NcDim* chtD;

	NcVar* oYearV;
	NcVar* oGrdidV;
	NcVar* oParentidV;
	NcVar* oChtidV;
	NcVar* oVegtypeV;
	NcVar* oPropV;
	NcVar* oAgeV;
	NcVar* oFlagV;

	NcBool nb;

	IOdata* ioptr;

private:

};

#endif /* OUTPUTER_H_ */
