void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void minHeapify(int* arr, int pos, int size) {
    if (pos >= size) return;
    int c1 = 2 * pos + 1;
    int c2 = 2 * pos + 2;
    int smaller = pos;
    if (c1 < size && arr[c1] < arr[smaller]) smaller = c1;
    if (c2 < size && arr[c2] < arr[smaller]) smaller = c2;
    if (smaller != pos) {
        swap(arr[smaller], arr[pos]);
        minHeapify(arr, smaller, size);
    }
}

void buildHeap(int* arr, int n) {
    // Write your code
    for (int i = ((n - 1) - 1) / 2; i >= 0; i--) minHeapify(arr, i, n);
}

void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, 0, i);
    }
}