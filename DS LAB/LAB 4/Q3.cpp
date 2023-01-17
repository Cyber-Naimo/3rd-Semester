#include<iostream>
using namespace std;

void InsertationSort(int arr[],int size)
{
	int temp,j;
	for(int i=0;i<size;i++)
	{
		temp = arr[i];
		j = i-1;
				
		while(j>=0 && arr[j] > temp)			
		{
			arr[j+1] = arr[j];
			j--;
			
		}
		arr[j+1] = temp;			
	}
	
}
void Print(int arr[], int size)
{
	cout<<"SORTED LIST OF ARRAYS: "<<endl;
	for(int i = 0; i < size; i++)
	{
		cout<<" *  "<<arr[i]<<endl;
	}
}
int main()
{
	int size;
	cout<<"ENTER THE SIZE OF THE ARRAY: ";
	cin>>size;
	int arr[size];
	for(int i = 0; i < size; i++)
	{
		cin>>arr[i];
	}
	InsertationSort(arr,size);
	Print(arr,size);
return 0;

}

