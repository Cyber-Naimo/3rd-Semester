#include <iostream>
#define size 10
using namespace std;
class HashTable
{
	public:
   int v, k;
   HashTable *next;
   HashTable(int k, int v)
   {
      this->k = k;
      this->v = v;
      this->next = NULL;
   }
};
class ContactBook
{
   public:
      HashTable **head;
      ContactBook()
	  {
         head = new HashTable*[size];
         for (int i = 0; i < size; i++)
         {
         	head[i] = NULL;	
		 }
            
      }
      int HashFunction(int key)
	  {
         return key % size;
      }
      void Insert(int k, int v) 
      {
	  
         int index = HashFunction(k);
         HashTable* pre = NULL;
         HashTable* temp = head[index];
         while (temp!= NULL)
		 {
            pre = temp;
            temp = temp->next;
         }
         if (temp == NULL)
		 {
            temp = new HashTable(k, v);
            if (pre == NULL)
			{
               head[index] = temp;
            }
			else
			{
               pre->next = temp;
            }
         }
		 else
		 {
            temp->v = v;
         }
      }
      bool empty()
      {
      	int index = 0;
      	HashTable* temp = head[index];
      	if(temp == NULL)
      	{
      		return true;
		}
		else
		{
			return false;
		}
	  }
      void Remove(int k)
	  {
         int index = HashFunction(k);
         HashTable* temp = head[index];
         HashTable* pre = NULL;
         if (temp == NULL || temp->k != k)
		 {
            cout<<"Element not found at key "<<k<<endl;
            return;
         }
         while (temp->next != NULL)
		 {
            pre = temp;
            temp = temp->next;
         }
         if (pre!= NULL)
		 {
            pre->next = temp->next;
         }
         delete temp;
      }
      void SearchKey(int k)
	  {
         int index = HashFunction(k);
         bool flag = false;
         HashTable* temp = head[index];
         if (temp != NULL) {
            while (temp != NULL)
			{
               if (temp->k == k)
			   {
                  flag = true;
               }
               if (flag)
			   {
                  cout<<"Element found at key "<<k<<": ";
                  cout<<temp->v<<endl;
               }
               temp = temp->next;
            }
         }
         if (!flag)
         {
         	 cout<<" Element not  found at key "<<k<<endl;
		 }
           
      }
      ~ContactBook()
	  {
      }
};

		
		

int main()
{
	
	//  		QUESTION NO 3
   ContactBook c;
   int k, v;
   int choice;
   while(choice!=5)
   {
      cout<<"Enter 1 to Insert element into the table"<<endl;
      cout<<"Enter 2 to Search element from the key"<<endl;
      cout<<"Enter 3 to Delete element at a key"<<endl;
      cout<<"Enter 4 to Exit"<<endl;
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
	            c.SearchKey(k);
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
         		exit(1);
			}
          
         default:
            cout<<"Enter correct option";
      }
   }
   return 0;
}


