#include <iostream>
#include <sstream>

using namespace std;

void memo_exercise(){
  string memo_size_tainted;
  int memo_size;

  cout << "Hi there. How much memory would you like to allocate?" << endl;
  getline(cin, memo_size_tainted);
  stringstream(memo_size_tainted) >> memo_size;

  if(memo_size > 100){
    cout << "Too much for the training purposes. Signing off." << endl;
    return;
  }

  //Allocating on the heap
  int* pool = new (nothrow) int[memo_size];

  if(pool == 0){
    cerr << "Could not allocate memory. It's a precious resource." << endl;
  }
  else{
    cout << "Dynamic allocation successful" << endl;
  }

  //Free the memo. Very important!!!! Works for null pointers.
  delete [] pool;
}
