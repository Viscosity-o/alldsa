//Roll no 23307


#include<iostream>                    
#include<string>                      
using namespace std;                  

struct Student {
    int rollno;                       
    float CGPA;                       
    string name;                      
};

class database {
    Student s[50];                    
    int n;                            // Number of students in database

public:
    void create();                    
    void display();                   // Function to display all records
    void MBubblesort();               // Sort by roll number (Bubble Sort)
    void MInsertionsort();            // Sort by name (Insertion Sort)
    void MLinearsearch();             // Search by CGPA (Linear Search)
    void MBinarysearch();             // Search by name (Binary Search)

    database() {                   
        n = 0;                        
    }
};


void database::create() {
    cout << "Enter number of students to be entered in database: ";
    cin >> n;                         // Input total number of students
    for (int i = 0; i < n; i++) {
        cout << "\nEnter name: ";
        cin >> s[i].name;             // Input student name
        cout << "Enter rollno: ";
        cin >> s[i].rollno;           // Input roll number
        cout << "Enter CGPA: ";
        cin >> s[i].CGPA;             // Input CGPA
    }
}


void database::display() {
    cout << "\nStudents Details\n";
    cout << "------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << "Roll no: " << s[i].rollno
             << " , Name: " << s[i].name
             << " , CGPA: " << s[i].CGPA << endl;
    }
}

// Function to sort records by roll number using Bubble Sort
void database::MBubblesort() {
    int t;                                        // Temporary variable for swapping roll numbers
    for (int j = 0; j < n - 1; j++) {             // Outer loop for passes
        for (int i = 0; i < n - 1; i++) {         // Inner loop for comparisons
            if (s[i].rollno > s[i + 1].rollno) {  // Compare consecutive roll numbers
                t = s[i].rollno;                  // Swap roll numbers
                s[i].rollno = s[i + 1].rollno;
                s[i + 1].rollno = t;
            }
        }
    }
}


void database::MInsertionsort() {
    for (int i = 0; i < n; i++) {
        Student key = s[i];            // Store current student record as key
        int j = i - 1;
        // Shift larger names ahead of key
        while (j >= 0 && s[j].name > key.name) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;                // Insert key at correct position
    }
}


void database::MLinearsearch() {
    float key;
    cout << "Enter CGPA to be searched: ";
    cin >> key;                        // Input CGPA to search
    int count = 0;                     // Flag to check if found
    for (int i = 0; i < n; i++) {
        if (s[i].CGPA == key) {        // If CGPA matches
            cout << "Name: " << s[i].name
                 << ", Rollno: " << s[i].rollno
                 << ", CGPA: " << s[i].CGPA;
            count++;
            break;                     // Stop after finding first match
        }
    }
    if (count == 0) {                  // If not found
        cout << "Data not found" << endl;
    }
}


void database::MBinarysearch() {
    string key;
    cout << "Enter name to be searched: ";
    cin >> key;                        // Input name to search
    int l = 0;                         // Left boundary
    int h = n - 1;                     // Right boundary

    while (l <= h) {                   // Continue until search space exists
        int mid = (l + h) / 2;         // Find middle index
        if (s[mid].name == key) {      // If match found
            cout << "Name: " << s[mid].name
                 << ", Rollno: " << s[mid].rollno
                 << ", CGPA: " << s[mid].CGPA;
            break;
        } else if (key < s[mid].name) { // If key is alphabetically smaller
            h = mid - 1;
        } else {                        // If key is alphabetically greater
            l = mid + 1;
        }
        if (l > h) {                    // When not found
            cout << "Data not found";
        }
    }
}


int main() {
    database d;                        
    d.create();                         
    cout << "Original database is:\n";
    d.display();                       

    int choice;                         
    do {
        cout << "\n1.Sort by roll no\n2.Sort by name\n3.Search by CGPA\n4.Search by name\n0.Exit\nEnter your choice: ";
        cin >> choice;                  // Take user choice

        switch (choice) {
        case 1:
            d.MBubblesort();            // Sort by roll number
            d.display();
            break;
        case 2:
            d.MInsertionsort();         // Sort by name
            d.display();
            break;
        case 3:
            d.MLinearsearch();          // Search by CGPA
            break;
        case 4:
            d.MBinarysearch();          // Search by name
            break;
        case 0:
            cout << "Exiting the Program";
            break;
        default:
            cout << "Invalid choice"; 
            break;
        }
    } while (choice != 0);              

    return 0;
}