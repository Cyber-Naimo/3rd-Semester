#include<iostream>
#include<queue>
using namespace std;
class Stack
{
	public:
	queue<int> q1;
	queue<int> q2;
	void push(int d)
	{
		/* AGAR KOI BH ELEMENT INSERT KRNA H TO SBSE PEHLE SAREY ELEMENTS Q2 M PUSH KRO THEN US ELEMENT 
		KO Q1 M PUSH KRO AND PHR WAPIS Q2 WALE ELEMNT Q1 M PUSH KRDO*/
		while(!q1.empty())
		{
			q2.push(q1.front());
			q1.pop();
		}
		q1.push(d);
		
		while(!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}
		
	}
	int  pop()
	{
		// IS CASE M TOP PE HAMSEHSA LAST ELEMENT H HOGA WHICH SATISFIES LIFO CONDITION
		int ans =  q1.front();
		q1.pop();
		return ans;
	}
	int top()
	{
		return q1.front();
	}

};
int main()
{
Stack s;
s.push(4);
cout<<" "<<s.top()<<endl;
s.push(6);
cout<<" "<<s.top()<<endl;
s.push(2);
cout<<" "<<s.top()<<endl;
s.pop();
cout<<" "<<s.top()<<endl;
return 0;

}

