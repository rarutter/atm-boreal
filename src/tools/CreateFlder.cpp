/*
 * CreateFlder.cpp
 *
 *  Created on: Jan 10, 2014
 *      Author: yujin_admin
 */

#include "./CreateFlder.h"

CreateFlder::CreateFlder(){

};

CreateFlder::~CreateFlder(){

};

void CreateFlder::Createflder(string dir, long grdid){

	stringstream fldname;
	string fldname2;

	fldname << grdid;

	fldname2 = fldname.str();

	createfld(fldname2);

	fldname.str("");

	return ;


};

void CreateFlder::createfld(string fname2){


	string fldname;

	//Before this, there should be a fold ".\DATA\Output\" under working directory.

	fldname = ".\\data\\output\\G" + fname2;

	const char* c = fldname.c_str();

	CreateDirectory(c, NULL);

	return;


};

