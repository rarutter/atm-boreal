/*
 * Thermo.cpp
 *
 *  Created on: Jul 24, 2013
 *      Author: yujin_admin
 */

#include "./Thermokarst.h"

Thermokarst::Thermokarst(){

};

Thermokarst::~Thermokarst(){

};

Nodes* Thermokarst::Expansion(Nodes* hnode, Nodes* nnode, Nodes* cnode, long &cchtid){

		return hnode;
};


Nodes* Thermokarst::Initiation(Nodes* newnode, Nodes* cnode, Nodes* grdnodes, long &tchtid){

		Nodes* plist;
		plist = cnode;

		//Nodes* newchtlist = new Nodes;
		//newchtlist = NULL;		//define the first list node


		if (plist->vegtype == 3 || plist->vegtype == 4 || plist->vegtype == 5
				|| plist->vegtype == 1 || plist->vegtype == 2 || plist->vegtype == 9 || plist->vegtype == 10){

/*				cout<<"1   plist->vegtype = "<<plist->vegtype<<endl;
				getchar();
				*/
				newnode = ChtInitiation(newnode, plist, grdnodes, tchtid);




			}

		return newnode;

};

Nodes* Thermokarst::ChtInitiation(Nodes* newnode, Nodes* cnode, Nodes* grdnodes, long &tchtid){


	//loop through linkedlist
	Nodes* plist = new Nodes;
	plist = cnode;
	while(plist != NULL){

		if(plist->vegtype == 3){

			newnode = InitiatingFrWS(newnode, cnode, grdnodes, plist, tchtid);	//initiation from 3, and add new cohort to cnode

		}else if(plist->vegtype == 4){

			newnode = InitiatingFrBS(newnode, cnode, grdnodes, plist, tchtid);

		}else if(plist->vegtype == 5){

			newnode = InitiatingFrDeci(newnode, cnode, grdnodes, plist, tchtid);


		}else if(plist->vegtype == 10){

			newnode = InitiatingFrTBog(newnode, cnode, grdnodes, plist, tchtid);

		}else if(plist->vegtype == 1){

			newnode = InitiatingFrBog(newnode, cnode, grdnodes, plist, tchtid);

		}else if(plist->vegtype == 2){

			newnode = InitiatingFrFen(newnode, cnode, grdnodes, plist, tchtid);

		}else if(plist->vegtype == 9){

			newnode = InitiatingFrLake(newnode, cnode, grdnodes, plist, tchtid);


		}else{

			cout<<endl<<"no Initiation/Expansion"<<endl;
		}

		plist = plist->pNext;

	}

	return newnode;

};


Nodes* Thermokarst::AddChtAge(Nodes* nnode){

	//After a year, add 1 to all old and new cohorts ages
	Nodes* plist = nnode;

	while (plist != NULL ){

			plist->age += 1;

			plist = plist->pNext;

	}

	return nnode;

};

Nodes* Thermokarst::ChtCombin(Nodes* hnode, Nodes* nnode){

	////combine the newchtlist to the current chtlist
	Nodes* nlist = new Nodes;
	Nodes* ListEnd = new Nodes;

	if (hnode != NULL){

		nlist = hnode;

		while(nlist != NULL){
			ListEnd = nlist;	//the pointer of last node
			nlist = nlist->pNext;	//point to next node
		}

		ListEnd->pNext = nnode;		//nodeEnd is the pointer of the end node of the list
		//cout<<"hnode = "<<hnode<<endl;

	}else{

		hnode = nnode;
	}

		return hnode;

};


Nodes* Thermokarst::ChtCombinInsert(Nodes* hnode, Nodes* nnode){

	////new node
	Nodes* pNode1 = new Nodes;     //
	pNode1->pNext = NULL;

	pNode1->year = nnode->year;
	pNode1->grdID = nnode->grdID;
	pNode1->parentid = nnode->cohortid;
	pNode1->cohortid = nnode->cohortid;
	pNode1->vegtype =  nnode->vegtype;;	//new lake
	pNode1->age =  nnode->age;;
	pNode1->proportion =  nnode->proportion;;
	pNode1->flag =  nnode->flag;;


	////add pNode1 before the current hnode
	pNode1->pNext = hnode;
	hnode = pNode1;
	return hnode;

};


Nodes* Thermokarst::InitiatingFrWS(Nodes* newnode, Nodes* curnode, Nodes* grdNodes, Nodes* llist, long &cchtid){

	//cout<<endl<<"initi WS "<<endl;

	float rate=0;  	//percent

	cchtid += 1;	//add 1 to previous cchtid
	Nodes* pNode1 = new Nodes;     //using type 3: generate a cohort for new bog;
	pNode1->pNext = NULL;

	pNode1->year = llist->year;
	pNode1->grdID = llist->grdID;
	pNode1->parentid = llist->cohortid;
	pNode1->cohortid = cchtid;
	pNode1->vegtype = 9;	//new lake
	pNode1->age = 0;
	pNode1->generation = llist->generation + 1;
	pNode1->flag = 2;

	pNode1->proportion = llist->proportion*rate/100;

	//modify the current cohort proportion
	llist->proportion -= pNode1->proportion;

	if (llist->proportion < 0){

		llist->proportion = 0;
	}


	newnode = pNode1;	//nnode is the new cohort list

	return newnode;  //header of the new linkedlist

};


Nodes* Thermokarst::InitiatingFrBS(Nodes* newnode, Nodes* curnode, Nodes* grdNodes, Nodes* llist, long &cchtid){

	//cout<<endl<<"Initi BS "<<endl;

	float originalProp = llist->proportion;

	float rate= bd->iodata.rate4_B2Fen;  	//percent

	float rate2= 0;  	//percent

	//to lake
	if (ld->iodata.rate9_Deci2LK != -9999){
		rate2= ld->iodata.rate9_Deci2LK;  	//percent
		cout<<"in tk, ld->iodata.rate9_Deci2LK = "<<ld->iodata.rate9_Deci2LK<<endl;
		//getchar();

	}


	//new a node for a new fen
	cchtid += 1;	//add 1 to cchtid

	Nodes* pNode2 = new Nodes;     //using type 3: generate a cohort for new bog;
	pNode2->pNext = NULL;

	//cout<<"pNode2 = "<<pNode2<<endl;

	pNode2->year = llist->year;
	pNode2->grdID = llist->grdID;
	pNode2->parentid = llist->cohortid;
	pNode2->cohortid = cchtid;
	pNode2->vegtype = 2;	//new fen
	pNode2->age = 0;
	pNode2->generation = llist->generation + 1;

	//pNode2->proportion = originalProp*rate/100;  //wrong
	pNode2->proportion = originalProp*rate;  //20141208

	pNode2->flag = 2;

	//modify the current cohort
	llist->proportion -= pNode2->proportion;


	if (llist->proportion < 0){

		llist->proportion = 0;
	}


	//new a node for a new fen
	cchtid += 1;	//add 1 to cchtid

	Nodes* pNode4 = new Nodes;     //using type 3: generate a cohort for new bog;
	pNode4->pNext = NULL;

	//cout<<"pNode2 = "<<pNode2<<endl;

	pNode4->year = llist->year;
	pNode4->grdID = llist->grdID;
	pNode4->parentid = llist->cohortid;
	pNode4->cohortid = cchtid;
	pNode4->vegtype = 9;	//new fen
	pNode4->age = 0;
	pNode4->generation = llist->generation + 1;

	//the proportion of new cht. (proportion of grid cell)
	pNode4->proportion = originalProp*rate2/100;

	pNode4->flag = 2;
	//modify the current cohort proportion again after the first modification,
	//the proportion of old cht (proportion of grid cell)
	llist->proportion -= pNode4->proportion;

	if (llist->proportion < 0){

		llist->proportion = 0;
	}

//getchar();


	pNode2->pNext = pNode4;
	newnode = pNode2;	//nnode is the new cohort list
	return newnode;  //header of the new linkedlist

	////////////////////////////////////////////////////////

};


Nodes* Thermokarst::InitiatingFrDeci(Nodes* newnode, Nodes* curnode, Nodes* grdNodes, Nodes* llist, long &cchtid){

	//cout<<endl<<"initi DECI "<<endl;
	float D2Brate = 0.0065;  	//percent
	float D2Frate = bd->iodata.rate5_D2Fen;
	float originalProp = llist->proportion;

	//new a node for a new bog
	cchtid += 1;	//add 1 to cchtid

	Nodes* pNode3 = new Nodes;     //using type 3: generate a cohort for new bog;
	pNode3->pNext = NULL;

	pNode3->year = llist->year;
	pNode3->grdID = llist->grdID;
	pNode3->parentid = llist->cohortid;
	pNode3->cohortid = cchtid;
	pNode3->vegtype = 1;	//new Bog
	pNode3->age = 0;

	pNode3->generation = llist->generation + 1;

	//cout<<"bf curnode->proportion = "<<curnode->proportion<<endl;
	//cout<<"bf pNode1->proportion = "<<pNode3->proportion<<endl;

	//new cht proportion (proportion of grid cell)
	pNode3->proportion = originalProp*D2Brate/100;

	//cout<<"af pNode1->proportion = "<<pNode3->proportion<<endl;
	pNode3->flag = 2;
	//the proportion of old cht (proportion of grid cell)
	llist->proportion -= pNode3->proportion;
	if (llist->proportion < 0){

		llist->proportion = 0;
	}


	//new a node for a new fen
	cchtid += 1;	//add 1 to cchtid

	Nodes* pNode2 = new Nodes;     //using type 3: generate a cohort for new bog;
	pNode2->pNext = NULL;

	//cout<<"pNode2 = "<<pNode2<<endl;

	pNode2->year = llist->year;
	pNode2->grdID = llist->grdID;
	pNode2->parentid = llist->cohortid;
	pNode2->cohortid = cchtid;
	pNode2->vegtype = 2;	//new fen
	pNode2->age = 0;
	pNode2->generation = llist->generation + 1;

	//the proportion of new cht. (proportion of grid cell)
	pNode2->proportion = originalProp*D2Frate;

	pNode2->flag = 2;
	//modify the current cohort proportion again after the first modification,
	//the proportion of old cht (proportion of grid cell)
	llist->proportion -= pNode2->proportion;

	if (llist->proportion < 0){

		llist->proportion = 0;
	}

	pNode3->pNext = pNode2;
	newnode = pNode3;	//nnode is the new cohort list
	return newnode;  //header of the new linkedlist

};


Nodes* Thermokarst::InitiatingFrTBog(Nodes* newnode, Nodes* curnode, Nodes* grdNodes, Nodes* llist, long &cchtid){


		//cout<<endl<<"initi treed bog 10"<<endl;
		float rate=0;  	//percent

		//new a node for a new fen
		cchtid += 1;	//add 1 to cchtid

		Nodes* pNode2 = new Nodes;     //using type 3: generate a cohort for new bog;
		pNode2->pNext = NULL;

		pNode2->year = llist->year;
		pNode2->grdID = llist->grdID;
		pNode2->parentid = llist->cohortid;
		pNode2->cohortid = cchtid;
		pNode2->vegtype = 4;	//new Black spruce
		pNode2->age = 0;

		pNode2->generation = llist->generation + 1;

		//cout<<"curnode->proportion = "<<curnode->proportion<<endl;
		//cout<<"bf pNode1->proportion = "<<pNode2->proportion<<endl;

		pNode2->proportion = llist->proportion*rate/100;

		//cout<<"af pNode1->proportion = "<<pNode2->proportion<<endl;

		//getchar();

		pNode2->flag = 2;

		//modify the current cohort
		llist->proportion -= pNode2->proportion;
		if (llist->proportion < 0){

			llist->proportion = 0;
		}

		newnode = pNode2;	//nnode is the new cohort list

		return newnode;  //header of the new linkedlist

};



Nodes* Thermokarst::InitiatingFrBog(Nodes* newnode, Nodes* curnode, Nodes* grdNodes, Nodes* llist, long &cchtid){


		//add a cohort for new treed bog
		//cout<<endl<<"initiate from bog 1111111"<<endl;

		float rate=0;	//percent

		cchtid += 1;	//add 1 to cchtid

		//new a node for new bog
		Nodes* pNode1 = new Nodes;     //using type 3: generate a cohort for new bog;
		pNode1->pNext = NULL;

		pNode1->year = llist->year;
		pNode1->grdID = llist->grdID;
		pNode1->parentid = llist->cohortid;
		pNode1->cohortid = cchtid;
		pNode1->vegtype = 10;	//new treed bog
		pNode1->age = 0;
		pNode1->generation = llist->generation + 1;

		//cout<<"curnode->proportion = "<<curnode->proportion<<endl;
		//cout<<"bf pNode1->proportion = "<<pNode1->proportion<<endl;

		pNode1->proportion = llist->proportion*rate/100;

		//modify the current cohort
		llist->proportion -= pNode1->proportion;

		if (llist->proportion < 0){

			llist->proportion = 0;
		}


		newnode = pNode1;	//nnode is the new cohort list
		return newnode;  //header of the new linkedlist

};


Nodes* Thermokarst::InitiatingFrFen(Nodes* newnode, Nodes* curnode, Nodes* grdNodes, Nodes* llist, long &cchtid){


	//add a cohort for new treed bog
	//cout<<endl<<"initiate from Fen 22222222"<<endl;
	float rate=0.09327;  	//percent //from Jen,vaijay's analysis

	cchtid += 1;	//add 1 to cchtid

	//new a node for new bog
	Nodes* pNode1 = new Nodes;     //using type 3: generate a cohort for new bog;
	pNode1->pNext = NULL;

	pNode1->year = llist->year;
	pNode1->grdID = llist->grdID;
	pNode1->parentid = llist->cohortid;
	pNode1->cohortid = cchtid;
	pNode1->vegtype = 1;	//to new bog
	pNode1->age = 0;
	pNode1->generation = llist->generation + 1;

	pNode1->proportion = llist->proportion*rate/100;

	pNode1->flag = 2;

	//substracted by
	llist->proportion -= pNode1->proportion;
	if (llist->proportion < 0){

		llist->proportion = 0;
	}

	newnode = pNode1;	//nnode is the new cohort list
	return newnode;  //header of the new linkedlist

};


Nodes* Thermokarst::InitiatingFrLake(Nodes* newnode, Nodes* curnode, Nodes* grdNodes, Nodes* llist, long &cchtid){


	//add a cohort for new treed bog
/*
	cout<<"in frlake, &bd = "<<bd<<endl;
	cout<<"in frlake, &ld = "<<ld<<endl;
	getchar();
*/

	float rate=0;  	//percent
	if (ld->iodata.rate9_LK2Fen != -9999){
		cout<<endl<<"in thmkarst, ld->iodata.rate9_LK2Fen = "<<ld->iodata.rate9_LK2Fen<<endl;

		rate= -ld->iodata.rate9_LK2Fen;  	//percent sum ====
		//cout<<endl<<"in thmkarst, rate = "<<rate<<endl;
		//getchar();

	}

	cchtid += 1;	//add 1 to cchtid

	//new a node for new bog
	Nodes* pNode1 = new Nodes;
	pNode1->pNext = NULL;

	pNode1->year = llist->year;
	pNode1->grdID = llist->grdID;
	pNode1->parentid = llist->cohortid;
	pNode1->cohortid = cchtid;
	pNode1->vegtype = 2;	//to new fen
	pNode1->age = 0;
	pNode1->generation = llist->generation + 1;

	pNode1->proportion = llist->proportion*rate/100;

	pNode1->flag = 2;

	//modify current cohort proportion
	llist->proportion -= pNode1->proportion;

	if (llist->proportion < 0){
		llist->proportion = 0;
	}

	newnode = pNode1;	//nnode is the new cohort list
	return newnode;  //header of the new linkedlist hnode

};


bool Thermokarst::Flagexit(Nodes* curnode, Nodes* ilist){

	bool bexist=false;

	Nodes* plist = new Nodes;
	plist = curnode;
	while ( plist != NULL){

		if (plist->vegtype == ilist->vegtype){ 	//old types

			bexist=true;
			//cout<<endl<<"bexist = "<<bexist<<endl;
			return bexist;
		}

		plist = plist->pNext;
	}

};

void Thermokarst::AggregationProp(Nodes* curnode, Nodes* ilist){

	Nodes* plist = new Nodes;
	plist = curnode;
	while(plist != NULL){

		if (plist->vegtype == ilist->vegtype ){ 	//old types

			plist->proportion += ilist->proportion;
		}

		plist = plist->pNext;
	}

};


void Thermokarst::SetPointer(IOdata* ptr){

	iopt = ptr;
};

void Thermokarst::SetPointer(BorealDataInputer* bdpt, LakeDataInputer* ldpt){

	bd = bdpt;
	ld = ldpt;


/*
	cout<<"in tk, &bd = "<<bd<<endl;
	cout<<"in th, &ld = "<<ld<<endl;
getchar();
*/

};
