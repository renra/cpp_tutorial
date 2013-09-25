#include <iostream>
#include <typeinfo>
using namespace std;

//Macro function can be used instead of a universal template function
//Typeid uses RTTI
#define compare(a, b) (typeid(a) == typeid(b))

void typeid_exercise(){
  int a, b;
  long c;

  cout << "The varibales a and b are of type: " << typeid(a).name() << endl;
  cout << "The varibale c is of type: " << typeid(c).name() << endl;

  cout << "The variables a and b are the same: " << compare(a, b) << endl;
  cout << "The variables a and c are the same: " << compare(a, c) << endl;
}

//Clean up not to pullute the rest of the code
#undef compare
