#include<iostream>
#include<vector>
using namespace std;
int main()
{
vector<int> v;
vector<int> a(v);			// copying the array elements
//for(int i:v)
//{
//	cout<<i<<endl;
//}
// size har bar double hojata ha 
v.push_back(1);
cout<<"Capicity:  "<<v.capacity()<<endl;
cout<<"SIZE : "<<v.size()<<endl;
v.push_back(7);
v.push_back(2);
cout<<"Capicity:  "<<v.capacity()<<endl;
cout<<"SIZE : "<<v.size()<<endl;
cout<<"AT 2 INDEX: "<<v.at(0)<<endl;			// indexing starts from 0
cout<<"FRONT : "<<v.front()<<endl;
v.pop_back();				// remove last element from array
//v.pop_back();
cout<<"AT 0 INDEX: "<<v.at(1)<<endl;
return 0;

}

