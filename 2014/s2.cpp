#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();  

    string S, S1;
    getline(cin, S);
    getline(cin, S1);

    vector<string> v1, v2;
    istringstream iss(S), iss1(S1);
    string name;

    while (iss >> name) {
        v1.push_back(name);
    }
    while (iss1 >> name) {
        v2.push_back(name);
    }

    // Create a mapping of partners
    for (int i = 0; i < N; i++) {
        string A = v1[i];
        string B = v2[i];

        if (A == B) { // Check if someone is partnered with themselves
            cout << "bad" << endl;
            return 0;
        }

        // Find B in v1 and check if its assigned partner is A
        int idx = -1;
        for (int j = 0; j < N; j++) {
            if (v1[j] == B) {
                idx = j;
                break;
            }
        }

        if (idx == -1 || v2[idx] != A) {
            cout << "bad" << endl;
            return 0;
        }
    }

    cout << "good" << endl;
    return 0;
}