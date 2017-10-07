/*
 *   kjs170430_Project2/main.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 */
#ifndef MAIN_H_INCL_GUARD
#define MAIN_H_INCL_GUARD

#include "file.h"
#include "contestant.h"
#include "constant.h"
#include "report.h"

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
using std::cin;


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
    answerKey = parseAnswers(ansFile,keySize);
  }
  bool next = closeInFile(ansFile,ANSWERS);
  
  if (next) {
    cout << "Answer Key Created" << endl;
  }
  //-------------------------------------------------//
  // Get Contestant Data                             //
  //-------------------------------------------------//
  fstream contestFile;
  Contestant* cPtr;
  int cSize;
  if (openInFile(contestFile, CONTESTANTS)) {
    cSize = getContestantCount(contestFile); //needed later for exit code
    cPtr = parseContestants(contestFile,keySize);
  }
  next = closeInFile(contestFile,CONTESTANTS);

  if (next) {
    cout << "Contestant Database Created" << endl;
  }

  gradeContestants(cPtr,cSize,answerKey,keySize);
  
  string temp;
  fstream report;
  cout << "Please enter a filename for report: ";
  cin >> temp;
  cout << endl;
  if (openOutFile(report, temp)) {
    for (int i = 0; i < cSize; i++) {
      generateContestantReport(i,report);
    }
    generateSummary(report);
  }
  if (closeOutFile(report, temp)) {
    cout << "Report " << temp << "generated successfully" << endl;
  }

  //exit and clean up
  releasePtr(cPtr,answerKey);
  return 0;
}


void releasePtr(Contestant* cPtr,char* answerKey) {

  //delete all contestant constructs. dynamic arrays within construct taken care of by destructor.
  delete [] cPtr;

  //delete answerKey
  delete [] answerKey;
}
