#include<iostream>
using namespace std;


//Taylor Series like e power x= 1+x/1 + x*x/2! ...4

  long long toh(int N, int from, int to, int aux) {
        if(N>0)
        {
            toh(N-1,from,aux,to);
            cout<<"move disk "<<N<<" from rod "<<from<<" to "<<to<<endl;
            toh(N-1,aux,to,from);
            
        }
    }
void TowerofHanoi(int n, int a,int b, int c)
{
//	O(2 power n) time complexity
	if(n>0)
	{
		TowerofHanoi(n-1,a,c,b);
		cout<<"FROM A: "<<a;
		cout<<" C: "<<c<<endl;
		TowerofHanoi(n-1,b,a,c);
	}
}
int NCR(int n, int r)
{
	if(n==r || r==0)
	{
		return 1;
	}
	else
	{
		return NCR(n-1,r-1)+NCR(n-1,r);
	}
}
double TaylarSeriesMethod2(double x,double y)
{
	static double z=1;
	if(y==0)
	{
		return z;
	}
	else
	{
		z = 1+(x/y)*z;		//TAKING COMMON
		return TaylarSeriesMethod2(x,y-1);
	}
}
//double TaylorSeries( double x, double y)
//{
//	
//	static double p=1, f=1;
//	double r;
//	
//	if(y==0)
//	{
//		return 1;
//	}
//	else
//	{
//		r = TaylorSeries(x,y-1);
//		p = p*x;
//		f = f*y;
//		return (r+p/f);
//	}
//}
int Power(int n, int m)
{


//	m represent 2's power;
	if(m==0)
	{
		return 1;
	}
	// checking for even condition
	else if(m%2==0)
	{
		return Power(n*n,m/2);
	}
	else
	{
		return Power(n*n,(m-1)/2)*n;
	}

//Another Logic for Power but its time consuming
//	else
//	{
//			return Power(n,m-1)*n;
//	}
}

// SUM OF N NATUARAL NUMBERS
int sum(int b)
{
    if(b==0)
    {
    	return 0;
	}
	else
	{
		return sum(b-1)+b;
	}
}

// Factorial of a Number

int fact(int b)
{
    if(b==0)
    {
    	return 1;
	}
	else
	{
		return fact(b-1)*b;
	}
}

int main()
{
	toh(2,1,3,2);
//    double x=5,y=3;
//    cout<<NCR(10,7);
}

