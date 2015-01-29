/*
 * BorealDataInputer.cpp
 *
 */

#include "BorealDataInputer.h"

BorealDataInputer::BorealDataInputer(){

};

BorealDataInputer::~BorealDataInputer(){

};

void BorealDataInputer::InitGridBDfstyr(string dir){

	//initializing cohortlist for first year, year 1.
	cohortlist = NULL;

};


void BorealDataInputer::getTransitionRates(double ttlforestarea, Nodes* cohortlist){

	double frsarea=ttlforestarea;
	double frsedge=0;
	//double frsedge1978=0;
	double chgyrlyarea=0;
	double chgdeci=0;
	double chgspruce=0;

/*
	//list the list data
	Nodes* plist = new Nodes;
	plist = cohortlist;
	//int num=1;

	while (plist != NULL ){

			cout<<endl<<"		cht num.= "<<num<<endl
				<<"plist->grdID = "<<pllist1->grdID<<endl
				<<"cohortid = "<<pllist1->cohortid<<endl
				<<"vegtype = ================ "<<pllist1->vegtype<<endl
				<<"age = "<<pllist1->age<<endl
				<<"proportion = "<<pllist1->proportion<<endl
				<<"flag = "<<pllist1->flag<<endl;

		if (plist->vegtype == 3 || plist->vegtype == 4 || plist->vegtype == 5){

			frsarea += plist->proportion;
		}


		plist = plist->pNext;
		//num +=1;
	}

*/


	//cout<<"Final ++++++++++++++++++++++ cohort num = "<<num-1<<endl; iodptr
	//getchar();

	if (frsarea<0)
		frsarea = 0;
	frsedge = 37914* pow(frsarea, 0.673);

	chgyrlyarea = 0.000001*frsedge -0.031917;
	if (chgyrlyarea < 0){
		chgdeci = sin(-29.41779*chgyrlyarea + 0.7388293);	//new relationship from Mark
		chgspruce = 1 - chgdeci;
	}else{
		chgdeci = 0;		//??, or 0.0057143, or no transitions?
		chgspruce = 0;		//??
	}

	iodata.rate4_B2Fen = chgspruce;
	iodata.rate5_D2Fen = chgdeci;

	//cout<<"in bd, iodata.rate5_D2Fen = "<<iodata.rate5_D2Fen<<endl;
	//cout<<"in bd, iodata.rate4_B2Fen = "<<iodata.rate4_B2Fen<<endl;
//getchar();



/*

	cout<<"frsedge = "<<frsedge<<endl;
	cout<<"chgyrlyarea = "<<chgyrlyarea<<endl;
	cout<<"chgdeci = "<<chgdeci<<endl;
	cout<<"chgspruce = "<<chgspruce<<endl;
*/

//getchar();

};


double BorealDataInputer::getTtlForestArea(string dir, int grdid, int ttlrec){

	double ttlforestarea = -9999;

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
 	   string msg = "Cannot get grdid  in TNNinitialCHT ";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_NOT_EXIST);
 	}

	//get one cht for the current gridid (rec=0-1000)
	int irec = 0;
	while(irec < ttlrec){

		//data for area calculating
		iodata4area.initlz();

		NcVar* grididV = grdFile.get_var("gridid");
 		if(grididV==NULL){
 		  cout <<"cannot get grididV\n";
 		}
 		grididV->set_cur(irec);
 		grididV->get(&iodata4area.ingrdid,1);

 		//////////////////////////////////
 		NcVar* inichtidV = grdFile.get_var("cohortid");
 		if(inichtidV==NULL){
 		  cout <<"cannot get inichtidV in inichtid.nc\n";
 		}

 		inichtidV->set_cur(irec);
 		inichtidV->get(&iodata4area.incohortid,1);

 		//////////////

 		NcVar* vegtypeV = grdFile.get_var("vegtype");
 		if(vegtypeV==NULL){
 		  cout <<"cannot get vegtypeV in inichtid.nc\n";
 		}
 		vegtypeV->set_cur(irec);
 		vegtypeV->get(&iodata4area.invegtype,1);

 		//////////////

 		NcVar* ageV = grdFile.get_var("age");
 		if(ageV==NULL){
 		  cout <<"cannot get ageV in inichtid.nc\n";
 		}
 		ageV->set_cur(irec);
 		ageV->get(&iodata4area.inage,1);

 		//////////////
 		NcVar* proportionV = grdFile.get_var("proportion");
 		if(proportionV==NULL){
 		  cout <<"cannot get proportionV in inichtid.nc\n";
 		}
 		proportionV->set_cur(irec);
 		proportionV->get(&iodata4area.inproportion,1);

 		//////////////
 		NcVar* flagV = grdFile.get_var("flag");
 		if(flagV==NULL){
 		  cout <<"cannot get flagV in inichtid.nc\n";
 		}
 		flagV->set_cur(irec);
 		flagV->get(&iodata4area.inflag,1);

 		//total forest area within grdid
 		if (iodata4area.ingrdid == grdid){

			if (iodata4area.invegtype==3 || iodata4area.invegtype==4 || iodata4area.invegtype==5 ){

				ttlforestarea += iodata4area.inproportion;
			}

 		}

		irec +=1;
	}

  	grdFile.close();
	return ttlforestarea;


};

void BorealDataInputer::getGridBDfstyr(IOdata* ioptr){

	//create a node dynamically and add it to existing chtlist;

	//cout<<"bf insert() cohortlist = "<<cohortlist<<endl;

	//cout<<"111 = "<<cohortlist<<endl;
	cohortlist = dlist.InsertNodeBefore(cohortlist, ioptr);

	//cout<<"af insert() cohortlist = "<<cohortlist<<endl;

/*

	//list the list data
	Nodes* pllist1 = new Nodes;
	pllist1 = cohortlist;
	int number=1;

	while (pllist1 != NULL ){
			cout<<"				insert	cht number.= "<<number<<endl
				<<"plist->grdID = "<<pllist1->grdID<<endl
				<<"cohortid = "<<pllist1->cohortid<<endl
				<<"vegtype = ================ "<<pllist1->vegtype<<endl
				<<"age = "<<pllist1->age<<endl
				<<"proportion = "<<pllist1->proportion<<endl
				<<"flag = "<<pllist1->flag<<endl;

			pllist1 = pllist1->pNext;
			number +=1;
	}

	cout<<"					after insert(), total number = "<<number-1<<endl;

	getchar();

*/


};


int BorealDataInputer::getNumVals(string dir){

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

int BorealDataInputer::getInitGrdRecID(string dir, int grdid, int irec){

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


int BorealDataInputer::getNumValsRec(string dir, int grid, int year){

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




int BorealDataInputer::getGrdRecID(string dir, int grdid, int year, int irec){

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

long BorealDataInputer::InitMaxChtId(){

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

	return max; iodptr
*/

};

void BorealDataInputer::InitGridiodata(){




};
