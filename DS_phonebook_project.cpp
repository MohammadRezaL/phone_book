
//hello
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Phone {
    string name;
    string phone_no;
    string email;
    string age;
    string friends;
};

char selection_menu();
// Print selecltion menu to screen and read user selection

void edit(string str,Phone pb[], int nRec);
//edit phone book

void delete_phonebook(string str, Phone pb[], int nRec);
//delete person

void f_phonebook(Phone pb[], int nRec);
//get a part an find everyone start by it

void print(Phone pb[], int nRec);
// Print phonebook records

void connectivity(Phone pb[], int nRec);
//connecting with friend

void sort_phonebook(Phone pb[], int nRec);
// Sort the phonebook records stored in the array parameter

void And_Or_phonebook(Phone pb[], int nRec);
//find some one

int search_phonebook(string str, Phone pb[], int nRec);
// Search the recrods of the phonebook by partial match of the name and return the number of records found

int add(Phone pb[], int nRec);
// Add a new record to the phonebook and return the new size

string upper_case(string str);
// Return a string with all letters in upper case

void grow_phonebook(Phone * &pb, int &pb_size, int n);
// Grow the phonebook by increasing the size of the array by n

int main()
{
	int phonebook_size = 3;
    Phone * phonebook = new Phone[phonebook_size];
				
   	int num_records = 0, count;
	string str;
	char a;
	
	Phone cop[num_records];
	Phone * c = new Phone[phonebook_size];
	char choice = selection_menu();
	while (choice != '0')
	{
		switch (choice)
		{
			case '1':
				c = phonebook;
				cout << "Please enter a name: ";
				cin >> str;
				cout << endl;
				edit(str, phonebook, num_records);
				break;
			
			case '2':
				c = phonebook;
				print(phonebook, num_records);
				break;
				
			case '3':
				c = phonebook;
				sort_phonebook(phonebook, num_records);
				print(phonebook, num_records);
				break;
				
			case '4':
				c = phonebook;
				cout << "Please enter a name: ";
				cin >> str;
				cout << endl;
				count = search_phonebook(str, phonebook, num_records);
				cout << count << " record(s) found." << endl << endl;
				break;
					
			case '5':
				c = phonebook;
				f_phonebook(phonebook,num_records);
				break;
				
			case '6':
				c = phonebook;
				if (num_records >= phonebook_size)
					grow_phonebook(phonebook, phonebook_size, 3);

				if (num_records < phonebook_size)
					num_records = add(phonebook, num_records);
				cout << "There are now " << num_records <<
						" record(s) in the phonebook." << endl << endl;
				break;
				
			case '7':
				c = phonebook;
				cout << "Please enter a name: ";
				cin >> str;
				cout << endl;
				delete_phonebook(str, phonebook, num_records);
				break;
				
			case '8':
				c = phonebook;
				connectivity(phonebook, num_records);
				break;
				
			case '9':
				And_Or_phonebook(phonebook, num_records);
				break;
			
			case '<'://baraye in bakhsh do ta rah dashtam yeki copy kardan data ghabl taghir ya estefade as stack
				char x;
				cout<<"your previous phonebook is : "<<endl;
				print(c,num_records);
				cout<<"replace it ?"<<endl;
				cin>>x;
				if(x == 'y')
				{
					cout<<"in bakhsh dar dast tamir ast ostad :) !!! "<<endl;
				}
				break;
				
			case '>':
				cout<<"in ham hamin tor :) !!! "<<endl;
				break;
				
			default:
				cout << "Invalid input!" << endl;
		}
		choice = selection_menu();
	}

	cout << "thank you for choosing us !!!" << endl << endl;

	delete [] phonebook;	

	return 0;
}

char selection_menu()
{
	char choice;
	cout << "********************************" << endl;
	cout << "*            Welcome           *" << endl;
	cout << "********************************" << endl;
	cout << "1. Edit." << endl;
	cout << "2. Print all records." << endl;
	cout << "3. Sort the records by ascending order of the name." << endl;
	cout << "4. Search the records by partial match of the name." << endl;
	cout << "5. Find a person." << endl;
	cout << "6. Add a new record." << endl;
	cout << "7. Delete." << endl;
	cout << "8. Connectivity." << endl;
	cout << "9. And , Or." << endl;
	cout << "<. Undo." << endl;
	cout << ">. Redo." << endl;
	cout << "0. Quit. " << endl;
	cout << "Please enter your choice: ";
	cin>>choice;
	cout<< endl;
	return choice;
}

void edit(string str,Phone pb[], int nRec)
{
	string n_name,n_phone,n_email,n_age;
	int i ,j;
	char edit;
	cout<<"what part do you want to change ? (name = 1 , phone = 2 , email = 3 , age = 4"<<endl;
	cin>>edit;
	
	for (i = 0; i < nRec; i++)
	{
		if(pb[i].name == str){
			j = i;
			break;
		}
	}
        switch(edit)
        	{
        		case '1':
        			cout<<"enter new name for this contact : "<<endl;
        			cin>>n_name;
        			pb[j].name = n_name;
        		break;
        		
        		case '2':
        			cout<<"enter new phone number for this contact : "<<endl;
        			cin>>n_phone;
        			pb[j].phone_no = n_phone;
        		break;
        		
        		case '3':
        			cout<<"enter new email adress for this contact : "<<endl;
        			cin>>n_email;
        			pb[j].email = n_email;
        		break;
        		
        		case'4':
        			cout<<"enter new age for this contact : "<<endl;
        			cin>>n_age;
        			pb[j].age = n_age;
        		break;
        		
        		default:
        			cout<<"Error"<<endl;
        
			}
}

void print(Phone pb[], int nRec)
{
    int i;
    for (i = 0; i < nRec; i++)
    {
    	std::string name;
    	name = pb[i].name;
		if(name.empty())
		{
			continue;
		}else
		{
        cout << "Name:\t" << pb[i].name << endl;
        cout << "Phone#:\t" << pb[i].phone_no << endl;
        cout << "Email:\t" << pb[i].email <<endl;
        cout << "Age:\t" << pb[i].age <<endl;
        cout << "friend:\t" << pb[i].friends <<endl;
    	}
    }
}

void sort_phonebook(Phone pb[], int nRec)
{
    int i, j ,idx;
    string min;
    // selection sort
    for (i = 0; i < nRec - 1; i++)
    {
        min = pb[i].name;
        idx = i;
        
        for (j = i + 1; j < nRec; j++)
        {
            if (pb[j].name < min)
            {
                min = pb[j].name;
                idx = j;
            }
        }
        
        if (idx != i)
        {
            Phone temp;
            // swap pb[i] & pb[idx]
            temp    = pb[i];
            pb[i]   = pb[idx];
            pb[idx] = temp;           
        }
    }
}

void delete_phonebook(string str, Phone pb[], int nRec)//find person and remove it
{
	
	int i, count = 0;
	for (i = 0; i < nRec; i++)
	{
		string name = pb[i].name;
		for(int j=i; j<(nRec); j++)
		{
            pb[j] = pb[j+1];
        }
        cout<<"delete was succesfull . "<<endl;
        nRec--;	
	}
}

void f_phonebook(Phone pb[], int nRec)
{
	char str,a;
	cout<<"waht do you know about him or her (name : 1 ,phone : 2 ,email : 3, age : 4) : "<<endl;
	cin>>a;
	cout<<"what is that ? "<<endl;
	cin>>str;
	cout<<endl;
	int i;
	switch(a)
	{
		case'1':
			for (i = 0; i < nRec; i++)
		{
			string name = pb[i].name;
			if(name[0] == str)
			{
			cout<<"we find it for you!!! "<<endl;
			cout << "Name:\t" << pb[i].name << endl;
        	cout << "Phone#:\t" << pb[i].phone_no <<endl;
        	cout << "Email:\t" << pb[i].email <<endl;
        	cout << "Age:\t" << pb[i].age <<endl;
        	}
		}
		break;
		case'2':
			for (i = 0; i < nRec; i++)
		{
			string phone = pb[i].phone_no;
			if(phone[0] == str)
			{
				cout<<"we find it for you!!! "<<endl;
				cout << "Name:\t" << pb[i].name << endl;
        		cout << "Phone#:\t" << pb[i].phone_no <<endl;
        		cout << "Email:\t" << pb[i].email <<endl;
        		cout << "Age:\t" << pb[i].age <<endl;
			}
		}
		break;
		case'3':
			for (i = 0; i < nRec; i++)
		{
			string email = pb[i].email;
			if(email[0] == str)
			{
				cout<<"we find it for you!!! "<<endl;
				cout << "Name:\t" << pb[i].name << endl;
        		cout << "Phone#:\t" << pb[i].phone_no <<endl;
        		cout << "Email:\t" << pb[i].email <<endl;
        		cout << "Age:\t" << pb[i].age <<endl;
			}
		}
		break;
		case'4':
			for (i = 0; i < nRec; i++)
		{
			string age = pb[i].age;
			if(age[0] == str)
			{
				cout<<"we find it for you!!! "<<endl;
				cout << "Name:\t" << pb[i].name << endl;
        		cout << "Phone#:\t" << pb[i].phone_no <<endl;
        		cout << "Email:\t" << pb[i].email <<endl;
        		cout << "Age:\t" << pb[i].age <<endl;
			}
		}
		break;
		default:
        	cout<<"not exist! "<<endl;
	}
}


void And_Or_phonebook(Phone pb[], int nRec)//and , or function is similary 
{
	char a,q;
	string str;
	do
	{
	cout<<"waht do you know about him or her (name : 1 ,phone : 2 ,email : 3, age : 4) : "<<endl;
	cin>>a;
	cout<<"what is that ? "<<endl;
	cin>>str;
	cout<<endl;
	int i;
	switch(a)
	{
		case'1':
			for (i = 0; i < nRec; i++)
		{
			string name = pb[i].name;
			if(upper_case(name).find(upper_case(str)) != string::npos)
			{
			cout<<"we find it for you!!! "<<endl;
			cout << "Name:\t" << pb[i].name << endl;
        	cout << "Phone#:\t" << pb[i].phone_no <<endl;
        	cout << "Email:\t" << pb[i].email <<endl;
        	cout << "Age:\t" << pb[i].age <<endl;
        	}
		}
		break;
		case'2':
			for (i = 0; i < nRec; i++)
		{
			string phone = pb[i].phone_no;
			if(upper_case(phone).find(upper_case(str)) != string::npos)
			{
				cout<<"we find it for you!!! "<<endl;
				cout << "Name:\t" << pb[i].name << endl;
        		cout << "Phone#:\t" << pb[i].phone_no <<endl;
        		cout << "Email:\t" << pb[i].email <<endl;
        		cout << "Age:\t" << pb[i].age <<endl;
			}
		}
		break;
		case'3':
			for (i = 0; i < nRec; i++)
		{
			string email = pb[i].email;
			if(upper_case(email).find(upper_case(str)) != string::npos)
			{
				cout<<"we find it for you!!! "<<endl;
				cout << "Name:\t" << pb[i].name << endl;
        		cout << "Phone#:\t" << pb[i].phone_no <<endl;
        		cout << "Email:\t" << pb[i].email <<endl;
        		cout << "Age:\t" << pb[i].age <<endl;
			}
		}
		break;
		case'4':
			for (i = 0; i < nRec; i++)
		{
			string age = pb[i].age;
			if(upper_case(age).find(upper_case(str)) != string::npos)
			{
				cout<<"we find it for you!!! "<<endl;
				cout << "Name:\t" << pb[i].name << endl;
        		cout << "Phone#:\t" << pb[i].phone_no <<endl;
        		cout << "Email:\t" << pb[i].email <<endl;
        		cout << "Age:\t" << pb[i].age <<endl;
			}
		}
		break;
		default:
        	cout<<"not exist! "<<endl;
	}
	cout<<"do you have more information(y/n) ? "<<endl;
	cin>>q;
	cout<<endl;
	}while(q == 'y');
}

int search_phonebook(string str, Phone pb[], int nRec)
{
	int i, count = 0;
	for (i = 0; i < nRec; i++)
	{
		//get name
		string name = pb[i].name;
		// search the name for any occurrence of str
		// both the name and str are converted into upper case to
		// make the search case insensitive
		if (upper_case(name).find(upper_case(str)) != string::npos)
		{
			// output the record to the screen
			cout << "Name:\t" << pb[i].name << endl;
        	cout << "Phone#:\t" << pb[i].phone_no <<endl;
        	cout << "Email:\t" << pb[i].email <<endl;
        	cout << "Age:\t" << pb[i].age <<endl;
        	count++;
		}
	}
	return count;
}

void connectivity(Phone pb[], int nRec)//if person x and y have same friend they can have connection 
{
	int p1,p2;
	string per1,per2;
	cout<<"enter name of person 1 : "<<endl;
	cin>>per1;
	cout<<"enter name of person 2 : "<<endl;
	cin>>per2;
	for (int i = 0; i < nRec; i++)
	{
		string name = pb[i].name;
		if (upper_case(name).find(upper_case(per1)) != string::npos)
		{
			p1 = i;
		}
	}
	for (int i = 0; i < nRec; i++)
	{
		string name = pb[i].name;
		if (upper_case(name).find(upper_case(per2)) != string::npos)
		{
			p2 = i;
		}
	}
	string f1 = pb[p1].friends;
	string f2 = pb[p2].friends;
	if(upper_case(f1).find(upper_case(f2)) != string::npos)
	{
		cout<<"they can connection "<<endl;
	}
	else
	{
		cout<<"they can't connection "<<endl;
	}
}


int add(Phone pb[], int nRec)
{
	char ans;
	string str;
	
	getline(cin, str); // flush the keyboard buffer
	cout << "Please enter a name: ";
	getline(cin, pb[nRec].name);
	cout << "Please enter a phone number: ";
	getline(cin, pb[nRec].phone_no);
	cout << "Please enter email: ";
	getline(cin, pb[nRec].email);
	cout << "Please enter age: ";
	getline(cin, pb[nRec].age);
	cout << "Please enter a name for (her/his) friend : ";
	getline(cin, pb[nRec].friends);
	cout << endl;
	cout << "Name:\t" << pb[nRec].name << endl;
    cout << "Phone#:\t" << pb[nRec].phone_no << endl;
    cout << "Email:\t" << pb[nRec].email << endl;
    cout << "Age:\t" << pb[nRec].age << endl;
    cout << "friend:\t" << pb[nRec].friends << endl;
    cout << "Add to phonebook (y/n)? ";
	cin >> ans;
	if (ans == 'y')
	{
		cout << "1 record added." << endl;
		nRec++;
	}
		
	return nRec;
}

string upper_case(string str)
{
	int i, n = str.length();
	for (i = 0; i < n; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')//by asci table code
			str[i] = str[i] - 'a' + 'A';
	}
	
	return str;
}

void grow_phonebook(Phone * &pb, int &pb_size, int n)
{
	// Step 1:
	// create a new dynamic array with a new size = max_size + n
	Phone * temppb = new Phone[pb_size + n];
	
	// Step 2:
	// copy all the records from the original array to the new dynamic array
	for(int i = 0; i< pb_size; i++){
		temppb[i] = pb[i];
	}
	// Step 3:
	// destroy the old dynamic array to free up the memory allocated to it
	delete [] pb;

	// assign the pointer to the new dynamic array to the pointer variable
	pb = temppb;

	// Step 4:
	// update the size of the array
	pb_size = pb_size + n;

	cout << "--->phonebook size enlarged to hold a maximum of " << pb_size << " records." << endl;
	return;
}