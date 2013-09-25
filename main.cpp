#include <iostream>

#include "macros.hpp"
#include "functions.hpp"

using namespace std;

//Largely based on the book C++ Language Tutorial written by Juan Soulié
int main(){
  cout << "I'm on line: " << __LINE__ << endl;
  cout << "I'm in file: " << __FILE__ << endl;
  cout << "It's: " << __DATE__ << " " << __TIME__ << endl;
  cout << "I've been compiled with: " << __cplusplus << endl;
  separate();

  int i = 0;
  letter a ('a');
  letter c = 'c', d = 'd';                     //Not possible in C

  increment_with_pointer(&i);
  cout << "The value on address: " << &i << " is: " << i << endl;
  increment_with_address(i);
  cout << "The value on address: " << &i << " is: " << i << endl;
  separate();

  print_data_types_info();
  separate();

  io_exercise();
  separate();
  
  function_pointer_exercise();
  separate();

  memo_exercise();
  separate();

  struct_exercise();
  separate();

  union_exercise();
  separate();

  enum_exercise();
  separate();

  oop_exercise();
  separate();

  template_exercise();
  separate();

  namespace_exercise();
  separate();

  exception_exercise();
  separate();

  typeid_exercise();
  separate();

  casting_exercise();
  separate();

  return 0;
}
