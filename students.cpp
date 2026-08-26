#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    string department;
};

// Add student
void addStudent() {
    Student s;

    ofstream file("students.txt", ios::app);

    cout << "\nEnter Student ID: ";
    cin >> s.id;

    cin.ignore();
    cout << "Enter Student Name: ";
    getline(cin, s.name);

    cout << "Enter Age: ";
    cin >> s.age;

    cin.ignore();
    cout << "Enter Department: ";
    getline(cin, s.department);

    file << s.id << "|" << s.name << "|"
         << s.age << "|" << s.department << endl;

    file.close();

    cout << "\nStudent added successfully!\n";
}

// Display students
void displayStudents() {
    ifstream file("students.txt");
    Student s;
    string line;

    cout << "\n----- STUDENT RECORDS -----\n";

    bool found = false;

    while (getline(file, line)) {
        size_t pos1 = line.find("|");
        size_t pos2 = line.find("|", pos1 + 1);
        size_t pos3 = line.find("|", pos2 + 1);

        s.id = stoi(line.substr(0, pos1));
        s.name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        s.age = stoi(line.substr(pos2 + 1,
                     pos3 - pos2 - 1));
        s.department = line.substr(pos3 + 1);

        cout << "\nID         : " << s.id;
        cout << "\nName       : " << s.name;
        cout << "\nAge        : " << s.age;
        cout << "\nDepartment : " << s.department;
        cout << "\n---------------------------\n";

        found = true;
    }

    if (!found) {
        cout << "\nNo student records found!\n";
    }

    file.close();
}

// Update student
void updateStudent() {
    int searchId;
    bool found = false;

    cout << "\nEnter Student ID to update: ";
    cin >> searchId;

    ifstream file("students.txt");
    ofstream temp("temp.txt");

    string line;

    while (getline(file, line)) {
        size_t pos = line.find("|");
        int id = stoi(line.substr(0, pos));

        if (id == searchId) {
            Student s;
            s.id = searchId;

            cin.ignore();

            cout << "Enter New Name: ";
            getline(cin, s.name);

            cout << "Enter New Age: ";
            cin >> s.age;

            cin.ignore();

            cout << "Enter New Department: ";
            getline(cin, s.department);

            temp << s.id << "|" << s.name << "|"
                 << s.age << "|" << s.department << endl;

            found = true;
        }
        else {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "\nStudent updated successfully!\n";
    else
        cout << "\nStudent ID not found!\n";
}

// Delete student
void deleteStudent() {
    int searchId;
    bool found = false;

    cout << "\nEnter Student ID to delete: ";
    cin >> searchId;

    ifstream file("students.txt");
    ofstream temp("temp.txt");

    string line;

    while (getline(file, line)) {
        size_t pos = line.find("|");
        int id = stoi(line.substr(0, pos));

        if (id == searchId) {
            found = true;
        }
        else {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "\nStudent deleted successfully!\n";
    else
        cout << "\nStudent ID not found!\n";
}

// Main menu
int main() {
    int choice;

    do {
        cout << "\n================================";
        cout << "\n   STUDENT MANAGEMENT SYSTEM";
        cout << "\n================================";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Update Student";
        cout << "\n4. Delete Student";
        cout << "\n5. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                updateStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                cout << "\nThank you! Program closed.\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
