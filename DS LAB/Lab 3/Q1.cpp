#include <iostream>
using namespace std;
void Sequence(int number_of_increament,int total,int No_term)
{
	if(No_term>10)
	{
		return;
	}
	else
	{
		cout<<" "<<total<<" , ";
		total+=number_of_increament;
		Sequence(number_of_increament+1,total,No_term+1);
	}

}
int main()
{
	
	int n,sum=1;
	cout<<"FROM WHICH SEQUENCE YOU WANT TO START: 0,2 :   ";
	cin>>n;
	// sequence start form 1;
	Sequence(n,sum,1);
	
}
