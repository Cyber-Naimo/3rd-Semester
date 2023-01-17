#include<bits\stdc++.h>
#include<stack>
using namespace std;
class MyQueue
{
	
	public:
		stack<int> s1;
		stack<int> s2;	
		void EnQueue(int data)
		{
			// simply insert it on stack1
			s1.push(data);
		}
		
		int DeQueue()
		{
			// simplu insert all elemnt into stack 2 then stack2 hold the first elemnt which is push in stack1 
			while(!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
			
			int ans = s2.top();
			// then pop top element then again fill the stack1 by poping stack2
			s2.pop();
			while(!s2.empty())
			{
				s1.push(s2.top());
				s2.pop();
			}
		}
		int front()
		{
			while(!s1.empty())
			{
				int val = s1.top();
				
				s2.push(val);
				s1.pop();
			}	
			int ans = s2.top();
			while(!s2.empty())
			{
				s1.push(s2.top());
				s2.pop();
			}
			return ans;	
		}
		
};
int main()
{
	MyQueue m;
	m.EnQueue(4);
	cout<<" "<<m.front()<<endl;
	m.EnQueue(43);
	cout<<" "<<m.front()<<endl;
	m.EnQueue(3);
	cout<<" "<<m.front()<<endl;
	m.DeQueue();
	cout<<" "<<m.front()<<endl;
 return 0;
}

