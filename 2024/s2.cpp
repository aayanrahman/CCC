#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isAlternating(const string& s) {
    unordered_map<char, int> freq;
    int n = s.size();

    //count the frequency of each letter
    for(char c : s) {
        freq[c]++;
    }

    // determine if the string alternates
    bool oddLight = (freq[s[0]] == 1); // First position is light if freq[s[0]] == 1
    for(int i = 0; i < n; i++) {
        bool isLight = (freq[s[i]] == 1);
        // check alternating condition
        if (i % 2 == 0 && isLight != oddLight) return false; 
        if (i % 2 == 1 && isLight == oddLight) return false; 
    }

    return true;
}

int main() {
    int T, N;
    cin >> T >> N;
    vector<string> strings(T);
    
    // read in the strings the user inputs 
    for (int i = 0; i < T; i++) {
        cin >> strings[i];
    }

    // iterate through the strings and check if they are alternating
    for (const string& s : strings) {
        if (isAlternating(s)) {
            cout << "T" << endl;
        } else {
            cout << "F" << endl;
        }
    }

    return 0;
}