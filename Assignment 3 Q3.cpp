
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000 + 5;

int n, m;
int parent[MAXN];
struct Edge {
    int u, v, weight;
    bool operator < (Edge const& other)  {
        return weight < other.weight;
    }
};
vector<Edge> edges;

int find_set(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find_set(parent[x]);
}


bool union_sets (int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) return 0;
    parent[y] = x;
    return 1;
}

int main() {
    cin>>n>>m;
    for (int i = 1; i <= n; ++i) 
    parent[i] = i;
    edges.resize(m);
    for (Edge &e : edges) {
        cin>>e.u>>e.v>>e.weight;
    }
    sort(edges.begin(), edges.end());
    long long cost = 0;
    for (Edge e : edges) {
        if (union_sets(e.u, e.v)) 
        cost += e.weight;
    }
    cout<< cost;

	// your code goes here
	return 0;
}
