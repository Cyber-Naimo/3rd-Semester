#include<iostream>
using namespace std;
void push(stack<int>& myStack,int x)
{
    if(myStack.empty())
    {
        myStack.push(x);
        return;
    }
    else
    {
        int top = myStack.top();
        myStack.pop();
        push(myStack,x);
        myStack.push(top);
    }
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
 
    push(myStack,x);
    return myStack;
}
int main()
{

return 0;

}

