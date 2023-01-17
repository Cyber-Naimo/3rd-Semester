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
				cout<<" Head:  "<<cur->val<<" --> ";
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
			return " Not Present";
		}
		
};

class HashTable
{
	public:
		Linkdlist* table = new Linkdlist[tablesize];
		int WordAsci(string str)
		{
			int  sum = 0; 
			for (int i = 0; str[i] != '\0'; i++)
			{
				 sum = sum + str[i];
			}
		    return sum;  
		}
		int CalculateKey(string str)
		{
			return WordAsci(str);
		}
		
		int HashFunction(int key)
		{
			return key%tablesize;
		}
		
		void insert(int key,string value)
		{
			int index = HashFunction(key);
			table[index].Insertion(key,value);
			cout<<"Value Inserted: "<<endl;
		}
		
		string search(int key)
		{
			int index = HashFunction(key);
			return (table[index].Search(key));
		}
		void show(int key)
		{
			int index = HashFunction(key);
			table[index].Display();
		}
};

int main()
{
    HashTable obj;
    obj.insert(obj.CalculateKey("Kindness")+16,"Kindness");
    obj.insert(obj.CalculateKey("Politness")+16,"Politness");
    obj.insert(obj.CalculateKey("Understandable")+16,"Understandable");
    obj.insert(obj.CalculateKey("Empathy")+16,"Empathy");
    obj.insert(obj.CalculateKey("Easy")+16,"Easy"); 
    cout<<" "<<obj.search(obj.CalculateKey("Understandable")+16)<<endl;
    obj.show(obj.CalculateKey("Understandable")+16);
}
