#include<iostream>
using namespace std;
#include<stack>
bool IsBalanced(string exp)
{
	stack<char> s;
	for(int i=0;i<exp.length();i++)
	{
		char ch = exp[i];
		// push tab krao jb openning ho
		if(ch == '{' || ch == '[' || ch == '(')
		{
			s.push(ch);
		}
		else
		{
			if(!s.empty())
			{
					char topelement = s.top();
					if( (topelement == '{' &&  ch == '}' ) 
					   ||(topelement == '[' &&  ch == ']' )
					   || (topelement == '(' &&  ch == ')' ) )
				{
					s.pop();
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;	
			}
		}	
	}
	if(s.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	string arr = "[{}]";
	if(IsBalanced(arr))
	{
		cout<<"EQUATION IS BALANCED "<<endl;
	}
	else
	{
		cout<<"EQUATION IS NOT BALANCED "<<endl;
	}
	return 0;

}

