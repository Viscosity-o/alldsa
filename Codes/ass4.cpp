#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// ✅ Function to convert INFIX → POSTFIX
string convertToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (char token : infix) {
        // If operand → directly add
        if (isalnum(token)) {
            postfix += token;
        }
        // If '(' push in stack
        else if (token == '(') {
            st.push(token);
        }
        // If ')' pop until '('
        else if (token == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Remove '('
        }
        // If operator
        else {
            while (!st.empty() && precedence(token) <= precedence(st.top())) {
                postfix += st.top();
                st.pop();
            }
            st.push(token);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

// ✅ Evaluate postfix
int evaluate(string postfix) {
    stack<int> st;

    for (char token : postfix) {
        // Operand → convert char to integer and push
        if (isdigit(token)) {
            st.push(token - '0'); // char → integer
        }
        else {
            int op2 = st.top(); st.pop();
            int op1 = st.top(); st.pop();
            int result;

            if (token == '+') result = op1 + op2;
            else if (token == '-') result = op1 - op2;
            else if (token == '*') result = op1 * op2;
            else if (token == '/') result = op1 / op2;

            st.push(result);
        }
    }

    return st.top();
}

int main() {
    string infix;

    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = convertToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    int result = evaluate(postfix);
    cout << "Result of Evaluation: " << result << endl;

    return 0;
}
