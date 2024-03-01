#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"
using namespace std;

class Student {
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int* daysToCompleteCourses; // array of number of days to complete each course
    DegreeProgram degreeProgram;

public:
    // Constructors
    Student(); // default constructor
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysToCompleteCourses, DegreeProgram degreeProgram);

    // Destructor
    ~Student();

    // Accessors (getters)
    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    int* getDaysToCompleteCourses() const;
    DegreeProgram getDegreeProgram() const;

    // Mutators (setters)
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysToCompleteCourses(int* daysToCompleteCourses);
    void setDegreeProgram(DegreeProgram degreeProgram);

    // Other member functions
    void print() const; // print specific student data
};

#endif
