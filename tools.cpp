/*
 *   kjs170430_Project2/tools.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 */
#include "tools.h"

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
  
Contestant* createContArray(int size) {
  Contestant * ptr;
  
  ptr = new Contestant[size];
  
  if (ptr == nullptr) {
    cerr << "Memory could not be allocated to Contestant array" << endl;
  }
  return ptr;
}

void gradeContestants(Contestant* cPtr, int cSize, char* aPtr, int aSize) {
  for (int i = 0; i < cSize; i++) {
    //for each contestant
      char cvar;
      char avar;
      int mInd = 0;
      bool hundredPercent = true;
      
      for (int j = 0; j < aSize; j++) {
      //for each answer given by contestant
        cvar = *((cPtr + i)->Qptr + j);
        avar = *(aPtr + j);
        if (!compareChar(cvar,avar)) {  
        // If contestant missed problem store the index value in int Mptr[]
          *((cPtr + i)->Mptr + mInd) = j;
          hundredPercent = false; //perfect score fuse/flag
          mInd++;
        }
      }
      
      if (hundredPercent) {
        //Special case either contestant missed none or one.
        (cPtr + i)->incorrect = 0;
      } else {
        (cPtr + i)->incorrect = mInd;
      }
      (cPtr + i)->correct = aSize - (cPtr + i)->incorrect;
      (cPtr + i)->score = double((cPtr + i)->correct)*100.0/aSize;
    }  
}