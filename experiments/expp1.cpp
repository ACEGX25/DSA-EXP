//Name :- Sarthak Pagar
//Roll No. :- 49
//Class :- SE(IT)
//Batch :- S2
//Problem Statement :- Consider a student database of SEIT class (at least 15 records). Database contains different fields of every student like Roll No, Name and SGPA.(array of structure) a) Design a roll call list, arrange list of students according to roll numbers in ascending order (Use Bubble Sort)b) Arrange list of students alphabetically. (Use Insertion sort) c) Arrange list of students to find out first ten toppers from a class. (Use Quick sort) d) Search students according to SGPA. If more than one student having same SGPA, then print list of all students having same SGPA.Search a particular student according to name using binary search without recursion.

#include <cstring>
#include <iostream>
using namespace std;

struct student
{
    char student_name[20];
    float SGPA;
    int Roll_no;
};
int n;
class student_data
{
    private :
          struct student s1[15];        
     public :
         void viewdata()
        {
            cout<<"\n\n   Student Name        SGPA        Roll No.\n-----------------------------------------------------\n";
            for (int i = 0; i < n; i++)
            {
                cout<<"    "<<i+1<<". "<<s1 [i].student_name ;
                cout<<"\t\t";
                cout<<s1[i].SGPA ;
                cout<<"\t\t";
                cout<<s1[i].Roll_no<<endl;
            }
        }

        void add()
        {       cout<<"\n Enter no. of Student details to be added (max 15) : ";
                cin>>n;
 		cout<<"\n Filling data such as Name,    SGPA,    Roll no.\n ------------------------------------------------------";
                for ( int i =0; i <n; i++)
                {
                    cout<<"\n\n# Details of Student no. "<<i+1<<" - \n\n  Enter Name of Student : ";
                    cin>>s1[i].student_name;
                    cout<<"\n  Enter Student SGPA : ";
                    cin>>s1[i].SGPA;
                    cout<<"\n  Enter Student Roll no. : ";
                    cin>>s1[i].Roll_no;
                }
                cout<<"---------------- Addition Done Successfully ! ----------------";
                student_data :: viewdata();
        }
        void search_sgpa(float r)  //linear search on SGPA
        {
            cout<<"\n\n< Searching in SGPA using Linear Search...>\n-----------------------------------------------";
            int t = 0;
            for (int i = 0; i < n; i++)
            {
                if(s1[i].SGPA == r)
                {
                    cout<<"\n\n#"<<t<<" Details of Student with SGPA "<<s1[i].SGPA;
                    cout<<"\n\n Student     Name           SGPA           Roll_No.\n";  			  		 			    cout<<"    "<<i+1<<".       "<<s1[i].student_name;
                    cout<<"    \t   "<<s1[i].SGPA<<"   \t    "<<s1[i].Roll_no;
                    cout<<"\n--------------------------------------------------------------";
                    t++;
                    continue;
                }
            }
            if(t == 0)
            {
                cout<<"\n Student '"<<r<<"' not found or Input correct SGPA";
            }
        }

       
        void sort_names()  //insertion sort for sorting names
        {
            for (int k=n-1; k>0; k--)
            {  
                struct student temp = s1[k];
                int j = k-1;
                while (j >= 0 && strcmp(temp.student_name, s1[j].student_name) < 0)  
                {
                    s1[j+1] = s1[j];
                    j = j-1;
                }
                s1[j+1] = temp;
            }
        }

   void sort_SGPA(int l, int k)  //sorting SGPA using quick sorting
        {
            int r = k-1;
            if (l>=r) return;
            int i=l;
            int j=r+1;
            struct student prec;
            int p = s1[l].SGPA; //Select pivot element
            prec = s1[l]; //temporarily storing pivot record prec
            while(1)
            {
                do{ i++; } while (s1[i].SGPA < p  && i <= r);
                do{ j--; } while (s1[j].SGPA > p && j >= l);
                if(i >= j) break;
                struct student temp;
                temp = s1[j];
                s1[j] = s1[i];
                s1[i] = temp;
            }
            s1[l] = s1[j];
            s1[j] = prec;
            sort_SGPA(l,j-1); //left list
            sort_SGPA(j+1,r); //right list          
        }
              
 void sort_RollNo()  //sorting roll no. in ascending order using bubble sort
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n-1; j++)
                {
                    if((s1[j].Roll_no) < (s1[j+1].Roll_no)) //Swapping
                    {
                        struct student temp;
                        temp = s1[j];
                        s1[j] = s1[j+1];
                        s1[j+1] = temp;
                    }
                }
            }
            student_data :: viewdata();
        }

  void search_name()
        {
            cout<<"\n Enter student name to be searched : ";
            char search[10];
            cin>>search;
            cout<<"\n< Searching name using Binary Search...>";
            int lower = 0, upper, mid;
            upper = n - 1;
            mid = (lower + upper)/2;
            student_data :: sort_names();
            while (lower <= upper)
            {
                if(strcmp(s1[mid].student_name, search)<0)
                {
                    lower = mid + 1;
                }
                else if(strcmp(s1[mid].student_name, search)==0)
                {
                    cout<<"\n\n# Details of Student with name "<<s1[mid].student_name<<" -";
                    cout<<"\n\n Student        Name         SGPA        Roll\n    No.                                           No.\n--------------------------------------------------------------\n";
                    cout<<"    1.        "<<s1[mid].student_name;
                    cout<<"   \t  "<<s1[mid].SGPA<<"   \t  "<<s1[mid].Roll_no;
                    cout<<"\n--------------------------------------------------------------";
                    break;
                }
                else
                {
                    upper = mid - 1;
                    mid = (lower + upper)/2;
                }
            }
            if(lower > upper)
            {
                cout<<"\n Student '"<<search<<"' details not found or Input correct name";
            }
        }
};


int main()
{
    student_data std;
    float r;
    cout<<"--------------------------------------------------------------------\n\t\t----- SE IT Student Database -----\n--------------------------------------------------------------------\n";
    char stopApp;
    stopApp = 'Y';
    while(stopApp == 'Y')
    {
        cout<<"\n\nSelect action from following : \n";
        cout<<"\n1.ADD RECORDS\t2.SEARCH SGPA\t3.SORT NAME \t4.SORT SGPA(Toppers)\t5.SORT ROLL NO.\t 6. SEARCH NAME\t7. EXIT\n";
        cout<<"Enter choice (1/2/3/4/5/6/7): ";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
                std.add();
                break;
            case 2:
                cout<<"\n Enter Student SGPA to be searched : ";
                cin>>r;
                std.search_sgpa(r);
                break;
            case 3:
                cout<<"\n< Sorting name alphabetically using Insertion Sort...>";
                std.sort_names();
                std.viewdata();
                break;
            case 4:
                cout<<"\n< Sorting top 10 SGPA using Quick Sort...>";
                std.sort_SGPA(0, 10);
                std.viewdata();
                break;
            case 5:
                cout<<"\n< Sorting Roll No. wise using Bubble Sort...>";
                std.sort_RollNo();
                break;
            case 6:
                std.search_name();
                break;
            case 7:
                cout<<" >Exited successful<\n --| END OF CODE |--";
                return 0;
            default :
                cout<<"\n Invalid choice !";
        }
        cout<<"\n\nDo you want to continue (Y/N) ? : ";
        cin>>stopApp;
        if (stopApp == 'N' | 'n')
        {
            cout<<" ----------------| END OF CODE |----------------\n";
        }
    }
    return 0;
}

/*Output
--------------------------------------------------------------------
		----- SE IT Student Database -----
--------------------------------------------------------------------


Select action from following : 

1.ADD RECORDS	2.SEARCH SGPA	3.SORT NAME 	4.SORT SGPA(Toppers)	5.SORT ROLL NO.	 6. SEARCH NAME	7. EXIT
Enter choice (1/2/3/4/5/6/7): 1

 Enter no. of Student details to be added (max 15) : 5

 Filling data such as Name,    SGPA,    Roll no.
 ------------------------------------------------------

# Details of Student no. 1 - 

  Enter Name of Student : Sarthak

  Enter Student SGPA : 8.99

  Enter Student Roll no. : 49


# Details of Student no. 2 - 

  Enter Name of Student : Dimple

  Enter Student SGPA : 7.00

  Enter Student Roll no. : 48


# Details of Student no. 3 - 

  Enter Name of Student : Aditya

  Enter Student SGPA : 8.45

  Enter Student Roll no. : 52


# Details of Student no. 4 - 

  Enter Name of Student : Ashutosh

  Enter Student SGPA : 7.69

  Enter Student Roll no. : 71


# Details of Student no. 5 - 

  Enter Name of Student : Geetesh

  Enter Student SGPA : 8.89

  Enter Student Roll no. : 36
---------------- Addition Done Successfully ! ----------------

   Student Name        SGPA        Roll No.
-----------------------------------------------------
    1. Sarthak		8.99		49
    2. Dimple		7		48
    3. Aditya		8.45		52
    4. Ashutosh		7.69		71
    5. Geetesh		8.89		36


Do you want to continue (Y/N) ? : Y
 ----------------| END OF CODE |----------------


Select action from following : 

1.ADD RECORDS	2.SEARCH SGPA	3.SORT NAME 	4.SORT SGPA(Toppers)	5.SORT ROLL NO.	 6. SEARCH NAME	7. EXIT
Enter choice (1/2/3/4/5/6/7): 2

 Enter Student SGPA to be searched : 7


< Searching in SGPA using Linear Search...>
-----------------------------------------------

#0 Details of Student with SGPA 7

 Student     Name           SGPA           Roll_No.
    2.       Dimple    	   7   	    48
--------------------------------------------------------------

Do you want to continue (Y/N) ? : Y
 ----------------| END OF CODE |----------------


Select action from following : 

1.ADD RECORDS	2.SEARCH SGPA	3.SORT NAME 	4.SORT SGPA(Toppers)	5.SORT ROLL NO.	 6. SEARCH NAME	7. EXIT
Enter choice (1/2/3/4/5/6/7): 5

< Sorting Roll No. wise using Bubble Sort...>

   Student Name        SGPA        Roll No.
-----------------------------------------------------
    1. Ashutosh		7.69		71
    2. Aditya		8.45		52
    3. Sarthak		8.99		49
    4. Dimple		7		48
    5. Geetesh		8.89		36


Do you want to continue (Y/N) ? : Y
 ----------------| END OF CODE |----------------


Select action from following : 

1.ADD RECORDS	2.SEARCH SGPA	3.SORT NAME 	4.SORT SGPA(Toppers)	5.SORT ROLL NO.	 6. SEARCH NAME	7. EXIT
Enter choice (1/2/3/4/5/6/7): 7
 >Exited successful< 
*/
