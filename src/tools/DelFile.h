/*
 * DelFile.h
 *
 *  Created on: Jan 13, 2014
 *      Author: yujin_admin
 */

#ifndef DELFILE_H_
#define DELFILE_H_

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

class DelFile{

public:
	DelFile();
	~DelFile();

	void delFile(string dir, int grdid, int year);

private:

};

#endif /* DELFILE_H_ */
