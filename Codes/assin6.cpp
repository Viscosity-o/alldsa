#include<iostream>
#include<string>
using namespace std;

struct Node{
    string username;
    string hashedPassword;
    Node*next;

};

string hashedPassword(string password){
    string hashed=""; //will store hashed password pass word which will convert into hash
    for(char c:password)
        hashed=to_string((int)c%10);
    return hashed;
}


//key for hash table which find the password stored in hashed values
int hashfunction(string username, int size){
    int sum = 0;
    for (char c : username){
        sum += c;
    }
    return sum % size;   
}

//chaining method
class HashTableChaining{
    Node**table;
    int size;
    public:
    HashTableChaining(int s) {
    size = s;
    table = new Node*[size];
    for (int i = 0; i < size; i++)
    { 
        table[i] = NULL;
    }
}
// to add the new user in the hash table
void insertUser(string username ,string password){
int index = hashfunction(username,size);// inser user at the index function
string hashed = hashedPassword(password);//to convert the password into hashed value

 Node* newNode = new Node{username, hashed, NULL};

 if (table[index] == NULL){
    table[index] = newNode;
cout<<"inserted"<<endl;
 }
 else{
    newNode->next = table[index];
    table[index] = new Node;
    cout<<"collision resolved<<"<<endl;

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


//opean addressing method
class HashTableOpen{
    
}
