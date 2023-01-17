#include<iostream>
using namespace std;
int Partition(int arr[],int s ,int e)
{
	int count = 0;
	int pivot = arr[s];			// first element
	for(int i = 1+s;i<=e;i++)	// traversing agey wale element sa
	{
		if(arr[i] <= pivot)		// count less elements
		{
			count++;
		}
	}
	int pivotindex = count+s;		
	swap(arr[pivotindex],arr[s]);
	int i = s;
	int j = e;
	while(i< pivotindex && j> pivotindex)
	{
		while(arr[i] <= pivot)
		{
			i++;
		}
		while(arr[j] > pivot )
		{
			j--;
		}
		
		if(i<pivotindex && j>pivotindex)
		{
			swap(arr[i++],arr[j--]);
		}
	}
	return pivotindex;
}

int Partition1(int arr[],int s ,int e)
{
	int count=0;
	int pivot = arr[s];
	for(int i=s+1;i<=e;i++)
	{
		if(arr[i] <= pivot)
		{
			count++;
		}
	}
	int pivotindex = count+s;
	swap(arr[pivotindex],arr[s]);
	int i=s;
	int j = e;
	while(i<pivotindex && j > pivotindex)
	{
		while(arr[i] <= pivot)
		{
			i++;
		}
		while(arr[j] > pivot)
		{
			j--;
		}
		if(i<pivotindex && j > pivotindex)
		{
			swap(arr[i++],arr[j--]);
		}
	}
	return pivotindex;
}
void QuickSort(int arr[],int s, int e)
{
	if(s>=e)
	{
		return;
	}
	else
	{
		int p = Partition1(arr,s,e);
		QuickSort(arr,s,p-1);
		QuickSort(arr,p+1,e);
	}
}
int main()
{
	int i,s = 10;
	int a[s]={5,6,7,2,3,0,10,11,12,1};
	cout<<"UNSORTED ARRAY: "<<endl<<endl;
	for(i=0;i<s;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"SORTED ARRAY: "<<endl<<endl;
	QuickSort(a, 0, s-1);
	
	for(i=0;i<s;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;


}

