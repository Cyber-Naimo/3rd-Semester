#include<iostream>
using namespace std;
void Merge(int arr[],int s, int m , int e)
{
	int fh = m - s +1;
	int sh = e - m;
	int a1[fh],a2[sh];
	
	for(int i = 0;i<fh;i++)
	{
		a1[i] = arr[s+i];
	}
	
	for(int j = 0;j<sh;j++)
	{
		a2[j] = arr[j+m+1];
	}
	
	int i =0 ,j=0;
	int k = s;
	while(i<fh && j<sh)
	{
		if(a1[i] <= a2[j])
		{
			arr[k++] = a1[i++];
		}
		else
		{
			arr[k++] = a2[j++];
		}
	}
	while(i<fh)
	{
		arr[k++] = a1[i++];
	}
	while(j<sh)
	{
		arr[k++] = a2[j++];
	}
}
void Merge1(int arr[],int s,int m,int e)
{
	int fh = m-s+1;
	int sh = e-m;
	int a1[fh],a2[sh];
	for(int i=0;i<fh;i++)
	{
		a1[i] = arr[s+i];
	}
	for(int j=0;j<sh;j++)
	{
		a2[j] = arr[j+m+1];
	}
	int i = 0, j = 0, k = s;
	while(i<fh && j<sh)
	{
		if(a1[i] <= a2[j])
		{
			arr[k++] = a1[i++];
		} 
		else
		{
			arr[k++] = a2[j++];
		}
	}
	while(i<fh)
	{
		arr[k++] = a1[i++];
	}
	while(j<sh)
	{
		arr[k++] = a2[j++];
	}
	
}
void MergeSort(int arr[],int s , int e){
	if(s>=e)
	{
		return;
	}
	else
	{
		int mid = s+(e-s)/2;
		MergeSort(arr,s,mid);
		MergeSort(arr,mid+1,e);
		Merge1(arr,s,mid,e);
	}
}
int main()
{

	int i,s = 5;
	int a[s]={4,3,2,1,0};
	
	for(i=0;i<s;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	MergeSort(a, 0, s-1);
	
	for(i=0;i<s;i++)
	{
		cout<<a[i]<<" ";
	}
return 0;

}

