#include "roster.h"

int main() {
    // Print out course title, programming language, WGU student ID, and your name
    cout << "Course Title: C867 - Scripting and Programming Applications" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "WGU Student ID: 011315946" << endl; 
    cout << "Your Name: Andrew Hilleary" << endl; 

    // Create an instance of the Roster class called classRoster
    Roster classRoster;

    // Pseudo student data
    string studentData[] = {
        "A1,John,Smith,john.smith@email.com,20,35,40,55,SECURITY",
        "A2,Jane,Doe,jane.doe@email.com,21,45,50,60,NETWORK",
        "A3,Bob,Johnson,bob.johnson@email.com,22,55,60,75,SOFTWARE",
        "A4,Chris,Williams,chris.williams@email.com,23,30,40,50,SECURITY",
        "A5,Andrew,Hilleary,ahil783@wgu.edu,24,40,45,55,NETWORK"
    };

    // Add each student to classRoster
    for (const auto& data : studentData) {
        classRoster.parseAndAddStudent(data);
    }

    // Print all students in the roster
    cout << "Print all students in the roster:" << endl;
    classRoster.printAll();
    cout << "--------------------------" << endl;

    // Print invalid email addresses
    cout << "Print invalid email addresses:" << endl;
    classRoster.printInvalidEmails();
    cout << "--------------------------" << endl;

    // Print average days to complete courses for each student
    cout << "Print average days to complete courses for each student:" << endl;
    for (int i = 0; i < Roster::MAX_STUDENTS; ++i) {
        if (classRoster.getClassRosterArray()[i] != nullptr) {
            classRoster.printAverageDaysInCourse(classRoster.getClassRosterArray()[i]->getStudentID());
        }
    }
    cout << "--------------------------" << endl;

    // Print students by degree program
    cout << "Print students by degree program (SOFTWARE):" << endl;
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << "--------------------------" << endl;

    // Remove student with ID "A3" from the roster
    cout << "Remove student with ID 'A3' from the roster:" << endl;
    classRoster.remove("A3");
    classRoster.printAll();
    cout << "--------------------------" << endl;

    // Attempt to remove student with ID "A3" again (should print an error message)
    cout << "Attempt to remove student with ID 'A3' again:" << endl;
    classRoster.remove("A3");

    return 0;
}
