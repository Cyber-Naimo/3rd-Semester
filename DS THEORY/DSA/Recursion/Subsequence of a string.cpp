#include<bits\stdc++.h>
using namespace std; 
	
// 		POWERS SET
 void solve(vector<int>&nums,vector<vector<int>> &ans, vector<int> temp,int i )
    {
        if(i>=nums.size())
        {
            ans.push_back(temp);
            return;
        }
        else
        {
//        	exclude call
            solve(nums,ans,temp,i+1);
//            include call
            int ele = nums[i];
            temp.push_back(ele);
            solve(nums,ans,temp,i+1);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
        vector<int> temp;
        int i =0;
        solve(nums,ans,temp,i);
        return ans;
    }
void solve(string str, vector<string> &ans, string temp,int i )
{
    if(i>=str.length())
    {
       if(temp.length()>0)
       {
           ans.push_back(temp);
       }
        return;
    }
    else
    {
        solve(str,ans,temp,i+1);
        char e = str[i];
        temp.push_back(e);
        solve(str,ans,temp,i+1);     
    }
}
vector<string> subsequences(string str){
	
	vector<string> ans;
    string temp = "";
    int i=0;
    solve(str,ans,temp,i);
    return ans;	
}

int main()
{

	vector<string> res = subsequences("Naimat");
	for(int i=0;i<res.size();i++)
	{
		cout<<" "<<res[i];
	}
	

}

