#include<iostream>
using namespace std;
#define N 8

bool safe(int arr[N][N], int r, int c)
{
	// for checking the rows
	
	for(int i=0;i<r;i++)
	{
		if(arr[i][c]==1)
		{
			return false;
		}
	}
	// checking the diagonals in backward direction
	while(r>=0 && c>=0)
	{
		if(arr[r][c]==1)
		{
			return false;
		}
		r--;
		c--;
	}
	// checking the diagonals in forward direction
	while(r>=0 && c<N)
	{
		if(arr[r][c]==1)
		{
			return false;
		}
		r--;
		c++;
	}
	return true;
}

bool Queen(int arr[N][N],int r)
{
	if(r>=N)
	{
//		when rows equal to n returning
		return true;
	}
	else
	{
		for(int col=0;col<N;col++)
		{
//			checking the box is it safe to place the queen or not
			if(safe(arr,r,col))
			{
//				if it return true then it will place the queen  and move forward and call the function again and again 
				arr[r][col]=1;
				
				if(Queen(arr,r+1))
				{
					return true;
				}
//				if above function return false then its mean we cannot place queen in the box so make it 0
				arr[r][col]=0; 	 // here backtracking is applying 
			}
		}
		return false;
	}
}

int main()
{
//	int n;
//	cout<<"ENTER NO OF ROWS OF A CHESS BOARD: ";
//	cin>>n;
//	cout<<"\n";
	int arr[N][N] = {0};
//	int **arr= new int*[n];
//	for(int i=0;i<n;i++)
//	{
//		 arr[i]=new int[n];
//		for(int j=0;j<n;j++)
//		{
//			arr[i][j]=0;
//		}
//	}
	if(Queen(arr,0))
	{
		cout<<"TRUE YOU CAN PLACE THE QUEEN AS:\n\n";
		for(int i=0;i<N;i++)
		{
			cout<<"\t\t";
			for(int j=0;j<N;j++)
			{
				cout<<arr[i][j]<<"  ";
			}
			cout<<"\n \n";
		}
	}
	

}

