/* 

SECJ2013 - Data Structure & Algorithm
ASSIGNMENT 1 - Sorting & Searching on Array 

ARIF AMIRUDDIN BIN SADIRAN					A19EC0022
MUHAMMAD 'AFIF AZHAN BIN MOHD ISMAIL			A19EC0092
MUHAMMAD ISKANDAR ZULQARNAIN BIN MOHD ISHAK		A19EC0098

*/

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <algorithm>
using namespace std;
int SIZE=10;

class Sport
{
	private:
        string name,sportType,month,chin,chout,ic;
		int age,date;

	public:
		Sport() {}
		Sport(string n,int a,string i,int d,string m,string s,string in,string out)
		{
        	name=n;
        	sportType=s;
        	month=m;
			age=a;
			ic=i;
			date=d;
			chin=in;
			chout=out;
		}
		string getName();
		void sortData(Sport[]);
	        void sortName(Sport[]);
	        void sortIC(Sport[]);
	        void sortAge(Sport[]);
		void searchData(Sport[]);
			void searchName(Sport[]);
			void searchIC(Sport []);
		void displayData();
		void option(Sport[]);
};

Sport y;
Sport tempValue;

int case_insensitive_match(string a1, string a2) // This function is used to compare customers' name and searched name in lowercase
{
   transform(a1.begin(), a1.end(), a1.begin(), ::tolower);
   transform(a2.begin(), a2.end(), a2.begin(), ::tolower);
   if(strstr(a1.c_str(),a2.c_str()))
      return 1; 
   return 0; 
}

string Sport::getName()
{
	return name;
}

void Sport::displayData()
{
        cout << left << setw(20) << name << setw(6) << age << setw(30) << ic
			 << setw(6) << date << setw(10) << month << setw(15)<< sportType
			 << setw(6) << chin << setw(6) << chout << endl;
			 
		return;
}

void Sport::sortData(Sport s1[])
{
    Sport y;
    int ch;
    do
	{
		cout << "\n\t\tChoose Your Option\n"
        	 << "\t\t[1]Sort by Name\n\t\t[2]Sort by Identification Card\n\t\t[3]Sort by Age\n\t\t-\n\t\t[0]Back\n\n";
    	cout << "Option: ";
    	cin  >> ch;
    	
    	switch(ch)
    	{
        	case 1 :
        		y.sortName(s1);
       	    	break;
       	    
      	  	case 2 :
            	y.sortIC(s1);
           		break;
           		
        	case 3 :
            	y.sortAge(s1);
            	break;
            	
        	case 0 :
        	{
         		option(s1);
         		break;
        	}
        	
        	default :
            	cout<<"Invalid Option !"<<endl;
   		}
    }
	while(ch!=0);

}

void Sport::sortName(Sport s2[])
{
	Sport tempValue;
    int ch;
    do
	{
		cout << "\n\t\tChoose Your Option\n"
        	 << "\t\t[1]Ascending Order\n\t\t[2]Descending Order\n\t\t-\n\t\t[0]Back\n\n";
    	cout << "Option: ";
    	cin  >> ch;
    	
   		switch(ch)
    	{
        	case 1 :
        	{
        		int pass;
		        bool sorted = false;
		        int CI[SIZE]={0};
		        
		        for( pass =1;(pass < SIZE)&& !sorted; pass++ )
		        {
			        int	compare =0,swap =0;
			        sorted = true;
			        for (int x = 0; x < SIZE-pass; x++)
		        	{
            			if(s2[x].name>s2[x+1].name)
            			{
			                tempValue.name=s2[x].name;
			                tempValue.sportType=s2[x].sportType;
			                tempValue.month=s2[x].month;
			                tempValue.age=s2[x].age;
			                tempValue.ic=s2[x].ic;
			                tempValue.date=s2[x].date;
			                tempValue.chin=s2[x].chin;
			                tempValue.chout=s2[x].chout;
			
			                s2[x].name=s2[x+1].name;
			                s2[x].sportType= s2[x+1].sportType;
			                s2[x].month= s2[x+1].month;
			                s2[x].age=s2[x+1].age;
			                s2[x].ic=s2[x+1].ic;
			                s2[x].date=s2[x+1].date;
			                s2[x].chin=s2[x+1].chin;
			                s2[x].chout=s2[x+1].chout;
			
			                s2[x+1].name=tempValue.name;
			                s2[x+1].sportType=tempValue.sportType;
			                s2[x+1].month=tempValue.month;
			                s2[x+1].age=tempValue.age;
			                s2[x+1].ic=tempValue.ic;
			                s2[x+1].date=tempValue.date;
			                s2[x+1].chin=tempValue.chin;
			                s2[x+1].chout=tempValue.chout;
			                sorted = false;
            			}
            		}
            	}
        	}
        	cout << endl;
        	cout << left << setw(20) << "Name" << setw(6) << "Age" << setw(30) << "Identification Card" 
		 		<< setw(6) << "Date" << setw(10) << "Month" << setw(15) << "Sport Type" << setw(6) << "Check In"
		 		<< setw(6) << "Check Out" << endl;
		 		
        	for(int i=0;i<SIZE;i++)
	        s2[i].displayData();
	        cout << endl;
	        system("pause");
        	option(s2);

        	case 2 :
        	{
        		int pass;
		        bool sorted = false;
		        int CI[SIZE]={0};
		        
		        for( pass =1;(pass < SIZE)&& !sorted; pass++ )
		        {
			        int	compare =0,swap =0;
			        sorted = true;
			        for (int x = 0; x < SIZE-pass; x++)
		        	{
            			if(s2[x].name<s2[x+1].name)
            			{
			                tempValue.name=s2[x].name;
			                tempValue.sportType=s2[x].sportType;
			                tempValue.month=s2[x].month;
			                tempValue.age=s2[x].age;
			                tempValue.ic=s2[x].ic;
			                tempValue.date=s2[x].date;
			                tempValue.chin=s2[x].chin;
			                tempValue.chout=s2[x].chout;
			
			                s2[x].name=s2[x+1].name;
			                s2[x].sportType= s2[x+1].sportType;
			                s2[x].month= s2[x+1].month;
			                s2[x].age=s2[x+1].age;
			                s2[x].ic=s2[x+1].ic;
			                s2[x].date=s2[x+1].date;
			                s2[x].chin=s2[x+1].chin;
			                s2[x].chout=s2[x+1].chout;
			
			                s2[x+1].name=tempValue.name;
			                s2[x+1].sportType=tempValue.sportType;
			                s2[x+1].month=tempValue.month;
			                s2[x+1].age=tempValue.age;
			                s2[x+1].ic=tempValue.ic;
			                s2[x+1].date=tempValue.date;
			                s2[x+1].chin=tempValue.chin;
			                s2[x+1].chout=tempValue.chout;
			                sorted = false;
            			}
            		}
            	}
        	}
        	cout << endl;
        	cout << left << setw(20) << "Name" << setw(6) << "Age" << setw(30) << "Identification Card" 
		 		<< setw(6) << "Date" << setw(10) << "Month" << setw(15) << "Sport Type" << setw(6) << "Check In"
		 		<< setw(6) << "Check Out" << endl;
		 		
        	for(int i=0;i<SIZE;i++)
	        s2[i].displayData();
	        cout << endl;
	        system("pause");
	        cout << endl;
        	option(s2);
        	
        	case 0 :
        	{
         		y.sortData(s2);
         		break;
        	}

        	default :
            	cout << "Invalid Option !" << endl;
   		}
    }
	while(ch!=0);
    option(s2);
}

void Sport::sortIC(Sport s2[])
{
    Sport y;
    Sport tempValue;
    int ch;
    do
	{
		cout << "\n\t\tChoose Your Option\n"
        	 << "\t\t[1]Ascending Order\n\t\t[2]Descending Order\n\t\t-\n\t\t[0]Back\n\n";
    	cout << "Option: ";
    	cin  >> ch;
    	
    	switch(ch)
    	{
        	case 1 :
        	{
        		int pass;
        		bool sorted = false;
        		
        		for (pass =1;(pass < SIZE)&& !sorted; pass++)
        		{
        			int	compare =0,swap =0;
        			sorted = true;
        			
       				for (int x = 0; x < SIZE-pass; x++)
        			{
        				if( s2[x].ic>s2[x+1].ic )
            			{
		            		tempValue.name=s2[x].name;
		                	tempValue.sportType=s2[x].sportType;
		                	tempValue.month=s2[x].month;
		                	tempValue.age=s2[x].age;
			                tempValue.ic=s2[x].ic;
			                tempValue.date=s2[x].date;
			                tempValue.chin=s2[x].chin;
			                tempValue.chout=s2[x].chout;
			
			                s2[x].name=s2[x+1].name;
			                s2[x].sportType= s2[x+1].sportType;
			                s2[x].month= s2[x+1].month;
			                s2[x].age=s2[x+1].age;
			                s2[x].ic=s2[x+1].ic;
			                s2[x].date=s2[x+1].date;
			                s2[x].chin=s2[x+1].chin;
			                s2[x].chout=s2[x+1].chout;
			
			                s2[x+1].name=tempValue.name;
			                s2[x+1].sportType=tempValue.sportType;
			                s2[x+1].month=tempValue.month;
			                s2[x+1].age=tempValue.age;
			                s2[x+1].ic=tempValue.ic;
			                s2[x+1].date=tempValue.date;
			                s2[x+1].chin=tempValue.chin;
			                s2[x+1].chout=tempValue.chout;
			                sorted = false;
            			}
            		}
            	}
            	cout << endl;
            	cout << left << setw(20) << "Name" << setw(6) << "Age" << setw(30) << "Identification Card" 
		 		<< setw(6) << "Date" << setw(10) << "Month" << setw(15) << "Sport Type" << setw(6) << "Check In"
		 		<< setw(6) << "Check Out" << endl;
		 		
        		for(int i=0;i<SIZE;i++)
	            s2[i].displayData();
        	}
        	cout << endl;
        	system("pause");
        	option(s2);
        
			case 2 :
        	{
				int pass;
        		bool sorted = false;
        		
        		for(pass =1;(pass < SIZE)&& !sorted; pass++)
        		{
        			int	compare =0,swap =0;
        			sorted = true;
       				
        			for (int x = 0; x < SIZE-pass; x++)
        			{
            			if ( s2[x].ic<s2[x+1].ic )
            			{
	                		tempValue.name=s2[x].name;
	                		tempValue.sportType=s2[x].sportType;
	                		tempValue.month=s2[x].month;
			                tempValue.age=s2[x].age;
			                tempValue.ic=s2[x].ic;
			                tempValue.date=s2[x].date;
			                tempValue.chin=s2[x].chin;
			                tempValue.chout=s2[x].chout;
			
			                s2[x].name=s2[x+1].name;
			                s2[x].sportType= s2[x+1].sportType;
			                s2[x].month= s2[x+1].month;
			                s2[x].age=s2[x+1].age;
			                s2[x].ic=s2[x+1].ic;
			                s2[x].date=s2[x+1].date;
			                s2[x].chin=s2[x+1].chin;
			                s2[x].chout=s2[x+1].chout;
			
			                s2[x+1].name=tempValue.name;
			                s2[x+1].sportType=tempValue.sportType;
			                s2[x+1].month=tempValue.month;
			                s2[x+1].age=tempValue.age;
			                s2[x+1].ic=tempValue.ic;
			                s2[x+1].date=tempValue.date;
			                s2[x+1].chin=tempValue.chin;
			                s2[x+1].chout=tempValue.chout;
			                sorted = false;
            			}
            		}
            	}
            	cout << endl;
            	cout << left << setw(20) << "Name" << setw(6) << "Age" << setw(30) << "Identification Card" 
		 		<< setw(6) << "Date" << setw(10) << "Month" << setw(15) << "Sport Type" << setw(6) << "Check In"
		 		<< setw(6) << "Check Out" << endl;
		 		
        		for(int i=0;i<SIZE;i++)
	            s2[i].displayData();
        	}
        	cout << endl;
        	system("pause");
        	option(s2);
        	
        	case 0 :
        		y.sortData(s2);
        		break;
        
			default :
            	cout << "Invalid Option !" << endl;
   		}	
    }
	while(ch!=0);
    option(s2);
}

void Sport::sortAge(Sport s2[])
{
    int ch;
    do
	{
		cout << "\n\t\tChoose Your Option\n"
	         << "\t\t[1]Ascending Order\n\t\t[2]Descending Order\n\t\t-\n\t\t[0]Back\n\n";
	    cout << "Option: ";
	    cin  >> ch;
	    switch(ch)
	    {
	        case 1 :
		        {
		        	int pass;
	        		bool sorted = false;
	        		
	        		for(pass =1;(pass < SIZE)&& !sorted; pass++)
	        		{
	        			int	compare =0,swap =0;
	        			sorted = true;
	       				
	        			for (int x = 0; x < SIZE-pass; x++)
	        			{
	            			if ( s2[x].age>s2[x+1].age )
	            			{
		                		tempValue.name=s2[x].name;
		                		tempValue.sportType=s2[x].sportType;
		                		tempValue.month=s2[x].month;
				                tempValue.age=s2[x].age;
				                tempValue.ic=s2[x].ic;
				                tempValue.date=s2[x].date;
				                tempValue.chin=s2[x].chin;
				                tempValue.chout=s2[x].chout;
				
				                s2[x].name=s2[x+1].name;
				                s2[x].sportType= s2[x+1].sportType;
				                s2[x].month= s2[x+1].month;
				                s2[x].age=s2[x+1].age;
				                s2[x].ic=s2[x+1].ic;
				                s2[x].date=s2[x+1].date;
				                s2[x].chin=s2[x+1].chin;
				                s2[x].chout=s2[x+1].chout;
				
				                s2[x+1].name=tempValue.name;
				                s2[x+1].sportType=tempValue.sportType;
				                s2[x+1].month=tempValue.month;
				                s2[x+1].age=tempValue.age;
				                s2[x+1].ic=tempValue.ic;
				                s2[x+1].date=tempValue.date;
				                s2[x+1].chin=tempValue.chin;
				                s2[x+1].chout=tempValue.chout;
				                sorted = false;
	            			}
	            		}
	            	}	
		        }
		        cout << endl;
		        cout << left << setw(20) << "Name" << setw(6) << "Age" << setw(30) << "Identification Card" 
		 		<< setw(6) << "Date" << setw(10) << "Month" << setw(15) << "Sport Type" << setw(6) << "Check In"
		 		<< setw(6) << "Check Out" << endl;
		 		
		        for(int i=0;i<SIZE;i++)
	            s2[i].displayData();
	            cout << endl;
	            system("pause");
		        option(s2);
	
	        case 2 :
		        {
		        	int pass;
	        		bool sorted = false;
	        		
	        		for(pass =1;(pass < SIZE)&& !sorted; pass++)
	        		{
	        			int	compare =0,swap =0;
	        			sorted = true;
	       				
	        			for (int x = 0; x < SIZE-pass; x++)
	        			{
	            			if ( s2[x].age<s2[x+1].age )
	            			{
		                		tempValue.name=s2[x].name;
		                		tempValue.sportType=s2[x].sportType;
		                		tempValue.month=s2[x].month;
				                tempValue.age=s2[x].age;
				                tempValue.ic=s2[x].ic;
				                tempValue.date=s2[x].date;
				                tempValue.chin=s2[x].chin;
				                tempValue.chout=s2[x].chout;
				
				                s2[x].name=s2[x+1].name;
				                s2[x].sportType= s2[x+1].sportType;
				                s2[x].month= s2[x+1].month;
				                s2[x].age=s2[x+1].age;
				                s2[x].ic=s2[x+1].ic;
				                s2[x].date=s2[x+1].date;
				                s2[x].chin=s2[x+1].chin;
				                s2[x].chout=s2[x+1].chout;
				
				                s2[x+1].name=tempValue.name;
				                s2[x+1].sportType=tempValue.sportType;
				                s2[x+1].month=tempValue.month;
				                s2[x+1].age=tempValue.age;
				                s2[x+1].ic=tempValue.ic;
				                s2[x+1].date=tempValue.date;
				                s2[x+1].chin=tempValue.chin;
				                s2[x+1].chout=tempValue.chout;
				                sorted = false;
	            			}
	            		}
	            	}
				}
				cout << endl;
				cout << left << setw(20) << "Name" << setw(6) << "Age" << setw(30) << "Identification Card" 
		 		<< setw(6) << "Date" << setw(10) << "Month" << setw(15) << "Sport Type" << setw(6) << "Check In"
		 		<< setw(6) << "Check Out" << endl;
		 		
		        for(int i=0;i<SIZE;i++)
	            s2[i].displayData();
	            cout << endl;
	            system("pause");
		        option(s2);
		        
	        case 0 :
	            y.sortData(s2);
	            
	        default :
	            cout << "Invalid Option !" << endl;
   		}
    }
	while(ch!=0);
    option(s2);
}

void Sport::searchData(Sport s1[])
{
	int ch;
    do
	{
		cout << "\n\t\tChoose Your Option\n"
	         << "\t\t[1]Search by Name\n\t\t[2]Search by Identification Card\n\t\t-\n\t\t[0]Back\n\n";
	    cout << "Option: ";
	    cin  >> ch;
	    switch(ch)
	    {
	        case 1 :
	            y.searchName(s1);
	            break;
	            
	        case 2 :
	            y.searchIC(s1);
	            break;
	            
	        case 0 :
	            option(s1);
	         	break;
	         	
	        default :
	            cout << "Invalid Option !" << endl;
	   }
    }
	while(ch!=0);
}

void Sport::searchName(Sport s1[])
{
	string tempName;
	int count = 0;
	cin.ignore();
	
	cout << "Enter Name: ";
	getline(cin,tempName,'\n');
	cout << endl;
	
	for(int x=0; x<SIZE; x++)
	{
		if(strstr(s1[x].name.c_str(),tempName.c_str()) || case_insensitive_match(s1[x].getName(), tempName))
		{
			count++;
			if(count==1)
			{
			cout << left << setw(20) << "Name" << setw(6) << "Age" << setw(30) << "Identification Card" 
		 		 << setw(6) << "Date" << setw(10) << "Month" << setw(15) << "Sport Type" << setw(6) << "Check In"
			     << setw(6) << "Check Out" << endl;
			}
			
			s1[x].displayData();
		}
		
	}
	
	if(count != 0)
	cout << endl << count << " customer(s) contain(s) '" << tempName << "' in their name.\n\n";
	
	else
	cout << "No customer has '" << tempName << "' in their name.\n\n";
	system("pause");
	option(s1);
}

void Sport::searchIC(Sport s1[])
{
	string tempIC;
	cout << "Enter Identification Card: ";
	cin  >> tempIC;
	cout << endl;
		
	for(int x=0; x<SIZE; x++)
	{
		if(s1[x].ic==tempIC)
		{
			cout << left << setw(20) << "Name" << setw(6) << "Age" << setw(30) << "Identification Card" << setw(6)
				 << "Date" << setw(10) << "Month" << setw(15) << "Sport Type" << setw(6) << "Check In" << setw(6) << "Check Out" << endl;
	        
			s1[x].displayData(); 
		}
	}
	cout << endl;
	system("pause");
	option(s1);
}

void Sport::option(Sport s1[])
{
	int ch;
	
	do
	{
	system("cls");
	cout << "----------------------------------------------------------\n";
	cout << "                 SPORTS CENTRE CUSTOMERS RECORD\n";
	cout << "----------------------------------------------------------\n";
	cout << "\n\t\tChoose Your Option\n"
         << "\t\t[1]Data Display\n\t\t[2]Data Sorting\n\t\t[3]Data Searching\n\t\t-\n\t\t[0]Exit\n\n";
    cout << "Option: ";

		cin  >> ch;
	    switch(ch)
	    {
	        case 1 :
	        	cout << endl;
				cout << left << setw(20) << "Name" << setw(6) << "Age" << setw(30) << "Identification Card" 
		 		<< setw(6) << "Date" << setw(10) << "Month" << setw(15) << "Sport Type" << setw(6) << "Check In"
		 		<< setw(6) << "Check Out" << endl;
		 		
		 		for(int i=0;i<SIZE;i++)
	            s1[i].displayData();
	
	            cout << endl;
	            system("pause");
	            option(s1);
	            
	        case 2 :
	        	system("cls");
	        	cout << "----------------------------------------------------------\n";
				cout << "                     DATA SORTING\n";
				cout << "----------------------------------------------------------\n";
	            y.sortData(s1);
	            break;
	            
	        case 3 :
	        	system("cls");
	        	cout << "----------------------------------------------------------\n";
				cout << "                     DATA SEARCHING\n";
				cout << "----------------------------------------------------------\n";
	            y.searchData(s1);
	            break;
	            
	        case 0 :
	        	cout << endl <<  "Thank youuuuuuuu :)";
	            exit(0);
	
	        default :
	            cout << "Invalid Option !" << endl;
	    }
	}
	while(ch!=0);
}

int main()
{
	Sport s1[SIZE];
	s1[0]=Sport("Farhan Amir",28,"921228031859",3,"July","Futsal","2100","2300");
	s1[1]=Sport("Saiful Badri",19,"010409018733",1,"April","Badminton","0800","1100");
	s1[2]=Sport("Nurul Ain",24,"960616148842",15,"Mac","Netball","1500","1800");
	s1[3]=Sport("Wing Xing",18,"020217081158",29,"September","Bowling","1100","1400");
	s1[4]=Sport("Riveena Andria",32,"880715100366",18,"November","Swimming","1400","1700");
	s1[5]=Sport("Uzair Hakimi",25,"950304011217",21,"December","Badminton","2000","2300");
	s1[6]=Sport("Looi Jay",42,"780527023048",9,"February","Futsal","2000","2300");
	s1[7]=Sport("Pavithra Rajan",37,"831118035172",8,"January","Bowling","1600","1900");
	s1[8]=Sport("Ainul Daniesya",31,"890130148814",14,"Ogos","Ping Pong","0900","1100");
	s1[9]=Sport("Harith Hamizan",20,"001015056901",16,"May","Tennis","0800","1100");
	
    y.option(s1);

	return 0;
}
