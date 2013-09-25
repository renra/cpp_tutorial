#include <iostream>

using namespace std;

void print_data_types_info(){
  //cout << "The size of void is: " << sizeof(void) << endl;                //Generates a warning
  cout << "The size of bool is: " << sizeof(bool) << endl;                //true and false
  cout << "The size of char is: " << sizeof(char) << endl;
  cout << "The size of wchar_t is: " << sizeof(wchar_t) << endl;          //L"One two three"
  cout << "The size of short is: " << sizeof(short) << endl;
  cout << "The size of int is: " << sizeof(int) << endl;
  cout << "The size of long is: " << sizeof(long) << endl;
  cout << "The size of float is: " << sizeof(float) << endl;              //54.56F
  cout << "The size of double is: " << sizeof(double) << endl;
  cout << "The size of long double is: " << sizeof(long double) << endl;  //54.56L
  cout << "The size of long long is: " << sizeof(long long) << endl;
}
