#include <iostream>
#include <string>
using namespace std;


class Person {
private:
    string name;
    int id;

public:
    Person(string n = "", int i = 0) : name(n), id(i) {}

    void display() const {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
};


class Student : public Person {
private:
    int yearLevel;
    string major;

public:
    Student(string n = "", int i = 0, int y = 0, string m = "")
        : Person(n, i), yearLevel(y), major(m) {}

    void display() const {
        Person::display();
        cout << "Year: " << yearLevel << ", Major: " << major << endl;
    }
};


class Instructor : public Person {
private:
    string department;
    int experienceYears;

public:
    Instructor(string n = "", int i = 0, string d = "", int e = 0)
        : Person(n, i), department(d), experienceYears(e) {}

    void display() const {
        Person::display();
        cout << "Department: " << department
             << ", Experience: " << experienceYears << " years" << endl;
    }
};


class Course {
private:
    string courseCode;
    string courseName;
    int maxStudents;
    Student* students;
    int currentStudents;

public:
    Course(string code = "", string name = "", int max = 0)
        : courseCode(code), courseName(name), maxStudents(max), currentStudents(0) {
        students = new Student[maxStudents];
    }

    ~Course() {
        delete[] students;
    }

    bool addStudent(const Student& s) {
        if (currentStudents < maxStudents) {
            students[currentStudents++] = s;
            return true;
        } else {
            cout << "Course is full!" << endl;
            return false;
        }
    }

    void displayCourseInfo() const {
        cout << "Course Code: " << courseCode
             << ", Course Name: " << courseName
             << ", Students Enrolled: " << currentStudents << "/" << maxStudents
             << endl;

        for (int i = 0; i < currentStudents; ++i) {
            cout << "  Student " << i + 1 << ": ";
            students[i].display();
        }
    }
};


int main() {
  
    Student s1("Omar", 101, 2, "Computer Science");
  
    Instructor inst("Dr.Lina", 2, "Computer Science", 5);

    
    Course c1("CS101", "Programming ", 10);


    c1.addStudent(s1);
    

   
    cout << "Instructor Info:" << endl;
    inst.display();

    cout << "\nCourse Info:" << endl;
    c1.displayCourseInfo();

    return 0;
}
