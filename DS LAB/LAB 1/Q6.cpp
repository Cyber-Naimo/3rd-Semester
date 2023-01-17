#include<iostream>
using namespace std;
class Animal
{
	private:
		string name;
		string color;

	public:
		Animal()
		{
		}	
	
		Animal(string name,string color)
		{
			this->name=name;
			this->color=color;
		}
	
		void print()
		{
			cout<<"Name of Animal: "<<name<<endl;
			cout<<"Color of Animal: "<<color<<endl;
	
		}
		
		string getname()
		{
			return name;
		}
		void setname(string a)
		{
			name=a;
		}
};

int main()
{


Animal *a[5];
a[0]=new Animal("Camel"," Brown");
a[1]=new Animal("Buffalo","White");
a[2]=new Animal("Cat","Black");
a[3]=new Animal("Rabbit","White");
a[4]=new Animal("Hen","light Yellow");

// Ascending sorting logic

	for (int i=0;i<5;i++)
	{
        for (int j=0;j<5-1;j++)
		{
		
            if (a[j]->getname() > a[j + 1]->getname())
			{
			
            		string b=a[j]->getname();
            		a[j]->setname(a[j+1]->getname());
            		a[j+1]->setname(b);
			}
		}
	}
	
	cout<<"DISPLAYING SORTED ARRAY BY ANIMAL NAMES: "<<endl<<endl;
     for (int i = 0; i < 5; i++)
     {
     	   cout << a[i]->getname() << endl;
	 }


}

