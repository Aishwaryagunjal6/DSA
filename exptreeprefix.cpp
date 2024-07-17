#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

class node {
public:
    char data;
    node* left;
    node* right;

    node(char s) {
        data = s;
        this->right = NULL;
        this->left = NULL;
    }
};

class expres {
public:
    node* root = NULL;
    stack<node*> st;

    node* createPrefix(string s) {
        for (int i = s.length() - 1; i >= 0; i--) {
            node* tree = new node(s[i]);
            if (isalpha(s[i])) {
                st.push(tree);
            } else {
                tree->left = st.top();
                st.pop();
                tree->right = st.top();
                st.pop();
                st.push(tree);
            }
        }
        root = st.top();
        return root;
    }

};

int main() {
    string s;
    expres e;
    node* root = NULL;

    cout << "Enter your expression : ";
    cin >> s;
    cout << endl;

    root = e.createPrefix(s);

    cout << "Postfix is :";
    e.postorder(root);
    cout << endl;
    cout << "Prefix is :";
    e.prerder(root);
    cout << endl;
    cout << "Inorder is :";
    e.inorder(root);
    cout << endl;
    cout << "nonrec inorder: ";
    e.Rinorder();
    cout << endl;
    cout << "nonrec preorder: ";
    e.Rpreorder();
    cout << endl;
    cout << "nonrec postorder: ";
    e.Rpostorder();

    return 0;
}
