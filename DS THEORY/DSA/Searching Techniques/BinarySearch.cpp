#include<iostream>
using namespace std;
int BinarY(int arr[],int size,int key)
{
		int start=0;
		int end = size-1;
		int mid = start + (end-start)/2;
		while(start<=end)
		{
			if(arr[mid]==key)
			{
				return mid;
			}
			else if(key<arr[mid])
			{
				end=mid-1;
			}
			else
			{
				start=mid+1;
			}
			mid = start + (end-start)/2;
		}
		return -1;
}

int InterPolationSearch(int arr[],int size,int key)
{
		int start=0;
		int end=size-1;
		int mid = start+(((end - start)/(arr[end]-arr[start]))* (key-arr[start]));
		while(start<=end)
		{
			if(arr[mid]==key)
			{
				return mid;
			}
			else if(key<arr[mid])
			{
				end=mid-1;
			}
			else
			{
				start=mid+1;
			}
			mid = start+(((end - start)/(arr[end]-arr[start])) * (key-arr[start]));
		}
		return -1;
}
void sort012(int arr[],int n)
{
	int left=0,mid=0,right=n-1;
	while(mid<=right)
	{
		if(arr[mid]==0)
		{
			swap(arr[mid++],arr[left++]);
		}
		else if(arr[mid]==1)
		{
			mid++;
		}
		else
		{
			swap(arr[mid],arr[right--]);
		}
	}
}
void sort01(int arr[],int n)
{
	int left=0,right=n-1;
		
	while(left < right)
	{
		while(arr[left] == 0 && left < right )
		{
			left++;
		}
		while(arr[right]==1 && left<right)
		{
			right--;
		}
		if(	left<right)
		{
			swap(arr[left++],arr[right--]);	
		}	
	}
}

int firstOcc(int arr[], int n, int key) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) 
	{

        if(arr[mid] == key)
		{
            ans = mid;
            e = mid - 1;
        }
        else if(key > arr[mid])
		{//Right me jao
            s = mid + 1;
        }
        else if(key < arr[mid])
		
		{	//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

int lastOcc(int arr[], int n, int key) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {

        if(arr[mid] == key)
		{
            ans = mid;
            s = mid + 1;
        }
        else if(key > arr[mid]) {//Right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]) {//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}
 long long int sqrtInteger(int n) {
        
        int s = 0;
        int e = n;
        long long int mid = s + (e-s)/2;
        
        long long int ans = -1;
        while(s<=e) {
            
            long long int square = mid*mid;
            
            if(square == n)
                return mid;
            
            if(square < n ){
                ans = mid;
                s = mid+1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
int main ()
{
	int odd[5]={1,3,5,7,7};
	int key=7;
	cout<<""<<BinarY(odd,5,key);
}


