#include<iostream>
using namespace std;

class heap {
public:
    int* arr;
    int size;

    heap() {
        arr = new int[100];
        size = 0;
    }

    void heapify(int arr[], int n, int i) {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= n && arr[largest] < arr[left]) {
            largest = left;
        }
        if (right <= n && arr[largest] < arr[right]) {
            largest = right;
        }
        if (largest != i) {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    void heapsort(int arr[], int n) {
        size = n;
        for (int i = n / 2; i >= 1; i--) {
            heapify(arr, n, i);
        }
        while (size > 1) {
            swap(arr[size], arr[1]);
            size--;
            heapify(arr, size, 1);
        }
    }

    void display(int arr[], int n) {
        for (int i = 1; i <= n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    heap h;
    int n, v;
    cout << "Enter size: ";
    cin >> n;
    int arr[n + 1];
    arr[0] = -1;
    for (int i = 1; i <= n; i++) {
        cout << "Enter data: ";
        cin >> v;
        arr[i] = v;
    }

    h.heapsort(arr, n);
    
    cout << "Heapsort: ";
    h.display(arr, n);

    return 0;
}
