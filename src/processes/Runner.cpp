/*
 * Runner.cpp
 *
 *  Created on: Jul 25, 2013
 *      Author: yujin_admin
 */

#include "./Runner.h"

Runner::Runner(){

};

Runner::~Runner(){

};


void Runner::InitInputFile(string & dirfile){   //check all model intput files to make sure they are correct

		///////////////////////////////////////////open and check for inputting giv data

		string dir4givfile = dirfile + "data/griddata/" + "TNNgiv.nc";

		NcFile givfile(dir4givfile.c_str(), NcFile::ReadOnly);


	 	if(!givfile.is_valid()){
	 		string msg = dir4givfile + " is not valid";
	 		char* msgc = const_cast< char* > ( msg.c_str());
	 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
	 	}

		NcDim* givD = givfile.get_dim("GRDID");
		if(!givD->is_valid()){
			string msg = "The Dimension for giv is not Valid in TNNgiv";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		givfile.close();

		///////////////////////////////////////////open and check for inputting permafrost data

		string dir4frostfile;
		dir4frostfile = dirfile +  "data/griddata/" + "TNNfrost.nc";

		NcFile frostfile(dir4frostfile.c_str(), NcFile::ReadOnly);

		if(!frostfile.is_valid()){
			string msg = dir4frostfile + " is not valid";
			char* msgc = const_cast< char* > ( msg.c_str());
			throw Exception( msgc, I_NCFILE_NOT_EXIST);
		}


		NcDim* frostD = frostfile.get_dim("GRDID");
		if(!frostD->is_valid()){
			string msg = "The Dimension for frost is not Valid in TNNfrost";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		frostfile.close();

		///////////////////////////////////////////open and check for inputting cohortid data

		string dir4cohortidfile;
		dir4cohortidfile = dirfile +  "data/griddata/" + "TNNcohortid.nc";

		NcFile cohortidfile(dir4cohortidfile.c_str(), NcFile::ReadOnly);
		//cout<<"cohortidfile.is_valid() = "<<cohortidfile.is_valid()<<endl;

		if(!cohortidfile.is_valid()){
			string msg = dir4cohortidfile + " is not valid";
			char* msgc = const_cast< char* > ( msg.c_str());
			throw Exception( msgc, I_NCFILE_NOT_EXIST);
		}

		NcDim* cohortidD = cohortidfile.get_dim("GRDID");
		if(!cohortidD->is_valid()){
			string msg = "The Dimension for cohortid is not Valid in TNNcohortid";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}
		cohortidfile.close();

		///////////////////////////////////////////open and check for inputting inicht data

		string dir4inichtfile;
		dir4inichtfile = dirfile +  "data/griddata/" + "TNNinicht.nc";

		NcFile inichtfile(dir4inichtfile.c_str(), NcFile::ReadOnly);

		if(!inichtfile.is_valid()){
			string msg = dir4inichtfile + " is not valid";
			char* msgc = const_cast< char* > ( msg.c_str());
			throw Exception( msgc, I_NCFILE_NOT_EXIST);
		}

		NcDim* inichtD = inichtfile.get_dim("TOTALCHTS");
		if(!inichtD->is_valid()){
			string msg = "The Dimension for inicht is not Valid in TNNinicht";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		inichtfile.close();

		///////////////////////////////////////////open and check for inputting lowland data

		string dir4lowlandfile;
		dir4lowlandfile = dirfile +  "data/griddata/" + "TNNlowlandnew.nc";


		NcFile lowlandfile(dir4lowlandfile.c_str(), NcFile::ReadOnly);
		if(!lowlandfile.is_valid()){
			string msg = dir4lowlandfile + " is not valid";
			char* msgc = const_cast< char* > ( msg.c_str());
			throw Exception( msgc, I_NCFILE_NOT_EXIST);
		}

		NcDim* lowlandD = lowlandfile.get_dim("GRDID");
		if(!lowlandD->is_valid()){
			string msg = "The Dimension for lowland is not Valid in TNNlowland";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		lowlandfile.close();

		//cout<<"done 5"<<endl;


		///////////////////////////////////////////open and check for inputting wetland data flag
		string dir4wetlandfile;
		dir4wetlandfile = dirfile +  "data/griddata/" + "TNNwetland.nc";

		NcFile wetlandfile(dir4wetlandfile.c_str(), NcFile::ReadOnly);

		if(!wetlandfile.is_valid()){
			string msg = dir4wetlandfile + " is not valid";
			char* msgc = const_cast< char* > ( msg.c_str());
			throw Exception( msgc, I_NCFILE_NOT_EXIST);
		}

		NcDim* wetlandD = wetlandfile.get_dim("GRDID");
		if(!wetlandD->is_valid()){
			string msg = "The Dimension for wetland is not Valid in TNNwetland";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		wetlandfile.close();


};

void Runner::Run(IOdata* ptr, string dir){

	//setup the year loop

	string dir4files;
	string filedir;

	dir4files = dir;

	//cout<<"	dir4files = "<<	dir4files<<endl;

	int year;
	int ystart = 2009;
	int yend = 2100;

	int yrec = 0; //record id of the output year dim in 'propoutT1.nc'
	int ChtRec;	//record of cohort input

	IOdata* pt;
	pt = ptr; // the pointer with function Run()

	Predisposition pred;
	//initializing the output file
	pred.InitiPred(dir4files);
	//setup the data pointer
	pred.SetPointer(pt);		//using the pointer to predisposing factors initializing

	BorealDataInputer bd;
	LakeDataInputer ld;

	Thermokarst thmkst;
	thmkst.SetPointer(pt);
	//pass &bd &ld to thmkst
	thmkst.SetPointer(&bd, &ld);

	Dlist dlist;

	ChtInputer chtin;
	Outputer outputr;

	DelFile delfile;

	//check input dataset in NetCDF files.
	InitInputFile(dir4files);

	ProcCht proccht;	//output cht
	proccht.SetPointer(pt);		//using the pointer to initial cohorts data in iodata

	ChtProp chtprop;
	//define output files
	chtprop.outpLatlont3(dir4files);
	chtprop.outpLatlont4(dir4files);
	chtprop.outpLatlont5(dir4files);
	chtprop.outpLatlont1(dir4files);
	chtprop.outpLatlont2(dir4files);
	chtprop.outpLatlont9(dir4files);
	chtprop.outpLatlont10(dir4files);

	////total amount of grid cells to run

	int ttlGrdCnt =2639;

	////////////////////////////////////////////////////
	CreateFlder crtfld;
	for(int grdid=1; grdid < ttlGrdCnt+1; grdid++){

		crtfld.Createflder(dir,grdid);
	}

	///////loop through years

	year = ystart;
	bool bthmkst = 0;

	string s_Dir;

	stringstream ss_Dir;

	long maxchtid = chtin.InitMaxChtId();	//compute the max cohort id in the initial landcover in order to track change in the cohort ID for the whole region
											//so the data set "TNNFlatsInichtAGU.nc" must be included. (need to modify the code later)

	////////////////////////////////////////////////////

	while ( year <= yend){   //loop through years

		////////////////////////////////////////////////////
		//loop through grid cells
		int grdid = 1;
		int xDid=0;	//Dim in the output netcdf files of the output of proportion of each cohort
		int yDid=0;

		int ttlRecnum=0;		//amount of the records for the current landcover file
		double ttlForestArea = 0;	//total area of forest within the current grid

		while (grdid <= ttlGrdCnt){   //loop through grids

				/////// specify the location of initial landcover input file

				if (grdid >= 1 && grdid <= 100){
					filedir = dir + "data/input/" + "TNNCHTSAGU100.nc";

				}else if(grdid >= 101 && grdid <= 200){
					filedir = dir + "data/input/" + "TNNCHTSAGU200.nc";

				}else if(grdid >= 201 && grdid <= 300){
					filedir = dir + "data/input/" + "TNNCHTSAGU300.nc";

				}else if(grdid >= 301 && grdid <= 400){
					filedir = dir + "data/input/" + "TNNCHTSAGU400.nc";

				}else if(grdid >= 401 && grdid <= 500){
					filedir = dir + "data/input/" + "TNNCHTSAGU500.nc";

				}else if(grdid >= 501 && grdid <= 600){
					filedir = dir + "data/input/" + "TNNCHTSAGU600.nc";

				}else if(grdid >= 601 && grdid <= 700){
					filedir = dir + "data/input/" + "TNNCHTSAGU700.nc";

				}else if(grdid >= 701 && grdid <= 800){
					filedir = dir + "data/input/" + "TNNCHTSAGU800.nc";

				}else if(grdid >= 801 && grdid <= 900){
					filedir = dir + "data/input/" + "TNNCHTSAGU900.nc";

				}else if(grdid >= 901 && grdid <= 1000){
					filedir = dir + "data/input/" + "TNNCHTSAGU1000.nc";

				}else if(grdid >= 1001 && grdid <= 1100){
					filedir = dir + "data/input/" + "TNNCHTSAGU1100.nc";

				}else if(grdid >= 1101 && grdid <= 1200){
					filedir = dir + "data/input/" + "TNNCHTSAGU1200.nc";

				}else if(grdid >= 1201 && grdid <= 1300){
					filedir = dir + "data/input/" + "TNNCHTSAGU1300.nc";

				}else if(grdid >= 1301 && grdid <= 1400){
					filedir = dir + "data/input/" + "TNNCHTSAGU1400.nc";

				}else if(grdid >= 1401 && grdid <= 1500){
					filedir = dir + "data/input/" + "TNNCHTSAGU1500.nc";

				}else if(grdid >= 1501 && grdid <= 1600){
					filedir = dir + "data/input/" + "TNNCHTSAGU1600.nc";

				}else if(grdid >= 1601 && grdid <= 1700){
					filedir = dir + "data/input/" + "TNNCHTSAGU1700.nc";

				}else if(grdid >= 1701 && grdid <= 1800){
					filedir = dir + "data/input/" + "TNNCHTSAGU1800.nc";

				}else if(grdid >= 1801 && grdid <= 1900){
					filedir = dir + "data/input/" + "TNNCHTSAGU1900.nc";

				}else if(grdid >= 1901 && grdid <= 2000){
					filedir = dir + "data/input/" + "TNNCHTSAGU2000.nc";

				}else if(grdid >= 2001 && grdid <= 2100){
					filedir = dir + "data/input/" + "TNNCHTSAGU2100.nc";

				}else if(grdid >= 2101 && grdid <= 2200){
					filedir = dir + "data/input/" + "TNNCHTSAGU2200.nc";

				}else if(grdid >= 2201 && grdid <= 2300){
					filedir = dir + "data/input/" + "TNNCHTSAGU2300.nc";

				}else if(grdid >= 2301 && grdid <= 2400){
					filedir = dir + "data/input/" + "TNNCHTSAGU2400.nc";

				}else if(grdid >= 2401 && grdid <= 2500){
					filedir = dir + "data/input/" + "TNNCHTSAGU2500.nc";

				}else if(grdid >= 2501 && grdid <= 2639){
					filedir = dir + "data/input/" + "TNNCHTSAGU2639.nc";

				}



				//////////initializing input files only one time when running for the first grid cell using "filedir"
				if (grdid == 1){
					chtin.InitChtFile(filedir);
				}

				////initializing output cht file for current grid cell
				ss_Dir.str("");
				ss_Dir << grdid;
				s_Dir = dir4files + "data/output/G" + ss_Dir.str() + "/";

				outputr.InitOutputCht(s_Dir,grdid,year);	//initializing for output cht file
				//cout<<"11111111___11 current grid s_Dir = "<<s_Dir<<endl;

				chtprop.initVals();

				Nodes* grdchtlist = new Nodes;
				grdchtlist = NULL;		//define linkied-list for the cohorts in the current grid, only 10 cohorts each year, because newly-initiated cohorts will be integrate to existing ones

				//if year = ystart, read data for current 'grdid' from the "filedir";
				//else, read from previous year output in folder for the current grid cell in current year
				if ( year == ystart){

					////initializing cohortlist and input file
					bd.InitGridBDfstyr(dir4files);
					////initializing iodata in bd,ld
					bd.iodata.initlz();
					ld.iodata.initlz();

					//cal lake transition rates for current grid
					ld.getLake(dir4files, grdid);
					ld.getLakeProb();

					///////////////
					ttlRecnum = chtin.getNumVals(filedir);   //amount of the records for the current landcover file

					//cal total forest area for current grid using ttlRecnum
					ttlForestArea = bd.getTtlForestArea(filedir, grdid, ttlRecnum);		//total area of forest within the current grid
					//bd.getTransitionRates(ttlforestarea, curchtlist);

					////////////////////////////////////////////////////
					//loop through all cohorts within a particular grid cell
					int irec = 0;	//read one cht each time, start from the first record id to look for the cohort within the current grid cell ttlnum
					while(irec < ttlRecnum){	//get one cht for the current gridid (rec=0-1000)

							ChtRec = chtin.getInitChtRecID(filedir, grdid, irec);

							if (ChtRec >= 0){

									proccht.GetCht(filedir, ChtRec);	//get one cht based on the current Rec to pt

									//get all cohort within current grid
									//get boreal data

									//cout<<"pt = "<<pt<<endl;
									bd.getGridBDfstyr(pt);    //add one cohort before the cohort list in bd;//add current IODATA ioptr to the current list nptr;

									//insert pt into cohort list
									Nodes* curchtlist = new Nodes;
									curchtlist = NULL;
									curchtlist = dlist.InsertNodeBefore(curchtlist, pt);		//insert only one cohort

									//cal rates for the current cohort, put in iodata in bd
									bd.getTransitionRates(ttlForestArea, curchtlist);
									//switch for thmkst initiation
									if(year % 1 == 0){

										bthmkst = 1;
									}else{

										bthmkst = 0;
									}

									//loop through the current chtlist to examine if a new cohort is initiated, add it to newlist in each year.
									if(bthmkst == 1){

										Nodes* newchtlist = new Nodes;
										newchtlist = NULL;

										newchtlist = thmkst.Initiation(newchtlist, curchtlist, grdchtlist, maxchtid);
										//cout<<"+++++++++++++++++++++++++  after Initiation in  "<<year<<endl;

										/////////////////////////////////////////////////////////////////////////
										//if newchtlist is not NULL, combine the newlist to curchtlist, other wise pass by
										if (newchtlist != NULL){
											curchtlist = thmkst.ChtCombin(curchtlist, newchtlist);
										}

										//combine curchtlist to grdchtlist
										if (grdchtlist != NULL){

												//loop through curchtlist cht by cht to see if there is the same vegtype as in the existing grdchtlist
												Nodes* list = new Nodes;
												list = curchtlist;
												int num=0;
												//cout<<"===============================================   loopin through curchtlist "<<endl;
												while ( list != NULL ){


														bool blexist=false;
														//cout<<endl<<"11 blexist = "<<blexist<<endl;

														blexist=thmkst.Flagexit(grdchtlist, list);

														//cout<<endl<<"22  blexist = "<<blexist<<endl;

														if (blexist==true){
															//add area to existing cohort
															//cout<<endl<<"add area to existing cohort"<<endl;

															//list the list data
															Nodes* pllist1 = new Nodes;
															pllist1 = grdchtlist;
															int No=0;

															//merge new to old
															thmkst.AggregationProp(grdchtlist, list);

														}else{//insert list to grdlist

															//cout<<endl<<"insert list to grdlist"<<endl;

															grdchtlist=thmkst.ChtCombinInsert(grdchtlist,list);

														}

														list = list->pNext;
														num +=1;
												}

										}else{//if grdchtlist==null, combine  curchtlist directly to grdlist,

												//cout<<endl<<"grdlist  cht=9          1000     22"<<endl;

												grdchtlist=thmkst.ChtCombin(grdchtlist,curchtlist);

										}

									}else{

										//cout<<"The year is not an initiation year."<<endl;

									}

									//After a year, add 1 to all old and new cohorts ages previous grdchtlist
									grdchtlist = thmkst.AddChtAge(grdchtlist);

							}//endofif

							irec += 1;

					}//end of cohort loop


					//outputting results to particular folder
					long tRecid = 0;	//total recordid for control of record of output file

					Nodes* plist = new Nodes;
					plist = NULL;
					plist = grdchtlist;
					while(plist != NULL){

						outputr.OutputCht(s_Dir, grdid, year, plist, tRecid);
						tRecid +=1;

						plist = plist->pNext;

						//getchar();
					}

					//calculating total proportion of each cohorts
					chtprop.calChtProps(grdchtlist);


					/////output cohort proportions within the current grid cell for the first year
					chtprop.outpPropt3(yrec, year, grdid);
					chtprop.outpPropt4(yrec, year, grdid);
					chtprop.outpPropt5(yrec, year, grdid);
					chtprop.outpPropt1(yrec, year, grdid);
					chtprop.outpPropt2(yrec, year, grdid);
					chtprop.outpPropt9(yrec, year, grdid);
					chtprop.outpPropt10(yrec, year, grdid);


					//////////////////////////////////
					//close output files and move to the next grid
					pred.PredFile->close();
					outputr.ChtFile->close();

					cout<<"grid = "<<grdid<<" year done = "<<year<<endl;


				}else if( year > ystart){

					cout<<"=============================================	year = "<<year<<"	grid = "<<grdid<<endl;
					//getchar();

					//get the num_vales of variable gridid in ".nc"
					int ttlRecnum = chtin.getNumValsRec(s_Dir, grdid, year);

					//cout<<endl<<"10004"<<endl;

					chtin.InitChtFile(s_Dir,grdid,year);

					////initializing cohortlist and input file
					bd.InitGridBDfstyr(s_Dir);

					////initializing iodata in bd,ld
					bd.iodata.initlz();
					ld.iodata.initlz();

					//cal lake transition rates for current grid
					ld.getLake(dir4files, grdid);
					ld.getLakeProb();

					////////////////////////////////////////////////////
					//loop through all cohorts within a particular gridgrid cell
					int irec = 0;	//start from the first record id

					while(irec < ttlRecnum){	//start from 0 till ttlRecnum

						//get the cht rec id and data from previous .nc and return the rec when gididv=grdid and move on to next rec which meets the if condition

						ChtRec = chtin.getGrdRecID(s_Dir, grdid, year, irec);

						if (ChtRec >= 0){

								proccht.GetCht(s_Dir, grdid, year, irec);  //proccht class, read data into IODATA

								//cout<<"pt = "<<pt<<endl;
								bd.getGridBDfstyr(pt);    //add one cohort before the cohort list in bd;

								Nodes* curchtlist = new Nodes;
								curchtlist = NULL;
								curchtlist = dlist.InsertNodeBefore(curchtlist, pt);

								//cal rates
								bd.getTransitionRates(ttlRecnum, curchtlist);


								if(year % 1 == 0){

									bthmkst = 1;
								}
								else{

									bthmkst = 0;
								}

								//loop through the current chtlist to examine if a new cohort is initiated, add it to newlist in each year.
								if(bthmkst == 1){

									Nodes* newchtlist = new Nodes;
									newchtlist = NULL;

									//cout<<endl<<"1000  21"<<endl;

									newchtlist = thmkst.Initiation(newchtlist, curchtlist, grdchtlist, maxchtid);


									/////////////////////////////////////////////////////////////////////////
									//if newchtlist is not NULL, combine the newlist to curchtlist,other wise pass by
									if (newchtlist != NULL)
										curchtlist = thmkst.ChtCombin(curchtlist, newchtlist);

									//loop through curchtlist cht by cht to see if there is the same vegtype as in the existing grdchtlist
									if (grdchtlist != NULL){

												//loop through curchtlist cht by cht to see if there is the same vegtype as in the existing grdchtlist
												Nodes* list = new Nodes;
												list = curchtlist;
												int num=0;
												//cout<<"===============================================   loopin through curchtlist "<<endl;
												while ( list != NULL ){

														bool blexist=false;
														//cout<<endl<<"11 blexist = "<<blexist<<endl;

														blexist=thmkst.Flagexit(grdchtlist, list);

														//cout<<endl<<"22  blexist = "<<blexist<<endl;

														if (blexist==true){
															//add area to existing cohort
															//cout<<endl<<"add area to existing cohort"<<endl;

															//list the list data
															Nodes* pllist1 = new Nodes;
															pllist1 = grdchtlist;

															//merge new cht to old cht
															thmkst.AggregationProp(grdchtlist, list);


														}else{//insert list to grdlist

															//cout<<endl<<"insert list to grdlist"<<endl;

															grdchtlist=thmkst.ChtCombinInsert(grdchtlist,list);


														}

														list = list->pNext;
														num +=1;
												}

										}else{//if grdchtlist==null, combine  curchtlist directly to grdlist,

												//cout<<endl<<"grdlist  cht=9          1000     22"<<endl;

												grdchtlist=thmkst.ChtCombin(grdchtlist,curchtlist);

										}


								}else{

									//cout<<"The year is not an initiation year."<<endl;

								}

								//After a year, add 1 to all old and new cohorts ages initializing for new cht file done
								grdchtlist = thmkst.AddChtAge(grdchtlist);

						}else{

								//cout<<"The Rec id is not the one needed"<<endl;
						}

						irec += 1;		//move to next cohort rec


					}//end of cohort loops

					//output the result of current cht and move on to the next
					long tRec = 0;	//control of record of output file

					Nodes* plist = new Nodes;
					plist = grdchtlist;
					while(plist != NULL){

						outputr.OutputCht(s_Dir, grdid, year, plist, tRec);
						plist = plist->pNext;

						tRec +=1;
					}

					//calculating only proportion of each cohort
					chtprop.calChtProps(grdchtlist);


					/////output cohort proportions within the current grid cell after the first year
					chtprop.outpPropt3(yrec, year, grdid);
					chtprop.outpPropt4(yrec, year, grdid);
					chtprop.outpPropt5(yrec, year, grdid);
					chtprop.outpPropt1(yrec, year, grdid);
					chtprop.outpPropt2(yrec, year, grdid);
					chtprop.outpPropt9(yrec, year, grdid);
					chtprop.outpPropt10(yrec, year, grdid);


					pred.PredFile->close();
					outputr.ChtFile->close();


				}else{

					cout<<"Year setting is not correct for current grid cell"<<endl;	//move to next grid cell

				}//end of year if condition for year>, = startyear

				///////////delete old file
				if (year > ystart){
					delfile.delFile(s_Dir, grdid, year);
				}

				xDid += 1;
				if (xDid > 9){
						xDid = 0;
						yDid +=1;
				}

				if (yDid > 9){
					//cout<<"out of the boundary of 10 * 10 area"<<endl;
				}

				grdid += 1;


		}	//end of grid loop

		year += 1;
		yrec += 1;

	}	//end of year loop


	//close all output nc files
	chtprop.Propfilet3->close();
	chtprop.Propfilet4->close();
	chtprop.Propfilet5->close();
	chtprop.Propfilet1->close();
	chtprop.Propfilet2->close();
	chtprop.Propfilet9->close();
	chtprop.Propfilet10->close();


};

void Runner::SetPointer(IOdata* pointer){

	ioptr = pointer;
};

