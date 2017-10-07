#ifndef CONTESTANT_H_INCL_GUARD
#define CONTESTANT_H_INCL_GUARD

struct Contestant {
    long int ID;    //Unique Identifier
    char * Qptr;    //Pointer for Ans Array, init after size is known.
    int size;       //initilizer for Q and total problem set.
    int * Mptr;     //Array for missed problems list
    int incorrect;  //initializer for M and number of incorrect Ans
    double score;   //Percentage correct
    int correct;    //    
  
    ~Contestant() {
      delete [] Qptr;
      delete [] Mptr;
    }
  };

#endif