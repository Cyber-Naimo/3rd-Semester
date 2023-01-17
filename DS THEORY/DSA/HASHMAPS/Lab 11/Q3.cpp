#include<iostream>
using namespace std;
class HashTable
{
	public:
	int k;		// student id
	int v;		//contact no
	HashTable()
	{
	}
	HashTable(int k, int v)
	{
		this->k= k;
		this->v = v;
	}

};
class ContactBook
{
	public:
		int size;
		int count;
		HashTable **arr;
		ContactBook(int size)
		{
			count = 0;
			this->size=size;
			arr = new HashTable*[size];
			for(int i=0;i<size;i++)
			{
				arr[i] = NULL;
			}	
		}
		bool empty()
		{
			if(count==0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		int getsize()
		{
		  return size;
		}
		int HashFunction(int key)
		{
			return key%size;
		}
		int SearchKey(int key)
		{
			if(empty())
			{
				cout<<" Table is Empty"<<endl;
				return -1;
			}
			else
			{
				int index = HashFunction(key);
				int temp = index;
				
				while(1)
				{
					if(arr[index] == NULL || arr[index]->k!=key)
					{
						index = ((index+1)%size);
					}
					else
					{
						break;
					}
					
					if(index == temp)
					{
						temp = -1;
						break;
					}
				}
				if(temp == -1)
				{
					cout<<" Key not Found. "<<endl;
				}
				else
				{
					return arr[index]->v;
				}
			}
		}
		void Insert(int key, int val)
		{	
			if(count == size)
			{
				cout<<" Table is Full. "<<endl;
				return;
			}
			else
			{
				int index = HashFunction(key);
				while(arr[index]!=NULL)
				{
					// LINEAR PROBING
					index = (index + 1)% size;
				}
				arr[index] = new HashTable(key,val);
				count++;
			}
		}
		void Remove(int key)
		{
			if(empty())
			{
				cout<<" Table is Empty"<<endl;
				return;
			}
			else
			{
				int index = HashFunction(key);
				int temp = index;
				
				while(1)
				{
					if(arr[index] == NULL || arr[index]->k!=key)
					{
						index = ((index+1)%size);
					}
					else
					{
						break;
					}
					
					if(index == temp)
					{
						temp = -1;
						break;
					}
				}
				if(temp == -1)
				{
					cout<<" Key not Found. "<<endl;
				}
				else
				{
					delete arr[index];
					arr[index] = NULL;
					count--;
				}
			}
		}
		void Display()
		{
			for(int i=0;i<size;i++)
			{
				if(arr[i]!=NULL)
				{
					cout<<" [ "<< i<<" ]: Key = "<<arr[i]->k<<" Value = "<<arr[i]->v<<endl;
				}
			}
		}
	};
		
		

int main()
{
	
	//  		QUESTION NO 3
   ContactBook c(10);
   int k, v;
   int choice;
   while(choice!=5)
   {
      cout<<"Enter 1 to Insert element into the table"<<endl;
      cout<<"Enter 2 to Search element from the key"<<endl;
      cout<<"Enter 3 to Delete element at a key"<<endl;
      cout<<"Enter 4 to Display All Pair. "<<endl;
      cout<<"Enter 5 to Exit"<<endl;
      cout<<"Enter your choice: ";
      cin>>choice;
    switch(choice)
 	{
         case 1:
         	{
         		cout<<"Enter element to be inserted: ";
	            cin>>v;
	            cout<<"Enter key at which element to be inserted: ";
	            cin>>k;
	            c.Insert(k, v);
       		    break;
			}
            
         case 2:
            {
            	cout<<"Enter key of the element to be searched: ";
	            cin>>k;
	            if (c.SearchKey(k) == -1)
				{
	               cout<<"No element found at key "<<k<<endl;
	               continue;
	            }
				else
				{
				    cout<<"Element at key "<<k<<" : ";
	                cout<<c.SearchKey(k)<<endl;
	            }
	      		break;
			}
         case 3:
            {
            	cout<<"Enter key of the element to be deleted: ";
	            cin>>k;
	            c.Remove(k);
        		break;
			}
		 case 4:
		 	{
		 	  c.Display();
		 	  break;
			}
         case 5:
         	{
         		exit(1);
			}
          
         default:
            cout<<"Enter correct option";
      }
   }
   return 0;
}


