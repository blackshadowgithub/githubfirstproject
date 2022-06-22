
#include <bits/stdc++.h>
using namespace std;
#define int long long int
struct Edge {
    int a, b, cost;
};

int n, m;
// vector<Edge> edges;

const int INF = 1000000000;

void solve(vector<Edge> &edges, vector<int> &d, vector<int> &p)
{

    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] + e.cost < d[e.b]) {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "NO"<<endl;
    } else {
        for (int i = 0; i < n; ++i)
            x = p[x];

        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES"<<endl;
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}

int32_t main() {
    
ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n >> m;
	vector<int> d(n+1); // declaring all vectors p, d and edges in main and then passing by reference to solve function below
    vector<int> p(n+1);
    vector<Edge> edges(m);
 
	for(int i = 0; i < m; ++i)
	{
		struct Edge inp;
		cin >> inp.a >> inp.b>> inp.cost;
		edges[i] = inp;
	}
 
	for(int i = 1; i <= n; ++i)
	{
		p[i] = -1;
	}
	solve(edges, d, p); // passing vector by reference 	
	// your code goes here
	return 0;
}
