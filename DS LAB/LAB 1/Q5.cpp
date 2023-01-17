#include<iostream>
using namespace std;
void MinMax(int  arr[],int size)
{
	int *min=&arr[size-1];
	int *max=&arr[0];
	for(int i=0;i<size-1;i++)
	{
		if(*(arr+i) < *min)
		{
			*min=*(arr+i);
		}
	
	}
	for(int i=0;i<size-1;i++)
	{
		if(*(arr+i) > *max)
		{
			*max=*(arr+i);
		}
	
	}
	cout<<"MINIMUM ELEMENT IS: "<<*min<<endl;
	cout<<"MAXIMUM ELEMENT IS: "<<*max;
	
}
int main ()
{
	int size;
	cout<<"ENTER SIZE OF THE ARRAY: ";
	cin>>size;
	int arr[size];
	for(int i=0;i<5;i++)
	{
		cin>>arr[i];
	}
	
	MinMax(arr,size);
}


