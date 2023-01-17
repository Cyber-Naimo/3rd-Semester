#include<iostream>
#include"File_name.h"

int main()
{
	int a,b;
	cout<<"ENTER TWO NUMBERS: "<<endl;
	cin>>a>>b;
	Airthmetics ptr(a,b);
	cout<<"\nSUM OF NUMBERS: "<<a<<" + "<<b<<": "<<ptr.sum()<<endl;
	cout<<"\nMULTIPLICATIONS OF NUMBERS: "<<a<<" * "<<b<<": "<<ptr.mul()<<endl;
	return 0;

}

