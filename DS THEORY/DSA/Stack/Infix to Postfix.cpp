#include<iostream>
using namespace std;
#include<stack>

		int precedence(char x)
		{
			if(x=='+' || x=='-')
			{
				return 1;
			}
			else if(x=='*' || x=='/')
			{
				return 2;
			}
			else if(x == '^')
			{
				return 3;
			}
			else
			{
				return -1;
			}
		}
		int postfixEvaluation(string s)
		{
			stack<int> st;
			for(int i =0 ;i< s.length();i++)
			{
				if(s[i]>=0 && s[i]<=9)
				{
//					st.push(st[i]-'0');			// converting character to int
				}
				else
				{
					int op2 = st.top();
					st.pop();
					int op1 = st.top();
					st.pop();
					switch(s[i])
					{
						case '+':
							st.push(op1+op2);
							break;
						case '-':
							st.push(op1-op2);
							break;
						case '*':
							st.push(op1*op2);
							break;
						case '/':
							st.push(op1/op2);
							break;
					} 
				}
			}
			return st.top();
		}
		string InfixToPostfix(string s)
		{
			/*
			step1: agr koi bh alphabet hogato hm srf use resultent string m add krenge
			step2: agr opening bracket h to simply use push krdege stack me
			step3: agr closing bracket h to loop tb tk chalayega jb tk use opening bracket nh milti and jo bh stack ka top hoga use wo res string m save krata rahega
			step4: agr koi opertaor h to uski precendence chack krna agr stack ki precedence sa ziada ho tbhi stack ka top ko resultant string m save krna simple.
			step5: last ma loop tk tk chalo jb tk stack empty nh hota and jo bh remaining element h use resultant string m save krake string return krdo
			*/
			stack<char> st;
			string res = " ";
			for(int i =0 ;i<s.length();i++)
			{
				if(s[i]>= 'a' &&  s[i]<= 'z')			// (a+b)*c
				{
					res+= s[i];
				}
				else if(s[i]=='(')
				{
					st.push(s[i]);
				}
				else if(s[i] ==')')
				{
					while(!st.empty() && st.top()!='(')
					{
						res+= st.top();
						st.pop();	  	
					}
					if(!st.empty())
					{
						st.pop();			// for deleting remaining opening bracket
					}
				}
				else
				{
					while(!st.empty() && precedence(st.top()) > precedence(s[i]))
					{
						res+= st.top();
						st.pop();
					}
					st.push(s[i]);
				}
			}
			
			while(!st.empty())
			{
				res+= st.top();
				st.pop();
			}
			return res;
		}
		
		
		string postfix_to_infix(string postfix)
		{
		  stack<string> s;
		
		  // getting length of postfix expression
		  int l=postfix.length();
		
		  // Reading the Postfix expression from left to right
		  for(int i=0;i<l;i++)
		  {
		      // if the symbol is an operand, push it to the stack
		      if((postfix[i]>='a' && postfix[i]<='z')||(postfix[i]>='A' && postfix[i]<='Z'))
		      s.push(string(1,postfix[i]));
		
		      // if symbol is an operator
		      else
		      {
		        // pop two operands (op1 & op2) from stack
		        string op1=s.top();
		        s.pop();
		        string op2=s.top();
		        s.pop();
		
		        // Creating a string by concatenating the two operands and the operator between them and pushing it back to the stack.
		        
		        
		        
		        string temp=("("+op2+postfix[i]+op1+")");
		        s.push(temp);
		      }
		  }
		  // returning element/string at top of stack
		  return s.top();
		}
		
int main()
{

	cout<<" "<<InfixToPostfix("((a+b)*c)-d")<<endl;
//	cout<<" "<<postfixEvaluation("46+2/5*7+")<<endl;
	cout<<" "<<postfix_to_infix("ab+cd-*");

}

