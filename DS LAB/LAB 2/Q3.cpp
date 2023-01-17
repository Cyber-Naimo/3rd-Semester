#include<iostream>
using namespace std;
void Max_Min(int arr[],int n)
{
	int a[n]; 			// making an temporary array;
	int start=0;		// min value  like a[0]
	int end=n-1;		// max value like a[n-1]
	bool count=true;
		
	
	for(int i=0;i<n;i++)
	{
		if(count)
		{
			a[i]=arr[end--];		// condition for max element then declaring count to false when count 
									// is false it will print min element
		}
		else
		{
			a[i]=arr[start++];
			
		}
		count=!count;
	}

	for(int i=0;i<n;i++)
	{
		arr[i]=a[i];			// copying the temporary element to original array;
	}
}
int main ()
{
	int n;
	cout<<"ENTER SIZE OF THE ARRAY: ";
	cin>>n;
	int arr[n];
	cout<<"ENTER ELEMENTS OF THE ARRAY:\n";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	Max_Min(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<" "<<arr[i];
	}
	
}
