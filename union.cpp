#include <iostream>
using namespace std;

//Anonymous union
//Anonymous struct is possible too but generates a warning
struct Furniture{
  union {
    float meters;
    float inches;
  } width;
  union {
    int model_international_code;
    int model_code;
  };
} cupboard;

void union_exercise(){
  cupboard.model_code = 123;
  cupboard.width.meters = 1.2;
  cout << "The cupboard's code is: " << cupboard.model_code << endl;
}
