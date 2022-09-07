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
        if(heap_size == 0) {
            cerr << "Heap is empty";
            return INT_MAX;
        }
        int x = arr[0];
        swap(arr[0], arr[heap_size - 1]);
        heap_size--;
        iterativeMinHeapify(0);
        return x;
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