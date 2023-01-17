#include<iostream>
#include<fstream>
using namespace std;
int main (int argc,char **argv)
{
	fstream object;
	object.open("MyFile.txt",ios::app);
	cout<<"TOTAL WORDS ARE: "<<argc<<endl;
	for(int i = 1; i<=argc; i++)
	{
	
		object<<argv[i]<<" ";
	}
	
}


