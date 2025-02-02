#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void solve() {
    int N;
    cin >> N;
    
    // Read mountain cars into vector (from top to bottom)
    vector<int> mountain(N);
    for (int i = 0; i < N; i++) {
        cin >> mountain[i];
    }
    
    stack<int> branch;
    int mtnCar = N - 1;  // Index of current mountain car (starting from bottom)
    int nextCar = 1;     // Next car we need in the lake
    bool possible = true;
    
    while (possible && nextCar <= N) {
        // If next needed car is on mountain, take it
        if (mtnCar >= 0 && mountain[mtnCar] == nextCar) {
            mtnCar--;
            nextCar++;
        }
        // If next needed car is on branch, take it
        else if (!branch.empty() && branch.top() == nextCar) {
            branch.pop();
            nextCar++;
        }
        // Otherwise, try moving a car from mountain to branch
        else if (mtnCar >= 0) {
            branch.push(mountain[mtnCar]);
            mtnCar--;
        }
        // If we can't do any of above, it's impossible
        else {
            possible = false;
        }
    }
    
    cout << (possible ? "Y" : "N") << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}