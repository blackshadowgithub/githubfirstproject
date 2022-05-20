
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<bool> visited;
vector<int> low,tin;     
vector<vector<int>> adjlist;    // adjacency list representing graph
int timer=0;        // current discovery time
void dfs(int s,vector<pair<int,int>> &bridges,int p=-1){
    visited[s]=true;
    low[s]=tin[s]=timer++;        // current value of tin[i] and low[i] equal to timer
    for(auto x:adjlist[s]){
        if(x==p) continue;          // if edge is connecting to parent then skip
        if(visited[x]) 
        low[s]=min(low[s],tin[x]); // if visited then take the minimum value
                                    // of discovery time of current vertex and terminus vertex. 
        else{
            dfs(x,bridges,s);
            low[s]=min(low[s],low[x]);      // propagate the change to the parent...
            if(low[x]>tin[s]){
                bridges.push_back({s+1,x+1});
            }
        }
    }
}
void findBridges(vector<pair<int,int>> &bridges){
    int n=adjlist.size();
    low.resize(n,-1); 
    tin.resize(n,-1);
    visited.resize(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i])
            dfs(i,bridges);
    }
}
int main(){
    int n,e; cin>>n>>e;
    adjlist.resize(n);
    for(int i=0;i<e;i++){   
        int u,v; cin>>u>>v;
        adjlist[u-1].push_back(v-1);
        adjlist[v-1].push_back(u-1);
    }
    vector<pair<int,int>> bridges;
    cout<<"Bridges: \n";
    findBridges(bridges);
    for(auto x:bridges) cout<<x.first<<" "<<x.second<<"\n";
    
    // your code goes here

    return 0;
}

	

