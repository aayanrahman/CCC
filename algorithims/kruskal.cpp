#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct Edge {
    int u, v, weight;
};

vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    parent[find(a)] = find(b);
}

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);

    int cost = 0;
    for (auto& e : edges) {
        if (find(e.u) != find(e.v)) {
            unite(e.u, e.v);
            cost += e.weight;
        }
    }
    return cost;
}
