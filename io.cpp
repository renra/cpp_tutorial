#include <iostream>
#include <sstream>
#include <fstream>
#include "functions.hpp"

#define FILENAME "names.txt"

using namespace std;

void read_contents(){
  string line;
  ifstream reader;
  reader.open(FILENAME);

  if(reader.is_open()){
    cout << "Records from the db:" << endl;
    while(!reader.eof()){
      getline(reader, line);
      cout << line << endl;
    }
    
    reader.close();
  }
  else{
    cout << "Error reading the file: " << FILENAME << endl;
  }

  separate();
}

void io_exercise(){
  string name;
  string age_tainted;
  int age;

  read_contents();

  cout << "Hello! What's your name: ";
  getline(cin, name);
  cout << "Well met, " << name << endl;

  cout << "Please, tell me your age too: ";
  cin >> age_tainted;

  stringstream(age_tainted) >> age;
  cout << "You are: " << age << " years old." << endl;

  // Modes: 
  //   ios::in
  //   ios::out
  //   ios::binary
  //   ios::app   -- output only
  //   ios::trunc
  //   ios::ate
  // They can be combined using binor: ios::in | ios::out
  ofstream file_write_stream;
  file_write_stream.open(FILENAME, ios::app);

  if(file_write_stream.is_open()){
    file_write_stream << name << "\t" << age << endl;
    cout << "Data stored" << endl;

    //The file pointer can be obtained via tellg() and tellp()
    //and manipulated via seekg() and seekp()
    //file_write_stream.seekp(0, ios::end);     The pointer should be at the end already
    ofstream::pos_type end = file_write_stream.tellp();
    
    cout << "Database size: " << end << " bytes" << endl;
  
    file_write_stream.close();  
  }
  else{
    cout << "Error opening the file" << endl;
  }



  
}
