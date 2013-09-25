#include <iostream>
using namespace std;

enum Day {
  monday, 
  tuesday, 
  wednesday, 
  thursday, 
  friday, 
  saturday, 
  sunday
};

void enum_exercise(){
  Day today = sunday;

  //Cooool
  if(today > friday){
    cout << "Weekend!!! Time to do something great." << endl;
  }
  else{
    cout << "Get up early and off to work." << endl;
  }
}
