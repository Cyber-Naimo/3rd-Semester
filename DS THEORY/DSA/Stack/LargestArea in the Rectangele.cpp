#include<iostream>
using namespace std;
#include<vector>
#include<stack>
class Solution 
{
  vector<int> NextSmallerElement(vector<int>& arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i = n-1; i>=0; i--)
    {
        int cur = arr[i];
        while(s.top()!=-1 && arr[s.top()]>= cur)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
         return ans;
}
    
 vector<int> PrevSmallerElement(vector<int>& arr, int n)
   {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i = 0;i<n;i++)
    {
        int cur = arr[i];
        while(s.top()!=-1 &&arr[s.top()]>= cur)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
         return ans;
    }
public:
  
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n);
        vector<int> pre (n);
        next = NextSmallerElement(heights,n);
        pre =  PrevSmallerElement(heights,n);
        int area = INT_MIN;
        for(int i =0;i<n;i++)
        {
            if(next[i] == -1)
            {
                next[i] = n;
            }
            int l = heights[i];
            int b = next[i] - pre[i]-1;
            int newArea = l*b;
            
            area = max(area,newArea);      
        }
        return area;
    }
  
};

int main()
{

return 0;

}




