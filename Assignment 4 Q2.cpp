
#include <bits/stdc++.h>

using namespace std;


 

const int INF = 1000000000;
const int modb = 1000000007;



void dijkstra(vector<vector<pair<int,int>>> &adj,int s,vector<long long> &d,vector<long long> & route,vector<int> & min_f, vector<int> & max_f)
{
    int n = adj.size();
    // d.assign(n+1,INF);
    
    using pii = pair<long long,int>;
	priority_queue< pii, vector<pii>, greater<pii> > q;
	q.push({0,s});
	d[s] = 0;
	route[s] = 1;
	min_f[s]=max_f[s]=0;
	while(!q.empty())
	{
		int v = q.top().second;
		long long d_v = q.top().first;
		q.pop();
		if(d_v !=  d[v])
		continue;
		for(auto edge : adj[v])
		{
			int to = edge.first;
			int len = edge.second;
			if(len+d_v > d[to]) continue;
			if(len+d_v == d[to]) 
			{
				route[to] += route[v];
				route[to] %= modb;
				min_f[to] = min(min_f[v]+1, min_f[to]);
				max_f[to] = max(max_f[v]+1, max_f[to]);
			}
			if(len+d_v < d[to])
			{
				d[to] = len+d_v;
				route[to] = route[v];
				min_f[to] = min_f[v]+1;
				max_f[to] = max_f[v]+1;
				q.push({d[to],to});
			}
		}
	}
}
int main()
{
	int n, m;
    cin >> n >> m;
vector<long long>d(n+1, 1000000000000000002); 
vector<long long>route(n+1, 0) ;
vector<int> min_f(n+1, INT_MAX);
vector<int> max_f(n+1, 0);
vector<vector<pair<int,int>>> adj(n+1);

	
	for(int i = 0; i <m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b,c));
	}
	// for(int i = 2; i <= n; ++i)
	// {
	// 	d[i] = INF;
	// }
	int s=1;
	dijkstra(adj,s,d,route,min_f,max_f);
	cout << d[n] <<" " <<route[n] <<" "<<min_f[n] <<" "<<max_f[n] << endl;


	// your code goes here
	return 0;
}


