//Roll no 23307
/*"Implementing Queues and Stacks Using Linked Lists for Real-World Task Management
Systems"*/

#include<iostream>                          
using namespace std;                      

enum priority{High = 1, Medium = 2, Low = 3};   // Enum to represent task priority levels

// Define a structure for each queue node
typedef struct QNode{
    string title;                           
    float time;                             
    struct QNode *next;                     
    priority p;                             
}NODE;                                      

class Mytask{
    NODE *front;                            // Pointer to the front of the queue
    NODE *rear;                             // Pointer to the rear of the queue
    public:
    Mytask(){                               // Constructor — initializes queue as empty
        front = NULL;
        rear = NULL;
    }
    void Menqueue();                        // Function to add (enqueue) a task
    void Mdequeue();                        // Function to remove (dequeue) a task
    NODE *getnode();                        // Function to create and return a new node
    void display();                         // Function to display tasks
};

// Function to create and return a new task node
NODE* Mytask::getnode(){
    NODE *t;                                // Temporary pointer for new node
    int pr;                                 // Variable to store user-entered priority
    t = new NODE;                           // Dynamically allocate memory for new node

    cout << "Enter Title of the task: ";
    cin >> t->title;                        

    cout << "Enter time required to complete the task: ";
    cin >> t->time;                         

    cout << "Enter Priority(1:High, 2:Medium, 3:Low): ";
    cin >> pr;                             
    t->p = (priority)pr;                    // Assign entered value to enum variable 'p'

    t->next = NULL;                         // Initialize next pointer to NULL
    return t;                               // Return pointer to the new node
}

// Function to enqueue (insert) a task into the queue
void Mytask::Menqueue(){
    NODE *t;                                // Temporary pointer for new node
    t = getnode();                          // Create a new node with user data
    if(front == NULL){                      // If queue is empty
        front = t;                          // Both front and rear point to new node
        rear = t;
    }else{                                  // If queue already has elements
        rear->next = t;                     // Link new node at the end
        rear = rear->next;                  // Move rear pointer to the new node
    }
}

// Function to dequeue (remove) a task from the queue
void Mytask::Mdequeue(){
    NODE *temp;                             // Temporary pointer for deletion
    temp = front;                           // Point temp to current front node
    if(front == NULL){                      // If queue is empty
        cout << "Task list is empty" << endl;
        return;                             
    }else{
        front = front->next;                // Move front pointer to next node
        delete temp;                       
    }
}

// Function to display tasks in the queue
void Mytask::display(){
    NODE *temp;                             // Temporary pointer to traverse queue
    temp = front;                           // Start from the front node
    if(temp == NULL){                       // If queue is empty
        cout << "Task list is empty:" << endl;
    }else{
        
        cout << "Title: " << temp->title
             << ", Time: " << temp->time << "hrs"
             << ", Priority: " 
             << (temp->p == High ? "High" : (temp->p == Medium ? "Medium" : "Low"))
             << endl;
    }
}


int main(){
    Mytask t;                               
    int choice;                            
    do{
        // Display menu options
        cout << "1.Enqueue\n2.Dequeue\n3.Display\n0.exit\nEnter your choice: ";
        cin >> choice;                     

        switch (choice){                   
        case 1:
            t.Menqueue();                  
            break;   
        case 2:
            t.Mdequeue();               
            break;
        case 3:
            t.display();                    
            break;
        case 0:
            cout << "Exiting the program...."; 
        default:
            cout << "Invalid Choice";       
            break;
        }
    }while(choice != 0);                   
}