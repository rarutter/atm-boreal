/*
 * CHTPROP.h
 *
 *  Created on: Aug 26, 2013
 *      Author: yujin_admin
 */

#ifndef CHTPROP_H_
#define CHTPROP_H_

	#include <iostream>
	#include <fstream>
	#include <string>


	using namespace std;

	#include "../netcdf/includes/netcdfcpp.h"
	#include "../inc/ErrorCode.h"
	#include "../inc/Exception.h"

	#include "./IOdata.h"
	#include "./LNode.h"

	class ChtProp{
		public:
			ChtProp();
			~ChtProp();

			void outpLatlont3(string dirfile);
			void outpLatlont4(string dirfile);
			void outpLatlont5(string dirfile);
			void outpLatlont1(string dirfile);
			void outpLatlont2(string dirfile);
			void outpLatlont9(string dirfile);
			void outpLatlont10(string dirfile);

			void outpPropt3(int yearrec, int year, int grid);
			void outpPropt4(int yearrec, int year,  int grid);
			void outpPropt5(int yearrec, int year,  int grid);
			void outpPropt1(int yearrec, int year, int grid);
			void outpPropt2(int yearrec, int year, int grid);
			void outpPropt9(int yearrec, int year, int grid);
			void outpPropt10(int yearrec,int year, int grid);

			void setPointer(IOdata* IOpointer);
			void initVals();
			void calChtProps(Nodes* list);


			//the proportion of each cohort within a grid cell
			float chtprop3;
			float chtprop4;
			float chtprop5;
			float chtprop1;
			float chtprop2;
			float chtprop9;
			float chtprop10;

			NcFile* PropFile;
			NcFile* PropFilet4;
			NcFile* PropFilet5;

			NcFile* Propfilet3;
			NcFile* Propfilet4;
			NcFile* Propfilet5;
			NcFile* Propfilet1;
			NcFile* Propfilet2;
			NcFile* Propfilet9;
			NcFile* Propfilet10;

			NcFile* LatLonFile;

			NcDim* xDim;
			NcDim* yDim;

			NcDim* Dimgridid3;
			NcDim* Dimgridid4;
			NcDim* Dimgridid5;
			NcDim* Dimgridid1;
			NcDim* Dimgridid2;
			NcDim* Dimgridid9;
			NcDim* Dimgridid10;

			NcDim* xDt3;
			NcDim* xDt4;
			NcDim* xDt5;
			NcDim* xDt1;
			NcDim* xDt2;
			NcDim* xDt9;
			NcDim* xDt10;

			NcDim* yDt3;
			NcDim* yDt4;
			NcDim* yDt5;
			NcDim* yDt1;
			NcDim* yDt2;
			NcDim* yDt9;
			NcDim* yDt10;

			NcDim* yearDt3;
			NcDim* yearDt4;
			NcDim* yearDt5;
			NcDim* yearDt1;
			NcDim* yearDt2;
			NcDim* yearDt9;
			NcDim* yearDt10;

			double lat[10];
			double lon[10];

/*			NcVar* xDV;
			NcVar* yDV;
*/
			NcVar* gridid3;

			NcVar* propV;
			NcVar* propVt4;
			NcVar* propVt5;

			NcVar* PropVt3;
			NcVar* PropVt4;
			NcVar* PropVt5;
			NcVar* PropVt1;
			NcVar* PropVt2;
			NcVar* PropVt9;
			NcVar* PropVt10;

			NcVar* YrDVt3;
			NcVar* YrDVt4;
			NcVar* YrDVt5;
			NcVar* YrDVt1;
			NcVar* YrDVt2;
			NcVar* YrDVt9;
			NcVar* YrDVt10;


			NcVar* DimgrididV3;
			NcVar* DimgrididV4;
			NcVar* DimgrididV5;
			NcVar* DimgrididV1;
			NcVar* DimgrididV2;
			NcVar* DimgrididV9;
			NcVar* DimgrididV10;



		private:
			string dir4latlonFile;
			string dir4PropFile;

			string dir4latlonFilet4;
			string dir4PropFilet4;

			string dir4latlonFilet5;
			string dir4PropFilet5;

			IOdata* ioptr;


	};

#endif /*CHTPROP_H_*/
