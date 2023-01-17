#include<iostream>
using namespace std;
int main ()
{
	int n;
	int sum=0;
	
	cout<<"ENTER YOUR NUMBER: ";
	cin>>n;
	if(n==-1)
	{
		return 0;
	}
	else
	{
		cout<<"PRIME FACTOR OF NUMBERS ARE : ";
		for(int i=1;i<=n/2;i++)
		{
			if(n%i==0)
			{
				cout<<i<<"  ";
				sum+=i;
			}
		}
		cout<<"\nSUM OF PRIME FACTORS ARE: "<<sum+n;
	}



}


