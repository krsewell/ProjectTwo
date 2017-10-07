#ifndef REPORT_H_INCL_GUARD
#define REPORT_H_INCL_GUARD

#include "tool.h"
#include <iostream>
#include <fstream>

using std::fstream;
using std::setw;

double* getScores(Contestant*,int);
void generateContestantReport(Contestant*,int,char*,fstream&);
void generateSummary(fstream&,double*,int);


#endif