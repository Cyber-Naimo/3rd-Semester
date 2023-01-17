#include<iostream>
using namespace std;

bool Safe(int x, int y,int **arr, int ** vis, int n)
{
	//x are rows   and y are colums
	
//	optimal condition check
	if((x>=0 && x<n)  && (y>=0 && y<n) && vis[x][y]!=1 && arr[x][y]==1)
	{
		return true;
	}

		return false;
}
bool solve(int r,int c,int **arr,int n, int **vis)
{
	// base condition when rat reaches last position of the array 3,3
	if(r==n-1 && c==n-1)
	{
		vis[r][c]=1;
		return true;
	}
	
	
	else
	{
		
		if(Safe(r,c,arr,vis,n))
		{
			vis[r][c]=1;
			
			// checking down
			if(solve(r+1,c,arr,n,vis))
			{
				return true;
			}
			// right
			if(solve(r,c+1,arr,n,vis))
			{
				return true;
			}
			//left
			if(solve(r,c-1,arr,n,vis))
			{
				return true;
			}
			//up
			if(solve(r-1,c,arr,n,vis))
			{
				return true;
			}
			//when nothiing path found make it 0 and return false
			vis[r][c]=0;
			return false;
		}
			return false;
	}
}

int main()
{
	
	// part b
	 int maze[4][4]={{0,1,1,1},
                    {0,1,1,1},
                    {0,0,1,1},
                    {1,0,0,1}
                   };
    int visited[4][4]={0};
    
    
	//part a
	int n;
	cout<<"ENTER SIZE OF THE ARRAY:";
	cin>>n;
	int **board= new int*[n];
	int **vis= new int*[n];
	
	for(int i=0;i<n;i++)
	{
		board[i]=new int[n];
		cout<<"ENTER ROW: "<<i+1<<" ELEMENT: ";
		for(int j=0;j<n;j++)
		{
				cin>>board[i][j];
		}
	}
	
	for(int i=0;i<n;i++)
	{
		vis[i]=new int[n];
		for(int j=0;j<n;j++)
		{
				vis[i][j]=0;
		}
	}
	

	
	
	if(solve(0,0,board,n,vis))
	{
		cout<<"PATH FINDED: "<<endl;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<"   "<<vis[i][j];
			}
			cout<<"\n\n";
		}
	}
	else
	{
		cout<<"PATH NOT FINDED: "<<endl;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<"   "<<board[i][j];
			}
			cout<<"\n\n";
		}
	}

	
	return 0;

}

