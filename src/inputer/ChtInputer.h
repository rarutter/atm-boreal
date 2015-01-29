/*
 * ChtInputer.h
 *
 *  Created on: Jan 8, 2014
 *      Author: yujin_admin
 */

#ifndef CHTINPUTER_H_
#define CHTINPUTER_H_

#include <iostream>
#include <string>
#include "../netcdf/includes/netcdfcpp.h"
#include "../inc/ErrorCode.h"
#include "../inc/Exception.h"

using namespace std;

class ChtInputer{

	public:
		ChtInputer();
		~ChtInputer();

		void InitChtFile(string dir);
		void InitChtFile(string dir, int grdid, int year);
		int getInitChtRecID(string dir, int grdid, int irec);
		int getNumVals(string dir);
		int getNumValsRec(string dir, int grid, int year);
		int getGrdRecID(string dir, int grdid, int year, int irec);

		long InitMaxChtId();

		/*
		NcFile grdFile;
		NcVar *chtid;
		NcVar *grdid;
		NcVar *age;
		NcVar *vegtype;
		NcVar *prop;
		NcVar *flag;
		 */

	private:

		string Filename;


};


#endif /* CHTINPUTER_H_ */
