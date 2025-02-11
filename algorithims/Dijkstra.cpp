#include <vector>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

vector<vector<pair<int, int>>> adj; // (neighbor, weight)

vector<int> dijkstra(int start, int n) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first, node = pq.top().second;
        pq.pop();

        if (d > dist[node]) continue;

        for (auto [neighbor, weight] : adj[node]) {
            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected
    }

    vector<int> shortest = dijkstra(0, n);
    for (int d : shortest) cout << d << " ";
}
