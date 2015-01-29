/*
 * Outputer.cpp
 *
 *  Created on: Jan 13, 2014
 *      Author: yujin_admin
 */

#include "./Outputer.h"


Outputer::Outputer(){

};

Outputer::~Outputer(){

};

void Outputer::InitOutputCht(string dir, int grdid, int year){

	stringstream ss_Grdid;
	string s_Grdid;
	stringstream ss_Year;
	string s_Year;

	ss_Grdid << grdid;
	s_Grdid = ss_Grdid.str();


   	ss_Year << year;
   	s_Year = ss_Year.str();


	string chtFilename = dir + "g"+ s_Grdid + "y" + s_Year + ".nc";

	NcError err(NcError::silent_nonfatal);

	ChtFile = new NcFile(chtFilename.c_str(), NcFile::Replace);


	//define dimension
    chtD = ChtFile->add_dim("TOTALCHTS");
  	if(!chtD->is_valid()){
  		string msg = "The Dimension for chtD is not Valid.";
 		char* msgc = const_cast<char*> (msg.c_str());
 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
 	}

  	//define variable
  	oYearV = ChtFile->add_var("year", ncFloat, chtD);
  	oYearV->add_att("units", "year");
  	oYearV->add_att("title", "Year in which cohorts were generated");

  	oGrdidV = ChtFile->add_var("gridid", ncInt, chtD);
  	oGrdidV->add_att("units", "no unit");
  	oGrdidV->add_att("title", "ID for grid cell");

  	oParentidV = ChtFile->add_var("parentid", ncInt, chtD);
  	oParentidV->add_att("units", "no unit");
  	oParentidV->add_att("title", "ID for parent cohort");

  	oChtidV = ChtFile->add_var("cohortid", ncInt, chtD);
  	oChtidV->add_att("units", "no unit");
  	oChtidV->add_att("title", "ID for current cohort");

  	oVegtypeV = ChtFile->add_var("vegtype", ncInt, chtD);
  	oVegtypeV->add_att("units", "no unit");
  	oVegtypeV->add_att("title", "ID for vegetation type");

  	oAgeV = ChtFile->add_var("age", ncInt, chtD);
  	oAgeV->add_att("units", "year");
  	oAgeV->add_att("title", "Cohort age");

	oPropV = ChtFile->add_var("proportion", ncFloat, chtD);
	oPropV->add_att("units", "%");
	oPropV->add_att("title", "Cohort proportion");

	oFlagV = ChtFile->add_var("flag", ncInt, chtD);
	oFlagV->add_att("units", "no unit");
	oFlagV->add_att("title", "Flag for ???");


	//cout<<"initializing for new cht file done"<<endl;

};

void Outputer::OutputCht(string dir,int grdid, int year, Nodes* list, long trecrd){


		NcError err(NcError::silent_nonfatal);
		oYearV->set_cur(trecrd);

		nb = oYearV->put(&year, 1);  	//count for reading is 1, current run year
		if (!nb) {
		 string msg = "problem in put parentidV in TNNtcht.nc";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_GET_ERROR);
		}

		oGrdidV->set_cur(trecrd);
		nb = oGrdidV->put(&list->grdID, 1);  	//count for reading is 1
		if (!nb) {
		 string msg = "problem in put grdidV in TNNtcht.nc";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_GET_ERROR);
		}


		oParentidV->set_cur(trecrd);
		nb = oParentidV->put(&list->parentid, 1);  	//count for reading is 1
		if (!nb) {
		 string msg = "problem in put parentidV in TNNtcht.nc";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_GET_ERROR);
		}

		oChtidV->set_cur(trecrd);

		nb = oChtidV->put(&list->cohortid, 1);  	//count for reading is 1//dim
		if (!nb) {
		 string msg = "problem in put cohortidV in TNNtcht.nc";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_GET_ERROR);
		}

		oVegtypeV->set_cur(trecrd);
		nb = oVegtypeV->put(&list->vegtype, 1);  	//count for reading is 1
		if (!nb) {
		 string msg = "problem in put vegtypeV in TNNtcht.nc";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_GET_ERROR);
		}

		oAgeV->set_cur(trecrd);
		nb = oAgeV->put(&list->age, 1);  	//count for reading is 1
		if (!nb) {
		 string msg = "problem in put ageV in TNNtcht.nc";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_GET_ERROR);
		}

		oPropV->set_cur(trecrd);
		nb = oPropV->put(&list->proportion, 1);  	//count for reading is 1 done =

/*if (list->vegtype==4 && year > 2009){
	cout<<"outputr, final output tp4  list->proportion = "<<list->proportion<<endl;
	getchar();

}*/


		if (!nb) {
		 string msg = "problem in put proportionV in TNNtcht.nc";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_GET_ERROR);
		}

		oFlagV->set_cur(trecrd);
		nb = oFlagV->put(&list->flag, 1);  	//count for reading is 1
		if (!nb) {
		 string msg = "problem in put flagV in TNNtcht.nc";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_GET_ERROR);
		}

};
