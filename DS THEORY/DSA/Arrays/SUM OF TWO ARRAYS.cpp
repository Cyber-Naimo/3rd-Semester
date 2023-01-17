#include<iostream>
using namespace std;
#include<vector>
//vector<int> reverse(vector<int>&a)
//{
//    int i=0;
//    int j=a.size()-1;
//    while(i<j)
//    {
//        swap(a[i++],a[j--]);
//    }
//    return a;
//}
//vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
//	// Write your code here.
//    int i=n-1;
//    int j=m-1;
//    
//    vector<int> ans;
//    int carry=0;
//    int sum=0;
//    
//    while(i>=0 && j>=0)
//    {
//        sum=a[i]+b[j]+carry;
//        carry=sum/10;
//        sum=sum%10;
//        ans.push_back(sum);
//        i--;
//        j--;
//    }
//    while(i>=0)
//    {
//        sum=a[i]+carry;
//        carry=sum/10;
//        sum=sum%10;
//        ans.push_back(sum);
//        i--;
//    }
//    while(j>=0)
//    {
//        sum=b[j]+carry;
//        carry=sum/10;
//        sum=sum%10;
//        ans.push_back(sum);
//        j--;
//    }
//    while(carry!=0)
//    {
//        sum=carry;
//        carry=sum/10;
//        sum=sum%10;
//        ans.push_back(sum);
//    }
//        
//   return reverse(ans);
//    
//    
//}
int main()
{
int arr[3]={1,3,2};
vector<int> ans;

for(int i=0;i<ans.size();i++)
{
	cout<<ans[i];
}



}

