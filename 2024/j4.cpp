#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    // Add a common character to the end of both strings to simplify edge cases
    s += ".";
    t += ".";

    char quiet = '-';
    char sillyOriginal = '-'; // Original character pressed for the silly key
    char sillyResult = '-';   // Resulting character displayed for the silly key

    // Step 1: Find the result of the silly key
    for (char c = 'a'; c <= 'z'; ++c) {
        if (t.find(c) != string::npos && s.find(c) == string::npos) {
            sillyResult = c;
            break;
        }
    }

    // Step 2: Process both strings to determine the original silly key and quiet key
    size_t i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            // Same letter, move both pointers
            ++i;
            ++j;
        } else if (t[j] == sillyResult) {
            // Result is the silly key; s[i] must be the original key
            sillyOriginal = s[i];
            ++i;
            ++j;
        } else {
            // Result is not the silly key; s[i] must be the quiet key
            quiet = s[i];
            ++i; // Only increment `i` for the quiet key
        }
    }

    // Step 3: Output the results
    cout << sillyOriginal << " " << sillyResult << endl;
    cout << quiet << endl;

    return 0;
}
