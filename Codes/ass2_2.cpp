//Roll no 23313
/*"Implementing Queues and Stacks Using Linked Lists for Real-World Task Management
Systems"*/

#include<iostream>
using namespace std;
typedef struct Node{
    string name;                //Title of task
    float time;                 //Time req to complete the task
    struct Node *next;          //pointer to next node
}NODE;

class Task{
    NODE *top;                  //pointer to topmost node
    public:
    Task(){top = NULL;}        //Constructor to initialize top to NULL
    void Mpush();
    int IsEmpty();
    void Mpop();
    void MPeek();
    NODE *getnode();

};
//Function to check if stack is empty
int Task::IsEmpty(){
    if(top == NULL){            //check if top is NULL
        return 1;
    }else{
        return 0;
    }
}

NODE *Task::getnode(){
    NODE *temp = new(NODE);             //new memory allocation
    cout<<"Enter name of task:";
    cin>>temp->name;                       //input title
    cout<<"Enter time required:";
    cin>>temp->time;                        //Input time req in hrs
    temp->next=NULL;
    return temp;
}
//Functon to puch the node into the stack
void Task::Mpush(){
    NODE *temp;                     
    temp = getnode();                       //Getting a new node
    temp->next = top;                       //link new node's next to current top node
    top = temp;                             //update top
}

void Task::Mpop(){
    int var;
    var = IsEmpty();                        //check if stack is empty
    if(var == 0){                            //if stack is not empty delete topmost node
        NODE *temp;
        temp = top;
        top = top->next;
        delete(temp);
        cout<<"Data at the top is deleted"<<endl;
    }else{
        cout<<"The list is empty"<<endl;
    }
}

void Task::MPeek(){
    if(!IsEmpty()){                         //if stack is not empty display data fro topmost node
        cout<<"The name of task is: "<<top->name<<"; Time required: "<<top->time;
    }else{
        cout<<"The list is empty"<<endl;
    }
}
int main(){
    Task t;
    int choice;
    while(true){
    cout<<"\nEnter Choice\n1.Push\n2.Pop\n3.Peek\n4.exit\n";
    cin>>choice;

switch (choice){
case 1:
    t.Mpush();
    break;
case 2:
    t.Mpop();
    break;
case 3:
    t.MPeek();
    break;
case 4:
    return 0;    
default:
    cout<<"Invalid Choice";
    break;
    }
}
}
