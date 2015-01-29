/*
 * Thermokarst.h
 *
 *  Created on: Jul 24, 2013
 *      Author: yujin_admin
 */

#ifndef THERMOKARST_H_
#define THERMOKARST_H_

#include "./IOdata.h"
#include "./ProcCht.h"
#include "./LNode.h"
#include "../inputer/BorealDataInputer.h"
#include "../inputer/LakeDataInputer.h"

class Thermokarst{

		public:
			Thermokarst();
			~Thermokarst();

			Nodes* Expansion(Nodes* hnode, Nodes* nnode, Nodes* cnode, long &cchtid);
			Nodes* Initiation(Nodes* newnode, Nodes* cnode, Nodes* grdnodes, long &tchtid);
			Nodes* ChtInitiation(Nodes* newnode, Nodes* cnode, Nodes* grdnodes, long &tchtid);
			Nodes* AddChtAge(Nodes* nnode);
			Nodes* ChtCombin(Nodes* hnode, Nodes* nnode);
			Nodes* ChtCombinInsert(Nodes* hnode, Nodes* nnode);

			Nodes* InitiatingFrWS(Nodes* newnode, Nodes* curnode, Nodes* grdNodes, Nodes* llist, long &cchtid);
			Nodes* InitiatingFrBS(Nodes* newnode, Nodes* curnode, Nodes* grdNodes, Nodes* llist, long &cchtid);
			Nodes* InitiatingFrDeci(Nodes* newnode, Nodes* curnode, Nodes* grdNodes, Nodes* llist, long &cchtid);
			Nodes* InitiatingFrTBog(Nodes* newnode, Nodes* curnode, Nodes* grdNodes, Nodes* llist, long &cchtid);
			Nodes* InitiatingFrBog(Nodes* newnode, Nodes* curnode, Nodes* grdNodes, Nodes* llist, long &cchtid);
			Nodes* InitiatingFrFen(Nodes* newnode, Nodes* curnode, Nodes* grdNodes, Nodes* llist, long &cchtid);
			Nodes* InitiatingFrLake(Nodes* newnode, Nodes* curnode, Nodes* grdNodes, Nodes* llist, long &cchtid);

			bool Flagexit(Nodes* curnode, Nodes* ilist);
			void AggregationProp(Nodes* curnode, Nodes* ilist);

			void SetPointer(IOdata* ptr);
			void SetPointer(BorealDataInputer* bdpt, LakeDataInputer* ldpt);

			IOdata* iopt;
			BorealDataInputer* bd;
			LakeDataInputer* ld;

		private:



};
#endif /* THERMOKARST_H_ */
