#include<iostream>
using namespace std;
class Airthmetics
{
	int a,b;
	public:
		Airthmetics()
		{
			cout<<"I AM A CONSTRUCTOR:"<<endl;	
		}
		Airthmetics(int a,int b)
		{
			cout<<"\nI AM A CONSTRUCTOR:"<<endl;
			this->a=a;
			this->b=b;
		}
		Airthmetics(const Airthmetics& obj)
		{
			a=obj.a;
			b=obj.b;
		}
		~Airthmetics()
		{
			cout<<"\nI AM A DESTRUCTOR:"<<endl;
		;
		}
		int sum()
		{
			return a+b;
		}
		int mul()
		{
			return a*b;
		}
		
		
};


