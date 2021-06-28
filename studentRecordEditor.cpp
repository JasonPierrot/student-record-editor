// WEEK 2 ASSIGNMENT (EVERY TIME I TRIED TO MAKE HEADER/LIBRARY FILES IT THE ERRORS WERE UNFIXABLE AND WOULDNT LET ME PROGRESS SO I HAD TO PUT ALL IN ONE FILE.)
//

//#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

struct Student{

    string name,name2;

    string dept,dept2;

    string program;

    int marks[6];

    }students[10];

struct Student read();
void  print (Student);
void insert (int&);
void output ();
struct Student update (Student);

int freepos,p;
string selecting;
char num;

int main() {

	cout << "\n\tWelcome to the Student Record Editor!" << endl; // INTRO TO MULTIPLE CHOICE OPTION
	
	do{ // START OF DO WHILE LOOP TO CONTROL SWITCH STATEMENT AND FUNCTIONS

	cout << "\n\tPlease choose from the following options = " << endl;
	cout << "\t1. Insert a student into the database." << endl;
	cout << "\t2. Edit a student's details in the database." << endl;
	cout << "\t3. Output student details." << endl;
	cout << "\t4. Terminate editor." << endl;
	cout << "\n\tPlease enter here = "; cin >> num; cout << endl; // USER INPUTS CHOICE HERE FOR SELECTION
	
	switch (num){
	case '1': cout << "\n\tNow preparing to insert student details..." << endl;
			cout << "\n\tNumber of students currently in the database (max - 10) = " << freepos << endl;	
			insert(freepos); // CASE 1 LOADS A READ/INSERT FUNTION TO WRITE A STUDENT TO POSITION IN ARRAY
			break;
	case '2': cout << "\n\tNow preparing to insert student details..." << endl;
			cout << "\n\tPlease choose which student to update (1-10) = "; cin >> p;
			students[p-1] = update(students[p-1]); // CASE 2 LETS THE USER OVERWRITE CERTAIN OR ALL DETAILS IN ONE POSITION IN THE ARRAY
			break;
	case '3': cout << "\n\tNow preparing to output student details..." << endl;
			output(); // CASE 3 OUTPUTS THE CONTENT OF THE ARRAY/STRUCT SO FAR AND LETS THE USER CHOOSE IF THEY WANT ONE OR ALL
			break;
	case '4': cout << "\tNow terminating editor..." << endl; // CASE 4 ENDS THE PROGRAM
			break;
	default: cout << "\t\nIncorrect input. Try again.\n" << endl; // DEFAULT RESETS THE LOOP SO USER HAS TO CHOOSE AGAIN IF THEY ENTER ANY SYMBOL OUTSIDE OF 1-4
			break;
	}
	
	}while(num != '4'); // THE DO WHILE LOOP RUNS UNTIL THE USER INPUTS 4 INTO THE CIN

	cout << "\n\tThank you for using this service!" << endl << endl; // END MESSAGE FOR USER BEFORE EXITING THE TERMINAL WINDOW

    return 0;

}

struct Student read (){ // THIS FUNTION READS USER INPUT INTO A SPOT IN THE STUDENT DATABASE AND THEN OUTPUTS TO INSERT FUNCTION, WHICH SAVES IT

	Student temp;

  	cout << "\n\tStudent Name: "; // THERE ARE 2 INPUTS SO THE USER CAN USE FIRST AND LAST NAME
	cin >> temp.name >> temp.name2;

  	cout << "\tStudent Department: "; 
	cin >> temp.dept >> temp.dept2;

  	cout << "\tStudent Program: "; 
	cin >> temp.program;

  	cout << "\tStudent Marks: "; 
	for (int m = 0; m < 6; m++) // THIS FOR LOOP IS TO INPUT THE 6 MARKS THE STUDENT HAS BY USING SPACES TO SEPARATE
		cin >> temp.marks[m];
	
	return(temp);

}

void print ( Student theone ) // THIS FUNCTION OUTPUTS ONE BLOCK OF STUDENT DETAILS TO THE USER
{

	cout << "\n\tStudent Name: "; 
	cout << theone.name << " " << theone.name2;
	cout << endl;

  	cout << "\tStudent Department: "; 
	cout << theone.dept << " " << theone.dept2;
	cout << endl;

  	cout << "\tStudent Program: "; 
	cout << theone.program;
	cout << endl;

  	cout << "\tStudent Marks: ";
	for (int m = 0; m < 6; m++)
		cout << theone.marks[m] <<  " ";
	cout << endl;

}

void insert (int &freepos){ //THIS FUNCTION USES THE GLOBAL VARIABLE 'FREEPOS' IN ORDER TO START INPUTING AND RE START WITHOUT OVERWRITING A BLOCK

for (int n = freepos; n < 10;n++){ //N BECOMES FREEPOS, WHICH IS INTITIALLY 0.
		students[n] = read (); // WITH EVERY LOOP, THE BLOCK FOR STUDENTS[N] IS FILLED FROM READ FUNCTION AND GOES UNTIL 10
		cout << "\n\tDo you want to enter another entry? - "; cin >> selecting; // USER IS ASKED IF THEY WOULD LIKE TO ENTER ANOTHER BLOCK OF DETAILS EACH TIME
		if (selecting == "no"){
			freepos = n+1; // IF THEY SELECT NO, THE FREEPOS VARIABLE IS INCRIMENTED BY 1 AND THE LOOP IS BROKEN
				break;}
	}

	cout << "\n\n";
}

void output (){ // THIS OUTPUTS DETAILS OF STRUCT IN THE ARRAY, USER CAN CHOOSE WHICH ONE THEY WANT TO OUTPUT OR OUTPUT ALL

		cout << "\n\tWould you like to output one or all students? - "; cin >> selecting; 
		if (selecting == "one"){
			cout << "\n\tWhich student would you like to display? (enter from 1-10) - "; cin >> p; // USER INPUTS NUMBER THEY WANT TO INPUT, NUMBER IS MADE BY P-1, TO TRANSFORM 1-10 STATEMENT INTO 0-9 ARRAY
			print(students[p-1]);}
		if (selecting == "all"){
			cout << "\n\tDisplaying all Students currently in database... " << endl;
			for (int i = 0; i < freepos;i++) // IF USER WRITES all THEN THE FOR LOOP WILL CONTINUE UNTIL JUST BEFORE THE AMOUNT IN THE FREEPOS VARIABLE
				print(students[i]);} // PERFORMS PRINT FUNCTION WHICH OUTPUTS DATA
		else;
}

struct Student update (Student change){ // THIS FUNCTION IS USED IF THE USER WISHES TO UPDATE A DATA BLOCK IN THE ARRAY

	cout << "\n\tStudent Name: "; 
	cout << change.name << " " << change.name2;
	cout << endl;

  	cout << "\tStudent Department: "; 
	cout << change.dept << " " << change.dept2;
	cout << endl;

  	cout << "\tStudent Program: "; 
	cout << change.program;
	cout << endl;

  	cout << "\tStudent Marks: ";
	for (int m = 0; m < 6; m++)
		cout << change.marks[m] <<  " "; // THE ORIGINAL DETAILS OF THE BLOCK ARE DISPLAYED, CORRESPONDING WITH NUMBER USER PICKED FROM 1-10
	cout << endl;

	do{ // DO WHILE LOOP COMMENCES, BRINGING UP A SEPERATE MENU

	cout << "\n\tPlease choose what details to update = " << endl;
	cout << "\t1. Student Name" << endl;
	cout << "\t2. Student Department" << endl;
	cout << "\t3. Student Program" << endl;
	cout << "\t4. Students Marks (1-6)" << endl;
	cout << "\t5. Go back to Main Menu" << endl;
	cout << "\n\tPlease enter here = "; 
	cin >> num; cout << endl;
	
	switch (num){
	case '1': 
			cout << "\n\tChange of Student Name = "; cin >> change.name >> change.name2;
			break; // CASE 1 CHANGES STUDENT NAME
	case '2': 
			cout << "\n\tChange of Student Deptartment = "; cin >> change.dept >> change.dept2;
			break; // CASE 2 CHANGES STUDENT DEPARTMENT
	case '3': 
			cout << "\n\tChange of Student Program = "; cin >> change.program;
			break; // CASE 3 CHANGES STUDENT DEPARTMENT
	case '4': 
			cout << "\n\tChange of Student Marks (1-6) = ";
			for (int m = 0; m < 6; m++)
			cin >> change.marks[m];
			break; // CASE 4 CHANGES STUDENT DEPARTMENT
	case '5': cout << "\tGoing back..." << endl;
			break; // CASE 5 ENDS MENU
	default: cout << "\t\nIncorrect input. Try again.\n" << endl;
			break; // DEFAULT CASE RESETS LOOP
	}
	
	}while(num != '5'); // DO WHILE ENDS WHEN USER INPUTS THE CHAR '5'

	return(change);

}
