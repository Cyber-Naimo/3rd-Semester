#include<iostream>
using namespace std;

// function for sorting the UnsortedSubArray
void Sort(int s,int e,int arr[], int n)
{
	for(int i = s; i<e-1;i++)
	{
		for(int j =s+1 ; j<e-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
			}
		}
	}
}
void UnsortedSubArray(int arr[],int n)
{

	int start = 0;
	int end = n-1;
	while(start < n-1 && arr[start] < arr[start+1])
	{
		start++;
	}
	 
	 while(end>0 && arr[end-1] < arr[end])
	 {
	 	end--;
	 }
	 int Max = INT_MIN;
	 int Min = INT_MAX;
	 
	 for(int i=start+1;i<end;i++)
	 {
 			Min = min(Min,arr[i]);
			Max = max(Max,arr[i]);
	 }
	 
	 while(start>=0 && arr[start] > Min)
	 {
	 	start--;
	 }
	 
	 while(end<n && arr[end] < Max)
	 {
	 	end++;
	 }
	 Sort(start+1,end-start+1,arr,n);
	 cout<<"YOUR INDEXES LIES BETWEEN -->  "<<start+1<<" *";
	 cout<<"  "<<end-start+1<<endl;
}

void Print(int arr[], int size)
{
	cout<<"SORTED LIST OF ARRAYS: "<<endl;
	for(int i = 0; i < size; i++)
	{
		cout<<" * "<<arr[i]<<endl;
	}
	cout<<endl;
}
int main()
{
	
	int arr[] = {10, 12, 20, 30, 25,
                 40, 32, 31, 35, 50, 60};
    int size = sizeof(arr)/sizeof(arr[0]);
    Print(arr,size);
    UnsortedSubArray(arr, size);
    Print(arr,size);


// 	FOR USER USE:
//	int size;
//	cout<<"ENTER THE SIZE OF THE ARRAY: "<<endl;
//	cin>>size;
//	int arr[size];
//	for(int i = 0; i < size; i++)
//	{
//		cin>>arr[i];
//	}
//	Print(arr,size);
//    UnsortedSubArray(arr, size);
//    Print(arr,size);
    
	return 0;

}

