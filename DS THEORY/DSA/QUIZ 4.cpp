#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

	string arr[] = {"How to delete a node? "," How to sort ?"," How to reverse a linkdlist? "};
	
//	cout<<"ENTER NO OF QUESTIONS:";
//	int n;
//	string ptr[n];
//	for(int i =0;i<n;i++)
//	{
//		cin>>ptr[i];
//	}
	
	stack<string> st;
	
	stack<string> sun;
	for(int i=0;i<3;i++)
	{
		st.push(arr[i]);
	}
	string ans;
	for(int i=0;i<3;i++)
	{
		string temp = st.top();
		cout<<temp<<endl;
		fflush(stdin);
		getline(cin,ans);
		sun.push(ans);
		st.pop();	
	}

	for(int i=0;i<3;i++)
	{
		st.push(arr[i]);
	}
	
	while(!sun.empty())
	{
		string ans1 = st.top();
		cout<<""<<ans1<<endl;
		fflush(stdin);
		cout<<" "<<sun.top()<<endl;
		sun.pop();
		st.pop();
	}
}

