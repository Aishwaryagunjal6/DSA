#include <iostream>
#include <cmath>
using namespace std;

template <class T>
class Stack;

template <class T>
class Node {
public:
    T info;
    Node<T>* next;

    Node(){
        info=0;
        next=NULL;
    }
    friend class Stack<T>;
};

template <class T>
class Stack{

public:
    Node<T>* head;

    Stack(){
        head=NULL;
    }
    bool empty();
    void push(T ele);
    void pop();
    T top();
};

template <class T>
bool Stack<T>::empty() {
    return head == nullptr;
}

template <class T>
void Stack<T>::push(T ele) {
    Node<T>* new1 = new Node<T>;
    new1->info = ele;
    new1->next = head;
    head = new1;
}

template <class T>
void Stack<T>::pop() {
    if (head == nullptr) {
        return;
    }
    Node<T>* temp = head->next;
    delete head;
    head = temp;
}

template <class T>
T Stack<T>::top() {
    return head->info;
}


class Expression {
public:
    int prec(char c) {
        if (c == '^') return 3;
        else if (c == '*' || c == '/') return 2;
        else if (c == '+' || c == '-') return 1;
        else return 0;
    }

    string reverse(string s) {
        string rev;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') rev += ')';
            else if (s[i] == ')') rev += '(';
            else rev += s[i];
        }
        return rev;
    }

    string infixToPostfix(string s) {
        Stack<char> st;
        string result;
        for (int i = 0; i < s.length(); i++) {
            if (isalnum(s[i])) {
                result += s[i];
            } else if (s[i] == '(') {
                st.push(s[i]);
            } else if (s[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                st.pop();
            } else {
                while (!st.empty() && prec(st.top()) >= prec(s[i])) {
                    result += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }

    string infixToPrefix(string s) {
        string reversed = reverse(s);
        string postfix = infixToPostfix(reversed);
        string result = reverse(postfix);
        return result;
    }

    int evaluatePostfix(string s) {
        Stack<int> st;
        for (char c : s) {
            if (isdigit(c)) {
                st.push(c - '0');
            } else {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                switch (c) {
                    case '+': st.push(op1 + op2); break;
                    case '-': st.push(op1 - op2); break;
                    case '*': st.push(op1 * op2); break;
                    case '/': st.push(op1 / op2); break;
                    case '^': st.push(pow(op1, op2)); break;
                }
            }
        }
        return st.top();
    }

    int evaluatePrefix(string s) {
        Stack<int> st;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (isdigit(s[i])) {
                st.push(s[i] - '0');
            } else {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                switch (s[i]) {
                    case '+': st.push(op1 + op2); break;
                    case '-': st.push(op1 - op2); break;
                    case '*': st.push(op1 * op2); break;
                    case '/': st.push(op1 / op2); break;
                    case '^': st.push(pow(op1, op2)); break;
                }
            }
        }
        return st.top();
    }
};

int main() {
    Expression e;
    cout << "Infix to Postfix: " << e.infixToPostfix("a+b*c-d") << endl;
    cout << "Infix to Prefix: " << e.infixToPrefix("a+b*c-d") << endl;
    cout << "Postfix Evaluation: " << e.evaluatePostfix("46+2/5*7+") << endl;
    cout << "Prefix Evaluation: " << e.evaluatePrefix("-+7*45+20") << endl;

    return 0;
}
