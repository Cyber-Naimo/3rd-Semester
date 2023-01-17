#include<bits\stdc++.h>
#define MAX 6
using namespace std;

class Priority
{
	public:
	int count=0;
	int arr[MAX];
	
		bool empty()
		{
			if(count==0)
			{
				return true;
			}
			return false;
		}
		bool full()
		{
			if(count==MAX)
			{
				return true;
			}
			return false;
		}
		int top()
		{
			return arr[count-1];
		}
		
		void enquue(int d)
		{
			int i = 0;
			// first check space
			if(!full())
			{
				if(count == 0 )
				{
					arr[count++] = d;
				}
				else
				{
					for(i = count-1;i>=0;i--)
					{
						// 0 index wale value agey dal rahe ho mean 1st index pe
						if(d <= arr[i])
						{
							arr[i+1] = arr[i];
						}
						else
						{
							break;
						}
					}
					
				}
				arr[i+1] = d;
				count++;
			}
		}
		
		
		void DeQueue()
		{
			--count;	 
		}
};
int kthlargest(int ptr[],int k,int n)
{
	Priority p;
	for(int i=0;i<n;i++)
	{
		int sum=0;
		for(int j=i;j<n;j++)
		{
			sum+=ptr[j];
			cout<<" "<<sum<<endl;
			p.enquue(sum);
		}
	 } 
	 int ans = 0;
	 cout<<"PRIORITY QUEUE: "<<endl;
	 for(int i=0;i<k;i++)
	 {
	 	 ans = p.top();
	 	 cout<<" "<<ans<<endl;
	 	 p.DeQueue();
	 }
	 return ans;
}
int main()
{
	int arr[] = {3,2,1};
//	cout<<" Kth Largest: "<<kthlargest(arr,2,3)<<endl;	
	Priority p;
	p.enquue(3);
	p.enquue(100);
	p.enquue(2);
	p.enquue(6);
	cout<<" "<<p.top();
	p.DeQueue();
	cout<<" "<<p.top();
	p.DeQueue();
	cout<<" "<<p.top();

	cout<<" "<<p.empty()<<endl;
	
 return 0;
}

