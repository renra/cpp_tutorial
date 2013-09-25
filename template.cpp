#include <iostream>
using namespace std;

class Mushroom{
  string name;
  int size;

  public:
  Mushroom(){
    cout << "Calling the default constructor" << endl;

    name = "";
    size = 0;
  }

  Mushroom(string name, int size){
    cout << "Calling the specialized constructor" << endl;

    this->name = name;
    this->size = size;
  }

  Mushroom(const Mushroom& factor){
    cout << "Calling the copy constructor" << endl;
    
    name = factor.name;
    size = factor.size;
  }

  bool operator> (const Mushroom& factor){
    return (size>factor.size ? true : false);
  }

  bool operator== (const Mushroom& factor){
    return (name==factor.name ? true : false);
  }

  void grow(int factor){
    size += factor;
  }

  string get_name(){
    return name;
  }
};

//From stack overflow 4421706
ostream& operator<< (ostream& os, Mushroom& m){
  os << m.get_name();
  return os;
}

//typename and class can be used interchangeably
template <typename Comparable>
Comparable& get_max(Comparable& a, Comparable& b){
  return (a>b ? a : b);
}

template <typename T>
class Container{
  public:
  T member;
  void report(){
    cout << "The member is: " << member << endl;
  }
};

//Passing by reference just to avoid additional data copy
//Might not be the best solution
template <>
class Container <Mushroom&>{
  public:
  Mushroom& member;
  void report(){
    cout << "The member is: " << member.get_name() << endl;
  }
};

void template_exercise(){
  Mushroom amanita("amanita", 2);
  Mushroom armillaria("armillaria", 1);

  armillaria.grow(2);

  //The compiler can determine the type on its own too
  cout << "And the bigger mushroom is: " << (get_max <Mushroom> (amanita, armillaria)) << endl;

  Container <int> c_i;
  c_i.member = 2;
  c_i.report();

  Container <string> c_s;
  c_s.member = "frog";
  c_s.report();

  Container <Mushroom> c_m;
  c_m.member = amanita;
  c_m.report();
}
