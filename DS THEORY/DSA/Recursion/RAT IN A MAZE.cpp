#include<iostream>
using namespace std;
#define N 4
bool Safe(int x, int y,int arr[N][N], int vis[N][N])
{
	if((x>=0 && x<N)  && (y>=0 && y<N) && vis[x][y]!=1 && arr[x][y]==1)
	{
		return true;
	}
	return false;
}
bool solve(int r,int c,int arr[N][N], int vis[N][N])
{
//	 || r==0 && c==N-1 ||r==1 && c==N-1 ||r==2 && c==N-1
	if(r==N	-1 && c==N-1)
	{
		vis[r][c]=1;
		return true;
	}

	else
	{
		
		if(Safe(r,c,arr,vis))
		{
			vis[r][c]=1;
			
			//down
			if(solve(r+1,c,arr,vis))
			{
				return true;
			}
			// right
			if(solve(r,c+1,arr,vis))
			{
				return true;
			}
			//left
			if(solve(r,c-1,arr,vis))
			{
				return true;
			}
			//up
			if(solve(r-1,c,arr,vis))
			{
				return true;
			}
			
			vis[r][c]=0;
			return false;
		}
			return false;
	}
}

int main()
{
	
	// part b
	 int maze[N][N]={{0,1,1,1},
                    {0,1,1,1},
                    {0,0,1,1},
                    {1,0,0,1}};
    int visited[N][N]={0};
    
    
	//part a
//	int n;
//	cout<<"ENTER SIZE OF THE ARRAY:";
//	cin>>n;
//	int **board= new int*[n];
//	int **vis= new int*[n];
//	
//	for(int i=0;i<n;i++)
//	{
//		board[i]=new int[n];
//		cout<<"ENTER ROW: "<<i+1<<" ELEMENT: ";
//		for(int j=0;j<n;j++)
//		{
//				cin>>board[i][j];
//		}
//	}
//	
//	for(int i=0;i<n;i++)
//	{
//		vis[i]=new int[n];
//		for(int j=0;j<n;j++)
//		{
//			vis[i][j]=0;
//		}
//	}
//	

	
	
	if(solve(0,0,maze,visited))
	{
		cout<<"PATH FINDED: "<<endl;
		
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				cout<<"   "<<visited[i][j];
			}
			cout<<"\n\n";
		}
	}
	else
	{
		cout<<"PATH NOT FINDED: "<<endl;
		
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				cout<<"   "<<maze[i][j];
			}
			cout<<"\n\n";
		}
	}

	
	return 0;

}

