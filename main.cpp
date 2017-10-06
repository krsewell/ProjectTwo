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
#include <iomanip>

// Per Google C++ Style Guide
//using namespace std;  // Should not be used.
using std::fstream;
using std::ios;
using std::stol;
using std::string;
using std::fixed;

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
  //--------------------------------------------------//
  // Compair Contestant Data with AnswerKey and grade //
  //--------------------------------------------------//
  for (int i = 0; i < contSize; i++) {
    char cvar;
    char avar;
    int mInd = 0;
    //initialize Mptr with max value
    (ptrContestant + i)->Mptr = createIntArray(keySize);
    for (int j = 0; j < keySize; j++) {
      cvar = *((ptrContestant + i)->Qptr + j);
      avar = *(answerKey + j);
      if (!compareChar(cvar,avar)) {  // If contestant missed problem store the index value in int Mptr[]
        *((ptrContestant + i)->Mptr + mInd) = j;
        mInd++;
      }
      (ptrContestant + i)->incorrect = mInd + 1;
      (ptrContestant + i)->correct = keySize - (ptrContestant + i)->incorrect;
      (ptrContestant + i)->score = double((ptrContestant + i)->correct)/keySize;
    }
  }
  
  //quick test
  for (int i = 0; i < contSize; i++) {
    cout  << "Score for: " << (ptrContestant + i)->ID << "is " << fixed << std::setprecision(2) 
          << (ptrContestant + i)->score << endl;
  }



  //exit and clean up
  releasePtr(ptrContestant,answerKey);
  return 0;
}


void releasePtr(Contestant* ptrContestant,char* answerKey) {

  //delete all contestant constructs. dynamic arrays within construct taken care of by destructor.
  delete [] ptrContestant;

  //delete answerKey
  delete [] answerKey;
}
