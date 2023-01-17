/****************************************************
* Author: Hunain Saeed								*
* ID: 18K-1176										*
* Section: B										*
* Language: C++										*
* Date: Octuber 11, 2019							*
*****************************************************/

#include<iostream>
using namespace std;

class matrix
{
	bool **a;
	int i,j,n;
	public:
		void input()
		{
			cout<<"Enter order of square matrix: ";
			cin>>n;
			a = new bool*[n];		//creating dynamic memory for 2d array
			for(i=0;i<n;i++)
			{
				a[i]= new bool[n];
			}
			cout<<"Enter matrix element (1 or 0): \n";
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					cout<<"Enter "<<i+1<<j+1<<" element: ";
					cin>>a[i][j];
				}
			}
		}
		
		void display()	//Displaying result in matrix form
		{
			cout<<"\n   ";
			for(i=0;i<n;i++)
			{
				cout<<i+1<<" ";
			}
			cout<<"\n  -";
			for(i=0;i<n;i++)
			{
				cout<<"--";
			}
			cout<<"\n";
			for(i=0;i<n;i++)
			{
				cout<<i+1<<"|";
				for(j=0;j<n;j++)
				{
					cout<<" "<<a[i][j];
				}
				cout<<endl;
			}
		}
		
		bool reflexive()	//Checking digonals elements
		{
			int i,j=0;
			for(i=0;i<n;i++)
			{
				if(a[i][i] == 1)
				{
					j++;
				}
			}
			if(j==n)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool symmetric()
		{
			int i,j;
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(a[i][j] == 1 && a[j][i] == 1)
					{
						continue;
					}
					else if(a[i][j] != a[j][i])
					{
						return false;
					}
				}
			}
			return true;
		}

		bool antiSymmetric()	
		{
			int i,j,c=0;
			for(i=0;i<n;i++)
			{
				if(a[i][i] == 1)
				{
					c++;
				}
			}
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(i!=j)
					{
						if(a[i][j] == 1 && a[j][i] == 1)
						{
							return false;
						}
						else
						{
							continue;
						}
					}
				}
			}
			if(c!=0)
			{
				return true;
			}
			return true;
		}

		bool transitive()
		{
			int k=0;
			for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					if(i != j)
					{
						if(a[i][j] == 1)
						{
							for(k=0; k<n; k++)
							{
								if(j != k)
								{
									if(a[j][k] == 1)
									{
										if(a[i][k] == 1)
										{
											continue;
										}
										else
										{
											return false;
										}
									}
								}
							}
						}
					}
				}
			}
			return true;
		}
		
		~matrix()
		{
			if(this->a)
			{
				for(int i=0; i<n;i++)
				{
					delete[] a[i];
				}
				delete[] a;
			}
		}

};

int main()
{
	matrix m;
	m.input();
	m.display();
	
	cout<<"\nReflexive : ";
	if(m.reflexive())	//checking if reflexive
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}
	
	cout<<"\nSymmetric : ";
	if(m.symmetric())		//Checking if Symmetric
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}	
	
	cout<<"\nAnti-Symmetric : ";
	if(m.antiSymmetric())	//Checking if Anti-Symmetric
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}
	
	cout<<"\nTransitive : ";
	if(m.transitive())	//Checking if transitive
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}
	
	return 0;
}
