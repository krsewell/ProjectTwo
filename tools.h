#ifndef TOOLS_H_INCL_GUARD
#define TOOLS_H_INCL_GUARD

#include "contestants.h"


#include <iostream>

// Per Google C++ Style Guide
//using namespace std;  // Should not be used.
using std::cerr;
using std::endl;

// declarations
bool compareChar(char, char);
char *createCharArray(int);
int *createIntArray(int);
Contestant* createContArray(int);
void gradeContestants(Contestant*,int,char*,int);


#endif