#include<iostream>
using namespace std;
int main()
{
	int i;
	bool p,q;
	for(i=0;i<4;i++){
		if(i>=2){
			p=false;
			cout<<"F"<<" | ";
		}else{
			p=true;
			cout<<"T"<<" | ";
		}
		if(i%2==0)
		{
			q=true;
			cout<<"T"<<" |";
		}else{
			q=false;
			cout<<"F"<<" |";
		}
		if( !(p | !(p & q)) == true){
			cout<<"     T       |"<<endl;
		}else{
			cout<<"     F       |"<<endl;
		}
	}
}


//cout<<"\n";
//	cout<<"  | p | q | ~(pv~(p^q)) |\n";
//	cout<<"--|---|---|-------------|\n";
//	
