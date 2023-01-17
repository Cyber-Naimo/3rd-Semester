#include <iostream>  
using namespace std;  

bool Common_Friend(bool ptr[5][5],int friend1,int friend2)
{      
    for (int i=0;i<5;i++)
	{         		
	    if(ptr[friend1][i])
		{            			
		    if(ptr[friend2][i])
			{                 				
		   		 return true; 			
		    } 		
	        
	    } 	
        
    }     	
    return false; 
    
}    
int main() 
{  	
    bool ptr[5][5] = {{false,true,false,true,true},{true,false,true,false,true},{false,true,false,false,false},{true,false,false,false,true},{true,true,false,true,false}}; 	    
	
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout<<"  "<<ptr[i][j];
			
		}
		cout<<"\n\n";	
	} 
	  int friend1 = 0;     
      int friend2 = 3;
	              
     if(Common_Friend(ptr,friend1,friend2))
	 {
		 cout<<friend1<<" and "<<friend2<<" have a common neighbour."; 
	 }    
	 else
	 {
	     cout<<friend1<<" and "<<friend2<<" do not have a common neighbour.";
			  
	 } 	
 }
