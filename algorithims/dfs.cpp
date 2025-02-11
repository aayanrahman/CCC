#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node){
    visited[node] = true; 
    cout << node << " ";

    for (int neighbor: adj[node] ) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0);
}