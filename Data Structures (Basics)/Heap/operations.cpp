#include <iostream>

using namespace std;

class minHeap {
private:
    int *arr;
    int capacity;
    int heap_size;
public:
    minHeap(int cap): capacity(cap), heap_size(0) {
        arr = new int[cap];
    }
    minHeap(int cap, int *arr): capacity(cap), heap_size(cap) {
        this->arr = arr;
    }

    int size() { return heap_size; }
    int get(int i) { return arr[i]; }

    int parent(int i) { return (i-1)/2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }

    void minHeapInsert(int key) {
        /**
         * Time Complexity: O(log n)
         * Auxiliary Space: O(1)
         */
        if(heap_size == capacity) {
            return;
        }
        heap_size++;
        arr[heap_size - 1] = key;
        int i = heap_size - 1;
        while(i != 0 and arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void recursiveMinHeapify(int i) {
        /**
         * Time Complexity: O(log n)
         * Auxiliary Space: O(log n)
         */
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(l < heap_size and arr[l] < arr[i]) {
            smallest = l;
        }
        if(r < heap_size and arr[r] < arr[smallest]) {
            smallest = r;
        }
        if(smallest != i) {
            swap(arr[i], arr[smallest]);
            recursiveMinHeapify(smallest);
        }
    }

    void iterativeMinHeapify(int i) {
        /**
         * Time Complexity: O(log n)
         * Auxiliary Space: O(1)
         */
        int l = left(i);
        int r = right(i);
        int smallest = i;
        while(l < heap_size or r < heap_size) {
            if(l < heap_size and arr[l] < arr[i]) {
                smallest = l;
            }
            if(r < heap_size and arr[r] < arr[smallest]) {
                smallest = r;
            }
            if(smallest != i) {
                swap(arr[i], arr[smallest]);
                i = smallest;
                l = left(i);
                r = right(i);
            }
            else {
                break;
            }
        }
    }

    int extractMin() {
        /**
         * Time Complexity: O(log n)
         * Auxiliary Space: O(1)
         */
        if(heap_size <= 0) {
            cerr << "Heap Underflow" << endl;
            return INT_MAX;
        }
        if(heap_size == 1) {
            heap_size--;
            return arr[0];
        }
        int root = arr[0];
        arr[0] = arr[heap_size - 1];
        heap_size--;
        iterativeMinHeapify(0);
        return root;
    }

    void decreaseKey(int i, int x) {
        /**
         * Time Complexity: O(log n)
         * Auxiliary Space: O(1)
         */
        arr[i] = x;
        while(i != 0 and arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i) {
        /**
         * Time Complexity: O(log n)
         * Auxiliary Space: O(1)
         */
        decreaseKey(i, INT_MIN);
        extractMin();
    }
};

minHeap buildMinHeap(int *arr, int n) {
    /**
     * Time Complexity: O(n)
     * Auxiliary Space: O(1)
     */
    minHeap heap(n, arr);
    for(int i = (n-2)/2; i >= 0; i--) {
        heap.iterativeMinHeapify(i);
    }
    return heap;
}

void descendingHeapSort(int *arr, int n) {
    /**
     * Time Complexity: O(n log n)
     * Auxiliary Space: O(1)
     */
    minHeap heap = buildMinHeap(arr, n);
    for(int i = n-1; i >= 1; i--) {
        arr[i] = heap.extractMin();
    }
}


int main() {
    int arr[7] = {10, 20, 15, 12, 40, 25, 18};
    descendingHeapSort(arr, 7);
    for(int i : arr) {
        cout << i << " ";
    }
}
