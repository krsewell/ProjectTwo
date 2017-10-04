/*
 *   kjs170430_Project2/main.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 */
#ifndef MAIN_H_INCL_GUARD
#define MAIN_H_INCL_GUARD

#include "fileInput.h"

#include <iostream>
#include <fstream>

// Per Google C++ Style Guide
//using namespace std;  // Should not be used.
using std::fstream;
using std::ios;


#endif

struct Contestant {
  long int ID;  //Unique Identifier
  char * Qptr;  //Pointer for Ans Array, init after size is known.
  int size;     //initilizer for Q
  Qptr = createCharArray(size);
  int correct;  //Number of correct Ans
  double score; //Percentage correct    
};



int main() {
  /*
     open anwsers.txt file
     loop find delimiting keyword
      read index data into temp var
      read data into temp var
      pass index and data to array
     close anwsers.txt

     open contestants.txt file
     get number of line/contestants
     store number into ansPool var
     close contestants.txt

     open contestants.txt file
     loop read contestant id into primary array
      read each anwser into secondary array
     close contestants.txt
   */
  fstream ansFile;
  ansFile.open("Answers.txt", ios::in);
  
  fstream contestantFile;
  contestantFile.open("Contestants.txt", ios::in);

  int ansPool = 0;
  ansPool = getKeywordCount(ansFile);
  
  char * answerKey;
  answerKey = createCharArray(ansPool);
  
  int i = 0;
  while (i < ansPool) {
    int index = getAnsIndexValue(ansFile);
    char data = getAnsDataValue(ansFile);
    *(answerKey + index) = data;
  }   
  ansFile.close();
  
  // Find number of contestants
  int contPool;
  contPool = getContestantCount(contestantFile);
  
  // Create contestant profiles
  for (int i = 0; i < contPool; i++) {
    Contestant ("Contest" + i);
  }





  return 0;
}
