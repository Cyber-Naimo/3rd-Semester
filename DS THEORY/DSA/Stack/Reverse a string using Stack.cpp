#include<iostream>
#include<vector>
using namespace std;
#include<stack>
int main()
{
	// REVERSING AN ARRAY:
	
	int arr[5] = {1,2,4,56,6};
	vector<int> a;
	stack<int> s;
	for(int i=0;i<5;i++)
	{
		int temp = arr[i];
		s.push(temp);
	}
	while(!s.empty())
	{
		int tem = s.top();
		a.push_back(tem);
		s.pop();
	}
	for(int i=0;i<5;i++)
	{
		cout<<" "<<a[i]<<" --> ";
	}
	
	// REVERSING  A STRING
//	string str = "live";
//	stack<char> s;
//	
//	for(int i=0;i<str.length();i++)
//	{
//		char ch = str[i];				// storing the character 
//		s.push(ch);						// pushing in the stack
//	}
//	string ans = " ";		// creating NULL string
//	
//	while(!s.empty())		// when stack is empty return
//	{
//		char c = s.top();				// storing the last character
//		ans.push_back(c);				// storing this character in new NULL string
//		s.pop(); 						// now removin this character inorder to make it empty
//	}
	return 0;

}

