#include<iostream>
using namespace std;
 void solve(string digits,string temp,vector<string> &ans,string arr[],int index)
    {
        if(index>=digits.length())
        {
            ans.push_back(temp);
            return;
        }
        else
        {
            int num = digits[index]-'0';	//for converting character in to integer numbers
            string val = arr[num];
            for(int i=0;i<val.length();i++)
            {
                temp.push_back(val[i]);
                solve(digits,temp,ans,arr,index+1);
                temp.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        vector<string> ans;
        if(digits.length()==0)
        {
            return ans;
        }
        string temp= "";
        int index  = 0;
        string arr[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,temp,ans,arr,index);
        return ans;
        
    }
int main()
{

return 0;

}

