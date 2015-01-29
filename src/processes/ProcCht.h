/*
 * ProcsCht.h
 *
 *  Created on: Jul 24, 2013
 *      Author: yujin_admin
 */

#ifndef PROCCHT_H_
#define PROCCHT_H_

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

#include "../netcdf/includes/netcdfcpp.h"
#include "../inc/ErrorCode.h"
#include "../inc/Exception.h"

#include "./IOdata.h"
#include "./LNode.h"


class ProcCht{

	public:
		ProcCht();
		~ProcCht();

		//IOdata iodata;

		//void InitiInputCht(string dir);
		void GetCht(string dirfile, int id);
		void GetCht(string dirfile, int gridid,int year, int id);
		//void GetChtData(string dirfile, int grdid, int chtcnt, int id);

		//void InitiOutputCht(string s_Dir, int grdid, int year);
		//void OutputCht(Nodes* outlist, int nYear, int nid);

		//insert cohort into list
		void InsertCht(Nodes *list, Nodes* lnode);

		void SetPointer(IOdata* ptr);


		//for new cohort

		NcFile* NChtFile;

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

#endif /* PROCCHT_H_ */
