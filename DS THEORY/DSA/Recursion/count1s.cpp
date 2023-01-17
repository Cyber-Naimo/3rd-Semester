#include <iostream>

using namespace std;
static int ans = 0;
int countOnes(int n)
{
    if (n==1){
        return n;
		  }
    else{
        if ((countOnes(n/2)%2==1)){
            ans++;
        }
        return n;
    }
}
int main()
{
    int n =countOnes(15);
    cout<<ans;
}
