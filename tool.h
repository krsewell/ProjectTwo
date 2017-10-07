#ifndef TOOL_H_INCL_GUARD
#define TOOL_H_INCL_GUARD

#include "contestant.h"


#include <iostream>
#include <string>
#include <sstream>

// Per Google C++ Style Guide
//using namespace std;  // Should not be used.
using std::cerr;
using std::endl;
using std::string;
using std::stringstream;

// declarations
bool compareChar(char, char);
char *createCharArray(int);
int *createIntArray(int);
Contestant* createContArray(int);
void gradeContestants(Contestant*,int,char*,int);
double findMean(double*,int);
string findMedian(double*,int);
double findMode(double*,int);
void quicksortArray(double*,int,int);
int partition(double*,int,int);
void swapElement(double*,int,int);

#endif