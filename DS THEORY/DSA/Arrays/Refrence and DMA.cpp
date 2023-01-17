#include<iostream>
using namespace std;

//Refrence varibale = same memory + different name
//int arr[n]=   BAD PRACTICE			memory uses from stack  runtime pe use nh krna ha
//int arr[10000]= good practice
void update(int &n)
{
//	pass by refrence krne sa value chnage hojato ha
	n++;
}
int main()
{
//	int i=5;
//	//REFRENCE VARIABLE
//	int &j=i;
//	cout<<" "<<i;
//	i++;
//	cout<<" "<<j;
//	j++;
//	cout<<" "<<i;
//	cout<<"BEFORe: "<<j;
//	update(i);
//	cout<<"after: "<<i;


int row;
cin>>row;
int col;
cin>>col;

int **ptr=new int*[row];


//int *arr=new int [n];			for 1d arrays

//int **ptr= new int *[n];   		// for 2d arrays;


for(int i=0;i<row;i++)
{
	ptr[i]=new int[col];
	for(int j=0;j<col;j++)
	{
		cin>>ptr[i][j];
	}
	
}
cout<<"\n\n";
for(int i=0;i<row;i++)
{	
	for(int j=0;j<col;j++)
	{	
		cout<<" "<<ptr[i][j];
	}
	cout<<"\n";
}
//
for(int i=0;i<row;i++)
{	
	
delete [] ptr[i];
}

delete []ptr;

for(int i=0;i<row;i++)
{	
	for(int j=0;j<col;j++)
	{	
		cout<<" "<<ptr[i][j];
	}
	cout<<"\n";
}
//

	
	
return 0;

}

