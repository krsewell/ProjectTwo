/*
 *   kjs170430_Project2/file.h
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 */

#ifndef FILE_H_INCL_GUARD
#define FILE_H_INCL_GUARD

#include "contestant.h"
#include "constant.h"
#include "tool.h"

#include <iostream>
#include <fstream>
#include <string>

// Per Google C++ Style Guide
//using namespace std;  // Should not be used.
using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::ios;
using std::fstream;
using std::stol;


// declarations

bool openInFile(fstream&, string);
bool closeInFile(fstream&, string);
bool openOutFile(fstream&, string);
bool closeOutFile(fstream&, string);

bool findKeyword(fstream&, string);
int getKeywordCount(fstream&);
char * parseAnswers(fstream&,int);
int getContestantCount(fstream& file);
Contestant* parseContestants(fstream&,int);

#endif // KJS170430_PROJECT2_FILEINPUT_H
