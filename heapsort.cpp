/*heap is a complete binary tree
max heap-> every parent having an element greater than all its decendants
min heap-> a complete binary tree satisfying the conddition that every node has elements 
smaller than all its elements
complete binary tree: every level is completely filled except the last level
nodes are always added from left to right
the index of leaf nodes in an array of heap lies from (n/2+1)to nth index where nis the size of array
timecomplexity of building a heap is O(log n)
*/
#include<iostream>
using namespace std;
class heap{
    public:
    int arr[100];
    int size=0;

    heap(){
        arr[0]=-1;
    }

   /* void insert(int val){
         size=size+1;
         int index=size;
         arr[index]=val;

         while(index>1){
            int parent=index/2;

            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
         }
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deletefromheap(){
        if(size==0){
            return;
        }
        else{
            arr[1]=arr[size];
            size--;
        }

      //take root node to its correct position
      int i=1;
      while(i<size){
        int leftindex=2*i;
        int rightindex=2*i+1;

        if(leftindex<size && arr[i]<arr[leftindex]){
            swap(arr[i],arr[leftindex]);
            i=leftindex;
        }
        else if(leftindex<size && arr[i]<arr[rightindex]){
            swap(arr[i],arr[rightindex]);
            i=rightindex;
        }
        else{
            return;
        }
      }
    }
*/
    void heapify(int arr[], int n, int i){
        int largest=i;
        int left=2*i;
        int right=2*i+1;

        if(left<=n && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<=n && arr[largest]<arr[right]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    void heapsort(int arr[], int n){
        int size=n;
        while(size>1){
            swap(arr[size], arr[1]);
            size--;

            heapify(arr,size,1);
        }
    }

    void display(int arr[], int n){
        for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    }
};
int main(){
    heap h;
   /* h.insert(50);
    h.insert(55);
    h.insert(67);
    h.insert(34);
    h.insert(90);
    h.print();
    h.deletefromheap();
    h.print();
    */
    int arr[6]={-1,56,45,89,54,23};
    int n=5;
    for(int i=n/2; i>0; i--){
        h.heapify(arr,n,i);
    }
    
    h.display(arr, n);
    
    h.heapsort(arr,n);
    cout<<"Heapsort :"<<endl;
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}