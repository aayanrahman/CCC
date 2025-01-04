#include <iostream>
using namespace std;

int main() {
    int D, Y;
    cin >> D;

    while (true) {
        cin >> Y;
        if (Y < D) {
            D += Y;  // Update Dusa's size correctly
        } else {
            break;  // Exit the loop when Dusa runs away
        }
    }

    cout << D << endl;  // Output Dusa's final size
    return 0;
}