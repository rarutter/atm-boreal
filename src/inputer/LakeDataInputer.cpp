/*
 * LakeDataInputer.cpp
 *
 */

#include "LakeDataInputer.h"

LakeDataInputer::LakeDataInputer(){

}

LakeDataInputer::~LakeDataInputer(){

}

void LakeDataInputer::InitLakeData(string dir){

/*	Filename = dir + "data/input/" + "TNNinichtNEW.nc";

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

  	grdFile.close();*/

};



void LakeDataInputer::getLake(string dir, int grdidrec){

	grdidrec=grdidrec-1;		//2639 records

	//******************************
	Filedist = dir + "data/input/" + "Lake_TNNdistance.nc";

	NcError err(NcError::silent_nonfatal);
	NcFile distFile(Filedist.c_str(), NcFile::ReadOnly);
 	if(!distFile.is_valid()){
 		string msg = Filedist +" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}

/* 	grdD = distFile.get_dim("x");
  	if(!grdD->is_valid()){
  		string msg = "Dimension x is not Valid in file";
 		char* msgc = const_cast<char*> (msg.c_str());
 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
 	}

 	grdD = distFile.get_dim("y");
  	if(!grdD->is_valid()){
  		string msg = "Dimension y is not Valid in file";
 		char* msgc = const_cast<char*> (msg.c_str());
 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
 	}*/

  	//get the value
 	NcVar*  riverdistV = distFile.get_var("TNNdistance");
 	if(riverdistV==NULL){
 	   string msg = "Cannot get distance  in .nc file";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_NOT_EXIST);
 	}
 	riverdistV->set_cur(grdidrec);
 	riverdistV->get(&filedist, 1);

  	distFile.close();


//cout<<"lake____111"<<endl;

	//******************************
	Filettlarea = dir +  "data/input/" + "Lake_sizesum.nc";

	NcFile ttlsizeFile(Filettlarea.c_str(), NcFile::ReadOnly);
 	if(!ttlsizeFile.is_valid()){
 		string msg = Filettlarea +" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}

  	//get the value
 	NcVar*  ttlsizeV = ttlsizeFile.get_var("Lakesize");
 	if(ttlsizeV==NULL){
 	   string msg = "Cannot get distance  in .nc file";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_NOT_EXIST);
 	}

 	ttlsizeV->get(&filettlarea, 1);

 	ttlsizeFile.close();


  	//cout<<"lake___2_"<<endl;


	//******************************
	Fileavgsize = dir + "data/input/" + "Lake_sizesavg.nc";

	NcFile avgsizeFile(Fileavgsize.c_str(), NcFile::ReadOnly);
 	if(!avgsizeFile.is_valid()){
 		string msg = Fileavgsize +" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}


  	//get the value
 	NcVar*  avgsizeV = avgsizeFile.get_var("Lakesize");
 	if(avgsizeV==NULL){
 	   string msg = "Cannot get distance  in .nc file";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_NOT_EXIST);
 	}
 	avgsizeV->set_cur(grdidrec);
 	avgsizeV->get(&fileavgsize, 1);		//pay attention to unavailable data -2147483648

 	avgsizeFile.close();

  	//cout<<"lake____3333"<<endl;

	//******************************
	Filedem = dir + "data/input/" + "Lake_demINT.nc";

	NcFile demFile(Filedem.c_str(), NcFile::ReadOnly);
 	if(!demFile.is_valid()){
 		string msg = Filedem +" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}

  	//get the value
 	NcVar*  lakedemV = demFile.get_var("TNNdemINT");
 	if(lakedemV==NULL){
 	   string msg = "Cannot get distance  in .nc file";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_NOT_EXIST);
 	}
 	lakedemV->set_cur(grdidrec);
 	lakedemV->get(&filedem, 1);

 	demFile.close();


	//******************************
	Filedeposit = dir + "data/input/" + "Lake_TNNdeposit2.nc";

	NcFile depositFile(Filedeposit.c_str(), NcFile::ReadOnly);
 	if(!depositFile.is_valid()){
 		string msg = Filedeposit +" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}

 	//get the value
 	NcVar*  lakedepositV = depositFile.get_var("TNNdeposit");
 	if(lakedepositV==NULL){
 	   string msg = "Cannot get distance  in .nc file";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_NOT_EXIST);
 	}
 	lakedepositV->set_cur(grdidrec);
 	lakedepositV->get(&filedeposit, 1);

 	depositFile.close();


	//******************************
	Filerocky = dir + "data/input/" + "Lake_TNNrocky.nc";

	NcFile rockyFile(Filerocky.c_str(), NcFile::ReadOnly);
 	if(!rockyFile.is_valid()){
 		string msg = Filerocky +" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}

  	//get the value
 	NcVar*  ykrockyV = rockyFile.get_var("TNNrocky");
 	if(ykrockyV==NULL){
 	   string msg = "Cannot get distance  in .nc file";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_NOT_EXIST);
 	}
 	ykrockyV->set_cur(grdidrec);
 	ykrockyV->get(&filerocky, 1);

 	rockyFile.close();


	//******************************
	Filesand = dir + "data/input/" + "Lake_TNNsandy3.nc";

	NcFile sandyFile(Filesand.c_str(), NcFile::ReadOnly);
 	if(!sandyFile.is_valid()){
 		string msg = Filesand +" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}
  	//get the value
 	NcVar*  yksandyV = sandyFile.get_var("TNNsandy");
 	if(yksandyV==NULL){
 	   string msg = "Cannot get distance  in .nc file";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_NOT_EXIST);
 	}
 	yksandyV->set_cur(grdidrec);
 	yksandyV->get(&filesandy, 1);

 	sandyFile.close();


	//******************************
	Filersds = dir + "data/input/" + "Lake_TNNradiation1916.nc";

	NcFile rsdsFile(Filersds.c_str(), NcFile::ReadOnly);
 	if(!rsdsFile.is_valid()){
 		string msg = Filersds +" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}

  	//get the value
 	NcVar*  ykrsdsV = rsdsFile.get_var("TNNradiation1916");
 	if(ykrsdsV==NULL){
 	   string msg = "Cannot get distance  in .nc file";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_NOT_EXIST);
 	}
 	ykrsdsV->set_cur(grdidrec);
 	ykrsdsV->get(&filersds, 1);

 	rsdsFile.close();

	//******************************
	Filefire8599 = dir + "data/input/" + "Lake_fire20002009.nc";

	NcFile fire8599File(Filefire8599.c_str(), NcFile::ReadOnly);
 	if(!fire8599File.is_valid()){
 		string msg = Filefire8599 +" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}

  	//get the value
 	NcVar*  fire8599V = fire8599File.get_var("fire");
 	if(fire8599V==NULL){
 	   string msg = "Cannot get distance  in .nc file";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_NOT_EXIST);
 	}
 	fire8599V->set_cur(grdidrec);
 	fire8599V->get(&filefire8599, 1);

 	fire8599File.close();


	//******************************
	Filefire0009 = dir + "data/input/" + "Lake_fire20002009.nc";

	NcFile fire0009File(Filefire0009.c_str(), NcFile::ReadOnly);
 	if(!fire0009File.is_valid()){
 		string msg = Filefire0009 +" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}

  	//get the value
 	NcVar*  fire0009V = fire0009File.get_var("fire");
 	if(fire0009V==NULL){
 	   string msg = "Cannot get distance  in .nc file";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_NOT_EXIST);
 	}
 	fire0009V->set_cur(grdidrec);
 	fire0009V->get(&filefire0009, 1);

 	fire0009File.close();

	//******************************flow accu
	Fileflowaccu = dir + "data/input/" + "Lake_accumulation.nc";

	NcFile flowaccuFile(Fileflowaccu.c_str(), NcFile::ReadOnly);
 	if(!flowaccuFile.is_valid()){
 		string msg = Fileflowaccu +" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}

  	//get the value
 	NcVar*  flowaccuV = flowaccuFile.get_var("TNNaccumulation");
 	if(flowaccuV==NULL){
 	   string msg = "Cannot get distance  in .nc file";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_NOT_EXIST);
 	}
 	flowaccuV->set_cur(grdidrec);
 	flowaccuV->get(&fileflowaccu, 1);

 	flowaccuFile.close();


  	//get lake dominate
	//******************************flow accu
 	Filelakedominate = dir + "data/input/" + "Lake_dominate4.nc";

	NcFile lakedominateFile(Filelakedominate.c_str(), NcFile::ReadOnly);
 	if(!lakedominateFile.is_valid()){
 		string msg = Fileflowaccu +" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}

  	//get the value
 	NcVar*  lakedominateV = lakedominateFile.get_var("TNN_lake_dominate");
 	if(lakedominateV==NULL){
 	   string msg = "Cannot get distance  in .nc file";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_NOT_EXIST);
 	}
 	lakedominateV->set_cur(grdidrec);
 	lakedominateV->get(&filelakedominate, 1);

 	lakedominateFile.close();

};


void LakeDataInputer::getLakeProb(){

	//pay attention to nodata value -2147483648
	double yr_dori;
	double yr_sori;

	double x1std;
	double x4std;
	double x5std;
	double x7std;

	double x1,x2rck,x2snd,x3,x4,x5,x6,x7,x8;
	x1 = -9999;
	x2rck = -9999;
	x2snd = -9999;
	x3 = -9999;
	x4 = -9999;
	x5 = -9999;
	x6 = -9999;
	x7 = -9999;
	x8 = -9999;

	//cout<<"++++++++++fileavgsize = "<<fileavgsize<<endl;
	//getchar();

	if (filelakedominate > 0){	//lake dominating

		x1=log(fileavgsize*1000000);	//km2 into m2
		x2rck=filerocky;
		x2snd=filesandy;
		x3=filedeposit;
		x4=filersds;	//pay attention to inf data
		x5=sqrt(filedist);
		x6=filefire8599;
		x8=filefire0009;

		if (filedem > 0){
			x7=log(filedem + 1);
		}else{		//no lake area
			cout<<"Checking the dem input"<<endl;
			return;
		}

//		x7=filedem;
/*
 *
		x7=filedem;
		cout<<"111111111111"<<endl;
 */

/*

		cout<<"x1 = "<<x1<<endl;
		cout<<"x2rck = "<<x2rck<<endl;
		cout<<"x2snd = "<<x2snd<<endl;
		cout<<"x3 = "<<x3<<endl;
		cout<<"x4 = "<<x4<<endl;
		cout<<"x5 = "<<x5<<endl;
		cout<<"x6 = "<<x6<<endl;
		cout<<"x7 = "<<x7<<endl;
		cout<<"x8 = "<<x8<<endl;
	getchar();
*/


		x1std=(x1-10.028933)/1.364491;
		x4std=(x4-501.219146)/25.0308118;
		x5std=(x5-95.3468537)/42.3370996;
		x7std=(x7-4.0063469)/1.0679023;

		yr_dori = 1.3871 + 0.489*x1std + 0.1151*x2rck + 0.314*x2snd + 0.3034*x3 + 0.3678*x4std + 0.06376*x5std - 0.9167*x6 + 0.1429*x7std - 0.1982*x8;

		yr_sori = 0.03774 + 1.048*x1std - 0.399*x2rck - 0.2645*x2snd + 0.2067*x3 + 0.2101*x4std + 0.1505*x5std - 0.1681*x6 - 0.01187*x7std + 0.1575*x8;


		probd = exp(yr_dori)/(exp(yr_dori) + exp(yr_sori) + 1);
		probs = exp(yr_sori)/(exp(yr_dori) + exp(yr_sori) + 1);
		probi = 1/(exp(yr_dori) + exp(yr_sori) + 1);

		//calculating rate for lake
		getLakeRates();


	}else{		//no lake area

		//cout<<"no lake within the grid! returning"<<endl;
		return;
	}

};


void LakeDataInputer::getLakeRates(){

	if (probd>probs && probd>probi){
		getLakeRates4Decrs();

	}else if (probs<probi && probd<probi){
		getLakeRates4Incrs();

	}else{

		cout<<"the lake is stable"<<endl;
	}

};


void LakeDataInputer::getLakeRates4Decrs(){

	cout<<"+++++++++++++++++++++ lake decreasing!"<<endl;

	iodata.rate9_LK2Fen = -9999;

	//pay attention to unavailable data -2147483648
	//rate of decreasing
	double x1,x2rck,x2snd,x3,x4,x5;
	double x1std;
	double x4std;
	double x5std;
	double yr_d;
	double rate;

	x1 = -9999;
	x2rck = -9999;
	x2snd = -9999;
	x3 = -9999;
	x4 = -9999;
	x5 = -9999;
	x1std = -9999;
	x4std = -9999;
	x5std = -9999;

	yr_d = -9999;
	rate = -9999;

	//cout<<"---------------filettlarea = "<<filettlarea<<endl;
	//getchar();

	if (filettlarea > 0){
		x1=log(filettlarea);
		x2rck=filerocky;
		x2snd=filesandy;
		x3=filefire8599;
		x4=filersds;
		x5=sqrt(filedist);

		x1std=(x1-10.4650266)/1.3070208;
		x4std=(x4-4.3973904)/1.0639228;
		x5std=(x5-95.2774584)/43.9385251;


		cout<<"x1 = "<<x1<<endl;
		cout<<"x2rck = "<<x2rck<<endl;
		cout<<"x2snd = "<<x2snd<<endl;
		cout<<"x3 = "<<x3<<endl;
		cout<<"x4 = "<<x4<<endl;
		cout<<"x5 = "<<x5<<endl;
		cout<<"x1std = "<<x1std<<endl;
		cout<<"x4std = "<<x4std<<endl;
		cout<<"x5std = "<<x5std<<endl;
		//getchar();


		yr_d = 0.6751 - 0.1026*x1std + 0.3094*x2rck + 0.2357*x2snd -0.2109*x3 + 0.1285*x4std - 0.08403*x5std;
		rate = -exp(yr_d);

		cout<<"yr_d = "<<yr_d<<endl;
		cout<<"rate = "<<rate<<endl;

		//rate of decreasing
		iodata.rate9_LK2Fen = rate;

		cout<<"iodata.rate9_LK2Fen = "<<iodata.rate9_LK2Fen<<endl;
		//getchar();


	}else{		//no lake area

		//cout<<"no lake decreasing within the grid!"<<endl;
		return;
	}


};


void LakeDataInputer::getLakeRates4Incrs(){

	cout<<"+++++++++++++++++++++ lake increasing!"<<endl;
	iodata.rate9_Deci2LK = -9999;

	//pay attention to unavailable data -2147483648
	//rate of increasing
	double x1,x2rck,x2snd,x3;
	double x1std;
	double x3std;
	double yr_i;
	double rate;

	x1 = -9999;
	x2rck = -9999;
	x2snd = -9999;
	x3 = -9999;
	x1std = -9999;
	x3std = -9999;
	yr_i = -9999;
	rate = -9999;

	if (filettlarea > 0){
		x1=log(filettlarea);
	}else{		//no lake area
		cout<<"no lake increasing within the grid!"<<endl;
		return;
	}

	x2rck=filerocky;
	x2snd=filesandy;
	x3=fileflowaccu;

	x1std=(x1-9.873801)/1.5623771;
	x3std=(x3-2.3887873)/2.4007176;

	yr_i = 0.3912 - 0.2765*x1std + 0.1534*x2rck + 0.08664*x2snd + 0.0463*x3;
	rate = exp(yr_i);

/*
	cout<<"x1 = "<<x1<<endl;
	cout<<"x2rck = "<<x2rck<<endl;
	cout<<"x2snd = "<<x2snd<<endl;
	cout<<"x3 = "<<x3<<endl;

	cout<<"x1std = "<<x1std<<endl;
	cout<<"x3std = "<<x3std<<endl;

	cout<<"yr_i = "<<yr_i<<endl;
	cout<<"rate = "<<rate<<endl;
*/

	//rate of increasing
	iodata.rate9_Deci2LK = rate;

	//cout<<"iodata.rate9_Deci2LK = "<<iodata.rate9_Deci2LK<<endl;
	//getchar();


};


int LakeDataInputer::getNumVals(string dir){

/*
	Filename = dir + "data/input/" + "TNNinichtNEW.nc";

	NcError err(NcError::silent_nonfatal);
	NcFile grdFile(Filename.c_str(), NcFile::ReadOnly);
 	if(!grdFile.is_valid()){
 		string msg = Filename +" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}

 	NcVar* grdidV = grdFile.get_var("gridid");
 	if(grdidV==NULL){
 	   string msg = "Cannot get grdid  in TNNinichtNEW.nc ";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_NOT_EXIST);
 	}

   	long n = (int)grdidV->num_vals();

  	grdFile.close();

   	return n;
*/

};

int LakeDataInputer::getInitGrdRecID(string dir, int grdid, int irec){

/*	NcError err(NcError::silent_nonfatal);

	Filename = dir + "data/input/" + "TNNinichtNEW.nc";

	NcFile grdFile(Filename.c_str(), NcFile::ReadOnly);
 	NcVar* grdidV = grdFile.get_var("gridid");
 	if(grdidV==NULL){
 	   string msg = "Cannot get grdid  in TNNinichtNEW.nc ";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_NOT_EXIST);
 	}

 	int id = -1;
	grdidV->set_cur(irec);	//using irec from outside to control the variable record
	grdidV->get(&id, 1);

	//grdFile.close();

	if(id == grdid)
		return irec;

	return -1;
	*/
};


int LakeDataInputer::getNumValsRec(string dir, int grid, int year){

/*
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
 	   string msg = "Cannot get grdid  in TNNinichtNEW.nc ";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_NOT_EXIST);
 	}

   	long n = (int)grdidV->num_vals();

  	grdFile.close();

   	return n;
*/

};




int LakeDataInputer::getGrdRecID(string dir, int grdid, int year, int irec){

/*	NcError err(NcError::silent_nonfatal);

	stringstream ss_Grdid;
	string s_Grdid;
	stringstream ss_Year;
	string s_Year;

	ss_Grdid << grdid;
	s_Grdid = ss_Grdid.str();
   	//cout<<"s_Grdid is "<<s_Grdid<<endl;

   	ss_Year << year-1;
   	s_Year = ss_Year.str();
   	//cout<<"s_Year is "<<s_Year<<endl;

	string chtFilename = dir + "g" + s_Grdid + "y" + s_Year + ".nc";

	NcFile grdFile(chtFilename.c_str(), NcFile::ReadOnly);
 	NcVar* grdidV = grdFile.get_var("gridid");
 	if(grdidV==NULL){
 	   string msg = "Cannot get grdid  in TNNinichtNEW.nc ";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_NOT_EXIST);
 	}

 	int id = -1;
	grdidV->set_cur(irec);
	grdidV->get(&id, 1);
	if(id == grdid)
		return irec;

	return -1;
	*/
};

long LakeDataInputer::InitMaxChtId(){

/*
	NcError err(NcError::silent_nonfatal);

	Filename = "./data/input/TNNinichtNEW.nc";

 	NcFile chtFile(Filename.c_str(), NcFile::ReadOnly);
 	NcVar* chtidV = chtFile.get_var("cohortid");
 	if(chtidV==NULL){
 	   string msg = "Cannot get grdid  in TNNinichtNEW.nc ";
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
*/

};
