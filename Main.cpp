/*
    Name: Student Grades 
    Copyright: Brayan Villatoro
    Author: Brayan Villatoro
    Date: 11/19/2020 10:09PM
    Compiler: dev-bloodshed c++ (v5.11)
    Description:

    CSCI-373 (FALL 2020) (Prof. Abdu) (Assignment 5) (Version 3) (John Jay College)
    -------------------------------------------------------------------------------
    o Student Class (Name and Grade)		  -Line 05 - Student.h
    o Add Student 							  -Line 54 - Main.cpp
    o Remove Student						  -Line 80 - Main.cpp
	o Update Student Grade				      -Line 93 - Main.cpp
    o Display class roster					  -Lime 122- Main.cpp
    o Binary search tree (Removal example)    -Line 80 - Student.h 

    • 2 Files 	
    • Main.cpp, Student.h
*/
#include <iostream>
#include <list>
#include <string>
#include <conio.h> // getch() 
#include "Student.h"
using namespace std;

int main() // Start 
{
	int val, ch; 		// val: Grade value Line 97 and ch: User selection  
	string StudentName; // Name of student 
	double Grade;   	// Grade of student 
	Student bst; 		// Student Node
// Guide 
	cout << "\t==============================================================================================";
	cout << "\n\t\tOnly enter grades 100 through 1, otherwise grade will be considered unknown '?'\n";
    cout << "\t(100 ~ 90 = A || 90 ~ 80 = B || 80 ~ 70 = C || 70 ~ 60 = D || 60 ~ 1 = F || Other grades = ?)\n";
	cout << "\t==============================================================================================\n";
// Menu :: Requirement 
	cout << "\t1: Add New Student\n";
	cout << "\t2: Remove a Student\n";
	cout << "\t3: Update Student Grade\n";
	cout << "\t4: Display Class Roster\n";
	cout << "\t5: Exit\n\n";
	
do 
{
	cout << "\tEnter your choice: "; // User input 
	cin >> ch;
	cout << "\t~~~~~~~~~~~~~~~~~~~~\n";
	
	switch(ch) // Switch case start 
{
	case 1: // New Student    
	cout << "\tEnter Student Name: ";
	cin >> StudentName; // Name input from user 
	cout << "\n\tEnter Student Grade: ";
	cin >> Grade; // Grade input from user 
	cout << "\n\t--------------------\n";
    //Grade validation A-F or ? unknown Grade 
	{
        if (Grade >= 90 && Grade <= 100)
            Grade = 'A';
        else if (Grade >= 80 && Grade < 90)
            Grade = 'B';
        else if (Grade >= 70 && Grade < 80)
            Grade = 'C';
        else if (Grade >= 60 && Grade < 70)
            Grade = 'D';
        else if (Grade >= 1 && Grade < 60)
            Grade = 'F';
        else if (Grade > 100 && Grade < 1000)
            Grade = '?';
        else Grade = '?';
    }
    
	bst.insert(StudentName,Grade); // Inserting the node data into BST tree 

break;
	case 2: // Remove Student 
	cout << "\tEnter Student Name to delete: ";
	cin >> StudentName; 
	if (bst.find(StudentName)!= 0) // While student is found
{
	bst.remove(StudentName);
	cout << "\t" << StudentName << " was deleted.\n\n";  
	cout << "\t--------------------\n";
}
else 
cout << StudentName << "\t Not Found.\n"; // Rquirement for Removal function 

break;
	case 3: // Update Grade 
	cout << "\tEnter Name: ";
	cin >> StudentName;
	if (bst.find(StudentName) == 0) // Handle non name values to not crash 
	cout << "\t" << val << " Not Found.\n"; // Given Grade value of Grade not found :: Requirement for Update function 
	
else
{
	cout << "\tEnter Grade replacement: ";
    cin >> Grade;
    //Grade validation A-F or ? unknown Grade 
	{
        if (Grade >= 90 && Grade <= 100)
            Grade = 'A';
        else if (Grade >= 80 && Grade < 90)
            Grade = 'B';
        else if (Grade >= 70 && Grade < 80)
            Grade = 'C';
        else if (Grade >= 60 && Grade < 70)
            Grade = 'D';
        else if (Grade >= 1 && Grade < 60)
            Grade = 'F';
        else if (Grade > 100 && Grade < 1000)
            Grade = '?';
        else Grade = '?';
    }
    bst.update(StudentName,Grade);  
}
break;
	case 4: // Display Name and Grades 'Roster' 
	cout << "\tName    Grade\n";
	cout << "\t----    -----\n";
	
	bst.display();
break;  
} 
} // Switch case end 
while (ch != 5); // Exit
getch(); // Block program exit text 
return 0;
} // Main End 

