////////////////////////////////////////////////////////////////////////////////////////
/* 
The submodel is used for the predisposition for ATM model
*/
////////////////////////////////////////////////////////////////////////////////////////
 
#include "Predisposition.h"

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

Predisposition::Predisposition(){

};

Predisposition::~Predisposition(){

};

void Predisposition::InitiPred(string dir){

	string dir4file;
	dir4file = dir + "data/griddata/" + "TNNpred.nc";

	cout<<"dir4file = "<<dir4file<<endl;

	NcError err(NcError::silent_nonfatal);

	//NcFile* PredFile;
	PredFile = new NcFile(dir4file.c_str(), NcFile::Replace);

	cout<<"done pred 11"<<endl;

	//define dimension
    grdD = PredFile->add_dim("GRDID");
  	if(!grdD->is_valid()){
  		string msg = "The Dimension for predisposed is not Valid.";
 		char* msgc = const_cast<char*> (msg.c_str());
 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
 	}

	cout<<"done pred 12"<<endl;

  	//define variable
	//NcVar* predV;
	predV = PredFile->add_var("predisposed", ncFloat, grdD);
	predV->add_att("units", "no unit");
	predV->add_att("title", "Predisposition results, % is predisposed, 0 is not.");

	cout<<"done pred"<<endl;
};

void Predisposition::Predisposed(int grdid){

		//initializing data module
		cout<<"Running the predisposition module, please stand by!..."<<endl;

		// getchar();


		if (iopt->predlowland == 1){

			if (iopt->predfrost == 1 && (iopt->predgiv  == 3 || iopt->predgiv  == 2)){

				predprop = iopt->predisposed;
				iopt->predFlag = 1;

			}else{

				predprop = 0;
				iopt->predFlag = 0;
			}

		}else{

			predprop = 0;
			iopt->predFlag = 0;

		}

		cout<<"predisposing No. "<<grdid<<" done..."<<endl;

};


void Predisposition::OutPred(int grdid){

	int id;
	id = grdid;

	NcError err(NcError::silent_nonfatal);

	//add data to variables
	predV->set_cur(id-1);

	nb1 = predV->put(&predprop, 1);  	//number for reading is 1
	if (!nb1) {
	 string msg = "problem in put predV in TNNpred.nc";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_GET_ERROR);
	}

};

void Predisposition::SetPointer(IOdata* pt){

	iopt = pt;
}
