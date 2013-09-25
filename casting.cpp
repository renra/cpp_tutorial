#include <iostream>
#include <exception>
using namespace std;

class FirstSource{
  public:
  virtual void generate(){};
};

class Elohim : public FirstSource{
  public:
  void genereate() {}
};

void point_to_nowhere(int** p_number){
  *p_number = NULL;
}

void casting_exercise(){
  int i;
  float f = 10.54;

  //implicit casting
  i = f;
  cout << "The cast integer is: " << i << endl;

  //explicit casting
  i = (int) f;  //C-like notation
  cout << "The cast integer is: " << i << endl;

  i = int(f);   //function notation
  cout << "The cast integer is: " << i << endl;

  //dynamic_cast -- ensures that the result is a complete object therefore may be slower, use only with pointers and references, 
  //  source type has to be polymorphic
  //Uses RTTI - Run-Time Type information, some compilers disable it by default
  FirstSource* p_fs = new FirstSource;
  FirstSource* p_fs2 = new Elohim;
  Elohim* p_e = NULL;
  
  //Causes SEGFAULT ???
  //p_e = dynamic_cast<Elohim*>(p_fs);


  //static_cast -- no safety checks, can be used to cast an Ancestor class to a Descendant
  p_e = static_cast<Elohim*>(p_fs);
  if(p_e == 0){
    cout << "Static cast failed" << endl;
  }

  // can be used as the standard explicit cast
  i = static_cast<int>(f);
  cout << "The cast integer is: " << i << endl;

  //reinterpret_cast -- trans-class casting, no checks
  void* p_void;
  p_void = reinterpret_cast<void*>(p_fs2);
  if(p_void == 0){
    cout << "Reinterpret cast failed" << endl;
  }

  //const_cast -- toggles the const attribute
  const int* p_i = &i;
  cout << "The pointer points to: " << p_i << endl;

  //Very dirty
  point_to_nowhere(const_cast<int**>(&p_i));
  cout << "The pointer points to: " << p_i << endl;

  delete p_fs;
  delete p_fs2;
  delete p_e;
}
