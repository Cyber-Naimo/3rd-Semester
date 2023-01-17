#include<iostream>
#include<string>
using namespace std;
//int countDistinctWays(int nStairs) {
//    if(nStairs<0)
//    {
//        return 0;
//    }
//    if(nStairs==0)
//    {
//        return 1;
//    }
//    else
//    {
//        return countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2);
//    }
//
//}
void NotoAlphabet(int n,string arr[])
{
	if(n==0)
	{
		return;
	}
	else
	{
		// Converting Number to the Aplhabet
		int rem=n%10;
		n/=10;
		NotoAlphabet(n,arr);
		cout<<" "<<arr[rem];
	}
}
// POWER  PROGRAM
int power(int n,int m)
{
//	n=no, m=power
	if(m==0)
	{
		return 1;
	}
	if(m==1)
	{
		return n;
	}
	else
	{
		// return n*fact(n-1);			factorial
		// return n+fact(n-1);			sum of n numbers
		//	fab(n-1)+fab(n-2);			FABONACCI SERIES
    	return n*power(n,m-1);		//	power of any number
	}
}
bool IsSorted(int arr[],int n)
{
	if(n==1 || n==0)
	{
		return true;
	}

		if(arr[0] > arr[1])
		 {
		 	return false;
		 }	
		 else
		 {
		 	return IsSorted(arr+1,n-1);
		 }
}
int SumofArray(int arr[],int n)
{
	
	if(n==0)
	{
		return 0;
	}
	if(n==1)
	{
		return arr[0];
	}
	else
	{
		cout<<arr[0]<<endl;
		return SumofArray(arr+1,n-1)+arr[0];
		
	}
}
bool KeyPresent(int arr[],int n , int key)
{
	
	// from linear search
	
	
	if(n==0)
	{
		return false;
	}
	
	if(arr[0]==key)
	{
		return true;
	}
	else
	{
		return KeyPresent(arr+1,n-1,key);
	}
}
void print(int arr[],int s,int e)
{
//	cout<<"\n\nSIZE OF THE ARRAY: "<<e<<endl;
	for(int i=s;i<e;i++)
	{
		cout<<" "<<arr[i];
	}
}
int  BinarySearch(int arr[],int s,int e, int key)
{
	
	cout<<"\n\n";
	print(arr,s,e);
	if(s>e)
	{
		return -1;
	}
	
	int mid = s + (e-s)/2;
	
	if(arr[mid] == key)
	{
		return mid;
	}
	
	if(arr[mid]<key)
	{
		return BinarySearch(arr,mid+1,e,key);
	}
	else
	{
		return BinarySearch(arr,s,mid-1,key);
	}
}

int main()
{
	int n,m;
	int arr[]={0,1,2,4,5,8};
	int size=6;
	int key=4;
//	cout<<" Key is:  "<<BinarySearch(arr,0,size-1,key);
//	string arr[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
//	cout<<"ENTER YOUR NUMBER: "<<endl;
//	cin>>n;
	cout<<"\n\n";
//	NotoAlphabet(n,arr);
	cout<<"ENTER NO THEN ITS POWER: ";
	cin>>n>>m;
	cout<<"POWER OF 2 IS: "<<power(n,m);
return 0;

}

