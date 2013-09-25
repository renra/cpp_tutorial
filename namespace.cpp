#include <iostream>
using namespace std;

namespace France {
  string greeting = "Bonjour";
}

namespace Czechia {
  string greeting = "Dobrý den";
  string greeting_alternative = "Zdár";
}

void namespace_exercise(){
  using France::greeting;

  cout << France::greeting << endl;
  cout << Czechia::greeting << endl;
  cout << greeting << endl;

  using namespace Czechia;
  cout << greeting << endl;               //This is still Bonjour!!!
  cout << greeting_alternative << endl;
}
