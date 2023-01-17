#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 7
class HashTableEntry
{
	public:
	int k;
	int v;
	HashTableEntry(int k, int v)
	{
		this->k= k;
		this->v = v;
	}

};
class HashMapTable	
{
	private:
	HashTableEntry **t;
	public:
	HashMapTable()
	{
		t = new HashTableEntry*[N];
		for(int i=0;i<N;i++)
		{
			t[i] = NULL;
		}
	}
	// HASH FUNCTION 1 :
	int HashFunc(int key)
	{
		return key % N;
	}
	// HASH FUNCTION 2 :
	int  frac(int &k)
	{
		return k*0.4;	
	}
	// HASH FUNCTION 3 :
 	int multiplication_hash(int key)
	{
 		int h  = floor (N * frac(key));
 		return h;
	 // m= size of table
	 //c in the range 0 < c < 1
	 // frac fractional part
	}
	// HASH FUNCTION 4 :
	int mid_square_hash(int key)
	{
		int value = key*key;
		int middle= value/2;
		return middle;
	}
	// HASH FUNCTION 5 :
	int Folding_hash(int value1, int value2, int value3)
	{
		return value1 + value2 + value3;
	}
	int base_number(int value)
	{
		int rem = 0;
		while(value!=0)
		{
		rem = value%2;
		rem+= rem*10;
		value/=2;
		}
		return rem;
	}
	// HASH FUNCTION 6 :
	int radix_hash(int value)
	{
		int result= base_number(value);
		return result;
		// return last4 digit of result;
	}
	void Insert(int k, int v)
	{
		// WE CAN USE ANY TYPE OF HASHING FUNCTION WE CREATED ABOVE FOR INDEXING
		int index = HashFunc(k);
		if(t[index] == NULL)
		{
			t[index] = new HashTableEntry(k,v);
		}
		else
		{
			delete t[index];
			t[index] = new HashTableEntry(k,v);
		}	
	}
	int SearchKey(int k)
	{
		// WE CAN USE ANY TYPE OF HASHING FUNCTION WE CREATED ABOVE FOR INDEXING
		int index = HashFunc(k);
		if(t[index]==NULL)
		{
			return -1;
		}
		else
		{
			return t[index]->v;
		}
	}
	void Remove(int k)
	{
		// WE CAN USE ANY TYPE OF HASHING FUNCTION WE CREATED ABOVE FOR INDEXING
		int index = HashFunc(k);
		if(t[index]==NULL)
		{
			return;
		}
		else
		{
			delete t[index];
		}
	}
	~HashMapTable()
	{
	
	}

};


int main()
{
	
	//  		QUESTION NO 1 AND 2 ARE COMBINE
   HashMapTable h;
   int k, v;
   int c;
   while(c!=4)
   {
      cout<<"Enter 1 to Insert element into the table"<<endl;
      cout<<"Enter 2 to Search element from the key"<<endl;
      cout<<"Enter 3 to Delete element at a key"<<endl;
      cout<<"Enter 4 to Exit"<<endl;
      cout<<"Enter your choice: ";
      cin>>c;
      switch(c)
 	{
         case 1:
         	{
         		cout<<"Enter element to be inserted: ";
	            cin>>v;
	            cout<<"Enter key at which element to be inserted: ";
	            cin>>k;
	            h.Insert(k, v);
       		    break;
			}
            
         case 2:
            {
            	cout<<"Enter key of the element to be searched: ";
	            cin>>k;
	            if (h.SearchKey(k) == -1)
				{
	               cout<<"No element found at key "<<k<<endl;
	               continue;
	            }
				else
				{
				    cout<<"Element at key "<<k<<" : ";
	               cout<<h.SearchKey(k)<<endl;
	            }
	      		break;
			}
         case 3:
            {
            	cout<<"Enter key of the element to be deleted: ";
	            cin>>k;
	            h.Remove(k);
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


