
#include <bits/stdc++.h>
using namespace std;

// Variable to keep track of time
int Time = 1;

// Function to perform DFS starting from node u
void dfs(int u, vector<vector<int>> adj,
					vector<int> &time_in,
					vector<int> &time_out,
					vector<int> &Visited)
{
	
	// Storing the pre number whenever
	// the node comes into recursion stack
	time_in[u] = Time;

	// Increment time
	Time++;
	Visited[u] = 1;
	
	for(int v : adj[u])
	{
		if (Visited[v] == 0)
			dfs(v, adj, time_in, time_out, Visited);
	}

	// Storing the post number whenever
	// the node goes out of recursion stack
	time_out[u] = Time;
	Time++;
}

// Driver Code
int main()
{
	
	// Number of nodes in graph
	int n = 6;

	// Adjacency list
	vector<vector<int>> adj(n + 1);
	
	vector<int> time_in(n + 1);
	vector<int> time_out(n + 1);

	// Visited array
	vector<int> Visited(n + 1);

	// Edges
	adj[1].push_back(2);
	adj[2].push_back(1);
	adj[2].push_back(4);
	adj[4].push_back(2);
	adj[1].push_back(3);
	adj[3].push_back(1);
	adj[3].push_back(4);
	adj[4].push_back(3);
	adj[3].push_back(5);
	adj[5].push_back(3);
	adj[5].push_back(6);
	adj[6].push_back(5);

	// DFS starting at Node 1
	dfs(1, adj, time_in, time_out, Visited);

	// Number of nodes in graph
	for(int i = 1; i <= n; i++)
		 cout << "Node " << i <<endl << " Time in  "
             << time_in[i] << " Time out "
             << time_out[i] << endl;
		
	// your code goes here	return 0;
	return 0;
}

