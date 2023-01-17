#include<bits\stdc++.h>
using namespace std;

/*
Input:
5 3
1 2 3 4 5

Output: 
3 2 1 4 5

Explanation: 
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.*/

void Display(queue<int> q)
{
	while(!q.empty())
	{
		cout<<" "<<q.front()<<" --> ";
		q.pop();
	}
	cout<<endl<<endl;
}
queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> s;
    for(int i=0;i<k;i++)
    {
    	s.push(q.front());
    	q.pop();
	}						// 3 2 1
	for(int i=0;i<k;i++)
	{
		q.push(s.top());
		s.pop();		//  4 5 3 2 1
	}
	int n = q.size();
	for(int i=0;i<n-k;i++)
	{
		int num = q.front();
		q.pop();
		q.push(num);
	}
    return q;
}
vector<int> firstNegative(vector<int> arr, int n, int k) {
	vector<int> ans;
    deque<int> dq;
    for(int i=0;i<k;i++)
    {
        if(arr[i]< 0)
        dq.push_back(i);
    }
    
    if(dq.size() > 0)
    {
        ans.push_back(arr[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }
    
    for(int i=k;i<n;i++)
    {
        if(!dq.empty() && i - dq.front()>=k)
        {
            dq.pop_front();
        }
        if(arr[i]< 0)
        dq.push_back(i);
        if(dq.size() > 0)
        {
            ans.push_back(arr[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}

int main()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	queue<int> p = modifyQueue(q,3);
	Display(p);

return 0;

}

