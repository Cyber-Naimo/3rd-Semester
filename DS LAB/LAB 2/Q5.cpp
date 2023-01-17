#include<iostream>
using namespace std;
int main()
{

	float sgpa;
	int rows;
	cout<<"ENTER NO OF STUDENTS IN THE UNIVERSITY: "<<endl;
	cin>>rows;
	int subjects[rows];
	cout<<endl;
	for(int i=0;i<rows;i++)
	{
		cout<<"ENTER THE TOTAL SUBJECTS CHOOSE BY STUDENT: "<<i+1<<endl;
		cin>>subjects[i];
	}
	int *arr[rows];
	cout<<endl;
	for(int i=0;i<rows;i++)
	{
		arr[i]=new int [subjects[i]];
	}
	cout<<endl;
	
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<subjects[i];j++)
		{
			cout<<" STUDENT:"<<i+1<<"["<<i<<"] ["<<j<<"] :  ";
			cin>>arr[i][j];
		}
		cout<<"\n";
	}
	
	
	for(int i=0;i<rows;i++)
	{
		float sum=0;
		int cal=0;
		float cgpa=3.22;
		for(int j=0;j<subjects[i];j++)
		{
		
			 cal=arr[i][j]*3;
			 sum+=cal;
			
			
		}
		sgpa=sum/15;
		cgpa=cgpa*115;
		cgpa=(cgpa+sgpa*15)/130;
		cout<<"\n";
		cout<<"SGPA OF STUDENT: "<<i+1<<" IS:  "<<sgpa;
		cout<<"\n";
		cout<<"CGPA OF STUDENT: "<<i+1<<" IS:  "<<cgpa;
	}
	
	
	
	
	
}
