#include<iostream>
using namespace std;
int main (int argc,char **argv)
{
	cout<<"TOTAL WORDS ARE: "<<argc<<endl;
	for(int i = 1; i<=argc; i++)
	{
	
		cout<<argv[i]<<" ";
	}
	
}


