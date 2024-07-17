#include<iostream>
using namespace std;
template <class T>
class stack;

template <class T>
class Node{
    public:
    T info;
    Node<T>* next;
    Node(){
        info=0;
        next=NULL;
    }
    
};

template <class T>
class stack{
    public:
    Node<T>* head;
    stack(){
        head=NULL;
    }
    
    bool empty();
    void push(T ele);
    void pop();
    T top();
};

template <class T>
bool stack<T> :: empty(){
    return head==NULL;
}

template <class T>
void stack<T> :: push(T ele){
    Node<T>* n= new Node<T>;
    n->info=ele;
    n->next=head;
    head=n;
}

template<class T>
void stack<T> :: pop(){
    if(head==NULL){
        return;
    }
    Node<T>* temp=head->next;
    delete head;
    head=temp;
}

template <class T>
T stack<T> :: top(){
    return head->info;
}


class node{
    public:
    char data;
    node* left;
    node* right;
    node(char c){
        data=c;
        left=NULL;
        right=NULL;
    }
};

class express{
    public:
    
    node* createfromPost(string s){
        node* root=NULL;
        stack<node*> st;
        for(int i=0; i<s.length(); i++){
            node* tree= new node(s[i]);
            if(isalpha(s[i])){
                st.push(tree);
            }
            else{
                tree->right=st.top();
                st.pop();
                tree->left=st.top();
                st.pop();
                st.push(tree);
            }
        }
        root=st.top();
        return root;
    }
    
    void Rinorder(node* root){
        if(root==NULL){
            return;
        }
        Rinorder(root->left);
        cout<<root->data<<" ";
        Rinorder(root->right);
    }
    
    void Rpreorder(node* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        Rpreorder(root->left);
        Rpreorder(root->right);
    }
    
    void Rpostorder(node* root){
        if(root==NULL){
            return;
        }
        Rpostorder(root->left);
        Rpostorder(root->right);
        cout<<root->data<<" ";
    }
    
    void inorder(node* root){
        stack<node*> st;
        node* current=root;
        while(current!=NULL || !st.empty()){
            while(current!=NULL){
                st.push(current);
                current=current->left;
            }
            current=st.top();
            st.pop();
            cout<<current->data<<" ";
            current=current->right;
        }
    }
    
    void preorder(node* root){
        stack<node*> st;
        node* current=root;
        while(current!=NULL || !st.empty()){
            while(current!=NULL){
                cout<<current->data<<" ";
                st.push(current);
                current=current->left;
            }
            current=st.top();
            st.pop();
            current=current->right;
        }
    }
    
    void postorder(node* root){
        stack<node*> p1;
        stack<node*> p2;
        node* current=root;
        p1.push(current);
        while(!p1.empty()){
            current=p1.top();
            p1.pop();
            p2.push(current);
            if(current->left){
                p1.push(current->left);
            }
            if(current->right){
                p1.push(current->right);
            }
        }
        
        while(!p2.empty()){
            current=p2.top();
            p2.pop();
            cout<<current->data<<" ";
        }
    }
};

int main(){
    express e;
    node* root=NULL;
    cout<<"Enter string: ";
    string s;
    cin>>s;
    root=e.createfromPost(s);
    e.Rinorder(root);
    cout<<endl;
    e.Rpreorder(root);
    cout<<endl;
    e.Rpostorder(root);
    cout<<endl;
    e.inorder(root);
    cout<<endl;
    e.preorder(root);
    cout<<endl;
    e.postorder(root);
}











