#include<iostream>
#include<string>
using namespace std;

// Enum for priority levels of news
enum Priority {
    Breaking = 1,          // Highest priority
    International = 2,     // Second priority
    State = 3,             // Third priority
    Local = 4,             // Lowest priority
};


struct node {
    string news;           // Stores news headline or content
    Priority priority;     // Stores priority of the news
    node* next;            // Pointer to next node
};


class MPQueue {
    node* front;          
    node* rear;            

    // Helper function to convert enum to string for display
    string pri_to_string(Priority p);

public:
    MPQueue() {            // Constructor
        front = rear = NULL;
    }

    void insert_by_priority(); 
    void delete_News();        
    void Display();          
    void peep();               
};

// Convert priority enum to string (for display)
string MPQueue::pri_to_string(Priority p) {
    switch (p) {
        case Breaking: return "Breaking News";
        case International: return "International News";
        case State: return "State News";
        case Local: return "Local News";
        default: return "Unknown";
    }
}

// Function to insert news according to its priority
void MPQueue::insert_by_priority() {
    string news;
    int PChoice;
    node* temp;
    node* current;

    cout << "Enter the news: ";
    getline(cin, news);    // Read complete news line

    // Ask for priority level
    cout << "Choose Priority:\n";
    cout << "1. Breaking News\n2. International News\n3. State News\n4. Local News\n";
    cout << "Enter Choice: ";
    cin >> PChoice;
    cin.ignore();          

    // Convert user input to Priority type
    Priority prio;
    switch (PChoice) {
        case 1: prio = Breaking; break;
        case 2: prio = International; break;
        case 3: prio = State; break;
        case 4: prio = Local; break;
        default: prio = Local; break;
    }

    // Create a new node
    temp = new node;
    temp->news = news;
    temp->priority = prio;
    temp->next = NULL;

    // If queue is empty
    if (front == NULL) {
        front = rear = temp;
    }
    else {
        // If new news has higher priority than front
        if (front->priority > prio) {
            temp->next = front;
            front = temp;
        }
        else {
            // Traverse until correct position is found
            current = front;
            while (current->next != NULL && current->next->priority <= prio) {
                current = current->next;
            }
            // Insert node in its correct position
            temp->next = current->next;
            current->next = temp;

            // Update rear pointer if inserted at end
            if (current == rear) {
                rear = temp;
            }
        }
    }
    cout << "News Added Successfully\n";
}

// Function to delete news with highest priority
void MPQueue::delete_News() {
    if (front == NULL) {
        cout << "No news to delete\n";
    }
    else {
        node* temp = front;
        front = front->next;       // Move front pointer to next node
        delete temp;               // Delete old front node

        if (front == NULL)         // If queue becomes empty
            rear = NULL;

        cout << "Top Priority News is Deleted\n";
    }
}

// Function to display all news
void MPQueue::Display() {
    node* current;
    if (front == NULL) {
        cout << "No news to display\n";
    }
    else {
        current = front;
        // Traverse the linked list
        while (current != NULL) {
            cout << pri_to_string(current->priority) << ": "
                 << current->news << endl;
            current = current->next;
        }
    }
}

// Function to show only the highest priority news
void MPQueue::peep() {
    if (front == NULL) {
        cout << "No news to display\n";
    }
    else {
        cout << "High Priority News: " << front->news << endl;
    }
}


int main() {
    MPQueue Q;
    int choice;

    do {
        cout << "\n========== NEWS PRIORITY QUEUE ==========\n";
        cout << "1. Enter News\n";
        cout << "2. Delete Top News\n";
        cout << "3. Peep (Show Highest Priority News)\n";
        cout << "4. Display All News\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
            case 1:
                Q.insert_by_priority();
                Q.Display();
                break;

            case 2:
                Q.delete_News();
                Q.Display();
                break;

            case 3:
                Q.peep();
                break;

            case 4:
                Q.Display();
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Choice! Try Again.\n";
                break;
        }

    } while (choice != 0);   

    return 0;
}