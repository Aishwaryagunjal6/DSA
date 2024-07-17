#include<iostream>
using namespace std;

class ciruclarq{
    public:
    int r,f,key,size;
    int*arr;
    
    ciruclarq(){
        f=r=-1;
        size=5;
        arr= new int[size];
    }
    
    bool isfull(){
        if((f==0 && r==size-1) || (r==(f-1)%(size-1))){
            cout<<"its full"<<endl;
            return true;
        }
        else{
            return false;
        }
    }
    bool isempty(){
        if(f==-1 && r==-1){
            cout<<"its empty"<<endl;
            return true;
        }
        else{
            return false;
        }
    }
    
    void enqueue(int val){
        if((f==0 && r==size-1) || (r==(f-1)%(size-1))){
            cout<<"que is full . ";
        }
        else if(f==-1 && r==-1){
            f=0;
            r=0;
            arr[r]=val;
        }
        else if(f!=0 && r==size-1){
            r=0;
            arr[r]=val;
        }
        else{
            r++;
            arr[r]=val;
        }
    }
    
    void dequeue() {
    if (f==-1) {
        cout << "Queue is empty." << endl;
    }
    else if (f == r) {
        int ans = arr[f];
        f = r = -1;
        cout << "Dequeue: " << ans << endl;
    } else if (f == size - 1) {
        int ans = arr[f];
        f = 0;
        cout << "Dequeue: " << ans << endl;
    } else {
        int ans = arr[f];
        arr[f] = NULL;
        f++;
        cout << "Dequeue: " << ans << endl;
    }
    }

    void display(){
       if(f==0){
           int i=f;
           while(i<=r){
            cout<<arr[i];
            i++;
           }
       }
       else if(f!=0){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
       }
    }
    
};

int main(){
    ciruclarq q;
    int ch=0;
    while(ch<6&&ch>=0){
    cout<<"Enter 1 to enqueue"<<endl;
    cout<<"Enter 2 to dequeue"<<endl;
    cout<<"Enter 3 to display"<<endl;
    cout<<"Enter 4 to check empty"<<endl;
    cout<<"Enter 5 to check full"<<endl;
    cout<<"Enter 6 to exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch){
        case 1:
        for(int i=1; i<=5; i++ ){
        int val;
        cout<<"Enter number "<<i<<" : ";
        cin>>val;
        q.enqueue(val);
        }
        break;
        
        case 2:
        q.dequeue();
        break;

        case 3:
        q.display();
        break;
        
        case 4:
        q.isempty();
        break;
        
        case 5:
        q.isfull();
        break;
        }
    }
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
