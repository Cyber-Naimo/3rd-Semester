#include<iostream>
#include<bits\stdc++.h>
using namespace std;
struct Node
{
		int data;
		struct Node* next;
};
struct AdjList
{
	struct Node* head;
};
class Graph
{
	public:
		int V;
		AdjList* array;
		 Graph(int V)
		 {
		 	this->V = V;
		 	array = new AdjList[V];
		 	for(int i=0;i<V;i++)
		 	{
		 		array[i].head = NULL;
			}
		 }
		 
		 void AddEdges(int u,int v)
		 {
		 	AdjList* newNode = new AdjList;
		 	newNode->data = v;
		 	newNode->next = NULL;
		 }
};
int main()
{

 return 0;

}

