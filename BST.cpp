#include<iostream>
#include<queue> 
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

class bst{
    public:
    
    node* insert(node* root, int data){
        if(root==NULL){
            root=new node(data);
            return root;
        }
        if(root->data > data){
            root->left=insert(root->left, data);
        }
        if(root->data < data){
            root->right=insert(root->right, data);
        }
        return root;
    }
    
    void input(node* &root){
        int data;
        cout<<"Enter data: ";
        cin>>data;
        while(data!=-1){
            root=insert(root, data);
            cin>>data;
        }
    }
    
    void lvlorder(node* root){
        if(root==NULL){
            return;
        }
        queue<node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            node* temp=q.front();
            q.pop();
            if(temp==NULL){
                cout<<endl;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                cout<<temp->data<<" ";
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
    }    
        
        int height(node* root){
            if(root==NULL){
                return 0;
            }
            
            int left=height(root->left);
            int right=height(root->right);
            
            int ans=max(left,right)+1;
            
            return ans;
        }
        
        bool search(node* root, int data){
            if(root==NULL){
                return false;
            }
            else if(root->data==data){
                return true;
            }
            else if(root->data > data){
                return search(root->left, data);
            }
            else{
                return search(root->right, data);
            }
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
        
        
        
    void leaf(node* root){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            cout<<root->data<<" ";
        }
        leaf(root->left);
        leaf(root->right);
    }

    int countn(node* root, int &count){
    if(root==NULL){
        return 0;
    }
    countn(root->left, count);
    count++;
    countn(root->right, count);
    return count;
}
};

int main(){
    node* root=NULL;
    bst b;
    b.input(root);
    cout<<"LVL: "<<endl;
    b.lvlorder(root);
    cout<<endl;
    int count=0;
    cout<<"Number of nodes :"<<b.countn(root, count);
    cout<<"height: "<<b.height(root)<<endl;
    cout<<"Enter ele to search: ";
    int d;
    cin>>d;
    cout<<"Element found: "<<b.search(root, d)<<endl;
    b.Rinorder(root);
    cout<<endl;
    b.Rpreorder(root);
    cout<<endl;
    b.Rpostorder(root);
    cout<<endl<<"leaf: ";
    b.leaf(root);
}

















