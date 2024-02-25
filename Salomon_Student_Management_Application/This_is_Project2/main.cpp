//Name: Salomon Bulambo Baraka
//Date:2022-07-25
//Description: Student Management Application  420-AP1-AS�PROJECT 2

#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;

// Functions Declaration
// no return
void print_welcome();
void print_main_list();
void exit();
void error_option();
void add();
void search();
void modify();
void del();
void show();


// Structure Declaration
struct person
{
	string first_name;
	string last_name;
	int age;
};

// Structure Declaration
struct address
{
	char nbe_str_name[30];
	char city_name[20];
	char Province[15];
	char po_code[7];
};

// Structure Declaration
struct student_Management
{
	int ID;
	person per; // sub struct
	address addr; // sub struct
	string phone;
	string email;
};

student_Management p[200]; // Global array size[200] Declaration - data of students
int box = 0; // Global variable - number of students


int main()
{
	// local variables - to use in switch
	int option;
	char ans;

	system("cls"); // clear screen
	print_welcome();//call function

	print_main_list(); //call function

	cout << "\nEnter your option\n";
	cout << "Type here:";
	cin >> option;

	cout << endl;

	// switch functions
	switch (option) {

	case 1: {
		do { // start looping
			add(); //call function
			cout << "\nAdd Another Student Record Press (Y, N): ";
			cin >> ans;

		} while (ans == 'Y' || ans == 'y'); // end looping
		main(); //call main() function
	}break;
	case 2: {
		search(); //call function
	}break;
	case 3: {
		modify(); //call function
	}break;
	case 4: {
		del(); //call function
	}break;
	case 5: {
		show(); //call function
	}break;
	case 6: {
		exit(); //call function
	}break;
	default: {
		error_option(); //call function
	}break;
	}//End Switch


	return 0;
}

// function Definition
void print_welcome() {
	cout << "\t\t\t\t\t     Wellcome to Project II   \n";
	cout << "\t\t\t\t\t   420 - AP1 - AS - PROJECT 2 \n";
	cout << "\t\t\t\t\t Student Management Application \n";
	cout << "\t\t\t\t\t*--*---*---*---*---*---*---*---*\n\n\n";

}

void print_main_list() {

	cout << setw(25) << "Main Menu\n\n";
	cout << "1-  Create and add a student\n\n";
	cout << "2-  Search for a student\n\n";
	cout << "3-  Modify the information of the student\n\n";
	cout << "4-  Delete the information of the student\n\n";
	cout << "5-  Display the student list\n\n";
	cout << "6-  Exit the application\n\n";

}

void exit() {

	system("cls"); // clear screen
	print_welcome(); //call function

	char ch; //local variable

	cout << "Do you want to logout...!! Enter (Y, N)" << endl;
	cin >> ch;

	cout << "\n\n\n";

	if (ch == 'Y' || ch == 'y') {
		system("cls"); // clear screen
		print_welcome(); //call function
		cout << "\n\n\n";
		cout << "\t\t\t\t\t\tThanks for using\n\n"
			<< "\t\t\t\t\t Student Management Application   ";

		// using loop to print increase '.'
		for (int i = 0; i < 1; i++) {
			ch = i;
			Sleep(700); cout << "=";
			Sleep(700); cout << "=";
			Sleep(700); cout << "=";
			Sleep(700); cout << "=";
			Sleep(700); cout << ">>";

		}// end for

		cout << "\n\n\n";

	}//end if
	else {
		main(); // call function
	}//end else

}

void error_option() {


	// show error text when user input different double
	if (!cin.good()) {
		while (!cin.good()) {
			cerr << "Value not correct...!\n";
			cout << "Return to Main Menu ";

			// using loop to print increase '.'
			for (int i = 0; i < 5; i++) {

				Sleep(700);
				cout << '.';
			}//end for
			cin.clear();
			cin.ignore(INT_MAX, '\n');

		}//end While
	}//end if
	else {
		// show error text when user input out of range of swicth case number
		cerr << "Incorrect value...!\n";
		cout << "Return to Main Menu ";
		// using loop to print increase '.'
		for (int i = 0; i < 5; i++) {

			Sleep(700);
			cout << '.';
		}//end for
	}//end else
	cout << endl;
	main(); // call function

}

void add() {
	system("cls"); // clear screen
	print_welcome(); //call function

	cout << "\tCreate and add a student\n\n";

	// using loop to input data from user
	for (int i = box; i <= box; i++) {

		cout << "Student No." << i + 1 << "\n\n";

		cout << "ID: ";
		cin >> p[i].ID;

		// show error text when user input different int
			while (!cin.good()) {
			cerr << "Incorrect value...! Please try again\n";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Enter The ID: ";
			cin >> p[i].ID;
		}//end While

		cout << "First Name: ";
		cin >> p[i].per.first_name;



		cout << "Last Name: ";
		cin >> p[i].per.last_name;


		cout << "Age: ";
		cin >> p[i].per.age;

		while (!cin.good()) {
			cerr << "Incorrect value...! Please try again\n";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Enter The Age: ";
			cin >> p[i].per.age;
		}//end While

		cin.ignore();

		cout << "Number and Street Name: ";
		cin.getline(p[i].addr.nbe_str_name, 30);
		while (!cin.good()) {
			cerr << "Incorrect value...! Please try again\n";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Enter Number and Street Name: ";
			cin.getline(p[i].addr.nbe_str_name, 30);
		}

		cout << "City Name: ";
		cin.getline(p[i].addr.city_name, 20);
		while (!cin.good()) {
			cerr << "Incorrect value...! Please try again\n";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Enter The City Name: ";
			cin.getline(p[i].addr.city_name, 20);
		}


		cout << "Province/State: ";
		cin.getline(p[i].addr.Province, 15);
		while (!cin.good()) {
			cerr << "Incorrect value...! Please try again\n";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Enter Province/State: ";
			cin.getline(p[i].addr.Province, 15);
		}

		cout << "Postal Code: ";
		cin.getline(p[i].addr.po_code, 7);
		while (!cin.good()) {
			cerr << "Incorrect value...! Please try again\n";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Enter Postal Code: ";
			cin.getline(p[i].addr.po_code, 7);
		}

		cout << "Phone number : ";
		cin >> p[i].phone;

		cout << "Email Address: ";
		cin >> p[i].email;

	}

	// insert data to box variable
	box++;


}//End function

void search() {

	system("cls");// clear screen
	print_welcome();//call function
m: // Lable
	cout << "\tSearch for a student\n\n";

	// to check if box is not empty
	if (box != 0) {

		//local variables
		int id;
		char ans;

			system("cls");// clear screen
			print_welcome();//call function

			cout << "\tSearch for a student\n\n";
			cout << "Enter The ID: ";
			cin >> id;

			// using loop to serach and display data
			for (int i = 0; i < box; i++) {
				if (p[i].ID == id) {
					cout << "ID: " << p[i].ID << endl;
					cout << "First Name: " << p[i].per.first_name << endl;
					cout << "Last Name: " << p[i].per.last_name << endl;
					cout << "Age: " << p[i].per.age << endl;
					cout << "Address: " << p[i].addr.nbe_str_name << ", " << p[i].addr.city_name << ", "
						                << p[i].addr.Province << "  " << p[i].addr.po_code << endl;
					cout << "Phone No.: " << p[i].phone << endl;
					cout << "Email Address: " << p[i].email << endl;

					cout << "\nSerach Another Student Press (Y, N): ";
					cin >> ans;

					if (ans == 'Y' || ans == 'y') {
						goto m;
					}//end if
					else {
						main(); // call function
					}//end else
					break;
				}//End if
				// show error text when user input ID not available in storage unit
				else if (i == box - 1) {
					cout << "No record found" << endl;
					cout << "\nReturn to Main Menu ";
					// using loop to print increase '.'
					for (int i = 0; i < 5; i++) {

						Sleep(700);
						cout << '.';
					}//end for
					main(); // call function
				}//end else if

			}

			cout << endl;

	}//end if
	else {
		// show error text when the system has no data
		cout << "No data is entered" << endl;
		cout << "\nReturn to Main Menu ";
		// using loop to print increase '.'
		for (int i = 0; i < 5; i++) {

			Sleep(700);
			cout << '.';
		}//end for
		cout << endl;
		main(); //call function
	}// end else

}// end function

void modify() {

	system("cls"); // clear screen
	print_welcome(); //call function

	// to check if box is not empty
	if (box != 0) {

	d: // lable
		system("cls");// clear screen
		print_welcome(); //call function

		//local variables
		int id, ch;
		char ans;

		cout << "\tModify the information of the student\n\n";
		// Modify list
		cout << "1-  Modify First Name\n\n";
		cout << "2-  Modify Last Name\n\n";
		cout << "3-  Modify Address\n\n";
		cout << "4-  Modify Phone No.\n\n";
		cout << "5-  Modify Email Address\n\n";
		cout << "6-  Return to Main Menu\n\n";

		cout << "\nEnter your option\n";
		cout << "Type here:"; cin >> ch;

		cout << endl;

		system("cls"); // clear screen
		print_welcome(); //call function

		cout << "\tModify the information of the student\n\n";

		switch (ch) {

		case 1: {
			cout << "Enter Student ID to be Modify: ";
			cin >> id;
			// using loop to return data which we need to modify
			for (int i = 0; i < box; i++) {
				if (p[i].ID == id) {
					cout << "First Name: " << p[i].per.first_name << "\n\n";

					cout << "New First Name: ";
					cin >> p[i].per.first_name;
					cout << endl;
					cout << "Modified successfully...! " << endl;

					cout << "\nModify Another Student Press (Y, N): ";
					cin >> ans;
					if (ans == 'Y' || ans == 'y') {
						goto d;
					}//end if
					else {
						main();
					}//end else
					break;
				}//End if
				else if (i == box - 1) {
					cout << "No record found" << endl;
					cout << "\nReturn to Menu ";
					for (int i = 0; i < 5; i++) {

						Sleep(700);
						cout << '.';
					}//end for
					goto d;
				}//end else if
			}//end for
		}break;

		case 2: {
			cout << "Enter student ID to be Modify: ";
			cin >> id;
			for (int i = 0; i < box; i++) {
				if (p[i].ID == id) {
					cout << "Last Name: " << p[i].per.last_name << "\n\n";

					cout << "New Last Name: ";
					cin >> p[i].per.last_name;
					cout << endl;
					cout << "Modified successfully...! " << endl;

					cout << "\nModify Another Student Press (Y, N): ";
					cin >> ans;
					if (ans == 'Y' || ans == 'y') {
						goto d;
					}//end if
					else {
						main(); //call function
					}//end else
					break;
				}//End if
				else if (i == box - 1) {
					cout << "No record found" << endl;
					cout << "\nReturn to Menu ";
					for (int i = 0; i < 5; i++) {

						Sleep(700);
						cout << '.';
					}//end for
					goto d;
				}//end else if
			}//end for

		}break;

		case 3: {
			cout << "Enter student ID to be Modify: ";
			cin >> id;
			for (int i = 0; i < box; i++) {
				if (p[i].ID == id) {
					cout << "The Address: \n\n";
					cout << "Number and street name: " << p[i].addr.nbe_str_name << endl;
					cout << "City name: " << p[i].addr.city_name << endl;
					cout << "Province/State: " << p[i].addr.Province << endl;
					cout << "Postal code: " << p[i].addr.po_code << "\n\n";

					cout << "New Number and street name: ";
					cin.getline(p[i].addr.nbe_str_name, 30);
					while (!cin.good()) {
						cerr << "Incorrect value...! Please try again\n";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cout << "Enter Number and Street Name: ";
						cin.getline(p[i].addr.nbe_str_name, 30);
					}//end while
					cout << "\nNew City name: ";
					cin.getline(p[i].addr.city_name, 20);
					while (!cin.good()) {
						cerr << "Incorrect value...! Please try again\n";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cout << "Enter The City Name: ";
						cin.getline(p[i].addr.city_name, 20);
					}//end while
					cout << "\nNew Province/State: ";
					cin.getline(p[i].addr.Province, 15);
					while (!cin.good()) {
						cerr << "Incorrect value...! Please try again\n";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cout << "Enter Province/State: ";
						cin.getline(p[i].addr.Province, 15);
					}//end while
					cout << "\nNew Postal code: ";
					cin.getline(p[i].addr.po_code, 7);
					while (!cin.good()) {
						cerr << "Incorrect value...! Please try again\n";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cout << "Enter Postal Code: ";
						cin.getline(p[i].addr.po_code, 7);
					}//end while

					cout << endl;
					cout << "Modified successfully...! " << endl;

					cout << "\nModify Another Student Press (Y, N): ";
					cin >> ans;
					if (ans == 'Y' || ans == 'y') {
						goto d;
					}//end if
					else {
						main();
					}//end else
					break;;
				}
				else if (i == box - 1) {
					cout << "No record found" << endl;
					cout << "\nReturn to Menu ";
					for (int i = 0; i < 5; i++) {

						Sleep(700);
						cout << '.';
					}//end for
					goto d;
				}//end else if
			}//end for

		}break;

		case 4: {
			cout << "Enter student ID to be Modify: ";
			cin >> id;
			for (int i = 0; i < box; i++) {
				if (p[i].ID == id) {
					cout << "Phone No.: " << p[i].phone << endl;

					cout << "New Phone No.: ";
					cin >> p[i].phone;
					cout << endl;
					cout << "Modified successfully...! " << endl;

					cout << "\nModify Another Student Press (Y, N): ";
					cin >> ans;
					if (ans == 'Y' || ans == 'y') {
						goto d;
					}//end if
					else {
						main(); //call function
					}//end else
					break;
				}//end if
				else if (i == box - 1) {
					cout << "No record found" << endl;
					cout << "\nReturn to Menu ";
					for (int i = 0; i < 5; i++) {

						Sleep(700);
						cout << '.';
					}//end for
					goto d;
				}//end else if
			}//end for


		}break;

		case 5: {
			cout << "Enter student ID to be Modify: ";
			cin >> id;
			for (int i = 0; i < box; i++) {
				if (p[i].ID == id) {
					cout << "Email Address: " << p[i].email << endl;

					cout << "New Email Address: ";
					cin >> p[i].email;
					cout << endl;
					cout << "Modified successfully...! " << endl;

					cout << "\nModify Another Student Press (Y, N): ";
					cin >> ans;
					if (ans == 'Y' || ans == 'y') {
						goto d;
					}//end if
					else {
						main();
					}//end else
					break;
				}
				else if (i == box - 1) {
					cout << "No record found" << endl;
					cout << "\nReturn to Menu ";
					for (int i = 0; i < 5; i++) {

						Sleep(700);
						cout << '.';
					}//end for
					goto d;
				}//end else if
			}//end for


		}break;

		case 6: {
			main(); // call function
		}break;

		default: {
			if (!cin.good()) {
				while (!cin.good()) {
					cerr << "Incorrect value...!\n";
					cout << "Return to Menu ";
					for (int i = 0; i < 5; i++) {

						Sleep(700);
						cout << '.';
					}//end for
					cin.clear();
					cin.ignore(INT_MAX, '\n');

				}//end while
			}//end if
			else {
				cerr << "Incorrect value...!\n";
				cout << "Return to Menu ";
				for (int i = 0; i < 5; i++) {

					Sleep(700);
					cout << '.';
				}//end for
			}//end else
			cout << endl;
			goto d; // got to lable
			break;
		}break;
		}//end switch


	}//End if
	else {
		cout << "No data is entered" << endl;
		cout << "\nReturn to Main Menu ";
		for (int i = 0; i < 5; i++) {

			Sleep(700);
			cout << '.';
		}//end for
		cout << endl;
		main(); //call function
	}//end else


}//end function

void del() {

	system("cls"); // clear screen
	print_welcome(); //call function

	// to check if box is not empty
	if (box != 0)
	{
	two: // lable
		system("cls");
		print_welcome();

		//local variables
		int ch, id;
		char ans;

		cout << "\tDelete the information of the student\n\n";

		// Delete Menu
		cout << "1-  Delete Specific Student\n\n";
		cout << "2-  Delete All Students\n\n";
		cout << "3-  Return to Main Menu\n\n";


		cout << "\nEnter your option\n";
		cout << "Type here:";
		cin >> ch;
		cout << endl;

		system("cls");
		print_welcome();

		cout << "\tDelete the information of the student\n\n";

		switch (ch) {

		case 1: {

			cout << "Enter student ID to be delete: ";
			cin >> id;

			// using loop to get student data to be delete
			for (int i = 0; i < box; i++) {

				if (p[i].ID == id) {
					p[i].ID = p[i + 1].ID;
					p[i].per.first_name = p[i + 1].per.first_name;
					p[i].per.last_name = p[i + 1].per.last_name;
					p[i].per.age = p[i + 1].per.age;
					p[i].addr.nbe_str_name == p[i + 1].addr.nbe_str_name;
					p[i].addr.city_name == p[i + 1].addr.city_name;
					p[i].addr.po_code == p[i + 1].addr.po_code;
					p[i].addr.Province == p[i + 1].addr.Province;
					p[i].phone = p[i + 1].phone;
					p[i].email = p[i + 1].email;

					cout << "\nDo you want to delete student No." << id << "?  Press (Y, N):  ";
					cin >> ans;

					if (ans == 'Y' || ans == 'y') {
						box--;
						cout << endl;
						cout << "Deleted successfully...! " << endl;

						cout << "\nDelete Another Student Record Press (Y, N): ";
						cin >> ans;
						if (ans == 'Y' || ans == 'y') {
							goto two;
						}//End if
						else {
							main();
						}//End else
						break;
					}//End if
					else {
						goto two; // go to lable
					}//End else

				}//End if
				else if (i == box - 1) {
					cout << "No record found" << endl;
					cout << "\nReturn to Menu ";
					for (int i = 0; i < 5; i++) {
						Sleep(700);
						cout << '.';
					}//end for

					goto two;

				}//end else if

			}//End for

		}break; //End case-1

		case 2: {

			cout << "\nDo you want to delete all Students?  Press (Y, N):  ";
			cin >> ans;

			if (ans == 'Y' || ans == 'y') {

				box = 0;
				cout << endl;
				cout << "Deleted successfully...! " << "\n\n";
				cout << "\nReturn to Menu ";
				for (int i = 0; i < 5; i++) {
					Sleep(700);
					cout << '.';
				}//end for
				goto two;
			} //End if
			else {

				goto two;

			} //End else

		}break; //End case-2

		case 3: {
			main(); //call function
		}break; //End case-3


		default: {

			if (!cin.good()) {

				while (!cin.good()) {

					cerr << "Incorrect value...!\n";
					cout << "Return to Menu ";
					for (int i = 0; i < 5; i++) {

						Sleep(700);
						cout << '.';

					} //End for

					cin.clear();
					cin.ignore(INT_MAX, '\n');

				} //End while

			} //End if
			else {

				cerr << "Incorrect value...!\n";
				cout << "Return to Menu ";
				for (int i = 0; i < 5; i++) {

					Sleep(700);
					cout << '.';

				} //End for


			} //End else

			cout << endl;
			goto two;
		}break; //End default

		}//End Switch

	}//End if
	else
	{
		cout << "No data is entered" << endl;
		cout << "\nReturn to Main Menu ";
		for (int i = 0; i < 5; i++) {

			Sleep(700);
			cout << '.';
		}//End for
		cout << endl;
		main();
	}//End else-1


}//end function

void show() {

	system("cls"); // clear screen
	print_welcome(); //call function

	cout << "\tGeneral List of students\n\n";

	// to check if box is not empty
	if (box != 0) {

		//local variables
		int temp = 0;
		string ty;
		char ans;

		//use looping to do sort function by ID in ascending order
		for (int i = 0; i < box; i++) {
			for (int j = 0; j < box; j++) {
				if (p[i].ID < p[j].ID) {

					temp = p[i].ID;
					p[i].ID = p[j].ID;
					p[j].ID = temp;

					ty = p[i].per.first_name;
					p[i].per.first_name = p[j].per.first_name;
					p[j].per.first_name = ty;

					ty = p[i].per.last_name;
					p[i].per.last_name = p[j].per.last_name;
					p[j].per.last_name = ty;

					temp = p[i].per.age;
					p[i].per.age = p[j].per.age;
					p[j].per.age = temp;

					ty == p[i].addr.nbe_str_name;
					p[i].addr.nbe_str_name == p[j].addr.nbe_str_name;
					p[j].addr.nbe_str_name == ty;

					ty == p[i].addr.city_name;
					p[i].addr.city_name == p[j].addr.city_name;
					p[j].addr.city_name == ty;

					ty == p[i].addr.Province;
					p[i].addr.Province == p[j].addr.Province;
					p[j].addr.Province == ty;

					ty == p[i].addr.po_code;
					p[i].addr.po_code == p[j].addr.po_code;
					p[j].addr.po_code == ty;

					ty = p[i].phone;
					p[i].phone = p[j].phone;
					p[j].phone = ty;

					ty = p[i].email;
					p[i].email = p[j].email;
					p[j].email = ty;


				}//End if i-j

			}//End for j

		}//End for i

		// use looping to get display list of student
		for (int i = 0; i < box; i++) {

			cout << endl;
			cout << "Data of student No." << i + 1 << endl;

			cout << "Student ID: " << p[i].ID << endl;

			cout << "Student First Name: " << p[i].per.first_name << endl;

			cout << "Student Last Name: " << p[i].per.last_name << endl;

			cout << "Student Age: " << p[i].per.age << endl;

			cout << "Student Address: " << p[i].addr.nbe_str_name << ", " << p[i].addr.city_name << ", "
				<< p[i].addr.Province << "  " << p[i].addr.po_code << endl;
			cout << "Student Phone No.: " << p[i].phone << endl;

			cout << "Student Email Address: " << p[i].email << endl;



		}// end for
		cout << "\nReturn to Main Menu Press (Y): ";
		cin >> ans;

		while (true){

			if (ans == 'Y' || ans == 'y') {

				main();
			}//End for
			else {
				main();
			}//End else
			break;
		}//End while

	}
	else {
		cout << "No data is entered" << endl;
		cout << "\nReturn to Main Menu ";
		for (int i = 0; i < 5; i++) {

			Sleep(700);
			cout << '.';
		}//End for
		cout << endl;
		main();
	}//End else

}// Done or ENd function
