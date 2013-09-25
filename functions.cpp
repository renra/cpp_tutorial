#include <iostream>
using namespace std;

//The compiler will probably make this inline on its own
void separate(){ cout << "********" << endl << endl; }

int add(int, int);

int add(int x, int y){
  return x+y;
}

void increment_with_pointer(int * a){
  cout << "About to increment the value on address: " << a << endl;
  (*a)++;
}

void increment_with_address(int& a){
  cout << "About to increment the value on address: " << &a << endl;
  a++;
}

int call_function(int param1, int param2, int (*function_to_call)(int, int)){
  return (*function_to_call)(param1, param2);
}

void function_pointer_exercise(){
  //Function alias
  int (*func)(int, int) = add;
  cout << "Calling add via function pointers: " << call_function(1, 2, func) << endl;
}
