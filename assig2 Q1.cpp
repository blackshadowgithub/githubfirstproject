#include <bits/stdc++.h>
using namespace std;

#define l1 long long
#define ar array

const int mxN = 1e5;
int n,m,p[mxN];
vector <int> adj[mxN];
bool visited[mxN],act[mxN];
vector<int> ans;

void dfs(int u){
    visited[u]=1;
    act[u]=1;
    for(int v : adj[u]){
        if(act[v]){
            cout<<"IMPOSSIBLE";
            exit(0);
        }else{
            if(!visited[v]){
                p[v]=u;
                dfs(v);
            }
        }
    }
    act[u]=0;
    ans.push_back(u);
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m; ++i){
    
        l1 a,b;
        cin>>a>>b, --a, --b;
        adj[a].push_back(b);
    }
    for(int i=0;i<n; ++i)
    if(!visited[i])
    dfs(i);
    reverse(ans.begin(), ans.end());
    for(int u : ans)
    cout<<u+1<<" ";

	// your code goes here
	return 0;
}
