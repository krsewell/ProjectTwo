/*
 *   kjs170430_Project2/main.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 */
#ifndef MAIN_H_INCL_GUARD
#define MAIN_H_INCL_GUARD

#include <iostream>
#include <fstream>
#include "fileInput.h"

using namespace std;

#endif

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
     store number into SIZE var
     close contestants.txt

     open contestants.txt file
     loop read contestant id into primary array
      read each anwser into secondary array
     close contestants.txt
   */
  fstream answers;
  answers.open("Answers.txt", ios::in);
  int size = 0;
  size = getKeywordCount(answers);
  
  
  char * answerKey;
  answerKey = createCharArray(size);
  

  return 0;
}
