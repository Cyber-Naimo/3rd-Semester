#include<iostream>
#include<stack>
using namespace std;
void InsertSort(stack<int> &stack, int n)
{
    if(stack.empty()  || stack.top() >  n)
    {
        stack.push(n);
        return;
    }
    else
    {
        int num  = stack.top();
        stack.pop();
        InsertSort(stack,n);
        stack.push(num);
    }
}
void sortStack(stack<int> &stack)
{
    if(stack.empty())
    {
        return;
    }
    else
    {
        int num = stack.top();			// toop nikala
        stack.pop();		
        sortStack(stack);			// phr next k lie call mari
        InsertSort(stack,num);		// AB insert kia sorted way
    }
}
int main()
{

}

