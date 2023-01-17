#include<iostream>
#include<vector>
using namespace std;
#include<string>
#include<vector>
class Solution {
public:
    
    bool ispal(string s){
        int i = 0, j = s.size()-1;
        while(i < j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    vector<vector<string>> ans;
    
    void solve(string s, vector<string> &temp, int i, int n){
        if(i == n){
            ans.push_back(temp);
            return;
        }
        for(int j = i; j<n; j++){
            string r = s.substr(i, j-i+1);
            if(ispal(r)){
                temp.push_back(r);
                solve(s, temp, j+1, n);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(s, temp, 0, s.size());
        return ans;
    }
};
int main()
{

return 0;

}

