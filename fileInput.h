/*
 *   kjs170430_Project2/fileInput.h
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 */

#ifndef KJS170430_PROJECT2_FILEINPUT_H
#define KJS170430_PROJECT2_FILEINPUT_H

#include <iostream>
#include <fstream>
#include <string>


using std::string;
using std::fstream;

// declarations

int compareString(string, string);
bool compareChar(char, char);
char *createCharArray(int);
int *createIntArray(int);
string str_toupper(string);
int getKeywordCount(fstream&);


#endif // KJS170430_PROJECT2_FILEINPUT_H