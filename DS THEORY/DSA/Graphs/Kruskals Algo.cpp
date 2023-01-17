#include<iostream>
#include<bits\stdc++.h>
using namespace std;
#include<vector>
#include<algorithm>
    bool cmp(vector<int>&a,vector<int>&b)
    {
        // we are sorting it by weights
        return a[2] < b[2];
    }

// implementation of disjoint set
void Initiallization( vector<int> &parent,vector<int> &rank,int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent,int x)
{
    if(parent[x] == x)
    {
        return x;
    }
    else
    {
        return parent[x] = findParent(parent,parent[x]);
    }
}

void UnionSet(vector<int> &parent,vector<int> &rank,int a,int b)
{
    int x = findParent(parent,a);
    int y = findParent(parent,b);
    if(rank[x] < rank[y])
    {
        parent[x] = y;
    }
    else if(rank[y] < rank[x])
    {
        parent[y] = x;
    }
    else
    {
        parent[x] = y;
        rank[y]++;
    }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    // sorting by weights
    sort(edges.begin(),edges.end(),cmp);
    // CODE FOR THE DISJOINT OF SET USING RANK AND PATH COMPRESION
     vector<int> parent(n);
     vector<int> rank(n);
     Initiallization(parent,rank,n);
     int ans = 0;
    for(int i=0;i<edges.size();i++)
    {
        int e = findParent(parent,edges[i][0]);
        int v = findParent(parent,edges[i][1]);
        // [i][0] consist edges
        // [i][1] consist vertice
        // [i][2] consist weight
        int weight = edges[i][2];
        if(e!=v)
        {
            ans +=weight;
            UnionSet(parent,rank,e,v);
        }
    }
    return ans;
    
}
int main()
{

 return 0;

}

