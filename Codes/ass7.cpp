#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class student {
    string name;
    int roll_no;
    string division;
    string city;

public:

    void addstudent() {
        cout << "\nEnter Roll Number: ";
        cin >> roll_no;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Division: ";
        cin >> division;
        cout << "Enter Address: ";
        cin >> city;

        ofstream file;
        file.open("student.txt", ios::app);

        file << roll_no << " " << name << " " << division << " " << city << endl;
        file.close();

        cout << "\nStudent added successfully!" << endl;
    }

    void search_student() {
        int r;
        bool found = false;
        cout << "\nEnter Roll Number to search: ";
        cin >> r;

        ifstream file("student.txt");

        while (file >> roll_no >> name >> division >> city) {
            if (r == roll_no) {
                cout << "\nStudent Found:\n";
                cout << "Roll No: " << roll_no 
                     << "\nName: " << name 
                     << "\nDivision: " << division 
                     << "\nCity: " << city << endl;
                found = true;
                break;
            }
        }

        if (!found)
            cout << "\nStudent record not found!" << endl;

        file.close();
    }

    void delete_student() {
        string tempName;
        bool deleted = false;

        cout << "\nEnter name to delete: ";
        cin >> tempName;

        ifstream file("student.txt");
        ofstream tempfile("temp.txt");

        while (file >> roll_no >> name >> division >> city) {
            if (name != tempName) {
                tempfile << roll_no << " " << name << " " << division << " " << city << endl;
            } else {
                deleted = true;
            }
        }

        file.close();
        tempfile.close();

        remove("student.txt");
        rename("temp.txt", "student.txt");

        if (deleted)
            cout << "\nRecord deleted successfully!" << endl;
        else
            cout << "\nNo record found with that name." << endl;
    }
};

int main() {
    student s;
    int ch;

    while (true) {
        cout << "\n====== STUDENT DATABASE MENU ======";
        cout << "\n1. Add Student";
        cout << "\n2. Search Student";
        cout << "\n3. Delete Student";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1: s.addstudent(); break;
        case 2: s.search_student(); break;
        case 3: s.delete_student(); break;
        case 4: exit(0);
        default: cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
