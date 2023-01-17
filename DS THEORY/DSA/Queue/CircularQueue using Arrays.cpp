#include<iostream>
using namespace std;
class CircularQueue
{
    int size;
    int front;
    int rear;
    int *arr;
    public:
    // Initialize your data structure.
    CircularQueue(int n)
	{
        size = n;
        front = -1;
        rear = -1;
        arr = new int[size];
    }
    bool IsFull()
    {
        if(rear== size-1 && front==0 ||(rear == (front-1)%(size-1)) )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if(IsFull())
        {
            return false;
        }
        else if(front==-1)
        {
            rear = front = 0;   
        }
        else if(rear == size-1 && front!=0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
        return true;
    }
    bool IsEmpty()
    {
        if(front==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
          
    }
    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue()
    {
        // checking empty condition
        if(IsEmpty())
        {
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear)   // checking first element condition
        {
            front = rear = -1;
        }
        else if(front == size-1)   // making cyclic when front reach last 
        {
            front = 0;
        }
        else    // normal operation simply moving front from 0 to 1
        {
            front++;
        }
      
        return ans;
    }
    int peek()
    {
    	if(IsEmpty())
    	{
    		return -1;
		}
		else
		{
			return arr[front];
		}
	}
};
int main()
{

	CircularQueue q(5);
	cout<<" "<<q.IsEmpty()<<endl;
	q.enqueue(10);
	q.enqueue(130);
	q.enqueue(50);
	q.enqueue(90);
	q.enqueue(70);
	cout<<" "<<q.dequeue()<<endl;
	cout<<" "<<q.dequeue()<<endl;
	cout<<" "<<q.peek()<<endl;
	
}

