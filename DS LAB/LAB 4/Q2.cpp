#include<iostream>
using namespace std;

		void Print(string day[], string month[] ,int year[] , int size)
		{
			cout<<"RECORDS ARE: "<<endl;
			for(int i=0;i<size;i++)
			{
				cout<<" DAY  --> "<<day[i]<<" ";
				cout<<" MONTH  --> "<<month[i]<<" ";
				cout<<" YEAR  --> "<<year[i]<<endl;
			}
				
		}
		
		void SortedYearPrint(int year[] , int size)
		{
			cout<<"SORTED RECORDS BY YEARS ARE: "<<endl;
			for(int i=0;i<size;i++)
			{
				cout<<" YEAR  --> "<<year[i]<<endl;
			}
				
		}
		void Input(string day[], string month[] ,int year[] , int size)
		{
			for(int i=0;i<size;i++)
			{
//				cout<<" ENTER THE DAY: ";
//				cin>>day[i];
//				cout<<" ENTER THE MONTH: ";
//				cin>>month[i];
				cout<<" ENTER THE YEAR: ";
				cin>>year[i];
				cout<<"\n **********************************************************************************************************************\n";
			}
		}
		void SelectionSort(int year[],int size)
		{
			int min;
			int i;
			
			for( i=0;i<size-1;i++)
			{
				min = i;
				
				for(int j = i+1; j<size;j++)
				{
					if(year[j] < year[min])
					{
						min = j;
					}
				}		
			}
			if(min!=i)
			{
				swap(year[min],year[i]);
			}
		}
int main()
{
	int size;
	cout<<" ENTER THE SIZE OF THE STRING: ";
	cin>>size;
	string day[size];
	string month[size];
	int year[size];
	Input(day,month,year,size);
	Print(day,month,year,size);
	SelectionSort(year,size);
	SortedYearPrint(year,size);
	

	return 0;

}

