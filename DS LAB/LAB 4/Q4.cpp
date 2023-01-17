#include<iostream>
using namespace std;
void Print(int arr[], int size, int count)
{
	cout<<" YOU CAN BUY "<<count<<" TOYS WITH THIS AMOUNT WITH AMOUNT OF: "<<endl;
	
	// this part is extra for detailed information
	for(int i = 0; i < count; i++)
	{
		cout<<" *  "<<arr[i]<<endl;
	}
}
void FinancialAdvisor(int arr[],int k,int n)
{
	int count=0;
	int temp[n];
	for(int i=0;i<n;i++)
	{
		if(arr[i] <= k)
		{
			count++;
			temp[i] = arr[i];
		}
	}
	Print(temp,n,count);
}
int main()
{
	int size,k;
	cout<<"ENTER THE NO OF TOYS: ";
	cin>>size;
	
	cout<<"ENTER THE AMOUNT OF TOYS YOU HAVE NOW IN YOUR POCKET : ";
	cin>>k;
	
	int arr[size];
	for(int i = 0; i < size; i++)
	{
		cin>>arr[i];
	}
	
	FinancialAdvisor(arr,k,size);
	
	
	
	return 0;

}

