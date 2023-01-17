#include <iostream>
#define tablesize 20
using namespace std;

class Node
{
    public:
    string val;
	int key;
    Node* next;
    Node(int k, string value)
	{
        val = value;
        key = k;
        next = NULL;
    }
};
class Linkdlist
{
	public:
		Node* head;
		Node* tail;
		Linkdlist()
		{
			head = tail = NULL;
		}
		void Insertion(int key,string value)
		{
			Node* newNode = new Node(key,value);
			if(head == NULL)
			{
				head = tail = newNode;
			}
			else
			{
				tail->next = newNode;
				tail = newNode;
			}
		}
		void Display()
		{
			Node* cur = head;
			while(cur!=NULL)
			{
				cout<<"  "<<cur->val<<" --> ";
				cur = cur->next;
			}
			cout<<"NULL"<<endl;
		}
		string  Search(int key)
		{
			if(head!=NULL)
			{
				Node* cur = head;
				while(cur!=NULL)
				{
					if(cur->key == key)
					{
						return cur->val;
					}
					cur = cur->next;
				}
			}
			return " Not Present ";
		}
		
};

class HashTable
{
	public:
		Linkdlist* table = new Linkdlist[tablesize];
		int WordAsci(string str)
		{
			int  sum = 0; 
			for (int i = 0; i<str.length(); i++)
			{
				 sum = sum + str[i];
			}
			// here 16 is my roll NO 21k-4540    = 16 + WORDCOUNT
		    return sum+16;  
		}
		int CalculateKey(string str)
		{
			return WordAsci(str);
		}
		
		int HashFunction(int key)
		{
			return key%tablesize;
		}
		
		void insert(string value)
		{
			int key=  CalculateKey(value);
			int index = HashFunction(key);
			table[index].Insertion(key,value);
			cout<<"Value Inserted! "<<endl;
		}
		
		string search(string value)
		{
			int key= CalculateKey(value);
			int index = HashFunction(key);
			return (table[index].Search(key));
		}
		
		void show()
		{
			for(int i=0;i<tablesize;i++)
			{
				table[i].Display();
			}
		}
		
};

int main()
{
    HashTable obj;
    obj.insert("Kindness");
    obj.insert("Politeness");
    obj.insert("Understandable");
    obj.insert("Empathy");
    obj.insert("Knowledge");
    obj.insert("Gratitude");
    obj.insert("Patience");
    obj.insert("Righteous");
    obj.insert("Appreciate");
    obj.insert("Easy");
    obj.insert("Thought");
    cout<<" SEARCH WORD:  "<< obj.search("Easy")<<endl;
    cout<<endl;
    obj.show();

}
