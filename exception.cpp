#include <iostream>
#include <exception>
using namespace std;

class TrainingException : public exception{
  public:
  string what(){
    return "You must not do that";
  }
};

//throw() -- must not throw, not stopped by compiler which leads to runtime errors
//without throw completely -- can throw anything
void ex_thrower() throw(TrainingException){
  TrainingException ex;
  throw ex;
}

void exception_exercise(){
  try{
    ex_thrower();
  }
  catch(TrainingException& te){
    cout << "Caught exception: " << te.what() << endl;
  }
  //Catches any kind of exception, but not the ones illegally thrown
  catch(...){
    cout << "Unknown exception caught" << endl;
  }
}
