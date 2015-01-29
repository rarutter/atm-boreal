/*
 * LNode.h
 *
 *  Created on: Jul 29, 2013
 *      Author: yujin_admin
 */

#ifndef LNODE_H_
#define LNODE_H_

	struct Nodes{

		//for inputting and outputting cohorts data

		int year;
		int grdID;   //grid id in initial TNNinitcht.nc
		int parentid;
		int cohortid;
		int vegtype;
		int age;
		float proportion;
		int flag;
		int generation;

		//Nodes* pLast;
		Nodes* pNext;

		};

#endif /* LNODE_H_ */
