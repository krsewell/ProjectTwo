/*
 *   kjs170430_Project2/fileInput.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 */

#include "fileInput.h"

//Global Constants
const char *ANSWERS     = "Answers.txt";
const char *CONTESTANTS = "Contestants.txt";
const char *KEYWORD     = "Question";


bool openInFile(fstream& file, string name) {
  file.open(name,ios::in);
  if (file.fail()) {
    cerr << "Error Opening File: " << name << endl;
    return false;
  } else {
    return true;
  }
}

bool closeInFile(fstream& file, string name) {
  file.close();
  if (file.is_open()) {
    cerr << "Error Closing File: " << name << endl;
    return false;
  } else {
    return true;
  }

}

bool findKeyword(fstream& file, string check) {
  if (file) { 
    string temp;
    file >> temp;
    if (temp == check) {
      return true;
    } else {
      return false;
    }
  } else {
    cerr << "File Error findKeyword()." << endl;
    return false;
  }
}

int getKeywordCount(fstream& file) {
  if (file) {
    string temp;
    int counter = 0;
    int * ptr = &counter;

    while (!file.eof()) {
      // Get String and check for Keyword
      file >> temp;
      int pos = temp.find(KEYWORD);
      // If found pull just the keyword for comparison
      if (pos >= 0) {
        *ptr = *ptr + 1;
        //temp.substr(pos,sizeof(KEYWORD));
        //----------------error checking--------------------
        //cout << "counter: " << *ptr << endl;
      }
      
    }
    //reset fstream and return counter
    
    file.clear();
    file.seekg(0,ios::beg);
    return counter;
    

  } else {
    cerr << "File Error in getKeywordCount()." << endl;
    return -1;
  }

}

char * parseAnswers(fstream& file) {
  if (file) {
    // set up array
    int size = getKeywordCount(file);
    cout << "Question Count is: " << size << endl;
    char * ptr;
    ptr = createCharArray(size);

    while (findKeyword(file,KEYWORD)) {
      string temp;
      int index;
      try {
        
        file >> temp;
        //next temp value should be the question number
        index = stoi(temp) - 1;
      } catch (...) {
        cerr << "Answer File Format incorrect" << endl;
        exit(-1);
      }
      file >> temp;
      //next temp value should be char for correct answer
      char data = temp.at(0);
      //pass to array
      *(ptr + index) = data;
    }
    return ptr;
  } else {
    cerr << "File Error in parseAnswers()." << endl;
    return nullptr;
  }
}

int getContestantCount(fstream& file) {
  if (file) {
    int counter = 0;
    while (!file.eof()) {
      try {
        string temp;
        int ID; //used as dummy varible. if exception is thrown it isnt an ID.
        
        file >> temp;
        ID = stol(temp);
        counter++;
      } catch (...) {}
      
    }
    file.clear();
    file.seekg(0,ios::beg);
    return counter;

  } else {
    cerr << "File Error in getContestantCount()." << endl;
    return -1;
  }
}

Contestant* parseContestants(fstream& file,int keySize) {
  if (file) {
    // set up array (type struct)
    int size;
    size = getContestantCount(file);
    cout << "Contestant Count is: " << size << endl;
    Contestant* ptr;
    ptr = createContArray(size);

    try {
      // i is the contest number from 0 thru total number of contestants
      for (int i = 0; i < size; i++) {
        //cout << "size: " << size << endl;
        //cout << "i: " << i << endl;
        string temp;
        file >> temp;  // pass first string from file

        long int ID;
        ID = stol(temp); 
        // convert ID into long. will throw exception if unable to parse 

        // Setup Basic Contestant Info
        (ptr + i)->ID = ID;
        (ptr + i)->size = sizeof(keySize);
        (ptr + i)->Qptr = nullptr; 

        //initialize question array
        (ptr + i)->Qptr = createCharArray((ptr + i)->size);

        //j is the element number to store a contestants answers
        char ch;
        //cout << "keySize: " << keySize << endl;
        for (int j = 0; j < keySize; j++) {
          //cout << "j: " << j << endl;
          file.seekg(1,ios::cur);       // advance cursor past space
          file.get(ch);                 // grab contestant answer
          *((ptr + i)->Qptr + j) = ch;  // store in array
        }
      }

    } catch (...) {
      cerr << "Contestant File Format incorrect" << endl;
      exit(-1);
    }
    return ptr;
  } else {
    cerr << "File Error in parseContestants()." << endl;
    return nullptr;
  }
}
