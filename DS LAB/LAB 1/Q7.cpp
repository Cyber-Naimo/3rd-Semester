#include<iostream>
using namespace std;
class Numbers{
	
	private:
		int *ptr,size;
		
	public:
	
	Numbers()
	{
		ptr=new int;	
	}	
	
	void set(int size,int p)
	{
		ptr=new int;
		*ptr=p;
		this->size=size;
	}
	
	void output()
	{
		cout<<"SIZE: "<<size<<endl;
		
	}
	
	Numbers(const Numbers &obj)		// COPY CONSTRUCTOR
	{
    	ptr=new int;
    	*ptr=*(obj.ptr);
    	this->size=obj.size;
	}
	
	~Numbers ()				// DESTRUCTOR
	{	
	    delete ptr;
	};
	
};

int main(){
	
	Numbers n1;
	n1.set(15,10);
	Numbers n2(n1);		
	n1.output();
	n2.output();
	
	
	
	
	
}

