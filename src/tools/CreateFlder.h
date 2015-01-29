/*
 * CreateFlder.h
 *
 *  Created on: Jan 10, 2014
 *      Author: yujin_admin
 */

#ifndef CREATEFLDER_H_
#define CREATEFLDER_H_

#include <string>
#include <iostream>
#include "windows.h"

#include <stdio.h>
#include <sstream>

using namespace std;

class CreateFlder{

	public:
		CreateFlder();
		~CreateFlder();

		void Createflder(string dir, long grdid);
		void createfld(string fld);

		string dir;
		string fldname;

		long grdid;
		int i;

	private:


};

#endif /* CREATEFLDER_H_ */
