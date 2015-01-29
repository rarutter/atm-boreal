/*
 * Dlist.cpp
 *
 *  Created on: Jul 28, 2013
 *      Author: yujin_admin
 */

#include "./Dlist.h"

Dlist::Dlist(){

};

Dlist::~Dlist(){

};

Nodes* Dlist::InsertNodeBefore(Nodes* pLast, IOdata* ioptr){  //add current IODATA ioptr to the current list nptr;

	//nCount = 0;

	ptr = ioptr;
	//cout<<"ptr = "<<ptr<<endl;

//	pPreNode = nptr;

	Nodes* pNode = new Nodes;     //or use Nodes node;
//	cout<<"inside insert() pNode = "<<pNode<<endl;

	pNode->year = ptr->year;
	pNode->grdID = ptr->ingrdid;
	pNode->parentid = ptr->ingrdid;
	pNode->cohortid = ptr->incohortid;
	pNode->vegtype = ptr->invegtype;
	pNode->age = ptr->inage;
	pNode->proportion = ptr->inproportion;
	pNode->flag = ptr->inflag;
	pNode->generation = 1;

	pNode->pNext = pLast; //add a node before the first node of the current list
	pLast = pNode;

//	cout<<"inside insert() pLast = "<<pLast<<endl;

	return pLast;

};


Nodes* Dlist::SearchNode(Nodes* nptr){

};

Nodes* Dlist::DeleteNode(Nodes* nptr){

};


Nodes* Dlist::DeleteList(Nodes* list){

		//free the memory occupied by chtlist

		Nodes* p;
		p = list;  //
		while(p != NULL){
			list = list->pNext; //
			delete p;
			p = list;
		}
		return p;
};


