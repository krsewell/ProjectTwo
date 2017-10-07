/*
 *   kjs170430_Project2/tools.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 */
#include "tool.h"

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


string findMean(double* ptr, int size) {
  stringstream strs;
  double avg = 0;
  for (int i = 0; i < size; i++) {
    avg += *(ptr + i); 
  }
  avg = avg/static_cast<double>(size);
  strs << fixed << setprecision(2) << avg;
  return strs.str();
}

string findMode(double* ptr, int size) {
  //Number accuring the most within a set
  stringstream strs;
  int counter = 1;
  int maxcount = 0;
  bool notfirstRun = false;  

  for (int i = 0; i < size; i++) {
    if (*(ptr + i) == *(ptr + (i+1))) {
      counter++;
    } 
    else if (counter > maxcount) {
      maxcount = counter;
      counter = 1;
    }
    else {
      counter = 1;
    }
  }

  for (int i = 0; i < size; i++) {
    if (*(ptr + i) == *(ptr + (i+1))) {
      counter++;
    }
    else if (counter == maxcount) {
      if (notfirstRun) {
        strs << ", ";
      }
      strs << fixed << setprecision(2) << *(ptr + i);
      notfirstRun = true;
      counter = 1;
    }
    else {
      counter = 1;
    }
  }

  return strs.str();
}

string findMedian(double* ptr, int size) {
  //Middle value in a given sorted set
  stringstream strs;
  double med1, med2;
  int index = (size/2)-1;
  med1 = *(ptr+index);

  if (size % 2 == 0) {
    index++;
    med2 = *(ptr+index);
    strs << fixed << setprecision(2) << med1;
    strs << ", ";
    strs << fixed << setprecision(2) << med2;
  } else {
    strs << fixed << setprecision(2) << med1;
  }
  return strs.str();
}

void quicksortArray(double* ptr, int start, int end) {
  int pivot;

  if (start < end) {
    pivot = partition(ptr,start,end);
    quicksortArray(ptr,start,pivot-1);
    quicksortArray(ptr,pivot+1,end);
  }
}

int partition(double* ptr, int start, int end) {
  int pivotData,pivotInd,mid;

  mid = (start + end)/2;
  swapElement(ptr,start,mid);
  pivotInd = start;
  pivotData = *(ptr+start);

  for (int i = start + 1; i <=end; i++) {
    if (*(ptr+i) < pivotData) {
      pivotInd++;
      swapElement(ptr,pivotInd,i);
    }
  }
  swapElement(ptr,start,pivotInd);
  return pivotInd;
}

void swapElement(double* ptr, int aInd, int bInd) {
  double temp;
  temp = *(ptr + aInd);
  *(ptr + aInd) = *(ptr + bInd);
  *(ptr + bInd) = temp;
}