#include <iostream>
using namespace std;
struct node
{
    struct node *left;
    struct node *right;
    int data;
    int lth;
    int rth;
};
class tbtree
{
public:
struct node *head;
struct node *dummy;
struct node *New;
    struct node *makenode(int key);
    void insert(node* head,node* New);
    void displayin(node *temp,node *dummy);
    void displaypre(node *temp,node *dummy);
};
struct node *tbtree::makenode(int key)
{
    struct node *p;
    p = new node;
    p->left = NULL;
    p->right = NULL;
    p->lth = 0;
    p->rth = 0;
    p->data = key;
        return p;
}
void tbtree::insert(node* head,node* New)
{
    if(head==NULL){dummy=makenode(-999);}
        if(New->data<head->data){
            if(head->lth==0){
                New->left=head->left;
                New->right=head;
                head->left=New;
                head->lth=1;
            }
            else{
                insert(head->left,New);
            }
        }
        else if(New->data>head->data){
            if(head->rth==0){
                New->right=head->right;
                New->left=head;
                head->right=New;
                head->rth=1;
            }
            else{
                insert(head->right,New);
            }
        }
}
void tbtree::displayin(node *head,node *dummy)
{
    while(head!=dummy && head)
    {
        while(head->lth==1)
        {
            head=head->left;
        }
        cout<<head->data<<endl;
        while(head->rth==0)
        {
            head = head->right;
            if(head==NULL)
                return;
            cout<<head->data<<endl;
        }
        head = head->right;
    }
}
void tbtree::displaypre(node *temp,node *dummy)
{
    bool flag =false;
    while(temp!=dummy&& temp)
    {
        if(!flag)
           cout<<temp->data<<endl;
        if((temp->lth==1)&&(!flag)){
            temp=temp->left;
        }
        else{
            while(1){
                if(temp->rth==1){
                    flag=false;
                    temp=temp->right;
                    break;
                }
                else{
                    if(temp!=NULL){
                        flag=true;
                        temp=temp->right;
                        break;
                    }
                }
            }
        }
    }
}
int main()
{
    tbtree t;
    int a,b,v;
    cout<<"Enter the root value : ";
    cin>>a;
    t.head=t.makenode(a);
    cout << "Enter of How many elements do u want a tree : ";
    int c;
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        cout << "Elements : "<<i+1<<" : ";
        cin>>v;
        t.New=t.makenode(v);
        t.insert(t.head,t.New);
    }
    bool res=true;
    while(res){
        cout << "Choose Your Traversal :" << endl;
        cout << "1]Inorder Traversal:" << endl;
        cout << "2]Preorder Traversal" << endl;
        cout << "3]Exit" << endl;
        cout<<"Enter the choice : ";
        cin>>b;
        switch(b){
            case 1:
               cout<<"Inorder Transveral : "<<endl;
               t.displayin(t.head,t.dummy);
               break;
            case 2:
            cout<<"Preorder Transveral : "<<endl;
               t.displaypre(t.head,t.dummy);
               break;
            case 3:
               cout<<"Thank You"<<endl;
               res=false;
               break;
            default:
               cout<<"INVALID CHOICE"<<endl;
               break;
        }
    }
    return 0;
}

