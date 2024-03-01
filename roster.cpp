#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include <iostream>
using namespace std;

class Roster {
private:
    static const int MAX_STUDENTS = 5;
    Student** classRosterArray;

public:
    // Constructor
    Roster();

    // Destructor
    ~Roster();

    // Parse student data and add to the roster
    void parseAndAddStudent(const string& studentData);

    // Add student to the roster
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    // Remove student from the roster by ID
    void remove(string studentID);

    // Print all students in the roster
    void printAll() const;

    // Print average days to complete courses for a specific student
    void printAverageDaysInCourse(string studentID) const;

    // Print invalid email addresses
    void printInvalidEmails() const;

    // Print students by degree program
    void printByDegreeProgram(DegreeProgram degreeProgram) const;
};

#endif
