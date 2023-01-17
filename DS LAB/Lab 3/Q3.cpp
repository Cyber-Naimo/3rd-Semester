#include <iostream>
using namespace std;
void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"  "<<arr[i]<<endl;
	}
}

// Tail
void SortusingTail(int arr[],int n)
{
	if(n==0 || n==1)
	{
		return;
	}
	else
	{
		for(int i=0;i<n-1;i++)
		{
			if(arr[i]>arr[i+1])
			{
				swap(arr[i],arr[i+1]);
				
			}
		}
		return SortusingTail(arr,n-1);
	}
}
// Nontail
void SortusingNon_Tail(int arr[],int n)
{
	if(n==0 )
	{
		return;
	}
	else
	{   
	   	int ele=arr[n];
	   	SortusingNon_Tail(arr,n-1);
	   	int i;
		for(i=n-1;i>=0;i--)
		{
			if(arr[i] > ele)
			{
				arr[i+1]=arr[i];
			}
			else
			{
				break;
			}
		}
		arr[i+1]=ele;	
	}
}
int main() {
	int n;
	cout <<"ENTER THE SIZE OF THE ARRAY: ";
	cin>>n;
	
	int arr[n];
	
	cout<<"ENTER ELEMENT: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	SortusingNon_Tail(arr,n-1);
	cout<<"SORTED ARRAY: "<<endl;
	print(arr,n);

	
	return 0;
}
