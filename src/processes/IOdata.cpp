#include "IOdata.h"

IOdata::IOdata(){
	
};

IOdata::~IOdata(){
	
};


void IOdata::initlz(){

	//input data for predisposition
	predgrdid = -9999;
	predfrost = -9999;
	predlowland = -9999;
	predgiv = -9999;
	predwetland = -9999;

	predisposed = -9999;
	predFlag = -9999;

	//data for Node for linked list

	year = -9999;
	ingrdid = -9999;
	inparentid = -9999;
	incohortid = -9999;
	invegtype = -9999;
	inage = -9999;
	inproportion = -9999;
	inflag = -9999;


	//intermediate

	//output data

	outgridid = -9999;
	outcohortid = -9999;
	outvegetype = -9999;
	outage = -9999;
	outproportion = -9999;
	outflag = -9999;


	area3 = -9999;
	area4 = -9999;
	area5 = -9999;
	area1 = -9999;
	area2 = -9999;
	area9 = -9999;
	area10 = -9999;

	//for the areas proportion
	rate3 = -9999;
	rate4_B2Fen = -9999;
	rate5_D2Fen = -9999;
	rate1 = -9999;
	rate2 = -9999;
	rate9_LK2Fen = -9999;
	rate9_Deci2LK = -9999;
	rate10 = -9999;

};





