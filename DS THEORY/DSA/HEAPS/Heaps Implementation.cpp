#include<iostream>
using namespace std;
#include<queue>
class Heap
{
	public:
		int arr[100];
		int size;
		
		Heap()
		{
			arr[0] = -1;
			size = 0;
		}
		void Display()
		{
			for(int i=1;i<=size;i++)
			{
				cout<<" "<<arr[i]<<" --> ";
			}
			cout<<"NULL";
		}
		void Insert(int data)
		{
			size +=1;			// we started from 1st index
			int i = size;		// creating local varible for handling 
			arr[i] = data;		// taking data
			while(i>1)			// it stop when its reaches 1st index
			{
				int parent = (i/2);
				if(arr[parent] < arr[i])
				{
					swap(arr[i],arr[parent]);
					i = parent;
				}
				else
				{
					return;
				}
			}
		}
		void Deletion()
		{
			if(size == 0)
			{
				return;
			}
			else
			{
				arr[1] = arr[size];			// taking last nodes to delete
				size--;						// removing last node now;
				
				int i = 1;
				// taking root node to its correct position
				while(i<size)
				{
					int rightchild = 2*i+1;
					int leftchild = 2*i;
					
					if(leftchild < size && arr[i] < arr[leftchild] )
					{
						swap(arr[i],arr[leftchild]);
						i = leftchild;
					}
					if(rightchild < size && arr[i] >  arr[rightchild])
					{
						swap(arr[i],arr[rightchild]);
						i = rightchild;
					}
					else
					{
						return;
					}
				}
			}
		}
		
		
};
void Heapify(int arr[],int n, int i)
{
	int largest = i;
	int rightchild = 2 * i + 2;
	int leftchild = 2 * i + 1;
	
	if(leftchild < n &&  arr[leftchild] > arr[largest])
	{

		largest = leftchild;
	}
	 if(rightchild < n && arr[rightchild] >  arr[largest] )
	{
		largest = rightchild;
	}
	
	if(largest!=i)
	{
		swap(arr[i],arr[largest]);
		Heapify(arr,n,largest);
	}
}

void HeapSort(int arr[], int n)
{
	for(int i = n/2-1;  i>= 0 ; i--)
	{
		Heapify(arr,n,i);
	}
	
	for(int i = n-1;i>=0;i--)
	{
		swap(arr[i],arr[0]);
		Heapify(arr,i,0);
	}
}
void Print(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<" "<<arr[i]<<" --> ";
	}
	cout<<"NULL"<<endl;
}
int main()
{
	Heap h;
	h.Insert(50);
	h.Insert(55);
	h.Insert(53);
	h.Insert(52);
	h.Insert(54);
//	h.Display();
//	cout<<"\n\n";
//	h.Deletion();
//	h.Display();
	
	int arr[] = {54,53,55,52,50};
	int n = 5;
	Print(arr,n);
	HeapSort(arr,n);
	cout<<"AFTER SORTING: "<<endl;
	Print(arr,n);
	
	// MAX HEAPS USING STL
//	priority_queue<int> pq;
//	pq.push(40);
//	pq.push(90);
//	pq.push(50);
//	pq.push(10);
//	cout<<" Top: "<<pq.top()<<endl;
//	pq.pop();
//	cout<<" Top: "<<pq.top()<<endl;
//	cout<<" SIZE : "<<pq.size()<<endl;
//
//	// MIN HEAPS USING STL
//	priority_queue<int,vector<int>,greater<int> > m;
//	m.push(40);
//	m.push(90);
//	m.push(50);
//	m.push(10);
//	cout<<" Top: "<<m.top()<<endl;
//	m.pop();
//	cout<<" Top: "<<m.top()<<endl;
//	cout<<" SIZE : "<<m.size()<<endl;
}

