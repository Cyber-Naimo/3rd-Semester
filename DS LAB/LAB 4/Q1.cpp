#include<iostream>
using namespace std;

void BubbleSort(string arr[], int size)
{
	for(int i=0;i<size-1;i++)
	{
		for(int j=0 ; j<size-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(arr[j],arr[j+1]);
			}
		}
	}
}

void Print(string arr[], int size)
{
	cout<<"SORTED LIST OF STRINGS: "<<endl;
	for(int i = 0; i < size; i++)
	{
		cout<<" *  "<<arr[i]<<endl;
	}
}
int main()
{
	int size;
	cout<<"ENTER THE SIZE OF THE STRING: "<<endl;
	cin>>size;
	string arr[size];
	for(int i = 0; i < size; i++)
	{
		cin>>arr[i];
	}
	BubbleSort(arr,size);
	Print(arr,size);
	

return 0;

}

