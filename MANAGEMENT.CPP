#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    string course;
    float marks;

    void input() {
        cout << "Enter Student ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();

        cout << "Enter Course: ";
        getline(cin, course);

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "\nStudent ID : " << id;
        cout << "\nName       : " << name;
        cout << "\nAge        : " << age;
        cout << "\nCourse     : " << course;
        cout << "\nMarks      : " << marks << endl;
        cout << "--------------------------\n";
    }
};

void addStudent() {
    Student s;
    ofstream file("student.txt", ios::app);

    s.input();

    file << s.id << endl;
    file << s.name << endl;
    file << s.age << endl;
    file << s.course << endl;
    file << s.marks << endl;

    file.close();

    cout << "\nStudent added successfully!\n";
}

void displayStudents() {
    Student s;
    ifstream file("student.txt");

    if (!file) {
        cout << "No records found!\n";
        return;
    }

    while (file >> s.id) {
        file.ignore();
        getline(file, s.name);
        file >> s.age;
        file.ignore();
        getline(file, s.course);
        file >> s.marks;

        s.display();
    }

    file.close();
}

void searchStudent() {
    int searchId;
    bool found = false;
    Student s;

    cout << "Enter Student ID to search: ";
    cin >> searchId;

    ifstream file("student.txt");

    while (file >> s.id) {
        file.ignore();
        getline(file, s.name);
        file >> s.age;
        file.ignore();
        getline(file, s.course);
        file >> s.marks;

        if (s.id == searchId) {
            cout << "\nStudent Found:\n";
            s.display();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Student not found!\n";

    file.close();
}

void updateStudent() {
    int searchId;
    bool found = false;
    Student s;

    cout << "Enter Student ID to update: ";
    cin >> searchId;

    ifstream file("student.txt");
    ofstream temp("temp.txt");

    while (file >> s.id) {
        file.ignore();
        getline(file, s.name);
        file >> s.age;
        file.ignore();
        getline(file, s.course);
        file >> s.marks;

        if (s.id == searchId) {
            cout << "\nEnter new details:\n";
            s.input();
            found = true;
        }

        temp << s.id << endl;
        temp << s.name << endl;
        temp << s.age << endl;
        temp << s.course << endl;
        temp << s.marks << endl;
    }

    file.close();
    temp.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found)
        cout << "Student record updated successfully!\n";
    else
        cout << "Student not found!\n";
}

void deleteStudent() {
    int searchId;
    bool found = false;
    Student s;

    cout << "Enter Student ID to delete: ";
    cin >> searchId;

    ifstream file("student.txt");
    ofstream temp("temp.txt");

    while (file >> s.id) {
        file.ignore();
        getline(file, s.name);
        file >> s.age;
        file.ignore();
        getline(file, s.course);
        file >> s.marks;

        if (s.id == searchId) {
            found = true;
            continue;
        }

        temp << s.id << endl;
        temp << s.name << endl;
        temp << s.age << endl;
        temp << s.course << endl;
        temp << s.marks << endl;
    }

    file.close();
    temp.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found)
        cout << "Student deleted successfully!\n";
    else
        cout << "Student not found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                cout << "Thank You!\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}