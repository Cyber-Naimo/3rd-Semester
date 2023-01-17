#include<iostream>
using namespace std;
class Deque
{
    int size;
    int front;
    int rear;
    int *arr;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        front = -1;
        rear = -1;
        arr = new int[size];
        // Write your code here.
    }
    bool isEmpty()
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

    // Returns true if the deque is full. Otherwise returns false.
   bool isFull()
    {
        if(rear== size-1 && front==0 ||((front!=0) && rear == (front-1)%(size-1)) )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if(isFull())
        {
            return false;
        }
        else if(front==-1)
        {
            front = rear = 0;
        }
        else if(front==0 && rear!=size-1)
        {
            front = size-1;
        }
        else
        {
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
       if(isFull())
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
         arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
         if(isEmpty())
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

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
       if(isEmpty())
       {
           return -1;
       }
        int ans = arr[rear];
        arr[rear] =-1;
        
        if(front==rear)
        {
            front=rear=-1;
        }
        else if(rear == 0)
        {
            rear = size-1;
        }
        else
        {
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
         if(isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[rear];
        }
        // Write your code here.
    }

    // Returns true if the deque is empty. Otherwise returns false.
    
};
int main()
{
	Deque q(5);
	q.pushFront(10);
	q.pushFront(20);
	q.pushRear(30);
	q.popFront();
	q.popRear();
	cout<<" "<<q.getFront()<<endl;
	cout<<" "<<q.getRear()<<endl;
		
return 0;

}

