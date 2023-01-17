#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<string>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include<windows.h>
#include<sstream>
#include<unordered_map>
using namespace std;



class Stack
{
	int top;
	char arr[1000][100];
	
	public:
		
		Stack()
		{

			top = -1;
		}
		
		void push(char* element)		
		{
			if(top<1000-1)
			{
				top++;
				strcpy(arr[top],element);	

			}
			else
			{
				cout<<"1000 transactions are done. You should go to bank to increase your transactions limit "<<endl;
			}
		}
		void pop()
		{
			if(top>=0)
			{			
				top--;
			}

		}
		
		
		
		bool empty()
		{
			if(top == -1)
			{
				return 1;

			}
			else
			{
				return 0;

			}
		}

		char* peek()
		{
				return arr[top];
		}
		

	
};



void title()
{
	string bankName="THE CITIZENS BANK";
		
			system("cls");
	        char Arr[100];
			strcpy(Arr,bankName.c_str());
			cout<<"\n\t\t----------------------------------------------";
			cout<<"\n\t\t   ";
			for(int i=1;i<=17;i++)
			{
				if( i < 9)
				{
					Sleep(100);
					cout<<">";
				}
				else if( i > 9 )
				{
					Sleep(100);
					cout<<"<";
				}
				else if( i == 9 )
				{
					cout<<"   ";
					for(int j=0;j<bankName.length();j++)
					{
						Sleep(100);
						cout<<Arr[j];
					}
					cout<<"   ";
					
				}
				else
				{
					cout<<endl;
				}
			}	
			cout<<"\n\t\t----------------------------------------------\n\n";
}
void loading()
{
	cout<<"\n\t\t";
    cout<<"\n\t\tLoading in process ";
    for(int i=0;i<3;i++)
    {
    	Sleep(400);
    	cout<<(char)16<<" "; 
    
	}
	Sleep(1000);
	system("cls");
}


class feedback
{
	protected :
		string name;
		string tfeed;
	public :
		feedback()
		{
			name = "Empty";
			tfeed = "Empty";
		}
		void getfeedback()
		{
			ofstream out;
			out.open("allfeedback.txt",ios::app);
			title();
			cout<<"\n\n\tEnter Your name : ";
			cin.ignore();
			getline(cin, name);
			cout<<" \n\t"<<name<<", Enter your feedback  : ";
			getline(cin, tfeed);
			out<<"\tName : "<<name<<"\tFeedback : "<<tfeed<<endl;
			cout<<"\n\n\t THANK YOU FOR FEEDBACK !!!\n\n";
			system("PAUSE");
			out.close();
		}
		void ShowAllFeedback()
		{
			char c;
			ifstream inp;
			inp.open("allfeedback.txt");
			if(!inp)
			{
				cout<<"\n\n\n\tFILE NOT FOUND\n\n";
				return;
			}
			title();
			while(1)
			{
				inp.get(c);
				cout<<c;
				if(inp.eof())
				{
					break;
				}
			}
			cout<<endl;
			system("PAUSE");
			inp.close();	
		}	
};









class account
{
	int accountnumber;
	char name[25];
	char cnic[20];
	char contactnumber[15];
	char address[35];
	char type;
	int Balance;
	int numberoftransactions;
	char pass[10];
	char openingtime[50];
	Stack history;
		
	int getaccnum()
	{	

		srand(time(0));
		return rand();			// generating random account no
	}	
	
public:
	
	void writinginfile()
	{	
		stringstream ss;  
	  	ss<<accountnumber;  
	  	string a;  
	  	ss>>a;
		string b=a.append(" account");

		string f=b.append(".txt");
		char const *p = f.c_str();
		ofstream fout;
		fout.open(p);
		fout << "\tAccount Number: " << accountnumber << endl; 
		fout << "\tAccount Type: " << type << endl;
		fout << "Name: " <<  name << endl;
		fout << "Cnic: " << cnic << endl;
		fout << "Contact Number: " << contactnumber << endl;
		fout << "Address: " << address << endl;
		fout << "Balance: " << Balance << endl;
		fout << "Number of Transactions: "<<numberoftransactions<<endl;
		fout << "Account Opening Date and Time: "<<openingtime<<endl;
	fout<<"\nHistory: \n\n";
	Stack tempp=history;
		while(1){
		fout<<tempp.peek()<<endl;
		tempp.pop();
		if(tempp.empty()){
			break;
		}
	}	
		fout.close();
	}
	
	void create_account()
{
	char a;
	
	accountnumber=getaccnum();
	cout<<"\n\nEnter The Name of The Account Holder: ";
	cin.ignore();
	cin.getline(name,25);
	cout<<"\nEnter The Cnic Number: ";
	cin.getline(cnic,20);
	cout<<"\nEnter The Contact Number: ";
	cin.getline(contactnumber,15);
	cout<<"\nEnter Address: ";	
	cin.getline(address,35);
	cout<<"\nEnter Type of The account (C/S): ";
	cin >> a;
	while(a!='c' && a!='C' && a!='s' && a!='S')
	{
		cout << "\nWrong Type Entered!\nEnter Again the Type of The Account (C/S): ";
		cin>>a;
	}
	type=a;
	type=toupper(type);
	numberoftransactions=0;
	if(type=='S')
	cout<<"\nEnter The Initial amount( >=500 for Saving Account ): ";
	if(type=='C'){
	cout<<"\nEnter The Initial amount( >=1000 for Current Account ): ";
	}
	cin>> Balance;
	

	
	while(((a=='s' || a=='S') && Balance<500) || ((a=='c' || a=='C') && Balance<1000)){
		cout<<"\nYou can't open account with this much balance!\n Enter Again The Initial amount(>=500 for Saving and >=1000 for Current ): ";
		cin>> Balance;
	}
	
	
  stringstream ss;  
  ss<<Balance;  
  string tmp;  
  ss>>tmp;
  tmp.append(" have been deposited in your account while opening on ");
   time_t now = time(0);
   char* dt = ctime(&now);
   strcat(openingtime,dt);
   string tmp1=dt;
   tmp.append(tmp1);

    int nnn = tmp.length();
	char char_array[tmp.length() + 1]; 
    strcpy(char_array, tmp.c_str());
	history.push(char_array);

	cout << "\n\nYour Account Number is: " << accountnumber;

while(1)
{
	int i = 0; 
	char a;
	
	while(1)
	{
	
	cout << "\n\nSet your password: ";
    
    
    for(i=0;;)
    {
        a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))

        {
            pass[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(a=='\r')
        {
            pass[i]='\0';
            break;
        }
    }
	
    if(i<=5)
    {
        cout<<"\nMinimum 6 digits needed.\nSet Again!. \n";
        getch();
    }
    else
	{
    	break;
	}
}
   char p[10];
    cout << "\nConfirm Password: ";
for(i=0;;)
    {
        a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))

        {
            p[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(a=='\r')
        {
            p[i]='\0';
            break;
        }
    }    
   
    i=0;int flag=0;
    while(pass[i]!='\0' || p[i]!='\0')
	{
    	if(p[i]==pass[i])
		{
    		flag=1;
    		i++;
		}
		else
		{
			flag=0;
			break;
		}
	}
	
    if(flag==1)
	{
    	cout << "\nPassword Successfully Set!";
    	break;
	}
	else
	{
		cout << "\n\nWrong Password!\nSet Your Password again!\n ";
		
	}
}

	cout<<"\n\n\n\tAccount Created...";
}

void show_account() 
{
	cout<<"\nAccount No.: "<<accountnumber;
	cout<<"\nAccount Holder Name: ";
	cout<<name;
	cout<<"\nCnic Number: "<<cnic;
	cout<<"\nPhone Number: " <<contactnumber;
	cout<<"\nAddress: "<<address;
	cout<<"\nType of Account : "<<type;
	cout<<"\nCurrent Balance: "<<Balance;
	cout<<"\nTotal Number Of Transactions: "<<numberoftransactions;
	cout <<"\nAccount Opening Time and Date: "<<openingtime;
	cout<<"\nHistory: \n\n";
	Stack tempp=history;
		while(1){
		cout<<tempp.peek()<<endl;
		tempp.pop();
		if(tempp.empty()){
			break;
		}
	}
	
	
//	cout<<"\n\n\tHistory:\n"<<history;
}

void modify()
{

	cout<<"\nAccount No.: "<<accountnumber;
	cout<<"\nAccount Holder Name: ";
	cout<<name;
	cout<<"\nPhone Number: " <<contactnumber;
	cout<<"\nAddress: "<<address;
	cout<< "\n\nYou can only modify phone number and address";
	while(1)
	{
	
	int ch;
	cout<<"\nWhat do you want to modify? \n1) Contact Number\n2) Address\n";
	cout<<"Enter your choice: ";
	cin>> ch;
	cin.ignore();
	if(ch==1)
	{
		cout<< "\nEnter new contact number: ";
		cin.getline(contactnumber,15);
		cout<<"\n\nContact Number Updated!\n";
	}
	else if(ch==2)
	{
		cout<<"\nEnter new address: ";
		cin.getline(address,30);
		cout<<"\n\nAddress Updated!\n";
	}
	else
	{
		break;
	}
}
}


void dep(int amount)
{

  stringstream ss;  
  ss<<amount;  
  string tmp;  
  ss>>tmp;
  tmp.append(" have been deposited in your account on ");
   time_t now = time(0);
   char* dt = ctime(&now);
   string a=dt;
   tmp.append(a);
   
   
	char char_array[tmp.length() + 1]; 
    strcpy(char_array, tmp.c_str());
	history.push(char_array); 
   
   
//	history.push(tmp);
//	
	Balance+=amount;
	numberoftransactions++;
}
	
void draw(int amount,int n)
{
	time_t now = time(0);
   	char* dt = ctime(&now);
    stringstream ss;  
  	ss<<amount;  
  	string tmp;  
  	ss>>tmp;  	

	
	if(n==1)
	{
	tmp.append(" have been sent to Jazzcash on ");	

	}
	else if(n==2)
	{
	tmp.append(" have been sent to EasyPaisa on ");
	
	}
	else if(n==3)
	{
	tmp.append(" have been sent to Bank Account on ");
	
	}	
	else if(n==4)
	{
	tmp.append(" have been paid to Electricity Bill on ");	
		
	}
	else if(n==5){
	tmp.append(" have been paid to Gas Bill on ");
	
	}			
	else if(n==6)
	{
	tmp.append(" have been paid to Water Bill on ");
	
	}
	else if(n==7)
	{
	tmp.append(" have been sent as Mobile Topup on ");
		
	}
	else
	{
	tmp.append(" have been withdrawed from your account on ");	
			
	}
	string a=dt;

	tmp.append(a);
	
	
	char char_array[tmp.length() + 1]; 
    strcpy(char_array, tmp.c_str());

	history.push(char_array);	
	
	
//	history.push(tmp);
	Balance-=amount;
	numberoftransactions++;
}
	
//void report() const
//{
//	int flag=0,i=0;
//	
//	while(name[i]!='\0')
//	{
//		if(name[i]==' ')
//		{
//			flag=1;
//			break;
//		}
//		i++;
//	}
//	if(flag==0)
//	cout<<accountnumber<<"  \t"<<name<<"\t\t "<<type<<"\t "<<Balance<<"\t\t"<<numberoftransactions<<"\t"<< openingtime <<endl;
//	if(flag==1)
//	cout<<accountnumber<<"  \t"<<name<<"\t "<<type<<"\t "<<Balance<<"\t\t"<<numberoftransactions<<"\t"<< openingtime <<endl;
//}


void report() const
{
	int flag=0,i=0;
	int c=0;
	while(name[i]!='\0')
	{
		if(name[i]==' ')
		{
			flag=1;
//			break;
		}
		c++;
		i++;
	}
	if (flag==0 && c<7)
	cout<<accountnumber<<"  \t "<<name<<"\t\t\t "<<type<<"\t "<<Balance<<"\t\t   "<<numberoftransactions<<endl;	
	if(flag==0 && c<=14 && c>=7)
	cout<<accountnumber<<"  \t "<<name<<"\t\t "<<type<<"\t "<<Balance<<"\t\t   "<<numberoftransactions<<endl;
	if(flag==0 && c>14)
	cout<<accountnumber<<"  \t "<<name<<"\t "<<type<<"\t "<<Balance<<"\t\t   "<<numberoftransactions<<endl;
	if(flag==1 && c<=14)
	cout<<accountnumber<<"  \t "<<name<<"\t\t "<<type<<"\t "<<Balance<<"\t\t   "<<numberoftransactions<<endl;
	if(flag==1 && c>14){
		cout<<accountnumber<<"  \t "<<name<<"\t "<<type<<"\t "<<Balance<<"\t\t   "<<numberoftransactions<<endl;
	}
}


	
int retacno() const
{
	return accountnumber;
}

int retdeposit() const
{
	return Balance;
}

char rettype() const
{
	return type;
}
char* retpass(){
	return pass;
}

char* retname(){
	return name;
}
};



class Node{	
	public:
		account data;
		Node* next;
		Node(){
			next=NULL;
		}
		Node(account a){
			data=a;
			next=NULL;
		}
		
};

unordered_map<int,Node*> m;

	
	
class Employee{
	protected:
		string name;
		double salary;
		string password_login;
	public:
		Employee(){
			name="Empty";
			salary=0;
			password_login="Empty";
		}
		Employee(string name,double salary,string password_login){
			this->name=name;
			this->salary=salary;
			this->password_login=password_login;
		}

		string get_password_login(){
			return password_login;
		}
		 
};

class Manager:public Employee{



	void write_account(){
	Node* a=NULL;	
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(ac));
	outFile.close();
	ac.writinginfile();
	
	a=new Node(ac);
	m[ac.retacno()]=a;

}

void fun(){	
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(ac))){
		Node* a=new Node(ac);
		m[ac.retacno()]=a;	
	}
	inFile.close();

}






		void MaxHeapify(account arr[],int i, int n)
		{
			int largest = i;
			int left = 2*i+1;
			int right = 2*i+2;
			
			if(left < n && arr[left].retacno() > arr[largest].retacno())
			{
				largest = left;
			}
			if(right<n && arr[right].retacno() > arr[largest].retacno())
			{
				largest = right;
			}
			
			if(largest!=i)
			{
				swap(arr[i],arr[largest]);
				MaxHeapify(arr,largest,n);
			}
		}
		void BuildMaxHeap(account arr[],int n)
		{
			for(int i=n/2-1;i>=0;i--)
			{
				MaxHeapify(arr,i,n);
			}
		}
		void HeapSort(account arr[],int n)
		{
			BuildMaxHeap(arr,n);
			for(int i=n-1;i>=0;i--)
			{
				swap(arr[0],arr[i]);
				MaxHeapify(arr,0,i);
			}
		}



void sort(){
	int a=0;
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(ac))){
		a++;
	}
	inFile.close();
	
	account array[a];
	
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	int i=0;
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(ac))){
		array[i]=ac;
		i++;
	}
	inFile.close();	
	remove("account.dat");


//	for(int i=0;i<a;i++){
//		for(int j=0;j<a;j++){
//		//if(strcmp(array[i].retname(),array[j].retname())<0){
//			if(array[i].retname()>array[j].retname()){
//				    account temp=array[i];
//        			array[i]=array[j];
//        			array[j]=temp;
//			}
//		}
//	}
HeapSort(array,a);
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);	
	for(int i=0;i<a;i++){
	outFile.write(reinterpret_cast<char *> (&array[i]), sizeof(array[i]));
		}
	outFile.close();	
}




void delete_account(int n){

	
	int c=0,flag=0;
	if(m.find(n)==m.end()){
		cout<<"Account not found!";
		return;
	}
	else{
	m.erase(n);
		c=1;	
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(ac)))
	{
		if(ac.retacno()==n){	
		  stringstream ss;  
  	ss<<n;  
  	string a;  
  	ss>>a;
  	string b=a.append(" account");
	string f=b.append(".txt");
		char const *p = f.c_str();
		remove(p);
			flag=1;
		}
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(ac));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	
	if(flag==1&&c==1)
	cout<<"\n\n\tAccount Deleted ..";

}
}

void modify_account(int n){

	bool found=false;
	int c=0;
	if(m.find(n)==m.end()){
		cout<<endl<<"Account Not found!!"<<endl;
		c=0;
		return;
	}else{
		c=1;

	account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}

	while(!File.eof() && found==false)
	{

		File.read(reinterpret_cast<char *> (&ac), sizeof(ac));
		if(ac.retacno()==n)
		{
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(ac));
			cout<<"\n\n\t Account Updated ..";
			found=true;
		  }
	}	
	File.close();
	if(found==true){
		ac.writinginfile();
		unordered_map<int,Node*> :: iterator itr = m.begin();
		itr=m.find(n);
		if(itr!=m.end()){
		itr->second->data=ac;
		}		
	}
}
}	

	
void display_all(){
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
//	cout<<"\n\n\t\t\t\tACCOUNT HOLDER LIST\n\n";
//	cout<<"===============================================================================\n";
//	cout<<"AccNo.\t Name\t\tType\tBalance\t     No. of\t\tOpening time\n";
//	cout<<"      \t     \t\t    \t       \t  Transactions\n";
//	cout<<"===============================================================================\n";
	cout<<"\n\n\t\t ACCOUNT HOLDER LIST\n\n";
	cout<<"=========================================================================\n";
	cout<<"AccNo.\t   Name\t\t\tType\tBalance\t    No. of transactions\n"; 
	cout<<"=========================================================================\n";



	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(ac)))
	{
		ac.report();
	}
	inFile.close();
}




	public:
		Manager():Employee(){
//			root=NULL;
			fun();
		}
		Manager(string name,double salary,string password_login):Employee(name,salary,password_login)
		{
//			root=NULL;
			fun();
		}
	
		void manager_function(){
				int choice;
				while(1){
				
				cout<<"\n\n\t\tMAIN MENU\n\n";
				cout<<"\n\t1) OPEN NEW ACCOUNT\n";
				cout<<"\n\t2) CLOSE AN ACCOUNT\n";
				cout<<"\n\t3) MODIFY AN ACCOUNT\n";
				cout<<"\n\t4) ALL ACCOUNT HOLDER LIST\n";
				cout<<"\n\t5) LOGOUT\n";
				cout<<"\n\tSelect Your Option (1-5): ";
				cin>>choice;
				system("cls");
				if(choice==1){
					title();
					write_account();
				}
				else if(choice==2){
					title();
					int num;
					cout<<"\n\n\tEnter The account No. : "; cin>>num;
					delete_account(num);
				}
				else if(choice==3){
					title();
					int num;
					cout<<"\n\n\tEnter The account No. : "; cin>>num;
					modify_account(num);
				}
				else if(choice==4){
					title();
					sort();
					display_all();
				}
				else if(choice==5){
					title();
					cout << "\n\n\n\n\t\tTHANKYOU FOR LOGGING AS A MANAGER..!\n";
					break;
				}
				else{
					title();
					cout<<"\n\t\tInvalid Choice\n";
					cout<<"\n\t\tInput Again !!!\n\n";
		
				}		
		cin.ignore();
		cin.get();
		system("cls");
		title();
		}
	}
	
	

	
	
	
};



class Cashier:public Employee{
	
public:	
void display(int n)
{
	Node* a=m[n];
if(a)
a->data.show_account();
else{
	cout<< endl<<"Account not exist!!"<<endl;
}
}



void withdraw(int n,int amt,int t){

	
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(ac));
		if(ac.retacno()==n)
		{
	
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"Insufficience balance";
				else
					ac.draw(amt,t);
			
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(ac));
			cout<<"\n\n\t TRANSACTION DONE SUCCESSFULLY .. ";
			found=true;
	       }
         }
	File.close();
	
		if(found==true){
		ac.writinginfile();
		unordered_map<int,Node*> :: iterator itr = m.begin();
		itr=m.find(n);
		if(itr!=m.end()){
		itr->second->data=ac;		
	}}
	if(found==false)
		cout<<"\n\n Account Not Found ";
}

private:
	
	void currencyconvert(){
			while(1){
	int ch,amt;double ans;
	cout<<"\n\n\t1) PKR TO DOLLAR";
	cout<<"\n\n\t2) DOLLAR TO PKR";
	cout<<"\n\n\t3) PKR TO RIYAL";
	cout<<"\n\n\t4) RIYAL TO PKR";
	cout<<"\n\n\t5) PKR TO CHINESE YUAN";
	cout<<"\n\n\t6) CHINESE YUAN TO PKR";
	cout<<"\n\n\t7) BACK TO MAIN MENU";
	cout<<"\n\n\tSelet Your Option (1-7): ";
	cin>>ch;
	system("cls");
	if(ch==1){
		title();
		cout<<"\n\n\t\tPKR TO DOLLAR";
		cout<<"\n\nEnter the amount in PKR: ";
		cin>> amt;
		ans=amt/200.0;
		cout<<"\n\n " << amt << " in PKR is equal to " << ans << " in dollar\n";	
	}
	else if(ch==2){
		title();cout<<"\n\n\t\tDOLLAR TO PKR";
		cout<<"\n\nEnter the amount in dollars: ";
		cin>> amt;
		ans=amt*200;
		cout<<"\n\n " << amt << " in dollar is equal to " << ans << " in PKR\n";	
	}
	else if(ch==3){
		title();cout<<"\n\n\t\tPKR TO RIYAL";
		cout<<"\n\nEnter the amount in PKR: ";
		cin>> amt;
		ans=amt/55.0;
		cout<<"\n\n " << amt << " in PKR is equal to " << ans << " in Riyal\n";	
	}
	else if(ch==4){
		title();cout<<"\n\n\t\tRIYAL TO PKR";
		cout<<"\n\nEnter the amount in Riyals: ";
		cin>> amt;
		ans=amt*55;
		cout<<"\n\n " << amt << " in Riyal is equal to " << ans << " in PKR\n";	
	}
	else if(ch==5){
		title();cout<<"\n\n\t\tPKR TO CHINESE YUAN";
		cout<<"\n\nEnter the amount in PKR: ";
		cin>> amt;
		ans=amt/30.0;
		cout<<"\n\n " << amt << " in PKR is equal to " << ans << " in Chinese Yuan\n";	
	}
	else if(ch==6){
		title();cout<<"\n\n\t\tCHINESE YUAN TO PKR";
		cout<<"\n\nEnter the amount in Chinese Yuans: ";
		cin>> amt;
		ans=amt*30;
		cout<<"\n\n " << amt << " in Chinese Yuans is equal to " << ans << " in PKR\n";	
	}
	else if(ch==7){
		title();cout<<"\n\n\n\n\tTHANKYOU FOR USING OUR CURRENCY CONVERING SERVICE...!";
		break;
	}
	else{
		title();cout<<"\n\nInvalid Choice.";
		cout<<"\n\n\tInput Again..!\n";
	}
	cin.ignore();
	cin.get();
	system("cls");
	title();				
}
	}

void deposit(int n,int amt)
{
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(ac));
		if(ac.retacno()==n)
		{
				ac.dep(amt);
			
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(ac));
			cout<<"\n\n\t TRANSACTION DONE SUCCESSFULLY .. ";
			found=true;
	       }
         }
	File.close();
	
		if(found==true){
		ac.writinginfile();
		unordered_map<int,Node*> :: iterator itr = m.begin();
		itr=m.find(n);
		if(itr!=m.end()){
		itr->second->data=ac;		
	}}
	if(found==false)
		cout<<"\n\n Account Not Found .. ";
}	
	
	public:
		Cashier():Employee()
		{
		}
		Cashier(string name,double salary,string password_login):Employee(name,salary,password_login)
		{
		
		}
		
		void cashier_function()
		{
		int choice;
			while(1)
			{
			
	
			cout<<"\n\n\t\tMAIN MENU\n\n";
			cout<<"\n\t1) DETAILS OF AN ACCOUNT\n";
			cout<<"\n\t2) DEPOSIT AMOUNT\n";
			cout<<"\n\t3) WITHDRAW AMOUNT\n";
			cout<<"\n\t4) CONVERT YOUR CURRENCY\n";
			cout<<"\n\t5) LOGOUT";
			cout<<"\n\n\tSelect Your Option (1-5): ";
			

			cin>>choice;
			system("cls");
			if(choice==1)
			
			{	title();int n;
				cout<<"\n\nEnter Account Number You Want to Get Details of: ";
				cin>>n;
				display(n);
			}
			else if(choice==2)
			{
				title();
			int num,dpt;
			cout<<"\n\n\tEnter The account Number: "; cin>>num;
			cout << "\nEnter the amount to be deposit: ";cin>>dpt;
			deposit(num,dpt);
			}
			else if(choice==3)
			{
				title();
			int num,with;
			cout<<"\n\n\tEnter The Account Number: "; cin>>num;
			cout << "\nEnter the amount to be withdrawn: ";cin>>with;
			withdraw(num,with,8);
			}
			else if(choice==4)
			{title();
					currencyconvert();
			}
			else if(choice==5){
				title();
				cout << "\n\n\n\n\t\tTHANKYOU FOR LOGGING AS A CASHIER..!\n";
				break;
			}
			else 
			{title();
					cout<<"\n\t\tInvalid Choice\n";
					cout<<"\n\t\tInput Again !!!\n\n";
				
			}
		cin.ignore();
		cin.get();
		system("cls");
		title();
		}

	}

};


         



class Bank
{
	

	
	void user()
	{
	system("color 06");
	int no;char p[10];
	title();
	cout << "\n\t\t\tWELCOME TO ONLINE BANKING APP\n\n";
	cout<< "\tLogin To Your Account!\n\n";
	cout << "Enter Account Number: ";
	cin >> no;
	cout << "Enter Your Password: ";

	char d;
    for(int i=0;;)
    {
        d=getch();
        if((d>='a'&&d<='z')||(d>='A'&&d<='Z')||(d>='0'&&d<='9'))

        {
            p[i]=d;
            ++i;
            cout<<"*";
        }
        if(d=='\b'&&i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(d=='\r')
        {
            p[i]='\0';
            break;
        }
    }
	account ac;
	fstream File;
char *b;int a;
	 File.open("account.dat",ios::binary|ios::in|ios::out);


	while(!File.eof())
	{
		if(no==ac.retacno()){
			
		b=ac.retpass();
		a=ac.retacno();
		break;}
File.read(reinterpret_cast<char *> (&ac), sizeof(ac));

	}
	File.close();

	int j=0,k=0;

while(b[j]!='\0'){
	j++;
}
while(p[k]!='\0'){
	k++;
}

int len=(j>k)?j:k;

	int f=0;
	for(int i=0;i<len;i++){
		if(b[i]!=p[i]){
			f=1;
			break;	
		}
	}
	
if(f==0 && a==no){
	cout << "\n\nCORRECT PASSWORD! \n\n";
	loading();
	system("cls");
	
	char ch;
	while(1)
	{
		system("cls");
		title();
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. TRANSFER AMOUNT";
		cout<<"\n\n\t02. PAY UTILITY BILLS";
		cout<<"\n\n\t03. BALANCE ENQUIRY";
		cout<<"\n\n\t04. MOBILE TOPUP";
		cout<<"\n\n\t05. EXIT";
		cout<<"\n\n\tSelect Your Option (1-5) ";
		cin>>ch;
		system("cls");
		int cc;

			if(ch=='1'){
				title();
			cout <<"\n\n\t01. TRANSFER TO JAZZCASH";
			cout << "\n\n\t02. TRANSFER TO EASYPAISA";
			cout << "\n\n\t03. TRANSFER TO ANOTHER BANK ACCOUNT";
			cout << "\n\n\t04. BACK TO MAIN MENU";
			cout << "\n\n\tSelect Your Option(1-4)";
			cin >> cc;
			if(cc==1){
				unsigned long long int jazz;int am;
				cout << "\n\nEnter jazzcash phone number: ";
				cin >> jazz;
				cout << "Enter amount: ";
				cin >> am;
				Cashier c;
				c.withdraw(a,am,1);
			}
			else if(cc==2){
				unsigned long long int easy;int am;
				cout << "\n\nEnter easypaisa phone number: ";
				cin >> easy;
				cout << "Enter amount: ";
				cin >> am;
				Cashier c;
				c.withdraw(a,am,2);				
			}
			else if(cc==3){
				long int accno;int am;
				cout << "\n\nEnter account number: ";
				cin >> accno;
				cout << "Enter amount: ";
				cin >> am;
				Cashier c;
				c.withdraw(a,am,3);			
			}
		
}
		if(ch=='2')
		{
			title();
			cout <<"\n\n\t01. PAY ELECTRICITY BILL";
			cout << "\n\n\t02. PAY GAS BILL";
			cout << "\n\n\t03. PAY WATER BILL";
			cout << "\n\n\t04. BACK TO MAIN MENU";
			cout << "\n\n\tSelect Your Option(1-3)";
			cin >> cc;
			
			if(cc==1)
			{
				unsigned long long int accno;int am;
				cout << "\nEnter bill account number: ";
				cin >> accno;
				cout <<"Enter amount: ";
				cin >> am;
				Cashier c;
				c.withdraw(a,am,4);
			}
			
			else if(cc==2)
			{		
				unsigned long long int accno;int am;
				cout << "\nEnter bill consumer ID: ";
				cin >> accno;
				cout <<"Enter amount: ";
				cin >> am;
				Cashier c;
				c.withdraw(a,am,5);
			}
			
			else if(cc==3)
			{
				unsigned long long int accno;int am;
				cout << "\nEnter bill consumer ID: ";
				cin >> accno;
				cout <<"Enter amount: ";
				cin >> am;
				Cashier c;
				c.withdraw(a,am,6);
			}						
		
}

		if(ch=='3')
		{
			Cashier c;
			title();
			c.display(a);
			
		}
				if(ch=='4')
			{
			
			char sim[10];int am;unsigned long long int pn;
			system("cls");
			title();
			cout << "\n\nEnter sim name: ";
			cin >> sim;
			cout << "Enter phone number: ";
			cin >> pn;
			cout << "Enter amount: ";
			cin >> am;
		Cashier c;
				c.withdraw(a,am,7);
			
		}
		if(ch=='5')
		{
			
			mainlogin();
			break;
		}
		else{
			
		}
		
		cin.ignore();
		cin.get();
		system("cls");
		
	}
	
	
}
else{
	cout<< "\n\nINCORRECT PASSWORD OR ACCOUNT NUMBER!\n\n";
	system("pause");
	system("cls");
	cout <<	"\n\n\n\n\n\t\tPRESS ANY KEY TO GO BACK TO MAIN MENU....";
	system("color f1");
}	
}
	
	void managerlogin(Manager &m){
		title();
	cout << "\n\n Enter Manager password: ";
    char a,p[10];int i,flag=0;
    for(i=0;;)
    {
        a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))

        {
            p[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(a=='\r')
        {
            p[i]='\0';
            break;
        }
    }
    i=0;
    string o=m.get_password_login();
   	while(o[i]!='\0')
	{
    	if(o[i]==p[i])
		{
    		flag=1;
    		i++;
		}
		else{
			flag=0;
			break;
		}
	}	
    if(flag==1)
	{
    	cout<<"\n\n\n\tCORRECT PASSWORD...!\n\n\n";
    	loading();
    	system("cls");
    	title();
    	cout << "\t\t\tWELCOME AS A MANAGER!\n";
    	m.manager_function();
	}
	else{
		cout << "\n\nWrong Password! Try Again\n";
		system("pause");
		system("cls");
		managerlogin(m);
		
	}		
	}
	
	void cashierlogin(Cashier &c)
	{
		title();
	cout << "\n\n Enter Cashier password: ";
    char a,p[10];int i,flag=0;
    for(i=0;;)
    {
        a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))

        {
            p[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(a=='\r')
        {
            p[i]='\0';
            break;
        }
    }
    i=0;
    string o=c.get_password_login();
   	while(o[i]!='\0')
	   {
    	if(o[i]==p[i])
		{
    		flag=1;
    		i++;
		}
		else{
			flag=0;
			break;
		}
	}	
    if(flag==1){
    	cout<<"\n\n\n\tCORRECT PASSWORD...!\n\n\n";
    	loading();
    	system("cls");
    	title();
    	cout << "\t\t\tWELCOME AS A CASHIER!\n";
    	c.cashier_function();
	}
	else{
		cout << "\n\nWrong Password! Try Again\n";
		system("pause");
		system("cls");
		cashierlogin(c);
		
	}		
	}	
	protected:
		string branch_name;
		string address;
		
	public:
		Bank(){
			branch_name="Empty";
			address="Empty";	
		}
		Bank(string branch_name,string address){
			this->branch_name=branch_name;
			this->address=address;
		}
		
		void mainlogin()
		{
			system("color f1");
			Cashier bankcashier("CASHIER NAME",30000,"cashier");
			Manager bankmanager("MANAGER NAME",80000,"manager"); 
			feedback f;
				
				
				while(1)
				{
				int choice;
				title();
				cout<<"\n\n\t\t1) MANAGER LOGIN";
				cout<<"\n\n\t\t2) CASHIER LOGIN ";
				cout<<"\n\n\t\t3) USER LOGIN";
				cout<<"\n\n\t\t4) FEEDBACK";
				cout<<"\n\n\t\t5) SHOW ALL FEEDBACK";
				cout<<"\n\n\t\t6) EXIT";
				cout<<"\n\t\t------------------------------------------------";
            	cout<<"\n\n\n\t\tSelect Your Option(1-6) ";
        
				fflush(stdin);
				cin>>choice;
				system("cls");
				if(choice==6)
				{
					cout<<"\n\n\n\tTHANK YOU FOR USING OUR BANK MANAGEMENT PROJECT\n\n";
					cout<<"\t\tHAVE A NICE DAY ..!\n\n";
					system("pause");
						exit(1);
				}
				else if(choice == 1)
				{
					managerlogin(bankmanager);
				}
				else if(choice == 2)
				{
					cashierlogin(bankcashier);
				}
				
				else if(choice ==3)
				{
					user();
				}
				else if(choice == 4)
				{
					f.getfeedback();
				}
				else if(choice == 5){
					f.ShowAllFeedback();
				}

				else 
				{
					cout<<"\n\tInvalid input"<<endl;
					cout<<"\tInput Again !!!"<<endl;
					getch();	
				}
		cin.ignore();
		cin.get();
		system("cls");			
		}
	}

};












class Screen
{
	private:
	string bankCode;
	string branch;
	string city;
	
	public:
		
		Screen()	
		{
			bankCode = "4540-4530-4608";
			branch = "MAIN BRANCH";
			city="KARACHI";
		}



		void display()
		{
			system("color f1");
			title();
			cout<<"\n\n\t\t\tBANK BRANCH : "<<branch;
			cout<<"\n\n\t\t\tBANK CITY : "<<city;
			cout<<"\n\n\t\t\tBANK CODE : "<<bankCode<<"\n\n";
			cout<<"\n\n\t\t PROJECT MADE BY: NAIMAT, MOHSIN AND NOHAIL";
			cout<<"\n\n\t\t--------------------------------------------\n";
			system("pause");
		}		
};




int main()
{
	Screen s;
	s.display();
	
	Bank ob;
	ob.mainlogin();
}
