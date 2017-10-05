/*
 *   kjs170430_Project2/main.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 */
#ifndef MAIN_H_INCL_GUARD
#define MAIN_H_INCL_GUARD

#include "fileInput.h"
#include "contestants.h"
#include "constants.h"

#include <iostream>
#include <fstream>
#include <string>

// Per Google C++ Style Guide
//using namespace std;  // Should not be used.
using std::fstream;
using std::ios;
using std::stol;
using std::string;



// declarations

void releasePtr(Contestant* ,char* );


#endif

int main() {
  //-------------------------------------------------//
  // Get Answer Key                                  //
  //-------------------------------------------------//
  fstream ansFile;
  char * answerKey;
  int keySize;
  if (openInFile(ansFile, ANSWERS)) {
    keySize = getKeywordCount(ansFile); //pass number of questions for later
    answerKey = parseAnswers(ansFile);
  }
  bool next = closeInFile(ansFile,ANSWERS);
  
  if (next) {
    cout << "Answer Key Created" << endl;
  }
  //-------------------------------------------------//
  // Get Contestant Data                             //
  //-------------------------------------------------//
  fstream contestFile;
  Contestant* ptrContestant;
  int contSize;
  if (openInFile(contestFile, CONTESTANTS)) {
    contSize = getContestantCount(contestFile); //needed later for exit code
    ptrContestant = parseContestants(contestFile,keySize);
  }
  next = closeInFile(contestFile,CONTESTANTS);

  if (next) {
    cout << "Contestant Database Created" << endl;
  }




  //exit and clean up
  releasePtr(contSize,ptrContestant,answerKey);
  return 0;
}


void releasePtr(Contestant* ptrContestant,char* answerKey) {

  //delete all contestant constructs
  delete [] ptrContestant;

  //delete answerKey
  delete [] answerKey;
}
