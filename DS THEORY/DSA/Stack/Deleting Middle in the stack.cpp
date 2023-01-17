#include<iostream>
using namespace std;
#include<stack>
#include <bits/stdc++.h>
void Mid(int count,int N,stack<int> &s)
{
	
    
	if(count == N/2)
    {
        s.pop();
        return;
    }
    else
    {
        int num = s.top();
        s.pop();
        Mid(count+1,N,s);
        s.push(num);
    }
}
void deleteMiddle(int N,stack<int> &s)
{
	int count = 0;
    Mid(count,N,s);
}

int main()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	deleteMiddle(3,s);
	cout<<" "<<s.top()<<endl;
	s.pop();
		cout<<" "<<s.top()<<endl;
	cout<<" "<<s.empty()<<endl;
	


}

