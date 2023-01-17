#include<iostream>
using namespace std;
print(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
	
		cout<<"\nArray: "<<i+1<<" =  "<<arr[i]<<endl;
	}
}
void SortArray(int *arr,int n)
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
		return SortArray(arr,n-1);
	}
}

//int power(int a, int b)
//{
//	if(b==0)
//	{
//		return 1;
//	}
//	
//	if(b==1)
//	{
//		return a;
//	}
//	int ans= power(a,b/2);
//	
//	if(b%2==0)
//	{
//		return ans*ans;
//	}
//	else
//	{
//		return a*ans*ans;
//	}
//}
int  CheckPalindrome(int n,int temp)
{
	if(n==0)
	{
		return temp ;
	}
	else
	{
		temp = (temp*10)+(n%10);
		return CheckPalindrome(n/10,temp);
	}
}

bool Palindrome(string arr,int i, int j)
{
	if(i>j)
	{
		return true;
	}
	 
	if(arr[i] != arr[j])
	{
		return false;
	}
	else
	{
		return Palindrome(arr,i+1,j-1);
	}
}
void Reverse(string &arr,int i, int j)
{
	// using loop
//	while(i<j)
//	{
//		swap(arr[i++],arr[j--]);
//	}

	if(i>j)
	{
		return ;
	}
	else
	{
		swap(arr[i++],arr[j--]);
//		i++;
//		j--;
		return Reverse(arr,i,j);
	}
}
int main()
{
	
	
	int n;
	cin>>n;
	int arr[n];
	
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
//		cout<<"Array: "<<i+1<<" "<<arr[i]<<endl;
	}
	SortingbyNon_Tail(arr,n);
	print(arr,n);
//	int a,b;
//	cin>>a>>b;
//	
//	int ans=power(a,b);
//	
//	cout<<"ANS: "<<ans;
//string arr="boob";
//int n=7538;
//int temp= CheckPalindrome(n,0);
//if(temp==n)
//{
//	cout<<"YES";
//}
//else
//{
//	cout<<"NO";
//}
//if(Palindrome(arr,0,arr.length()-1))
//{
//	cout<<"STRING IS PALINDROME: ";
//}
//else
//{
//	cout<<"STRING IS NOT PALINDROME: ";
//}

	return 0;

}

