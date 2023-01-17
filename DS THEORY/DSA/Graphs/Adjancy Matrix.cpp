#include<iostream>
#include<bits\stdc++.h>
using namespace std;
	int arr[20][20];		// 0
class Graph
{
	public:
		
	
		// function for creating adjancy Matrix
		void AddEdges(int row,int col)
		{
			arr[row][col] = 1;
			arr[col][row] = 1;
		}
		
		// dunction to print Adjency Matrix
		void DisplayAdjencyMatrix(int n)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					cout<<" "<<arr[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		
};
int main()
{
	// n = No of nodes
	int n;
	cout<<"ENTER NO OF NODES: "<<endl;
	cin>>n;
	int edges;
	cout<<"Enter No of Edges: "<<endl;
	cin>>edges;
	Graph g;
	cout<<"Enter Edges Connection : "<<endl;
	for(int i=0;i<edges;i++)
	{
		int row,col;
		cin>>row>>col;
		// now creating an edges
		g.AddEdges(row,col);
	}
	cout<<"Adjancy Matrix: "<<endl;
	g.DisplayAdjencyMatrix(n);
	/*
	1 0
	1 2
	2 3
	3 1
	3 4
	0 4
	*/
	/*
	 AdjancyMatrix for directed graphs;
	int n,m;
    cin >> n >> m;
    vector<vector<int>> ans(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
	{
        int u,v;
        cin >> u >> v;
        ans[u][v] = 1;
    }    
    for(int i=0;i<n;i++)
	{
        for(int j = 0;j<n;j++)
		{
            cout << ans[i][j] << " ";
        }
		cout << endl;
    }
    */
}

