#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main()
{
	//unorder map ki time complexity O(1) hoti ha; ye Hashing pe kam krta ha
	// map ki time complexity O(logn) hoti h wo BST pe kam krta ha
	unordered_map<string,int> m;
	/* INSERTION DIFFERENT METHOD:
	*/
	// Method 1:
	pair<string,int> p("Naimat",9);
	m.insert(p);
	
	// Method 2:
	m["Nohail"] = 1;
	m["Mohsin"] = 2;
	cout<<" "<<m["Nohail"]<<endl;
	// Now key value of Nohail will be updated to 3 because each strings has Unique value no duplicates allowed
	m["Nohail"] = 3;
	cout<<" "<<m["Nohail"]<<endl;
	cout<<" "<<m.at("Naimat")<<endl;
	cout<<"SIZE: "<<m.size()<<endl;
	
	// Now look at an example which is not exit
//	cout<<" "<<m.at("JILA")<<endl; 	// this will give garbage value or exception beacuse no string exits
	
	// Solution for above 
	
	cout<<" "<<m["JILA"]<<endl;		// this will assign JILA key to 0 
	cout<<" "<<m.at("JILA")<<endl;	// it also give 0 because in above line 0 key assign to JILA.
	cout<<"SIZE: "<<m.size()<<endl;
	
	// check key exist or not
	cout<<" "<<m.count("Naimat")<<endl;
	
	// Deletion of key
	m.erase("JILA");
	cout<<"SIZE: "<<m.size()<<endl;
	
	// Iterator to print All the pairs;
	unordered_map<string,int> :: iterator it = m.begin();
	while(it!=m.end())
	{
		cout<<" "<<it->first<<"  "<<it->second<<endl;
		it++;
	}
	return 0;

}

