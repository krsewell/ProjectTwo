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