/*
 * DelFile.cpp
 *
 *  Created on: Jan 13, 2014
 *      Author: yujin_admin
 */

#include "./DelFile.h"

DelFile::DelFile(){

};

DelFile::~DelFile(){

};


void DelFile::delFile(string dir, int grdid, int year){

	stringstream ss_Grdid;
	string s_Grdid;
	stringstream ss_Year;
	string s_Year;

	ss_Grdid << grdid;
	s_Grdid = ss_Grdid.str();

   	ss_Year << year-1;
   	s_Year = ss_Year.str();

	string chtFilename = dir + "g" + s_Grdid + "y" + s_Year + ".nc";

	const char * ch_Filename = chtFilename.c_str();

	if(remove(ch_Filename)){

		cout<<"Could not delete the file"<<endl;

	}else{
		//cout<<"deleted the file."<<endl;
	}
};
