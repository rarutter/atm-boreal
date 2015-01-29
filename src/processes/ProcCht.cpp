/*
 * ProcsCht.cpp
 *
 *  Created on: Jul 24, 2013
 *      Author: yujin_admin
 */


#include "./ProcCht.h"

ProcCht::ProcCht(){

};

ProcCht::~ProcCht(){

};


void ProcCht::GetCht(string dirfile, int id){

	//////////////////////Open and Read inicht data

	string dir4inichtfile;
	dir4inichtfile = dirfile;

	NcError err(NcError::silent_nonfatal);

	NcFile inichtfile(dir4inichtfile.c_str(), NcFile::ReadOnly);
 	if(!inichtfile.is_valid()){
 		string msg = dir4inichtfile + " is not valid";
 		//char* msgc = const_cast< char* > ( msg.c_str());
 		cout<<msg<<endl;
 		//throw Exception( msgc, I_NCFILE_NOT_EXIST);

 		cout<<"Stop model simulations!"<<endl;
 	 	exit(0);

 	}else{

		NcDim* grdD = inichtfile.get_dim("TOTALCHTS");
		if(!grdD->is_valid()){
			string msg = "Dimension is not Valid in chtFilename";
			//char* msgc = const_cast<char*> (msg.c_str());
			//throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}


		//////////////

		NcVar* grididV = inichtfile.get_var("gridid");
		if(grididV==NULL){
		  cout <<"cannot get grididV\n";
		}

		grididV->set_cur(id);

		grididV->get(&ioptr->ingrdid,1);

		//////////////////////////////////

		NcVar* inichtidV = inichtfile.get_var("cohortid");
		if(inichtidV==NULL){
		  cout <<"cannot get inichtidV in inichtid.nc\n";
		}

		inichtidV->set_cur(id);

		inichtidV->get(&ioptr->incohortid,1);


		//////////////

		NcVar* vegtypeV = inichtfile.get_var("vegtype");
		if(vegtypeV==NULL){
		  cout <<"cannot get vegtypeV in inichtid.nc\n";
		}

		vegtypeV->set_cur(id);

		vegtypeV->get(&ioptr->invegtype,1);


		//////////////

		NcVar* ageV = inichtfile.get_var("age");
		if(ageV==NULL){
		  cout <<"cannot get ageV in inichtid.nc\n";
		}

		ageV->set_cur(id);

		ageV->get(&ioptr->inage,1);


		//////////////

		NcVar* proportionV = inichtfile.get_var("proportion");
		if(proportionV==NULL){
		  cout <<"cannot get proportionV in inichtid.nc\n";
		}

		proportionV->set_cur(id);


		//output data to
		proportionV->get(&ioptr->inproportion,1);

		//////////////

		NcVar* flagV = inichtfile.get_var("flag");
		if(flagV==NULL){
		  cout <<"cannot get flagV in inichtid.nc\n";
		}

		flagV->set_cur(id);

		flagV->get(&ioptr->inflag,1);


 	}

};



void ProcCht::GetCht(string dirfile, int gridid, int year, int id){

	//////////////////////Open and Read inicht data

	stringstream ss_Grdid;
	string s_Grdid;
	stringstream ss_Year;
	string s_Year;

	ss_Grdid << gridid;
	s_Grdid = ss_Grdid.str();


   	ss_Year << year-1;
   	s_Year = ss_Year.str();


	string dir4inichtfile;
	dir4inichtfile = dirfile + "g" + s_Grdid + "y" + s_Year + ".nc";


	NcError err(NcError::silent_nonfatal);

	NcFile inichtfile(dir4inichtfile.c_str(), NcFile::ReadOnly);

	if(!inichtfile.is_valid()){
		string msg = dir4inichtfile + " is not valid";
		char* msgc = const_cast< char* > ( msg.c_str());
		throw Exception( msgc, I_NCFILE_NOT_EXIST);
	}

	//////////////

	NcVar* grididV = inichtfile.get_var("gridid");
	if(grididV==NULL){
	  cout <<"cannot get grididV\n";
	}


	grididV->set_cur(id);

	grididV->get(&ioptr->ingrdid,1);

	//////////////////////////////////

	NcVar* inichtidV = inichtfile.get_var("cohortid");
	if(inichtidV==NULL){
	  cout <<"cannot get inichtidV in inichtid.nc\n";
	}

	inichtidV->set_cur(id);
	inichtidV->get(&ioptr->incohortid,1);

	//////////////

	NcVar* vegtypeV = inichtfile.get_var("vegtype");
	if(vegtypeV==NULL){
	  cout <<"cannot get vegtypeV in inichtid.nc\n";
	}

	vegtypeV->set_cur(id);

	vegtypeV->get(&ioptr->invegtype,1);

	//////////////

	NcVar* ageV = inichtfile.get_var("age");
	if(ageV==NULL){
	  cout <<"cannot get ageV in inichtid.nc\n";
	}

	ageV->set_cur(id);

	ageV->get(&ioptr->inage,1);


	//////////////

	NcVar* proportionV = inichtfile.get_var("proportion");
	if(proportionV==NULL){
	  cout <<"cannot get proportionV in inichtid.nc\n";
	}

	proportionV->set_cur(id);

	proportionV->get(&ioptr->inproportion,1);

	//////////////

	NcVar* flagV = inichtfile.get_var("flag");
	if(flagV==NULL){
	  cout <<"cannot get flagV in inichtid.nc\n";
	}

	flagV->set_cur(id);

	flagV->get(&ioptr->inflag,1);

	inichtfile.close();


};



void ProcCht::InsertCht(Nodes *list, Nodes* lnode){


};

void ProcCht::SetPointer(IOdata* ptr){

	ioptr = ptr;
}

