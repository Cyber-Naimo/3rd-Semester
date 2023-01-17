#include<iostream>
using namespace std;
#include<stack>
#include<limits.h>
class SpecialStack 
{
    // Define the data members.

    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
    	
         stack<int> s;
        int min = INT_MAX;
    void push(int data)
    {
        if(s.empty())
        {
            s.push(data);
             min = data;
        }
        else
        {
            if(data < min)
            {
            	// 2*data-min
                s.push(2*data-min);
                min = data;
            }
            else
            {
                s.push(data);
            }            
        }
    }

    int pop() {
        
        if(s.empty())
        {
            return -1;
        }
        else
        {
            int cur = s.top();
            s.pop();
            if(cur > min)
            {
                return cur;
            }
            else
            {
                int premin = min;
                int val = 2*min-cur;
                min = val;
                return premin;            
            }
        }
            
    }

    int top()
	{
        if(s.empty())
        {
            return -1;
        }
        else
        {
            int cur = s.top();
            if(cur > min )
            {
                return  cur;
            }
            else
            {
                return min;
            }
        }
        // Implement the top() function.
    }

    bool isEmpty()
	{
        return s.empty();
        // Implement the isEmpty() function.
    }

    int getMin()
	{
        if(s.empty())
        {
            return -1;
        }
        else
        {
            return min;
        }
        // Implement the getMin() function.
    }  
};
int main()
{
	SpecialStack s;
	s.push(10);
	s.push(20);
	s.push(21);
	s.push(3);
	s.push(43);
	s.push(9);
	cout<<" POP: "<<s.pop()<<endl;
	cout<<" MIN: "<<s.getMin()<<endl;
	return 0;

}

