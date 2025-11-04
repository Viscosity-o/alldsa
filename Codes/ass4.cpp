//Roll no 23313\
//Conversion and Evaluation of Expressions


#include <iostream> 
#include <stack>
#include <string>
#include <cmath>
using namespace std;


int precedance(char op) {
    if (op == '+' || op == '-') return 1;  // Lowest precedence
    if (op == '*' || op == '/') return 2;  // Medium precedence
    if (op == '^') return 3;               // Highest precedence (exponent)
    return 0;
}


int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;    // Addition
        case '-': return a - b;    // Subtraction
        case '*': return a * b;    // Multiplication
        case '/': return a / b;    // Division
        case '^': return pow(a, b); // Exponentiation
        default: return 0;
    }
}


int evaluate(string Postfix) {
    stack<int> valStack;                     // Stack to hold operands during evaluation
    
    for (char token : Postfix) {
        // If the character is an operand
        if (isalnum(token)) {
            int value;
            cout << "Enter value of " << token << ": ";
            cin >> value;
            valStack.push(value);                // Push its value onto stack
        } 
        else { 
            // Otherwise, the character is an operator
            int val2 = valStack.top(); valStack.pop();                   // Get 2nd operand
            int val1 = valStack.top(); valStack.pop();                 // Get 1st operand
            int result = applyOp(val1, val2, token);                 // Perform operation
            valStack.push(result);                                    // Push result back
        }
    }
    return valStack.top();                                 // Final result on top of stack
}

int main() {
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;

    stack<char> st;                                 // Stack to hold operators
    string postfix = " ";                          // String to store postfix result

    // Convert Infix → Postfix using stack
    for (char token : infix) {
        if (isalnum(token)) {
            // If operand, add directly to postfix
            postfix = postfix + token;
        } 
        else if (token == '(') {
            // Push '(' to stack
            st.push(token);
        } 
        else if (token == ')') {
            // Pop until '(' is found
            while (!st.empty() && st.top() != '(') {
                postfix = postfix + st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // Remove '('
        } 
        else {
            // If operator, pop from stack until lower precedence found
            while (!st.empty() && precedance(token) <= precedance(st.top())) {
                postfix = postfix + st.top();
                st.pop();
            }
            st.push(token);                               // Push current operator
        }
    }

    // Pop remaining operators from stack
    while (!st.empty()) {
        postfix = postfix + st.top();
        st.pop();
    }

    cout << "Postfix Expression is: " << postfix << endl;

    // Evaluate the postfix expression
    int result = evaluate(postfix);
    cout << "Result of evaluation: " << result << endl;

    return 0;
}