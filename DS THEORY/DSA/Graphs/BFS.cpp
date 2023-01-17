#include<iostream>
#include<bits\stdc++.h>
using namespace std;
void BFS (int arr[][7],int start,int n)
{
	int i=start;
	int visited[n] = {0};
	cout<<" "<<i<<" --> ";
	visited[i] = 1;
	
	queue<int> q;
	q.push(i);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		
		for(int v = 1;v<=n;v++)
		{
			if(arr[u][v] == 1 && visited[v] == 0)
			{
				cout<<" "<<v<<" --> ";
				visited[v] = 1;
				q.push(v);
			}
		}
	}
}
	void solve(int i,bool *visited,vector<int> &ans,int V,vector<int> adj[])
    {

        visited[i]=true;

        ans.push_back(i);

        for(auto neighbour:adj[i])
        {

            if(visited[neighbour]==0)
            {
                solve(neighbour,visited,ans,V,adj);
            }

        }

    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {

        // Code here

        bool visited[V]={false};

        vector<int> ans;

        solve(0,visited,ans,V,adj);

        return ans;

    }

int main()
{
	int arr[7][7] = {{0,0,0,0,0,0,0},
				    {0,0,1,1,0,0,0},
					{0,1,0,0,1,0,0},
					{0,1,0,0,1,0,0},
					{0,0,1,1,0,1,1},
					{0,0,0,0,1,0,0},
					{0,0,0,0,1,0,0}};
		BFS(arr,5,7);
 return 0;

}

