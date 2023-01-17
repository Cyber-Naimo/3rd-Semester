#include<iostream>
#include<bits\stdc++.h>
using namespace std;
void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<" "<<arr[i]<<" --> ";
	}
	cout<<"\n\n";
}
void Rotate(int arr[],int n, int k)
{
	int temp[n];
	for(int i=0;i<n;i++)
	{
		temp[(i+k)%n] = arr[i];
	}
	for(int i=0;i<n;i++)
	{
		arr[i] = temp[i];
	}
}
void Reverse(int arr[], int n)
{
	int s = 0;
	int e = n-1;
	while(s<e)
	{
		swap(arr[s++],arr[e--]);
	}
}
void ReverseSubElements(int arr[],int n)
{
	for(int i=0;i<n;i+=2)
	{
		if(i+1<n)
		{
			swap(arr[i],arr[i+1]);
		}
	}
}
int UniqueElement(int *arr,int n)
{
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans = ans^arr[i];
	}
	return ans;
}


void DuplicateinUnsorted(int arr[],int n)
{
	for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i]==arr[j])
            {
                cout<<arr[i]<<"\t";
            }
        }
        
    }
}
vector<int> Intersection(vector<int> &arr1, int n,vector<int> &arr2, int m)
{
	int i=0,j=0;
	vector<int>  ans;
	while(i<n && j<m)
	{
		if(arr1[i] == arr2[j])
		{
			ans.push_back(arr1[i]);
			i++;
			j++;
		}
		else if(arr1[i] < arr2[j])
		{
			i++;
		}
		else
		{
			j++;
		}		
	}
	return ans;	
}
vector<vector<int> > PairSum(vector<int> &arr, int key)
{
	vector<vector<int> > ans;
	int n = arr.size();
	for(int i=0;i<n-1;i++)
	{
		for(int j = i+1;j<n-1;j++)
		{
			if(arr[i]+arr[j]==key)
			{
				vector<int> temp;
				temp.push_back(min(arr[i],arr[j]));
				temp.push_back(max(arr[i],arr[j]));
				ans.push_back(temp);
			}
		}
	}
	sort(ans.begin(),ans.end());
	return ans;
}
void  bubble(int arr[],int n)
{
	int i=0,j=0;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n-1;j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(arr[j],arr[j+1]);
			}
		}
	}
	
}
void  selection(int arr[],int n)
{
	int i=0,j=0,min;
	for(i=0;i<n-1;i++)
	{
		min = i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}
		if(min!=i)
		{
			swap(arr[min],arr[i]);
		}
	}	
}
void Insertion(int arr[],int n)
{
	int i,j,key;
	for(int i=1;i<n;i++)
	{
		key = arr[i];
		j = i-1;
		while(j>=0 && arr[j]> key)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
}

void Insert(int arr[],int n,int key)
{
	int i=n-1;
	while(arr[i]>key)
	{
		arr[i+1]=arr[i];
		i--;
	}
	arr[i+1]=key;
}


void Sort01(int arr[],int n)
{
	int s=0;
	int e= n-1;
	while(s<e)
	{
		if(arr[s]==0 && s<e)
		{
			s++;
		}
		else if(arr[e]==1 && s<e)
		{
			e--;
		}
		else
		{
			swap(arr[s++],arr[e--]);
		}
	}
}
void SORT012(int arr[],int n)
{
	int s=0;
	int mid=0;
	int e=n-1;
	while(mid<=e)
	{
		if(arr[mid] == 0)
		{
			swap(arr[mid++],arr[s++]);
		}
		else if(arr[mid]==1)
		{
			mid++;
		}
		else
		{
			swap(arr[mid],arr[e--]);
		}
	}
}
int Binary_Search(int arr[],int n,int s,int key)
{
	int e= n-1;
	int mid = s+(e-s)/2;
	while(s<=e)
	{
		if(arr[mid] == key)
		{
			return mid;
		}
		else if(key>arr[mid])
		{
			s = mid+1;
		}
		else
		{
			e = mid-1;
		}
		mid = s+(e-s)/2;
	}
}

void InsertionSort(int arr[],int n)
{
	int i,j;
	int temp,local;
	for( i=1;i<n;i++)
	{
		temp = arr[i];
		local = Binary_Search(arr,i,0,arr[i]);
		for(j=i-1;j>=local;j--)
		{
			arr[j+1] = arr[j];
		}
		cout<<endl<<endl;
		arr[local]=temp;
	}
}
int main()
{
	vector<int> v1;
	vector<int> v2;
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(2);
	
	v2.push_back(4);
	v2.push_back(2);
	v2.push_back(3);	
	
	vector<int> v3 = Intersection(v1,v1.size(),v2,v2.size());
	for(int i=0;i<v3.size();i++)
	{
		cout<<" "<< v3[i]<<" --> ";
	}
	
	return 0;

}

