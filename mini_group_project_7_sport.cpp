/* 

SECJ2013 - Data Structure & Algorithm
PROJECT

ARIF AMIRUDDIN BIN SADIRAN				A19EC0022
MUHAMMAD 'AFIF AZHAN BIN MOHD ISMAIL			A19EC0092
MUHAMMAD ISKANDAR ZULQARNAIN BIN MOHD ISHAK		A19EC0098

*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <fstream>
using namespace std;

string Month[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
string Sports[7] = {"Futsal","Badminton","Netball","Bowling","Swimming","Ping Pong","Tennis"};
const int size = 10;
time_t     rawtime;
struct tm* timeinfo;
ofstream out;
ifstream inp ;
int currentDate;

class Node
{
public:

    string name,sportType,month,ic,borrowedItem;
    int age,date,chin,chout,mon;
    Node* link; // pointer to next node
};

class EquipmentList
{
	private:
		int front, back,count;
		string items[size];
	
	public:
		EquipmentList()
		{
			front = 0;
			back  = size-1;
			count = 0;
		}
		
		
		bool isEmpty()
		{
			return(count == 0);
		}
		
		void insertEq(string newItem)
		{
			if(newItem == "")
			return;
			back = (back+1) % size;
			items[back] = newItem;
			++count;
		}
		
		string getFront()
		{
			return items[front];
		}
		
		void removeEq()
		{
			front = (front+1) % size;
			--count;
		}

};

EquipmentList Ball;
EquipmentList rentedBall;

class List
{
	private:
    	Node* head;
    	Node* borrowHead ;
    	
	public:
    	List(void) { head = NULL; 
		borrowHead = NULL;}
    	~List(void) { head = NULL; 
		borrowHead = NULL;};
    	Node* InsertNode(string, string, string, int, string, int ,int ,int);
    	Node* InsertNode(string, string, string, int, string, int ,int ,int,int);
    	Node* InsertBorrowNode(string, string, int, int, string);
    	void deleteNode(int);
    	void Find();
    	void FindName(string);
    	void FindIC(string);
    	void FindMonth(string);
    	void Sort();
    	void SortName(int);
    	void SortIC(int);
    	void SortAge(int);
    	void Delete();
    	void Insert();
    	void Rent();
    	void menu();
    	int displayBorrower();
    	int DisplayList();
    	
};

Node* List::InsertNode(string n, string m, string s, int a, string i, int d, int ci, int co)
{
	int currIndex = 0;
	Node* currNode = head;
	Node* prevNode = NULL;
	while ((currNode && n>currNode->name)&&(currNode && s>currNode->sportType)&&(currNode && m>currNode->month)&&(currNode && a>currNode->age)&&
	(currNode && i>currNode->ic)&&(currNode && d>currNode->date)&&(currNode && ci>currNode->chin)&&(currNode && co>currNode->chout))
		{
    	prevNode = currNode;
    	currNode = currNode->link;
    	currIndex++;
		}
		
	Node* newNode = new Node;
	newNode->name= n;
	newNode->sportType= s;
	newNode->month= m;
	newNode->age= a;
	newNode->ic= i;
	newNode->date= d;
	newNode->chin= ci;
	newNode->chout= co;
	
	if(currIndex==0)
	{
    newNode->link=head;
    head= newNode;
	}
	
	else {
	newNode->link= prevNode->link;
	prevNode->link= newNode;
	}
	
	return newNode;
}


Node* List::InsertNode(string n, string m, string s, int a, string i, int d, int ci, int co,int index)
{
	int currIndex = 1;
	Node* currNode = head;
	while ((currNode && index > currIndex))
		{
    	currNode = currNode->link;
    	currIndex++;
		}
	
	if(index>0 && currNode == NULL)
	return NULL;
		
	Node* newNode = new Node;
	newNode->name= n;
	newNode->sportType= s;
	newNode->month= m;
	newNode->age= a;
	newNode->ic= i;
	newNode->date= d;
	newNode->chin= ci;
	newNode->chout= co;
	
	if(index==0)
	{
    newNode->link=head;
    head = newNode;
	}
	
	else {
	newNode->link = currNode->link;
	currNode->link = newNode;
	}
	
	return newNode;
}

Node* List::InsertBorrowNode(string n, string i, int m, int d, string b)
{
	
	int currIndex = 0;
	Node* currNode = borrowHead;
	Node* prevNode = NULL;
	while ((currNode && n>currNode->name)&&(currNode && i>currNode->ic)&&(currNode && d>currNode->date))
		{
    	prevNode = currNode;
    	currNode = currNode->link;
    	currIndex++;
		}

	Node* newNode = new Node;
	newNode->name= n;
	newNode->mon= m;
	newNode->ic= i;
	newNode->date= d;

	newNode->borrowedItem = b;
	
	if(currIndex==0)
	{
    newNode->link=borrowHead;
    borrowHead= newNode;
	}
	
	else {
	newNode->link= prevNode->link;
	prevNode->link= newNode;
	}
	
	return newNode;
}

int List::DisplayList()
{
	int num = 1;
	Node* currNode = head;
	
	if(currNode)
	{	
		cout << "\nCustomers List"
			 << "\n--------------";
		cout << left << endl << setw(4) << "No" << setw(20) << "Name" << setw(6) << "Age" << setw(22) << "Identification Card" 
		 		<< setw(6) << "Date" << setw(10) << "Month" << setw(15) << "Sport Type" << setw(10) << "Check In"
		 		<< setw(6) << "Check Out" << endl;
	}
	
	else
	{
		cout << "There are no customer record in the list.";
		return 0;
	}
	
	while(currNode != NULL)
	{
		
		cout << left << " " << setw(3) << num << setw(20) << currNode->name << setw(6) << currNode->age << setw(22) << currNode->ic
			 << setw(6) << currNode->date << setw(10) << currNode->month << setw(15)<< currNode->sportType
			 << setw(10) << currNode->chin << setw(6) << currNode->chout << endl;
    	currNode = currNode->link;
   		num++;
    }
    return num;
}

int List::displayBorrower()
{
	int num = 1;
	Node* currNode = borrowHead;
	
	if(!currNode)
	{
	cout << "\nNo one has rented any equipment today yet.";
	return 0;
	}
	
	else 
	{
		cout << left << endl << setw(4) << "No" << setw(20) << "Name" << setw(22) << "Identification Card" 
		 	 << setw(6) << "Date" << setw(10) << "Month"  << setw(5) << "Rented Item"<< endl;
	}
	
	while(currNode != NULL)
	{
		
		cout << left << " " << setw(3) << num << setw(20) << currNode->name << setw(22) << currNode->ic
			 << setw(6) << currNode->date << setw(10) << Month[currNode->mon] << currNode->borrowedItem << endl;
    	currNode = currNode->link;
   		num++;
    }
    return num;
}

void List::FindName(string N) 
{
	Node* currNode = head;
	while (currNode  && currNode ->name != N) {
	currNode  = currNode ->link;
	}
	
	if (currNode)
		{
			cout << "Below is the information of " << N << ":" << endl << endl;
			cout << "Name  : " << currNode ->name << endl 
				 << "Age   : " << currNode ->age << endl
				 << "IC    : " << currNode ->ic  << endl
				 << "Sport : " << currNode ->sportType << endl
				 << "Date  : " << currNode ->date << " " <<  currNode ->month << endl
				 << "Checked in time  : " << currNode ->chin << endl
				 << "Checked out time : " << currNode ->chout << endl<<endl;
			
			
		}
	
	else
		cout << "There is no customer named " << N << " in the record." << endl << endl;
		getch();
		return;
}

void List::FindIC(string I) 
{
	Node* currNode = head;
	while (currNode && currNode->ic != I) {
	currNode = currNode->link;
	}
	
	if (currNode)
		{
			cout << "\nBelow is the information ainpthe customer with IC " << I << " :" << endl <<endl ;
			cout << "Name  : " << currNode->name << endl 
				 << "Age   : " << currNode->age << endl
				 << "IC    : " << currNode->ic  << endl
				 << "Sport : " << currNode->sportType << endl
				 << "Date  : " << currNode->date << " " <<  currNode->month << endl
				 << "Checked in time  : " << currNode->chin << endl
				 << "Checked out time : " << currNode->chout << endl<<endl;
			
		}
	
	else
		cout << "\nThere is no customer with IC " << I << " in the record.\n";
		getch();
		return;
}

void List::FindMonth(string M) 
{
	Node* currNode = head;
	int num = 0;
	while (currNode ) 
	{
	
	if (currNode->month == M)
		{
			num++;
			if (num == 1)
			{
				cout << "\nBelow is the customer(s) that used the sport centre in " << M << " :" << endl << endl;
				cout << left << setw(4) << "No" << setw(20) << "Name" << setw(6) << "Age" << setw(22) << "Identification Card" 
		 		<< setw(6) << "Date" << setw(10) << "Month" << setw(15) << "Sport Type" << setw(10) << "Check In"
		 		<< setw(6) << "Check Out" << endl;
			}
		 		
			cout << left << setw(4) << num << setw(20) << currNode->name << setw(6) << currNode->age << setw(22) << currNode->ic
			 << setw(6) << currNode->date << setw(10) << currNode->month << setw(15)<< currNode->sportType 
			 << setw(10) << currNode->chin << setw(6) << currNode->chout << endl;
		}
	currNode = currNode->link;	
	}
		if(num == 0)
		cout << "There is no customer enter the sport centre in " << M << ".";
		cout << endl << endl;
		getch();
		return ;
}

void List::Find()
{
	int ch,m;
	string tempIC,tempName,tempMonth;
    do
	{
		system("cls");
		cout << "----------------------------------------------------------\n";
		cout << "                     DATA SEARCHING\n";
		cout << "----------------------------------------------------------\n";
		
		cout << "\n\t\tChoose Your Option\n"
	         << "\t\t[1] Search by Name"
			 << "\n\t\t[2] Search by Identification Card"
			 << "\n\t\t[3] Search by Month"
			 <<"\n\t\t-\n\t\t[0]Back\n\n";
	    cout << "Option: ";
	    cin  >> ch;
	    switch(ch)
	    {
	        case 1 :
	        	cin.ignore();
				cout << "\nEnter Name: ";
				getline(cin,tempName,'\n');
				cout << endl;
	            FindName(tempName);
	            break;
	            
	        case 2:
	        	
				cout << "\nEnter Identification Card: ";
				cin  >> tempIC;
				FindIC(tempIC);
				break;
	        
	        case 3:
	        	cout << "\t\tChoose which month";
	        	cout << "\n\t\t[1] January"
	        		 << "\n\t\t[2] February"
	        		 << "\n\t\t[3] March"
	        		 << "\n\t\t[4] April"
	        		 << "\n\t\t[5] May"
	        		 << "\n\t\t[6] June"
	        		 << "\n\t\t[7] July"
	        		 << "\n\t\t[8] August"
	        		 << "\n\t\t[9] September"
	        		 << "\n\t\t[10] October"
	        		 << "\n\t\t[11] November"
	        		 << "\n\t\t[12] December"
	        		 << "\n\t\t-"
	        		 << "\n\t\t[0] Back";
				cout << "\n\nOption: ";
				cin >> m;
				
				if(m == 0)
				Find();
				
				if(m < 1 || m > 12)
				{
				cout << "Invalid option ! Please try again." << endl;
	            getch();
	            Find();
	       		}
				FindMonth(Month[m-1]);
	        	break;
	        
			case 0 :
			return;
				
	        default :
	            cout << "\nInvalid option ! Please try again." << endl;
	            getch();
	   }
    }
	while(ch!=0);
}

void List::Delete()
{
		int ch;
		system("cls");
		cout << "----------------------------------------------------------\n";
		cout << "                     DATA DELETION\n";
		cout << "----------------------------------------------------------\n";
		DisplayList();
		cout << "\nSelect which customer record you want to delete ('0' to return)\nOption : ";
		cin >> ch;
		if(ch == 0)
		menu();
		deleteNode(ch);
		cout << "\nThe list after deletion process :\n";
		DisplayList();
		cout << endl;
		_getch();
	    Delete();
}

void List::deleteNode(int a)
{
	int currIndex = 1;
	char choice;
	Node* currNode = head;
	Node* prevNode = NULL;
	
	while (currNode && currIndex != a) 
	{
	prevNode = currNode;
	currNode = currNode->link;
	currIndex++;
	}
	
	if(!currNode)
	{
		cout << "\nThere is no number '" << a << "' in the list. Please try again.\n\n";
		_getch();
		Delete();
	}
	
	cout << "\nDelete the record for " << currNode->name << " ? Option (Y/N) : ";
	cin >> choice;
	
	if(choice == 'N')
	Delete();
	
	if (currNode) {
		if (prevNode) 
			{
			prevNode->link = currNode->link;
			delete currNode;
			}
			
	else {
		head = currNode->link;
		delete currNode;
		}
		return ;
		}
	
	cout << "There is no number '" << a <<"' in the list.";
	return;
}

void List::Insert()
{
	string Iname,Imonth,Iic;
    int Iage,Idate,Ichin,Ichout,ch,Inum,IsportType;
	system("cls");
		cout << "----------------------------------------------------------\n";
		cout << "                     DATA INSERTION\n";
		cout << "----------------------------------------------------------\n";
		Inum = DisplayList();
		
		cout << "\n\n\t\tChoose Your Option\n"
	         << "\t\t[1] Insert data in the beginning of the list"
			 << "\n\t\t[2] Insert data in the middle of the list"
			 << "\n\t\t[3] Insert data in the end of the list"
			 <<"\n\t\t-\n\t\t[0]Back\n\n";
	    cout << "Option: ";
	    cin  >> ch;
	    
	    if(ch<0 || ch>3)
	    {
	    cout << "\nInvalid option! Please try again.";
	    getch();
	    Insert();
		}
		
		if(ch==0)
		menu();
	    
	    cout << "\nPlease fill the information for the new data :\n";
	    cin.ignore();
	    cout << "\nName : ";
	    getline(cin,Iname,'\n');
	    cout << "Age  : "; 
	    cin >> Iage;
	    cout << "IC   : "; 
	    cin >> Iic;
	    cout << "Sport Type  : [1] Futsal\n" 
	    	 << "              [2] Badminton\n"
	    	 << "              [3] Netball\n"
	    	 << "              [4] Bowling\n"
	    	 << "              [5] Swimming\n"
	    	 << "              [6] Ping Pong\n"
	    	 << "              [7] Tennis\n\n"
	    	 << "              Choice: ";
	    cin >> IsportType;
	    cout << "\nDate of Check In and Check Out (i.e.: 7 January) : "; 
	    cin >> Idate;
	    cin >> Imonth;
	    cout << "Check In time (24H)  : "; 
	    cin >> Ichin;
	    cout << "Check Out time (24H) : "; 
	    cin >> Ichout;
	    
	   		if(ch == 1) 
	   		{
	        	InsertNode(Iname,Imonth,Sports[IsportType-1],Iage,Iic,Idate,Ichin,Ichout);
	    	}
	        
	        if(ch == 2) 
	   		{
	        	InsertNode(Iname,Imonth,Sports[IsportType-1],Iage,Iic,Idate,Ichin,Ichout,Inum/2-1);
	    	}
	    	
	        if(ch == 3) 
	   		{
	        	InsertNode(Iname,Imonth,Sports[IsportType-1],Iage,Iic,Idate,Ichin,Ichout,Inum-1);
	    	}
	        
	    cout << "\nThe list after insertion process.\n";
		DisplayList();  
	    
		cout << "\nReturning to main menu.";
		_getch();
		return;	
}

void List::SortName(int choice)
{
if(choice==1)
{
    Node* dummy = new Node;
    Node* currNode = head;

    while (currNode != NULL)
    {
        Node* temp = currNode->link;
        Node* prevNode = dummy;
        Node* lk = dummy->link;

        while (lk != NULL)
        {

            if (lk->name > currNode->name)
            {

                break;
            }

            prevNode = lk;
            lk = lk->link;
        }
        currNode->link = lk;
        prevNode->link = currNode;
        currNode = temp;
    }
    head = dummy->link;
}
else if(choice==2)
{
    Node* dummy = new Node;
    Node* currNode = head;

    while (currNode != NULL)
    {
        Node* temp = currNode->link;
        Node* prevNode = dummy;
        Node* lk = dummy->link;

        while (lk != NULL)
        {
            if (lk->name < currNode->name)
            {
                break;
            }

            prevNode = lk;
            lk = lk->link;
        }
        currNode->link = lk;
        prevNode->link = currNode;
        currNode = temp;
    }
    head = dummy->link;
}
cout << "\nSorting process successful. Please refer to the new list below. \n";
DisplayList();
getch();
Sort();
}

void List::SortIC(int choice)
{
if(choice==1)
{
    Node* dummy = new Node;
    Node* currNode = head;

    while (currNode != NULL)
    {
        Node* temp = currNode->link;
        Node* prevNode = dummy;
        Node* lk = dummy->link;

        while (lk != NULL)
        {
            if (lk->ic > currNode->ic)
            {
                break;
            }

            prevNode = lk;
            lk = lk->link;
        }
        currNode->link = lk;
        prevNode->link = currNode;
        currNode = temp;
    }
    head = dummy->link;
}
else if(choice==2)
{
    Node* dummy = new Node;
    Node* currNode = head;

    while (currNode != NULL)
    {
        Node* temp = currNode->link;
        Node* prevNode = dummy;
        Node* lk = dummy->link;

        while (lk != NULL)
        {
            if (lk->ic < currNode->ic)
            {
                break;
            }

            prevNode = lk;
            lk = lk->link;
        }
        currNode->link = lk;
        prevNode->link = currNode;
        currNode = temp;
    }
    head = dummy->link;
}
cout << "\nSorting process successful. Please refer to the new list below. \n";
DisplayList();
_getch();
Sort();
}

void List::SortAge(int choice)
{
if(choice==1)
{
    Node* dummy = new Node;
    Node* currNode = head;

    while (currNode != NULL)
    {
        Node* temp = currNode->link;
        Node* prevNode = dummy;
        Node* lk = dummy->link;

        while (lk != NULL)
        {
            if (lk->age > currNode->age)
            {
                break;
            }

            prevNode = lk;
            lk = lk->link;
        }
        currNode->link = lk;
        prevNode->link = currNode;
        currNode = temp;
    }
    head = dummy->link;
}
else if(choice==2)
{
    Node* dummy = new Node;
    Node* currNode = head;

    while (currNode != NULL)
    {
        Node* temp = currNode->link;
        Node* prevNode = dummy;
        Node* lk = dummy->link;

        while (lk != NULL)
        {
            if (lk->age < currNode->age)
            {
                break;
            }

            prevNode = lk;
            lk = lk->link;
        }
        currNode->link = lk;
        prevNode->link = currNode;
        currNode = temp;
    }
    head = dummy->link;
}
cout << "\nSorting process successful. Please refer to the new list below. \n";
DisplayList();
_getch();
Sort();
}

void List::Rent()
{
	int ch,ch1;
	string bName,bIC,bDay,bMonth;
	
	if(currentDate != timeinfo->tm_mday)
	{
		while(!rentedBall.isEmpty())
		{
		Ball.insertEq(rentedBall.getFront());
		rentedBall.removeEq();	
		}
	}
	
	system("cls");
	cout << "----------------------------------------------------------\n";
	cout << "                 Equipment Rental - " << timeinfo->tm_mday << " " << Month[timeinfo->tm_mon];
	cout << "\n----------------------------------------------------------\n";
	cout << "\n\t\tChoose Your Option\n"
	     << "\t\t[1] Rent a futsal ball";
	     
	if(Ball.isEmpty())
	cout << " [Not Available]"; 
	
	cout << "\n\t\t[2] Rent a racket [Coming Soon]";
	cout << "\n\t\t[3] Display rental record."; 
	cout << "\n\t\t-\n\t\t[0]Back\n\n"
	     << "Option: ";
	cin  >> ch;
	
	if(ch==0)
	menu();
		
	else if(ch==1)
		{
			if(Ball.isEmpty())
			{
			cout << "\nAll futsal balls have been rented for the day. Please try again tomorrow!";
			getch();
			}
			
			else
			{
			cin.ignore();
			cout << "\nPlease enter your information below."
				 << "\n\nName : ";
			getline(cin,bName,'\n');
			
	    	cout << "IC   : "; 
	    	cin >> bIC;
	    	
	    	InsertBorrowNode(bName,bIC,timeinfo->tm_mon,timeinfo->tm_mday,Ball.getFront());
	    	
	    	cout << "\nRent request successful! Please show the ticket below to the counter to retrieve your item.\n";
	    	cout << left <<"\n\t\tX------------------------------------------------X"
	    	     << "\n\t\t|                                                |"
	    	     << "\n\t\t|\t    Name : " << setw(30) << bName << "|"
	    	     << "\n\t\t|\t    IC   : " << setw(30) << bIC   << "|"
	    	     << "\n\t\t|\t    Date : " << setw(2) << timeinfo->tm_mday << " " << setw(27) << Month[timeinfo->tm_mon] << "|"
	    	     << "\n\t\t|\t    Item : " << setw(30) << Ball.getFront() << "|"
	    	     << "\n\t\t|                                                |"
	    	     << "\n\t\t|                                                |"
	    	     << "\n\t\t|                   G7 Sports Centre Sdn. Bhd.   |"
	    	     << "\n\t\t|                                                |"
	    	     << "\n\t\tX------------------------------------------------X";
	    	
	    	rentedBall.insertEq(Ball.getFront());
	    	Ball.removeEq();	    	
	    	
	    	}
		}
	
	else if(ch==3)
	{
		displayBorrower();
		cout << endl;
	}
	
	else
	cout << "\nInvalid option. Please try again.";
	_getch();
	Rent();
}

void List::Sort()
{
	int ch,ch1;
	system("cls");
	cout << "----------------------------------------------------------\n";
	cout << "                     DATA SORTING\n";
	cout << "----------------------------------------------------------\n";
	cout << "\n\t\tChoose Your Option\n"
	     << "\t\t[1] Sort by Name"
		 << "\n\t\t[2] Sort by Identification Card"
		 << "\n\t\t[3] Sort by Age"
		 << "\n\t\t-\n\t\t[0]Back\n\n"
	     << "Option: ";
	     
	cin  >> ch;
	
	if(ch==0)
	menu();
	
	else if(ch==1)
		{
			cout << "\n\t\tChoose Your Option\n"
	         	 << "\t\t[1]Ascending Order\n\t\t[2]Descending Order\n\t\t-\n\t\t[0]Back\n\n";
	    	cout << "Option: ";
	    	cin  >> ch1;
	    	
	    	if(ch1==0)
	    	Sort();
	    	
	    	else if(ch1 == 1 || ch1 ==2)
	    	SortName(ch1);
	    	
	    	else
	    	cout << "\nInvalid option ! Returning to sorting menu.";
	    	_getch();
		}
	
	else if(ch==2)
		{
			cout << "\n\t\tChoose Your Option\n"
	         	 << "\t\t[1]Ascending Order\n\t\t[2]Descending Order\n\t\t-\n\t\t[0]Back\n\n";
	    	cout << "Option: ";
	    	cin  >> ch1;
	    	
	    	if(ch1==0)
	    	Sort();
	    	
	    	else if(ch1 == 1 || ch1 ==2)
	    	SortIC(ch1);
	    	
	    	else
	    	cout << "\nInvalid option ! Returning to sorting menu.";
	    	_getch();
		}
	
	else if(ch==3)
		{
			cout << "\n\t\tChoose Your Option\n"
	         	 << "\t\t[1]Ascending Order\n\t\t[2]Descending Order\n\t\t-\n\t\t[0]Back\n\n";
	    	cout << "Option: ";
	    	cin  >> ch1;
	    	
	    	if(ch1==0)
	    	Sort();
	    	
	    	else if(ch1 == 1 || ch1 ==2)
	    	SortAge(ch1);
	    	
	    	else
	    	cout << "\nInvalid option ! Returning to sorting menu.";
		}
		
	else
	cout << "\nInvalid option. Please try again.";
	_getch();
	Sort();
}

void List::menu()
{
int ch;
	
	do
	{
	// Get Local Time
	time( &rawtime );
	timeinfo = localtime( &rawtime );
	
	system("cls");
	cout << "----------------------------------------------------------\n";
	cout << "                 SPORTS CENTRE CUSTOMERS RECORD\n";
	cout << "----------------------------------------------------------\n";
	cout << "\n\t\tChoose Your Option\n"
         << "\t\t[1] Data Display"
         << "\n\t\t[2] Data Insertion"
		 << "\n\t\t[3] Data Sorting"
		 << "\n\t\t[4] Data Searching"
		 << "\n\t\t[5] Data Deletion"
		 << "\n\t\t[6] Daily Equipment Rental"
		 << "\n\t\t-\n\t\t[0]Exit\n\n";
    cout << "Option: ";
		cin  >> ch;
	    switch(ch)
	    {
	        case 1 :
	        	DisplayList();
	        	cout << endl;
	        	getch();
	        	break;
	        
	        case 2:
	        	Insert();
	        	break;
	        
			case 3:
				Sort();
				break;
				
	        case 4 :
	        	Find();
	        	break;
	        
	        case 5:
	        	Delete();
	        	break;
	        		
	        case 6:
	        	Rent();
	        	break;
	        	
			case 0:
				cout << endl <<  "Thank youuuuuuuu :)";
				
	            exit(0);
					
	        default:
	        	cout << "\nInvalid option! Please try again.";
	        	_getch();
	        	
		}
	
	}while(ch!=0);
	return;
}

int main()
{
List cust;
string inpName,inpIC,inpItem,usedBall;
int inpD, inpM;

string ballID[size] = {"Abidas B1","Abidas B2","Abidas B3","Abidas B4","Abidas B5","Naik B6","Naik B7","Naik B8","Naik B9","Naik B10"};
cust.InsertNode("Farhan Amir","July","Futsal",28,"921228031859",3,2100,2300);
cust.InsertNode("Saiful Badri","April","Badminton",19,"010409018733",1,800,1100);
cust.InsertNode("Nurul Ain","Mac","Netball",24,"960616148842",15,1500,1800);
cust.InsertNode("Wing Xing","September","Bowling",18,"020217081158",29,1100,1400);
cust.InsertNode("Riveena Andria","November","Swimming",32,"880715100366",18,1400,1700);
cust.InsertNode("Uzair Hakimi","December","Badminton",25,"950304011217",21,2000,2300);
cust.InsertNode("Looi Jay","February","Futsal",42,"780527023048",9,2000,2300);
cust.InsertNode("Pavithra Rajan","January","Bowling",37,"831118035172",8,1600,1900);
cust.InsertNode("Ainul Daniesya","July","Ping Pong",31,"890130148814",14,900,1100);
cust.InsertNode("Harith Hamizan","May","Tennis",20,"001015056901",16,800,1100);

for(int i=0;i<size;i++)
Ball.insertEq(ballID[i]);

time( &rawtime );
timeinfo = localtime( &rawtime );
currentDate = timeinfo->tm_mday;

cust.menu();
return 0;
}
