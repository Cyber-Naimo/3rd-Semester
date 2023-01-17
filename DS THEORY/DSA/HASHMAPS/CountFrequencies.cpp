#include<bits\stdc++.h>
using namespace std;
const int N = 1e7+10;
int hsh[N]; 		// deafult initiallize with   zeros
int main()
{
	int size;
	cin>>size;
	int arr[size];
	// 1 1 2 2 3
	cout<<"ENTER ARRAY VALUES: "<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
		hsh[arr[i]]++;
	}
	
	int q;
	cout<<"ENTER NO OF TEST CASES: "<<endl;
	cin>>q;
	while(q--)
	{
		int x;
		cin>>x;
		cout<<" Count of "<<x<<" :  "<<hsh[x]<<endl;
	}
 return 0;
}

