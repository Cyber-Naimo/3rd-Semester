#include<iostream>
#include<string>
using namespace std;
#include<stack>
class Stack
{
	int size;
	int top;
	int *arr;
	public:
		Stack(int size)
		{
			this->size = size;
			arr = new int[size];
			top = -1;
		}
		bool IsEmpty()
		{
			if(top == -1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool IsFull()
		{
			if(top == size-1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		void push(int element)		
		{
			// first check space is availabe or not
			if(size - top > 1)			// checking space condition
			{
				
				arr[++top] = element;
			}
			else
			{
				cout<<"Stack OverFlow "<<endl;
			}
		}
		int pop()
		{
			int ans = arr[top];
			if(top>=0)
			{			
				cout<<"POP with a Value of "<<arr[top]<<endl;
				top--;
			}
			else
			{
				cout<<"Stack UnderFlow "<<endl;
			}
			return ans;
		}
		
		int peek()
		{
			if(top>=0)
			{
				return arr[top];
			}
			else
			{
				cout<<"Stack is Empty "<<endl;
				return -1;
			}
		}
		int Search(int ele)
		{
			// we will use temp variable for serchings
			if(top>=0)
			{
				while(top>=0)
				{
					if(arr[top] == ele)
					{
						return arr[top];
					}
					else
					{
						top--;
					}
				}
				cout<<"ELEMENT NOT FOUND: "<<endl;
				return -1;
			}
			else
			{
				cout<<"Stack is Empty "<<endl;
			}
		}
		
	
};
class TwoStack
{
	int size;
	int *arr;
	int top1;
	int top2;
	public:
		TwoStack(int size)
		{
			this->size = size;
			arr = new int[size];
			top1 = -1;
			top2 = size;
		}
		void push1(int d)
		{
			if(top2 - top1 > 1)
			{
				top1++;
				arr[top1] = d;
			}
			else
			{
				cout<<" Stack OverFlow "<<endl;
			}
		}
		void push2(int d)
		{
			if(top2 - top1 > 1)
			{
				top2--;	
				arr[top2] = d;
			}
			else
			{
				cout<<" Stack OverFlow "<<endl;
			}		
		}
		int pop1()
		{
			if(top1>=0)
			{
				int ans = arr[top1];
				top1--;
				return ans;
			}
			else
			{
				cout<<" Stack UnderFlow"<<endl;
				return -1;
			}	
		}
		int pop2()
		{
			if(top2<size)
			{
				int ans = arr[top2];
				top2++;
				return ans;
			}
			else
			{
				cout<<" Stack UnderFlow"<<endl;
				return -1;
			}
		}
};
int main()
{
//	TwoStack s(5);
//	s.push1(3);
//	s.push2(4);
//	s.push1(5);
//	cout<<" "<<s.pop1()<<endl;
//	cout<<" "<<s.pop2();	
	
	

	int size;
	int data;
	cout<<"ENTER THE SIZE OF THE STACK: "<<endl;
	cin>>size;
	Stack s(size);
	cout<<"ENTER ELEMENT IN THE STACK: "<<endl;
	for(int i = 1;i<=size;i++)
	{
		cin>>data;
		s.push(data);
	}
	cout<<"Search Value: "<<s.Search(20);

	return 0;

}

