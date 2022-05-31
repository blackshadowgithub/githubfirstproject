#include <bits/stdc++.h>
using namespace std;

#define l1 long long
#define ar array

const int mxN = 1e5;
int n,m,p[mxN],dp[mxN];
vector <int> adj[mxN];
bool visited[mxN],act[mxN];
vector<int> ans;

void dfs(int u){
    dp[u] =u==n-1?1:-1e9;
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
        if(dp[v]+1>dp[u])
        p[u]=v,dp[u]=dp[v]+1;
    }
    act[u]=0;
    
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
    if(dp[0]<0){
        cout<<"IMPOSSIBLE";
    }else{
        ans.push_back(0);
        int u=0;
        while(u^n-1){
            u=p[u];
            ans.push_back(u);
        }
    
    cout<<ans.size()<<"\n";
    for(int a : ans)
    cout<<a+1<<" ";
    }

	// your code goes here
	return 0;
}
