/*
BorealDataInputer.h
 *
 */

#ifndef BOREALDATAINPUTER_H_
#define BOREALDATAINPUTER_H_

#include <iostream>
#include <string>
#include <cmath>
#include "../netcdf/includes/netcdfcpp.h"
#include "../inc/ErrorCode.h"
#include "../inc/Exception.h"

#include "../processes/IOdata.h"
#include "../processes/Dlist.h"
#include "../processes/LNode.h"
#include "../inputer/ChtInputer.h"


using namespace std;

class BorealDataInputer{

	public:
		BorealDataInputer();
		~BorealDataInputer();

		void InitGridBDfstyr(string dir);
		void getGridBDfstyr(IOdata* ioptr);

		void getTransitionRates(double ttlforestarea, Nodes* cohortlist);
		double getTtlForestArea(string dir, int grdid, int ttlrec);

		int getInitGrdRecID(string dir, int grdid, int irec);
		int getNumVals(string dir);
		int getNumValsRec(string dir, int grid, int year);
		int getGrdRecID(string dir, int grdid, int year, int irec);

		long InitMaxChtId();
		void InitGridiodata();

		Dlist dlist;
		IOdata iodata;
		IOdata iodata4area;

		Nodes* cohortlist;
		//cohortlist = NULL;

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


#endif /* BOREALDATAINPUTER_H_ */
