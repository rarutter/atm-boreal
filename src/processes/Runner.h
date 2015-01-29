/*
 * Runner.h
 *
 *  Created on: Jul 25, 2013
 *      Author: yujin_admin
 */

#ifndef RUNNER_H_
#define RUNNER_H_

	#include <string>
	#include <iostream>
	#include <sstream>
	#include <cstdlib>
	#include <sstream>

	#include "../netcdf/includes/netcdfcpp.h"
	#include "../inc/ErrorCode.h"
	#include "../inc/Exception.h"

	using namespace std;

	#include "./IOdata.h"
	#include "./Predisposition.h"
	#include "./Thermokarst.h"
	#include "./Dlist.h"
	#include "./LNode.h"
	#include "./ProcCht.h"
	#include "./ChtProp.h"
	#include "../tools/CreateFlder.h"
	#include "../outputer/Outputer.h"
	#include "../tools/DelFile.h"
	#include "../inputer/ChtInputer.h"
	#include "../inputer/BorealDataInputer.h"
	#include "../inputer/LakeDataInputer.h"

	class Runner{

		public:
			Runner();
			~Runner();

			void InitInputFile(string & dirfile);
			//void GetGrdData(string dirfile, int grdid);
			void SetPointer(IOdata* pointer);
			void Run(IOdata* ptr, string dir);

			IOdata* ioptr;

/*
			NcFile* givfile;
			NcFile* frostfile;
			NcFile* cohortidfile;
			NcFile* inichtfile;
			NcFile* lowlandfile;
			NcFile* wetlandfile;
*/

			NcDim* givD;
			NcVar* givV;

			NcDim* frostD;
			NcVar* frostV;

			NcDim* cohortidD;
			NcVar* cohortidV;

			NcDim* inichtD;
			NcVar* grididV;
			NcVar* inichtidV;
			NcVar* vegtypeV;
			NcVar* ageV;
			NcVar* proportionV;
			NcVar* flagV;

			NcDim* lowlandD;
			NcVar* lowlandV;

			NcDim* wetlandD;
			NcVar* wetlandV;

		private:

		};

#endif /* RUNNER_H_ */
