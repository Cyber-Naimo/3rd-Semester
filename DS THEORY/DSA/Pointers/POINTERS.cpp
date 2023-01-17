#include<iostream>
using namespace std;
void fun(int **p)
{

	p=p+1;  			// kch chnnage hoga  -> 		nh hoga
	*p=*p+1;					// kch chnnage hoga  ->    adress chnage hoga
	**p = **p + 1;						// kch chnnage hoga  -> value chnage hogi

}
   //*arr    or arr[]  dono same hote h mean jb size nikaloge to pointer ka size h ayega
   //jb m function m *p pass krta ho to adress chnage nh hota h but value change hoskti ha
int main()
{
//	int n=5;					//	n[5]=  adress is 100;         p[100]=adress is 700       p2[700]= adress is 1001
//	int *p1=&n;
//	int **p2=&p1;                           /*suppose nth adress is 100 so in p1 block 100 is assigned and p1 adress is 700, now i have create double pointer 
//											now in p2 block 700 is assigned suppose p2 adress is 1001; */
//	cout<<"BEFORE: "<<endl;										
//	cout<<"Value of n : "<<n<<endl;
//	cout<<"adress of p1 : "<<p1<<endl;
//	cout<<"adress of p2 : "<<p2<<endl;
//	fun(p2);
//	cout<<"Value of n : "<<n<<endl;
//	cout<<"adress of p1 : "<<p1<<endl;
//	cout<<"adress of p2 : "<<p2<<endl;	
//	char ch[]="ABCDE";
//	char *c=&ch[0];
////	c+=1;
//	cout<<" "<<c<<endl;   	//*c will print the first letter   and c print entire array
	int arr[]={2,5,6};
	int *p=&arr[0];
	cout<<"Before  "<<*p<<endl;
	p+=1;     // we are accesing the second memory adress
	cout<<"after   "<<*p<<endl;
//	arr=arr+1;   // it gives error we can not chnage it
	cout<<" "<<sizeof(arr)<<endl;  // complete size of array
	cout<<" "<<sizeof(*arr)<<endl; //size of the data type of array
	cout<<" "<<sizeof(&arr)<<endl; // its a pointer it always take 8 
//	for(int i=0;i<3;i++)
//	{
//		cout<<" "<<i[arr]<<endl;     // new method  i[n]= *(i+arr)
//	}
//	cout<<" "<<arr;				// print adress at 0 location
//	cout<<" "<<*arr;			// print value at 0 location
//	cout<<" "<<arr[0];			// print value at 0 location
//	cout<<" "<<arr+1;			// print adress at 1 location because we add arr+1 mean arr= arr[1]
//	cout<<" "<< *arr+1;			// print value at 0 location with adding 1
//	cout<<" "<<*(arr+1);		// print value at 1 location
//	int n=5;
//	int a=n;
//	cout<<"A Before: "<<n<<endl;
//	a++;
//	cout<<"A AFTER: "<<n<<endl;
//	int *p=&n;
//	cout<<"P Before: "<<n<<endl;
//	(*p)++;
//	cout<<"P AFTER: "<<n<<endl;
//	// copying a apointer
//	int *q=p;
//	(*p)++;
//	cout<<"VALUE:  "<<*p<<endl;
//	cout<<"VALUE:  "<<(*q)<<endl;
//	(*q)++;	
//	(*q)++;	
//	(*q)=(*q)+1;
////	jo q ki value h wahi p ki value ha	
//
//	cout<<"VALUE:  "<<(*q) + (*p)<<endl;
	
//	Agr adress mjhe plus krana ho to m q=q+1 krunga  ike in Arrays
	
//	first method      INT *P=0  P=&N;
//	int *p=0;
//	p=&n;	
//	cout<<"VALUE:  "<<*p<<endl;
//	2ND METHOD:     int *q=&n;
//	int *q=&n;
//	p is a pointer to int variable	   int *q=&n;
//	P ME ADRESS SAVE HOTA H 
//	*P MEAN DEREFRENCING YE VALUE DEGA
// pointer ka size hamsesha 8 hoga in any data type
//	cout<<"VALUE: "<<n<<endl;
//	cout<<"ADRESS: "<<q<<endl;
//	cout<<"SIZE: "<<sizeof(q)<<endl;
//	cout<<"VALUE: "<<*q<<endl;
	return 0;

}

