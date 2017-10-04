/*
 *   kjs170430_Project2/fileInput.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 */

#include "fileInput.h"

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::toupper;
using std::transform;
using std::ios;

const char *ANWSERS    = "Answers.txt";
const char *CONTESTANT = "Contestants.txt";
const char *KEYWORD    = "Question";

string str_toupper(string str) {
  transform(str.begin(), str.end(), str.begin(), 
               [](unsigned char c){return toupper(c);}
            );
  return str;
}

int compareString(string keyword, string str) {
  // Ignore cases
  keyword = str_toupper(keyword);
  str = str_toupper(str);

  return str.find(keyword);
}

bool compareChar(char var1, char var2) {
  if (var1 > 96) {
    var1 -= 32;
  }
  if (var2 > 96) {
    var2 -= 32;
  }

  if (var1 == var2) {
    return true;
  } else {
    return false;
  }
}

int getKeywordCount(fstream& file) {
  if (file.is_open()) {
    string temp;
    int counter = 0;
    int * ptr = &counter;

    while (!file.eof()) {
      // Get String and check for Keyword
      file >> temp;
      int pos = temp.find(KEYWORD);
      // If found pull just the keyword for comparison
      if (pos >= 0) {
        *ptr = *ptr + 1;
        //temp.substr(pos,sizeof(KEYWORD));
        //----------------error checking--------------------
        cout << "counter: " << *ptr << endl;
      }
      
    }
    return counter;

  } else {
    cerr << "File Error for fstream object." << endl;
    return -1;
  }

}

int getAnsIndexValue(fstream& file) {
  if (file.eof()) {
    file.clear();
    file.seekg(0,ios::beg);
  }


}

char* createCharArray(int size) {
  char *ptr;

  ptr = new char[size];

  if (ptr == nullptr) {
    cerr << "Memory could not be allocated to char array" << endl;
  }
  return ptr;
}

int* createIntArray(int size) {
  int *ptr;

  ptr = new int[size];

  if (ptr == nullptr) {
    cerr << "Memory could not be allocated to int array " << endl;
  }
  return ptr;
}
