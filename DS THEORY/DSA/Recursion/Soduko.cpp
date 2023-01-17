#include<iostream>
using namespace std;
#define N 9
void Display(int grid[N][N])
{ 

   for (int row = 0; row < N; row++)
   {
   			cout<<"\t\t";
      for (int col = 0; col < N; col++)
	  {
         if(col == 3 || col == 6)
            cout << " | ";
         cout << grid[row][col] <<" ";
      }
      if(row == 2 || row == 5){
         cout << endl;
         for(int i = 0; i<N; i++)
         		cout<<"\t\t";
       
      }
      cout << endl;
   }
}
bool IsSafe(int arr[N][N], int row, int col, int value)
{
	for(int i=0;i<N; i++)
	{
		if(arr[row][i] == value || arr[i][col]==value)
		{
			return false;
		}
	}
	
	int smi = row-row % 3;
	int smj = (col-col % 3);
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(arr[i+smi][j+smj]==value)
			{
				return false;
			}
		}
	}
	return true;
}

bool Sudoku(int arr[N][N] ,int row , int col)
{
	if(row == N-1 && col == N)
	{
		return true;
	}
	else
	{
		if(col==N)
		{
			row++;
			col = 0;
		}
		if(arr[row][col]>0)
		{
			return Sudoku(arr,row,col+1);
		}
		else
		{
			for(int val = 1;val<=N;val++)
			{
				if(IsSafe(arr,row,col,val))
				{
					arr[row][col] = val;
					if(Sudoku(arr,row,col+1))
					{
						return true;
					}				
				}
				arr[row][col]=0;
			}
		}
		
		return false;
	}
	
}
int main()
{

	int arr[N][N] = {
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0},
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 5, 2, 0, 6, 3, 0, 0}
};
	if(Sudoku(arr,0,0))
	{
		cout<<"SOLUTION EXIST: "<<endl;
		Display(arr);	
	}	
	else
	{
		cout<<"SOLUTION DOESN'T EXIST: ";
	}
	return 0;

}

