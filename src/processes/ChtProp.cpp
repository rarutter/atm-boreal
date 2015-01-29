/*
 * CHTPROP.cpp
 *
 *  Created on: Aug 26, 2013
 *      Author: yujin_admin
 */

#include "ChtProp.h"
#include <stdio.h>

ChtProp::ChtProp(){

};

ChtProp::~ChtProp(){

};


void ChtProp::outpLatlont3(string dirfile){

		////////////////////////////////////////////////////////////////////
		//define the nc file for outputting results
		////////////////////////////////////////////////////////////////////

		dir4PropFile = dirfile + "data/output/" + "TNNPropTp3.nc";
		//cout<<"dir4PropFile === "<<dir4PropFile<<endl;

		Propfilet3 = new NcFile(dir4PropFile.c_str(), NcFile::Replace);
		if(!Propfilet3->is_valid())
		{
			string msg = "The PropFile is not Valid in PropFile.";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		//define dimension
	 	Dimgridid3 = Propfilet3->add_dim("GRIDID",2639);
	  	if(!Dimgridid3->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

	  	yearDt3 = Propfilet3->add_dim("Year");		//unlimited dimension
	  	if(!yearDt3->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		// add dim variables
	  	DimgrididV3 = Propfilet3->add_var("GRIDID", ncDouble, Dimgridid3);	//dim var name is same as dimension
		YrDVt3 = Propfilet3->add_var("Year", ncInt, yearDt3);

		// add dim variables attributes
		DimgrididV3->add_att("units", "id");
		DimgrididV3->add_att("title", "grid id");
		YrDVt3->add_att("units", "year");
		YrDVt3->add_att("title", "Running years");

		// add var proportion
		PropVt3 = Propfilet3->add_var("Prop", ncFloat, yearDt3, Dimgridid3);
		PropVt3->add_att("units", "percent");
		PropVt3->add_att("title", "Proportion of thermokarst area");

		cout<<"done with t33333333333"<<endl;
		//getchar();

};


void ChtProp::outpLatlont4(string dirfile){

	////////////////////////////////////////////////////////////////////
	//define the nc file for outputting results
	////////////////////////////////////////////////////////////////////

	dir4PropFile = dirfile + "data/output/" + "TNNPropTp4.nc";
	//cout<<"dir4PropFile === "<<dir4PropFile<<endl;

	Propfilet4 = new NcFile(dir4PropFile.c_str(), NcFile::Replace);
	if(!Propfilet4->is_valid())
	{
		string msg = "The PropFile is not Valid in PropFile.";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	}

	//define dimension
 	Dimgridid4 = Propfilet4->add_dim("GRIDID",2639);
  	if(!Dimgridid4->is_valid()){
  		string msg = "The Dimension for PropFile is not Valid in PropFile";
 		char* msgc = const_cast<char*> (msg.c_str());
 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
 	}

  	yearDt4 = Propfilet4->add_dim("Year");		//unlimited dimension
  	if(!yearDt4->is_valid()){
  		string msg = "The Dimension for PropFile is not Valid in PropFile";
 		char* msgc = const_cast<char*> (msg.c_str());
 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
 	}

	// add dim variables
  	DimgrididV4 = Propfilet4->add_var("GRIDID", ncDouble, Dimgridid4);  //dim var name is same as dimension
	YrDVt4 = Propfilet4->add_var("Year", ncInt, yearDt4);

	// add dim variables attributes
	DimgrididV4->add_att("units", "id");
	DimgrididV4->add_att("title", "grid id");
	YrDVt4->add_att("units", "year");
	YrDVt4->add_att("title", "Running years");

	// add var proportion
	PropVt4 = Propfilet4->add_var("Prop", ncFloat, yearDt4, Dimgridid4);
	PropVt4->add_att("units", "percent");
	PropVt4->add_att("title", "Proportion of thermokarst area");


		cout<<"done with t4"<<endl;

};

void ChtProp::outpLatlont5(string dirfile){

		////////////////////////////////////////////////////////////////////
		//define the nc file for outputting results
		////////////////////////////////////////////////////////////////////

		dir4PropFile = dirfile + "data/output/" + "TNNPropTp5.nc";
		//cout<<"dir4PropFile === "<<dir4PropFile<<endl;

		Propfilet5 = new NcFile(dir4PropFile.c_str(), NcFile::Replace);
		if(!Propfilet5->is_valid())
		{
			string msg = "The PropFile is not Valid in PropFile.";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		//define dimension
	 	Dimgridid5 = Propfilet5->add_dim("GRIDID",2639);
	  	if(!Dimgridid5->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

	  	yearDt5 = Propfilet5->add_dim("Year");		//unlimited dimension
	  	if(!yearDt5->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		// add dim variables
	  	DimgrididV5 = Propfilet5->add_var("GRIDID", ncDouble, Dimgridid5);
		YrDVt5 = Propfilet5->add_var("Year", ncInt, yearDt5);
		// add dim variables attributes
		DimgrididV5->add_att("units", "id");
		DimgrididV5->add_att("title", "grid id");
		YrDVt5->add_att("units", "year");
		YrDVt5->add_att("title", "Running years");

		// add var proportion
		PropVt5 = Propfilet5->add_var("Prop", ncFloat, yearDt5, Dimgridid5);
		PropVt5->add_att("units", "percent");
		PropVt5->add_att("title", "Proportion of thermokarst area");

		cout<<"done with t51"<<endl;
};

void ChtProp::outpLatlont1(string dirfile){

	////////////////////////////////////////////////////////////////////
	//define the nc file for outputting results
	////////////////////////////////////////////////////////////////////

	dir4PropFile = dirfile + "data/output/" + "TNNPropTp1.nc";
	//cout<<"dir4PropFile === "<<dir4PropFile<<endl;

	Propfilet1 = new NcFile(dir4PropFile.c_str(), NcFile::Replace);
	if(!Propfilet1->is_valid())
	{
		string msg = "The PropFile is not Valid in PropFile.";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	}

	//define dimension
 	Dimgridid1 = Propfilet1->add_dim("GRIDID",2639);
  	if(!Dimgridid1->is_valid()){
  		string msg = "The Dimension for PropFile is not Valid in PropFile";
 		char* msgc = const_cast<char*> (msg.c_str());
 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
 	}

  	yearDt1 = Propfilet1->add_dim("Year");		//unlimited dimension
  	if(!yearDt1->is_valid()){
  		string msg = "The Dimension for PropFile is not Valid in PropFile";
 		char* msgc = const_cast<char*> (msg.c_str());
 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
 	}

	// add dim variables
  	DimgrididV1 = Propfilet1->add_var("GRIDID", ncDouble, Dimgridid1);
	YrDVt1 = Propfilet1->add_var("Year", ncInt, yearDt1);
	// add dim variables attributes
	DimgrididV1->add_att("units", "id");
	DimgrididV1->add_att("title", "grid id");
	YrDVt1->add_att("units", "year");
	YrDVt1->add_att("title", "Running years");

	// add var proportion
	PropVt1 = Propfilet1->add_var("Prop", ncFloat, yearDt1, Dimgridid1);
	PropVt1->add_att("units", "percent");
	PropVt1->add_att("title", "Proportion of thermokarst area");


		cout<<"done with t1"<<endl;

};

void ChtProp::outpLatlont2(string dirfile){

	////////////////////////////////////////////////////////////////////
	//define the nc file for outputting results
	////////////////////////////////////////////////////////////////////

	dir4PropFile = dirfile + "data/output/" + "TNNPropTp2.nc";
	//cout<<"dir4PropFile === "<<dir4PropFile<<endl;

	Propfilet2 = new NcFile(dir4PropFile.c_str(), NcFile::Replace);
	if(!Propfilet2->is_valid())
	{
		string msg = "The PropFile is not Valid in PropFile.";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	}

	//define dimension
 	Dimgridid2 = Propfilet2->add_dim("GRIDID",2639);
  	if(!Dimgridid2->is_valid()){
  		string msg = "The Dimension for PropFile is not Valid in PropFile";
 		char* msgc = const_cast<char*> (msg.c_str());
 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
 	}

  	yearDt2 = Propfilet2->add_dim("Year");		//unlimited dimension
  	if(!yearDt2->is_valid()){
  		string msg = "The Dimension for PropFile is not Valid in PropFile";
 		char* msgc = const_cast<char*> (msg.c_str());
 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
 	}

	// add dim variables
  	DimgrididV2 = Propfilet2->add_var("GRIDID", ncDouble, Dimgridid2);
	YrDVt2 = Propfilet2->add_var("Year", ncInt, yearDt2);
	// add dim variables attributes
	DimgrididV2->add_att("units", "id");
	DimgrididV2->add_att("title", "grid id");
	YrDVt2->add_att("units", "year");
	YrDVt2->add_att("title", "Running years");

	// add var proportion
	PropVt2 = Propfilet2->add_var("Prop", ncFloat, yearDt2, Dimgridid2);
	PropVt2->add_att("units", "percent");
	PropVt2->add_att("title", "Proportion of thermokarst area");

		cout<<"done with t2"<<endl;
};

void ChtProp::outpLatlont9(string dirfile){

	////////////////////////////////////////////////////////////////////
	//define the nc file for outputting results
	////////////////////////////////////////////////////////////////////

	dir4PropFile = dirfile + "data/output/" + "TNNPropTp9.nc";
	//cout<<"dir4PropFile === "<<dir4PropFile<<endl;

	Propfilet9 = new NcFile(dir4PropFile.c_str(), NcFile::Replace);
	if(!Propfilet9->is_valid())
	{
		string msg = "The PropFile is not Valid in PropFile.";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	}

	//define dimension
 	Dimgridid9 = Propfilet9->add_dim("GRIDID",2639);
  	if(!Dimgridid9->is_valid()){
  		string msg = "The Dimension for PropFile is not Valid in PropFile";
 		char* msgc = const_cast<char*> (msg.c_str());
 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
 	}

  	yearDt9 = Propfilet9->add_dim("Year");		//unlimited dimension
  	if(!yearDt9->is_valid()){
  		string msg = "The Dimension for PropFile is not Valid in PropFile";
 		char* msgc = const_cast<char*> (msg.c_str());
 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
 	}

	// add dim variables
  	DimgrididV9 = Propfilet9->add_var("GRIDID", ncDouble, Dimgridid9);
	YrDVt9 = Propfilet9->add_var("Year", ncInt, yearDt9);
	// add dim variables attributes
	DimgrididV9->add_att("units", "id");
	DimgrididV9->add_att("title", "grid id");
	YrDVt9->add_att("units", "year");
	YrDVt9->add_att("title", "Running years");

	// add var proportion
	PropVt9 = Propfilet9->add_var("Prop", ncFloat, yearDt9, Dimgridid9);
	PropVt9->add_att("units", "percent");
	PropVt9->add_att("title", "Proportion of thermokarst area");

		cout<<"done with t9"<<endl;
};

void ChtProp::outpLatlont10(string dirfile){

	////////////////////////////////////////////////////////////////////
	//define the nc file for outputting results
	////////////////////////////////////////////////////////////////////

	dir4PropFile = dirfile + "data/output/" + "TNNPropTp10.nc";
	//cout<<"dir4PropFile === "<<dir4PropFile<<endl;

	Propfilet10 = new NcFile(dir4PropFile.c_str(), NcFile::Replace);
	if(!Propfilet10->is_valid())
	{
		string msg = "The PropFile is not Valid in PropFile.";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	}

	//define dimension
 	Dimgridid10 = Propfilet10->add_dim("GRIDID",2639);
  	if(!Dimgridid10->is_valid()){
  		string msg = "The Dimension for PropFile is not Valid in PropFile";
 		char* msgc = const_cast<char*> (msg.c_str());
 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
 	}

  	yearDt10 = Propfilet10->add_dim("Year");		//unlimited dimension
  	if(!yearDt10->is_valid()){
  		string msg = "The Dimension for PropFile is not Valid in PropFile";
 		char* msgc = const_cast<char*> (msg.c_str());
 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
 	}

	// add dim variables
  	DimgrididV10 = Propfilet10->add_var("GRIDID", ncDouble, Dimgridid10);
	YrDVt10 = Propfilet10->add_var("Year", ncInt, yearDt10);
	// add dim variables attributes
	DimgrididV10->add_att("units", "id");
	DimgrididV10->add_att("title", "grid id");
	YrDVt10->add_att("units", "year");
	YrDVt10->add_att("title", "Running years");

	// add var proportion
	PropVt10 = Propfilet10->add_var("Prop", ncFloat, yearDt10, Dimgridid10);
	PropVt10->add_att("units", "percent");
	PropVt10->add_att("title", "Proportion of thermokarst area");

		//cout<<"done with t10"<<endl;

};


void ChtProp::outpPropt3(int yearrec,int year, int grid){

	PropVt3->set_cur(yearrec, grid-1);	//recored id of the output year dim

	NcBool nb1 = PropVt3->put(&chtprop3, 1, 1);  	//put in one number each time
	if (!nb1) {
	 string msg = "problem in put prop in TNNprop.nc";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_GET_ERROR);
	}

	if (grid==1){//only write in var 'year' for one time

		YrDVt3->set_cur(yearrec);	//recored id of the output year dim
		nb1 = YrDVt3->put(&year, 1);  	//number for reading
		if (!nb1) {
		 string msg = "problem in put prop in TNNprop.nc";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_GET_ERROR);
		}

	}

};


void ChtProp::outpPropt4(int yearrec,int year, int grid){

	PropVt4->set_cur(yearrec, grid-1);
	NcBool nb1 = PropVt4->put(&chtprop4, 1, 1);  	//number for reading
	//cout<<"output total chtprop4 = "<<chtprop4<<endl;
	//getchar();

	if (!nb1) {
	 string msg = "problem in put prop in TNNprop.nc";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_GET_ERROR);
	}

	if (grid==1){//only write in var 'year' for one time

		YrDVt4->set_cur(yearrec);
		nb1 = YrDVt4->put(&year, 1);  	//number for reading
		if (!nb1) {
		 string msg = "problem in put prop in TNNprop.nc";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_GET_ERROR);
		}
	}

	//cout<<"yearrec = "<<yearrec<<endl;
	//cout<<"grid = "<<grid<<endl;

	//cout<<"chtprop4 = "<<chtprop4<<endl;

	//getchar();


};

void ChtProp::outpPropt5(int yearrec,int year, int grid){

	PropVt5->set_cur(yearrec, grid-1);
	NcBool nb1 = PropVt5->put(&chtprop5, 1, 1);  	//number for reading
	if (!nb1) {
	 string msg = "problem in put prop in TNNprop.nc";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_GET_ERROR);
	}

	if (grid==1){//only write in var 'year' for one time

			YrDVt5->set_cur(yearrec);
		nb1 = YrDVt5->put(&year, 1);  	//number for reading
		if (!nb1) {
		 string msg = "problem in put prop in TNNprop.nc";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_GET_ERROR);
		}


	}


	//cout<<"yearrec = "<<yearrec<<endl;
	//cout<<"grid = "<<grid<<endl;

	//cout<<"chtprop5 = "<<chtprop5<<endl;

	//getchar();



};

void ChtProp::outpPropt1(int yearrec,int year, int grid){

	PropVt1->set_cur(yearrec, grid-1);
	NcBool nb1 = PropVt1->put(&chtprop1, 1, 1);  	//number for reading
	if (!nb1) {
	 string msg = "problem in put prop in TNNprop.nc";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_GET_ERROR);
	}

	//cout<<"chtprop1 = ++++++++++++ "<<chtprop1<<endl;
	//getchar();


	if (grid==1){//only write in var 'year' for one time

		YrDVt1->set_cur(yearrec);
		nb1 = YrDVt1->put(&year, 1);  	//number for reading
		if (!nb1) {
		 string msg = "problem in put prop in TNNprop.nc";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_GET_ERROR);
		}

	}

};


void ChtProp::outpPropt2(int yearrec,int year, int grid){

	PropVt2->set_cur(yearrec, grid-1);
	NcBool nb1 = PropVt2->put(&chtprop2, 1, 1);  	//number for reading
	if (!nb1) {
	 string msg = "problem in put prop in TNNprop.nc";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_GET_ERROR);
	}

	if (grid==1){//only write in var 'year' for one time

		YrDVt2->set_cur(yearrec);
		nb1 = YrDVt2->put(&year, 1);  	//number for reading
		if (!nb1) {
		 string msg = "problem in put prop in TNNprop.nc";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_GET_ERROR);
		}


	}


};

void ChtProp::outpPropt9(int yearrec,int year, int grid){

	PropVt9->set_cur(yearrec, grid-1);
	NcBool nb1 = PropVt9->put(&chtprop9, 1, 1);  	//number for reading
	if (!nb1) {
	 string msg = "problem in put prop in TNNprop.nc";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_GET_ERROR);
	}


	if (grid==1){//only write in var 'year' for one time

		YrDVt9->set_cur(yearrec);
		nb1 = YrDVt9->put(&year, 1);  	//number for reading
		if (!nb1) {
		 string msg = "problem in put prop in TNNprop.nc";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_GET_ERROR);
		}

	}


};

void ChtProp::outpPropt10(int yearrec,int year, int grid){

	PropVt10->set_cur(yearrec, grid-1);
	NcBool nb1 = PropVt10->put(&chtprop10, 1, 1);  	//number for reading
	if (!nb1) {
	 string msg = "problem in put prop in TNNprop.nc";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_GET_ERROR);
	}


	if (grid==1){//only write in var 'year' for one time

		YrDVt10->set_cur(yearrec);
		nb1 = YrDVt10->put(&year, 1);  	//number for reading
		if (!nb1) {
		 string msg = "problem in put prop in TNNprop.nc";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_GET_ERROR);
		}

	}

};

void ChtProp::initVals(){

	chtprop3 = 0;
	chtprop4 = 0;
	chtprop5 = 0;
	chtprop1 = 0;
	chtprop2 = 0;
	chtprop9 = 0;
	chtprop10 = 0;

};


void ChtProp::calChtProps(Nodes* list){

	double sum=0;

	Nodes* plist = new Nodes;
	plist = NULL;
	plist = list;
	while(plist != NULL){

		//calculating the proportion of each cohorts input
		if(plist->vegtype == 3)
			chtprop3 += plist->proportion;
		else if(plist->vegtype == 4)
			chtprop4 += plist->proportion;
		else if(plist->vegtype == 5)
			chtprop5 += plist->proportion;
		else if(plist->vegtype == 1)
			chtprop1 += plist->proportion;
		else if(plist->vegtype == 2)
			chtprop2 += plist->proportion;
		else if(plist->vegtype == 9)
			chtprop9 += plist->proportion;
		else if(plist->vegtype == 10)
			chtprop10 += plist->proportion;

		//cal sum  of all chts
		sum += plist->proportion;

		plist = plist->pNext;
	}

	//cout<<"proportion sum =========== "<<sum<<endl;
	//getchar();
};


void ChtProp::setPointer(IOdata* IOpointer){

		ioptr = IOpointer;
};
