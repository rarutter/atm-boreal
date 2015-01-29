/*
LakeDataInputer.h
 *
 */

#ifndef LAKEDATAINPUTER_H_
#define LAKEDATAINPUTER_H_

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

class LakeDataInputer{

	public:
		LakeDataInputer();
		~LakeDataInputer();

		void InitLakeData(string dir);
		void getLake(string dir, int grdidrec);

		void getLakeProb();
		void getLakeRates();
		void getLakeRates4Decrs();
		void getLakeRates4Incrs();

		int getInitGrdRecID(string dir, int grdid, int irec);
		int getNumVals(string dir);
		int getNumValsRec(string dir, int grid, int year);
		int getGrdRecID(string dir, int grdid, int year, int irec);

		long InitMaxChtId();

		double probd;
		double probs;
		double probi;

		IOdata iodata;

	private:

		NcDim* grdD;

		string Filedist;
		string Fileavgsize;
		string Filettlarea;
		string Filedem;
		string Filedeposit;
		string Filerocky;
		string Filesand;
		string Filersds;
		string Fileflowaccu;
		string Filefire8599;
		string Filefire0009;
		string Filelakedominate;

		double filedist;
		double fileavgsize;
		double filettlarea;
		double filedem;
		int filedeposit;
		int filerocky;
		int filesandy;
		double filersds;
		double fileflowaccu;
		int filefire8599;
		int filefire0009;
		int filelakedominate;

};


#endif /* LAKEDATAINPUTER_H_ */
