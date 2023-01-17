#include<iostream>
#include<bits\stdc++.h>
using namespace std;
class Graph
{
	public:
		unordered_map<int,set<int>> ad;
		
		// function for creating adjancy list
		void AddEdges(int row,int col,bool directed)
		{
			// 1 mean directed
			// 0 means undirected
			ad[row].insert(col);
			
			// for undirected 
			if(directed == false)
			{
				ad[col].insert(row);
			}
		}
		
		// dunction to print Adjency List
		void DisplayAdjencyList()
		{
			for(auto i:ad)
			{
				cout<<" "<<i.first<<" --> ";
				for(auto j:i.second)
				{
					cout<<" "<<j<<" , ";
				}
				cout<<endl;
			}
			
		}
		
};
int main()
{
	int n;
	cout<<"ENTER NO OF NODES: "<<endl;
	cin>>n;
	int m;
	cout<<"Enter No of Edges: "<<endl;
	cin>>m;
	Graph g;
	cout<<"Enter Edges Connection : "<<endl;
	for(int i=0;i<m;i++)
	{
		int row,col;
		cin>>row>>col;
		// now creating an edges
		g.AddEdges(row,col,0);
	}
	cout<<"Adjancy List: "<<endl;
	g.DisplayAdjencyList();
	/*
	1 0
	1 2
	2 3
	3 1
	3 4
	0 4
	*/
}

