#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int K, m;
    cin >> K >> m;

    vector<int> invitees;
    for (int i = 1; i <= K; i++) {
        invitees.push_back(i);
    }

    // Process m rounds
    for (int i = 0; i < m; i++) {
        int r;
        cin >> r;

        vector<int> to_remove;
        // Identify positions to remove (1-based positions)
        for (int pos = 1; pos <= invitees.size(); pos++) {
            if (pos % r == 0) {
                to_remove.push_back(pos - 1); // Convert to 0-based index
            }
        }

        // Remove from highest index first to avoid shifting issues
        reverse(to_remove.begin(), to_remove.end());
        for (int idx : to_remove) {
            invitees.erase(invitees.begin() + idx);
        }
    }

    // Output remaining invitees
    for (int num : invitees) {
        cout << num << endl;
    }

    return 0;
}