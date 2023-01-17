#include<iostream>
using namespace std;
int main()
{
	int rows,columns;
	int count=0;
	cout<<"ENTER ROWS ANDS COLUMNS OF THE MATRIX: "<<endl;
	cin>>rows>>columns;
	
	int arr[rows][columns];
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			cout<<"ENTER MATRIX: ["<<i<<"]"<<" ["<<j<<"] : "<<endl;
			cin>>arr[i][j];
		}
	}
	cout<<"\n \n";
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			cout<<"  "<<arr[i][j];
		}
		cout<<"\n";
	}
	
	
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			if(i==j)
			{
				if(arr[i][j]!=1)
				{
					count=1;
				}
			}
			else
			{
				if(arr[i][j]!=0)
				{
					count=1;
				}
			}
		}
	}
	if(count==1)
	{
		cout<<"\nMATRIX IS NOT IDENTITY MATRIX: "<<endl;
	}
	else
	{
		
		cout<<"\nMATRIX IS  IDENTITY MATRIX: "<<endl;		
	}
	
}
