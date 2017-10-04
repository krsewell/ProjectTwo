/*
 *   kjs170430_Project2/fileInput.h
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 */

#ifndef KJS170430_PROJECT2_FILEINPUT_H
#define KJS170430_PROJECT2_FILEINPUT_H

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// Per Google C++ Style Guide
//using namespace std;  // Should not be used.
using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::toupper;
using std::transform;
using std::ios;
using std::fstream;

const char *ANWSERS    = "Answers.txt";
const char *CONTESTANT = "Contestants.txt";
const char *KEYWORD    = "Question";

// declarations

int compareString(string, string);
bool compareChar(char, char);
char *createCharArray(int);
int *createIntArray(int);
string str_toupper(string);
int getKeywordCount(fstream&);


#endif // KJS170430_PROJECT2_FILEINPUT_H
