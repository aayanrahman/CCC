#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i = 0; i < N; i++) {
        cin >> H[i];
    }
    int count = 0; 

    // iterate through the first N/2 seats as opposite realtionships are symentrical
    for (int i=0; i<N/2; i++){
        // for each seat check if the opposite seat is the same
        // each seat being i compare with H[i] and H[i+N/2]
        if(H[i]==H[i+N/2]){
            count++;
        }
        if(H[i+N/2]==H[i]){
            count++;
        }
    }
    // Output the number of times this happens 
    cout << count << endl;
    return 0;
}