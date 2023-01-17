#include <iostream>
using namespace std;
int total=1;
int No_term=1;
void Sequence2(int number_of_terms,int start);
void Sequence1(int n, int sum, int check)
{
    if (sum==0)
    {
        cout<<n<<" ";
    }
    if(sum==2)
    {
    	cout<<n<<" ";
	}
    if (sum>check-1)
    return;
    cout<<n+sum<<" ";
    n+=sum;
    Sequence1(n,sum+1,check);
}
void Sequence2(int number_of_terms,int start)
{
    Sequence1(1,start,number_of_terms);
}
int main()
{
	
	int n,terms;
	cout<<"FROM WHICH SEQUENCE YOU WANT TO START: 0,2 :   ";
	cin>>n;
	cout<<"HOW MANY TERMS YOU WANT TO ADD: ";
	cin>>terms;
    Sequence2(terms,n);

	
}
