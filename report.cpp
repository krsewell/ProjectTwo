#include "report.h"


double* getScores(Contestant* ptr, int size) {
  double * array;
  array = new double[size];

  for (int i = 0; i < size; i++) {
    //std::cout << (ptr + i)->score << " ";
    *(array + i) = (ptr + i)->score;
  }
  //std::cout << std::endl;
  return array;
}

void generateSummary(fstream& file, double* ptr, int size) {
  quicksortArray(ptr,0,size-1);
  string median = findMedian(ptr,size);
  string mean = findMean(ptr,size);
  string mode = findMode(ptr,size);

  file << "Summary" << endl; 
  file << "Median Score: " << median << endl;
  file << "Mean Score: " << mean << endl;
  file << "Mode of Scores: " << mode << endl;
  delete [] ptr;
}

void generateContestantReport(Contestant* ptr, int contestantIndex, char* answerKey, fstream& file) {
  file << "Contestant ID: " << (ptr + contestantIndex)->ID << endl;
  file << "Score: " << (ptr + contestantIndex)->score << endl;
  //missed problem list
  file << "Missed Problems: " << endl; 
  
  int mInd = (ptr+contestantIndex)->incorrect - 1;     //Last index of questions missed
  for (int i = 0; i < mInd + 1; i++) {                  //for all questions missed
    int dex = *((ptr+contestantIndex)->Mptr + i);      //let dex equal the index stored in the ith position of Mptr
    file << setw(6) << dex+1 << ".) ";                  //dex + 1 is equal to problem number
    file << setw(2) << *((ptr+contestantIndex)->Qptr + dex);    //Qptr + dex is equal to the problem answer
    file << " Answer:" << *(answerKey+dex) << endl;
  }
  file << endl;
}