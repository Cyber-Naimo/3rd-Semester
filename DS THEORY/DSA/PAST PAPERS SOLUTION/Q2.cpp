#include<bits\stdc++.h>
using namespace std;
void InsertinSorted(stack<int> &s,int n)
{
	if(s.empty() || s.top()>n)
	{
		s.push(n);
		return;
	}
	else
	{
		int num = s.top();
		s.pop();
		InsertinSorted(s,n);
		s.push(num);
	}
}
void SortStack(stack<int> &s)
{
	if(s.empty())
	{
		return;
	}
	else
	{
		int num = s.top();
		s.pop();
		SortStack(s);
		InsertinSorted(s,num);
	}
}
int main()
{
	stack<int> s;
	s.push(32);
	s.push(21);
	s.push(12);
	s.push(89);
	s.push(11);
	SortStack(s);
	while(!s.empty())
	{
		int value = s.top();
		cout<<" "<<value<<" --> ";
		s.pop();
	}
	 return 0;
}

