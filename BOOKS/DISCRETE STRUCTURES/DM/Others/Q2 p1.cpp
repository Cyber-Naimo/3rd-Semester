#include<iostream>
using namespace std;
int main()
{
	int i;
	bool p,q,r;
	cout<<"\n";
	cout<<"  | p   q   r | ~(Pv(Q^R)) | (~P)^(~Qv~R) |\n";
	cout<<"--|-----------|------------|--------------|\n";
	for(i=0;i<8;i++)
	{
		cout<<i+1<<" | ";
		if(i>3)
		{
			p=false;
			cout<<"F"<<" | ";
		}
		else
		{
			p=true;
			cout<<"T"<<" | ";
		}
		if(i==0 || i==1 || i==4 || i==5)
		{
			q=true;
			cout<<"T"<<" | ";
		}
		else
		{
			q=false;
			cout<<"F"<<" | ";
		}
		if(i%2==0)
		{
			r=true;
			cout<<"T"<<" |";
		}
		else
		{
			r=false;
			cout<<"F"<<" |";
		}
		
		if( !(p|(q&r)) == true)
		{
			cout<<"     T      |";
		}
		else{
			cout<<"     F      |";
		}
		
		if( (!p)&((!q)|(!r)) == true)
		{
			cout<<"       T      |"<<endl;
		}
		else{
			cout<<"       F      |"<<endl;
		}
	}
}












