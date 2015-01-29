/*
 * ChtInputer.cpp
 *
 *  Created on: Jan 8, 2014
 *      Author: yujin_admin
 */

#include "ChtInputer.h"

ChtInputer::ChtInputer(){

}

ChtInputer::~ChtInputer(){

}

void ChtInputer::InitChtFile(string dir){

	Filename = dir;

	NcError err(NcError::silent_nonfatal);
	NcFile grdFile(Filename.c_str(), NcFile::ReadOnly);
 	if(!grdFile.is_valid()){
 		string msg = Filename +" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}

 	NcDim* grdD = grdFile.get_dim("TOTALCHTS");
  	if(!grdD->is_valid()){
  		string msg = "Dimension is not Valid in chtFilename";
 		char* msgc = const_cast<char*> (msg.c_str());
 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
 	}

  	grdFile.close();

};


void ChtInputer::InitChtFile(string dir, int grdid, int year){

	stringstream ss_Grdid;
	string s_Grdid;
	stringstream ss_Year;
	string s_Year;

	ss_Grdid << grdid;
	s_Grdid = ss_Grdid.str();
   	//cout<<"s_Grdid is "<<s_Grdid<<endl;

   	ss_Year << year-1;
   	s_Year = ss_Year.str();
   	//cout<<"previous s_Year is "<<s_Year<<endl;

	string chtFilename = dir + "g" + s_Grdid + "y" + s_Year + ".nc";
   	//cout<<"input chtFilename is "<<chtFilename<<endl;
   	//getchar();

	NcError err(NcError::silent_nonfatal);
	NcFile grdFile(chtFilename.c_str(), NcFile::ReadOnly);
 	if(!grdFile.is_valid()){
 		string msg = chtFilename +" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}

 	NcDim* grdD = grdFile.get_dim("TOTALCHTS");
  	if(!grdD->is_valid()){
  		string msg = "Dimension is not Valid in chtFilename";
 		char* msgc = const_cast<char*> (msg.c_str());
 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
 	}

  	//grdFile.close();
   	//cout<<"check new input file done "<<endl;

};

int ChtInputer::getNumVals(string dir){

	Filename = dir;

	NcError err(NcError::silent_nonfatal);
	NcFile grdFile(Filename.c_str(), NcFile::ReadOnly);
 	if(!grdFile.is_valid()){
 		string msg = Filename +" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}

 	NcVar* grdidV = grdFile.get_var("gridid");
 	if(grdidV==NULL){
 	   string msg = "Cannot get grdid  in .nc ";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_NOT_EXIST);
 	}

   	long n = (int)grdidV->num_vals();

  	grdFile.close();

   	return n;

};

int ChtInputer::getInitChtRecID(string dir, int grdid, int irec){

	NcError err(NcError::silent_nonfatal);

	Filename = dir;

	NcFile grdFile(Filename.c_str(), NcFile::ReadOnly);
 	NcVar* grdidV = grdFile.get_var("gridid");
 	if(grdidV==NULL){
 	   string msg = "Cannot get grdid  in .nc ";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_NOT_EXIST);
 	}

 	int id = -1;
	grdidV->set_cur(irec);	//using irec from outside to control the variable record
	grdidV->get(&id, 1);

	if(id == grdid)
		return irec;

	grdFile.close();

	return -1;
};


int ChtInputer::getNumValsRec(string dir, int grid, int year){

	stringstream ss_Grdid;
	string s_Grdid;
	stringstream ss_Year;
	string s_Year;

	ss_Grdid << grid;
	s_Grdid = ss_Grdid.str();
   	//cout<<"s_Grdid is "<<s_Grdid<<endl;

   	ss_Year << year-1;
   	s_Year = ss_Year.str();
   	//cout<<"s_Year is "<<s_Year<<endl;

	Filename = dir + "g"+ s_Grdid + "y" + s_Year + ".nc";

   	//cout<<"input Filename is "<<Filename<<endl;
   	//getchar();

   	NcError err(NcError::silent_nonfatal);
   	NcFile grdFile(Filename.c_str(), NcFile::ReadOnly);
 	if(!grdFile.is_valid()){
 		string msg = Filename +" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}

 	NcVar* grdidV = grdFile.get_var("gridid");
 	if(grdidV==NULL){
 	   string msg = "Cannot get grdid  in .nc ";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_NOT_EXIST);
 	}

   	long n = (int)grdidV->num_vals();

  	grdFile.close();

   	return n;

};




int ChtInputer::getGrdRecID(string dir, int grdid, int year, int irec){

	NcError err(NcError::silent_nonfatal);

	stringstream ss_Grdid;
	string s_Grdid;
	stringstream ss_Year;
	string s_Year;

	ss_Grdid << grdid;
	s_Grdid = ss_Grdid.str();
   	//cout<<"s_Grdid is "<<s_Grdid<<endl;

   	ss_Year << year-1;			//previous year
   	s_Year = ss_Year.str();
   	//cout<<"s_Year is "<<s_Year<<endl;

	string chtFilename = dir + "g" + s_Grdid + "y" + s_Year + ".nc";

	NcFile grdFile(chtFilename.c_str(), NcFile::ReadOnly);
 	NcVar* grdidV = grdFile.get_var("gridid");
 	if(grdidV==NULL){
 	   string msg = "Cannot get grdid  in .nc ";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_NOT_EXIST);
 	}

 	int id = -1;
	grdidV->set_cur(irec);
	grdidV->get(&id, 1);
	if(id == grdid)
		return irec;

	return -1;
};

long ChtInputer::InitMaxChtId(){

	NcError err(NcError::silent_nonfatal);

	Filename = "./data/input/TNNFlatsInichtAGU.nc";

 	NcFile chtFile(Filename.c_str(), NcFile::ReadOnly);
 	NcVar* chtidV = chtFile.get_var("cohortid");
 	if(chtidV==NULL){
 	   string msg = "Cannot get grdid  in .nc ";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_NOT_EXIST);
 	}

 	long id = 0;
 	long max = 0;
 	for (int i=0;i<(int)chtidV->num_vals();i++){
 		chtidV->set_cur(i);
 		chtidV->get(&id, 1);
 		if(id>max)
 			max=id;
 	}

	chtFile.close();

	return max;

};
