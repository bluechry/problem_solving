// Problem ID: HELLOWORLD
//
// Problem Definition
//   사람들의 이름들을 받아서 "Hello, 이름!" 이라고 출력한다.
//   사람들의 수는 1명 이상 50명 이하이다.
//
// Description
//   For given people's names, print "Hello, name!".
//   The number of people is not less than 1 and not more than 50.

#include <iostream>

using namespace std;

void SayHello(const string& name) {
  cout << "Hello, " << name << '!' << endl;
}

int main() {
  int num_cases;
  cin >> num_cases;
  while (num_cases--) {
    string name;
    cin >> name;
    SayHello(name);
  }
  return 0;
}
