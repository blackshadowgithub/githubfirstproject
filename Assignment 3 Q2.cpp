
#include <bits/stdc++.h>
#include<vector>
using namespace std;

const int MAXN = 50000 + 5;

int n, m,k;
set<pair<int, int>> S;
vector<pair<int, pair<int, int>>> a;
vector<int> answer;
int parent[MAXN];

int find_set(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find_set(parent[x]);
}
void union_sets(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u!= v)
        parent[v] = u;
}


int main() {
    cin>>n>>m>>k;
    for (int i = 1, u, v; i <= m; ++i) {
        cin>>u>>v;
        S.insert({min(u, v), max(u, v)});
    }
    char s[5];
    for (int i = 1, u, v; i <= k; ++i) {
        cin>>s>>u>>v;
        a.push_back({s[0] == 'c', {u, v}});
        if (s[0] == 'c') S.erase({min(u, v), max(u, v)});
    }
    for (int i = 1; i <= n; ++i) 
    parent[i] = i;
    for (auto x : S) 
    union_sets(x.first, x.second);
    for (int i = k - 1; i >= 0; --i) {
        if (a[i].first == 0) {
            answer.push_back(find_set(a[i].second.first) == find_set(a[i].second.second));
        } else {
            union_sets(a[i].second.first, a[i].second.second);
        }
    }
    for (int i = answer.size() - 1; i >= 0; --i) {
        puts(answer[i] ? "YES" : "NO");
    }
    
	// your code goes here
	return 0;
}


	

