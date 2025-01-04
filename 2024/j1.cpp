#include <iostream>
#include <string>
using namespace std;

int main() {
   int R, G, B;
   cin >> R >> G >> B;
   int P = R*3+G*4+B*5;
   cout << P << endl;
   return 0;
}