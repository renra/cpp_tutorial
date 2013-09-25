#include <iostream>
using namespace std;

struct Person{
  string name;
  int born_on;
  void speak(){cout << "I have spoken" << endl;}
} Johnny;

void struct_exercise(){
  Johnny.name = "Honza";
  Johnny.born_on = 27;
  Johnny.speak();
}
