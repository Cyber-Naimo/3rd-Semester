#include<iostream>
using namespace std;
void SORT(int *arr[],int n)
{
//	Assending order

	for(int i=0; i<n; i++)
	{	
		for(int j=i+1; j<n; j++)	
		{
					
			if(*arr[i]>*arr[j])	
			{
				int *a=*(arr+i);
				
				arr[i]=arr[j];
				
				arr[j]=a;	
			}	
		}	
	}
	cout<<"\nARRAY IS ASCENDING ORDER:\n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<*arr[i];
	}
	
	
	for(int i=0; i<n; i++)
	{	
		for(int j=i+1; j<n; j++)	
		{		
			if(*arr[i]<*arr[j])	
			{
				int *a=arr[i];
				
				arr[i]=arr[j];
				
				arr[j]=a;	
			}	
		}	
	}
	cout<<"\nARRAY IS DESCENDING ORDER:\n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<*arr[i];
	}
	
}
int main()
{
	int n;
	cout<<"ENTER SIZE OF THE ARRAY: ";
	cin>>n;
	int arr[n];
	int *a[n];
	
	
	cout<<"ENTER ELEMENTS OF THE ARRAY:\n";
	for(int i=0;i<n;i++)
	{
		cin>>*(arr+i);
	}
	
	for(int i=0;i<n;i++)
	{
		a[i]=&arr[i];
	}
	
	SORT(a,n);
	
	cout<<"\nORIGINAL ARRAY AFTER RETURNING:\n";
	
	for(int i=0;i<n;i++)
	{
		cout<<" "<<arr[i];
	}
	
}
