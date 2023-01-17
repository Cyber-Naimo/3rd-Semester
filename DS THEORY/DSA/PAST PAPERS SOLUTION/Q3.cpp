#include<iostream>
#include<bits\stdc++.h>
using namespace std;
void Merge(int arr[],int s,int m,int e)
{
	int fh = m-s+1;
	int sh = e-m;
	
	int arr1[fh],arr2[sh];
	
	for(int i=0;i<fh;i++)
	{
		arr1[i] = arr[s+i];
	}
	for(int i =0;i<sh;i++)
	{
		arr2[i] = arr[i+m+1];
	}
	int i=0,j=0;
	int k=s;
	while(i<fh && j<sh)
	{
		if(arr1[i] <= arr2[j])
		{
			arr[k++] = arr1[i++];
		}
		else
		{
			arr[k++] = arr2[j++];
		}
	}
	while(i<fh)
	{
		arr[k++] = arr1[i++];
	}
	while(j<sh)
	{
		arr[k++] = arr2[j++];
	}
	
}
void MergeSort(int arr[],int s,int e)
{
	if(s>=e)
	{
		return;
	}
	else
	{
		int mid = s+(e-s)/2;
		MergeSort(arr,s,mid);
		MergeSort(arr,mid+1,e);
		Merge(arr,s,mid,e);
	}
}
int Partition(int arr[],int s,int e)
{
	int count = 0;
	int pivot = arr[s];		// first element
	
	for(int i=1+s;i<=e;i++)
	{
		if(arr[i]<= pivot)
		{
			count++;
		}
	}
	
	int pivotindex = count+s;
	swap(arr[pivotindex],arr[s]);
	int i=s;
	int j=e;
	while(i<pivotindex && j > pivotindex)
	{
		while(arr[i] <= pivotindex)
		{
			i++;
		}
		while(arr[j] > pivotindex)
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
void QuickSort(int arr[],int s,int e)
{
	if(s>=e)
	{
		return;
	}
	else
	{
		int part = Partition(arr,s,e);
		QuickSort(arr,s,part-1);
		QuickSort(arr,part+1,e);
	}
}
void Display(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}	
}
int main()
{

	int i,s = 10;
	int a[s]={5,6,7,2,23,0,10,11,12,1};
	cout<<"UNSORTED ARRAY: "<<endl<<endl;
	Display(a,s);
	cout<<endl;
	cout<<endl;
	cout<<"SORTED ARRAY: "<<endl<<endl;
	QuickSort(a, 0, s-1);
	Display(a,s);	
	return 0;

}

