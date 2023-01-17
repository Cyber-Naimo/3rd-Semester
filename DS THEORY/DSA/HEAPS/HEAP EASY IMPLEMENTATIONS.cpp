#include<iostream>
using namespace std;
		
	
		void MaxHeapify(int arr[],int i, int n)
		{
			int largest = i;
			int left = 2*i+1;
			int right = 2*i+2;
			
			if(left < n && arr[left] > arr[largest])
			{
				largest = left;
			}
			if(right<n && arr[right] > arr[largest])
			{
				largest = right;
			}
			
			if(largest!=i)
			{
				swap(arr[i],arr[largest]);
				MaxHeapify(arr,largest,n);
			}
		}
		void MinHeapify(int arr[],int i, int n)
		{
			int largest = i;
			int left = 2*i+1;
			int right = 2*i+2;
			
			if(left < n && arr[left] < arr[largest])
			{
				largest = left;
			}
			if(right<n && arr[right] < arr[largest])
			{
				largest = right;
			}
			
			if(largest!=i)
			{
				swap(arr[i],arr[largest]);
				MinHeapify(arr,largest,n);
			}
		}
		void BuildMaxHeap(int arr[],int n)
		{
			for(int i=n/2-1;i>=0;i--)
			{
				MaxHeapify(arr,i,n);
			}
		}
		
		void BuildMinHeap(int arr[],int n)
		{
			for(int i=n/2-1;i>=0;i--)
			{
				MinHeapify(arr,i,n);
			}
		}
		void Display(int arr[],int n)
		{
			for(int i =0;i<n;i++)
			{
				cout<<" "<<arr[i]<<"--> ";
			}cout<<endl;
		}
		void HeapSort(int arr[],int n)
		{
//			BuildMaxHeap(arr,n);
			for(int i=n-1;i>=0;i--)
			{
				swap(arr[0],arr[i]);
				MaxHeapify(arr,0,i);
			}
		}
		void Deletion(int arr[],int n, int i)
		{
			int last = arr[n-1];
			arr[i] = last;
			n = n-1;
			MaxHeapify(arr,i,n);
		}
int main()
{
	int arr[] = {35,33,42,10,14,19,27,44,26,31};
	int n = 10;
	
	// Building Max Heap
	BuildMaxHeap(arr,n);
	cout<<"MAX HEAP: "<<endl;
	Display(arr,n);
	cout<<endl;
	//part a
	cout<<"MAX HEAP After Deletion: "<<arr[2]<<endl;
	Deletion(arr,n,2);

	Display(arr,n);
	cout<<endl<<endl;
	
	// part C
	cout<<"HEAP SORT:"<<endl;
	HeapSort(arr,n);
	Display(arr,n);
	cout<<endl;
	// Building Min Heap
	for(int i=n/2-1;i>=0;i--)
	{
		MinHeapify(arr,i,n);
	}
	cout<<"MIN HEAP: "<<endl;
	Display(arr,n);
	cout<<endl;
	//part 	B
	cout<<"Min HEAP After Deletion: "<<arr[0]<<endl;
	Deletion(arr,n,0);
	cout<<"MIN HEAP: "<<endl;
	Display(arr,n);
	cout<<endl<<endl;
	return 0;

}

