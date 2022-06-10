
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int N, M;
int parent[MAXN];
int find_set(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find_set(parent[x]);
}

void union_sets(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if(u!=v)
        parent[v] = u;
}



int main() {
    cin>>N>>M;
    for (int i = 1; i <= N; ++i) parent[i] = i;
    char s[10];
    for (int i = 1, u, v; i <= M; ++i) {
        cin>>s>>u>>v;
        if (s[0] == 'u') {
            union_sets(u, v);
        } else {
            puts(find_set(u) == find_set(v) ? "YES" : "NO");
        }
    }
   


	// your code goes here
	return 0;
}
