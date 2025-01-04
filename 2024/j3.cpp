#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N, S;
    cin >> N;
    vector<int> V;

    while (cin >> S) {
        V.push_back(S);
        if (V.size() == N) {
            break;
        }
    }

    sort(V.begin(), V.end(), greater<int>()); // Sort scores in descending order

    // Find the third unique score
    set<int> uniqueScores; // Use a set to track unique scores
    int thirdHighest = -1;

    for (int score : V) {
        uniqueScores.insert(score); // Add the score to the set
        if (uniqueScores.size() == 3) { // Stop once we have the third unique score
            thirdHighest = score;
            break;
        }
    }

    if (thirdHighest == -1) {
        cout << "Not enough unique scores" << endl; // Handle cases where there aren't 3 unique scores
    } else {
        // Count how many participants have the third-highest score
        int count = 0;
        for (int score : V) {
            if (score == thirdHighest) {
                count++;
            }
        }

        cout << thirdHighest << " " << count << endl; // Print the result
    }

    return 0;
}