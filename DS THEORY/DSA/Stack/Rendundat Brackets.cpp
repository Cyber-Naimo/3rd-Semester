#include<iostream>
using namespace std;
#include<stack>
bool findRedundantBrackets(string &s)
{
     stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')			// ( (a+b))  in this first braces are uselles so return true;
        {
            st.push(ch);
        }
        else
        {
            if(ch == ')')
            {
                bool reduntant = true;
                while(st.top()!='(')
                {
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        reduntant = false;
                    }
                    st.pop();
                }
                if(reduntant == true)
                {
                    return true;
                }
                st.pop();
            }           
        }
    }
     return false; 
}
int main()
{

return 0;

}

