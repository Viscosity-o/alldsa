//Roll no 23307
/*Implementation of a Double-Ended Queue (Deque)
• Implement a double-ended queue where insertion and deletion can happen from both ends.
• Support operations such as enqueue front, enqueue rear, deque front, dequeue rear*/


#include<iostream>
using namespace std;

#define MAX 10   // Maximum size of deque

// Class definition for Double Ended Queue
class DQueue {
    int arr[MAX];
    int front; 
    int rear;

public:
    DQueue() {
        front = rear = -1;   // Initialize empty deque
    }

    bool isFull();
    bool isEmpty();
    void EnqueueFront(int x);
    void EnqueueRear(int x);
    void DequeueFront();
    void DequeueRear();
    void getFront();
    void getRear();
    void Display();
};

// Function to check if deque is full
bool DQueue::isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// Function to check if deque is empty
bool DQueue::isEmpty() {
    return (front == -1);
}

// Insert element at front end
void DQueue::EnqueueFront(int x) {
    if (isFull()) {
        cout << "Overflow! Cannot insert.\n";
        return;
    }

    if (isEmpty()) {                  // First element
        front = rear = 0;
    } 
    else if (front == 0) {            // Circular condition
        front = MAX - 1;
    } 
    else {
        front--;
    }

    arr[front] = x;
    cout << "Inserted " << x << " at front.\n";
}

// Insert element at rear end
void DQueue::EnqueueRear(int x) {
    if (isFull()) {
        cout << "Overflow! Cannot insert.\n";
        return;
    }

    if (isEmpty()) {                  // First element
        front = rear = 0;
    } 
    else if (rear == MAX - 1) {       // Circular condition
        rear = 0;
    } 
    else {
        rear++;
    }

    arr[rear] = x;
    cout << "Inserted " << x << " at rear.\n";
}

// Delete element from front
void DQueue::DequeueFront() {
    if (isEmpty()) {
        cout << "Underflow! No data to delete.\n";
        return;
    }

    cout << "Deleted from front: " << arr[front] << endl;

    if (front == rear) {              // Only one element
        front = rear = -1;
    } 
    else if (front == MAX - 1) {      // Circular condition
        front = 0;
    } 
    else {
        front++;
    }
    cout<<"Deleted value from front"<<endl;
}

// Delete element from rear
void DQueue::DequeueRear() {
    if (isEmpty()) {
        cout << "Underflow! No data to delete.\n";
        return;
    }

    cout << "Deleted from rear: " << arr[rear] << endl;

    if (front == rear) {              // Only one element
        front = rear = -1;
    } 
    else if (rear == 0) {             // Circular condition
        rear = MAX - 1;
    } 
    else {
        rear--;
    }
    cout<<"Deleted value from rear"<<endl;
}

// Display front element
void DQueue::getFront() {
    if (isEmpty()) {
        cout << "Deque is empty.\n";
    } else {
        cout << "Front Element: " << arr[front] << endl;
    }
}

// Display rear element
void DQueue::getRear() {
    if (isEmpty()) {
        cout << "Deque is empty.\n";
    } else {
        cout << "Rear Element: " << arr[rear] << endl;
    }
}

// Display all elements in deque 
void DQueue::Display() {
    if (isEmpty()) {
        cout << "Deque is empty.\n";
        return;
    }
    cout << "Deque elements: ";

    // Case 1: When front <= rear 
    if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
    }
    // Case 2: When  (front > rear)
    else {
        // Print from front to end of array
        for (int i = front; i < MAX; i++) {
            cout << arr[i] << " ";
        }
        // Then print from 0 to rear
        for (int i = 0; i <= rear; i++) {
            cout << arr[i] << " ";
        }
    }

    cout << endl;
}


int main() {
    DQueue dq;
    int choice, value;
    int run = 1;

    do {
        cout << "\n===== DOUBLE ENDED QUEUE MENU =====\n";
        cout << "1. Enqueue Front\n";
        cout << "2. Enqueue Rear\n";
        cout << "3. Dequeue Front\n";
        cout << "4. Dequeue Rear\n";
        cout << "5. Get Front Element\n";
        cout << "6. Get Rear Element\n";
        cout << "7. Display Deque\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at front: ";
            cin >> value;
            dq.EnqueueFront(value);
            break;

        case 2:
            cout << "Enter value to insert at rear: ";
            cin >> value;
            dq.EnqueueRear(value);
            break;

        case 3:
            dq.DequeueFront();
            break;

        case 4:
            dq.DequeueRear();
            break;

        case 5:
            dq.getFront();
            break;

        case 6:
            dq.getRear();
            break;

        case 7:
            dq.Display();
            break;

        case 8:
            cout << "Exiting program...\n";
            run = 0;
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (run != 0);

    return 0;
}