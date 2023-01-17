#include<iostream>
using namespace std;
class Queue
{
	public:
	int size;
	int front;
	int rear;
	int *arr;
	Queue(int size)			// constructor
	{
		this->size = size;
		front = 0;
		rear = 0;
		arr = new int[size];
	}
	bool IsFull()
	{
		if(rear == size)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool IsEmpty()
	{
		if(rear == front)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void EnQueue(int data)
	{
		if(IsFull())
		{
			cout<<"QUEUE OVERFLOW "<<endl;
		}
		else
		{
			arr[rear] = data;
			rear++;
		}
	}
	int DeQueue()
	{
		if(IsEmpty())
		{
			cout<<"Queue UnderFlow"<<endl;
			return -1;
		}
		else
		{
			int ans = arr[front];
			arr[front] = -1;
			front++;
			if(IsEmpty())
			{
				front = 0;
				rear = 0;
			}
			return ans;
		}
	
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
	Queue q(5);
	cout<<" "<<q.IsEmpty()<<endl;
	q.EnQueue(10);
	q.EnQueue(20);
	q.EnQueue(30);
	q.EnQueue(40);
	q.EnQueue(50);
	cout<<" "<<q.peek();
	cout<<" "<<q.peek();
	
	return 0;

}

