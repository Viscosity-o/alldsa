#include <iostream>
#include <string>
using namespace std;

//  Password Hashing 
string hashPassword(string password) {
    string hashed = "";
    for (char c : password)
        hashed += to_string((int)c % 10);  
    return hashed;
}

//  Hash Function
int hashFunction(string username, int size) {
    int sum = 0;
    for (char c : username)
        sum += c;
    return sum % size;
}

//  CHAINING METHOD 
struct Node {
    string username;
    string hashedPassword;
    Node* next;
};

class HashTableChaining {
    Node** table;
    int size;
public:
    HashTableChaining(int s) {
        size = s;
        table = new Node*[size];
        for (int i = 0; i < size; i++) table[i] = NULL;
    }

    void insertUser(string username, string password) {
        int index = hashFunction(username, size);
        string hashed = hashPassword(password);

        Node* newNode = new Node{username, hashed, NULL};

        if (table[index] == NULL) {
            table[index] = newNode;
            cout << "Inserted '" << username << "' at index " << index << " directly.\n";
        } else {
            newNode->next = table[index];
            table[index] = newNode;
            cout << "Collision at index " << index << " → resolved using chaining.\n";
        }
    }

    void display() {
        cout << "\n--- Hash Table (Chaining) ---\n";
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            Node* temp = table[i];
            while (temp) {
                cout << "[" << temp->username << "]";
                if (temp->next) cout << " -> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

//  OPEN ADDRESSING (LINEAR PROBING) 
class HashTableOpen {
    string* usernames;
    string* passwords;
    bool* used;
    int size;
public:
    HashTableOpen(int s) {
        size = s;
        usernames = new string[size];
        passwords = new string[size];
        used = new bool[size];
        for (int i = 0; i < size; i++) used[i] = false;
    }

    void insertUser(string username, string password) {
        int index = hashFunction(username, size);
        string hashed = hashPassword(password);

        if (!used[index]) {
            usernames[index] = username;
            passwords[index] = hashed;
            used[index] = true;
            cout << "Inserted '" << username << "' at index " << index << " directly.\n";
        } else {
            cout << "Collision at index " << index << " → resolving by linear probing...\n";
            for (int i = 1; i < size; i++) {
                int probe = (index + i) % size;
                if (!used[probe]) {
                    usernames[probe] = username;
                    passwords[probe] = hashed;
                    used[probe] = true;
                    cout << "Inserted '" << username << "' at index " << probe << " after probing.\n";
                    return;
                }
            }
            cout << "[!] Table full, cannot insert " << username << endl;
        }
    }

    void display() {
        cout << "\n--- Hash Table (Open Addressing) ---\n";
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            if (used[i]) cout << "[" << usernames[i] << "]";
            cout << endl;
        }
    }
};


int main() {
    int tableSize, n;
    cout << "Enter hash table size: ";
    cin >> tableSize;

    cout << "Enter number of users to insert: ";
    cin >> n;

    // Create both hash tables
    HashTableChaining chainTable(tableSize);
    HashTableOpen openTable(tableSize);

    cout << "\n=== INSERT USERS (CHAINING) ===\n";
    for (int i = 0; i < n; i++) {
        string username, password;
        cout << "\nEnter username " << i + 1 << ": ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        chainTable.insertUser(username, password);
    }
    chainTable.display();

    cout << "\n=== INSERT USERS (OPEN ADDRESSING) ===\n";
    for (int i = 0; i < n; i++) {
        string username, password;
        cout << "\nEnter username " << i + 1 << ": ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        openTable.insertUser(username, password);
    }
    openTable.display();

    return 0;
}
