// link : https://leetcode.com/problems/sort-an-array/
// ALGO : Heap Sort

class Solution
{
    int left(int parent)
    {
        return (2 * parent + 1);
    }
    int right(int parent)
    {
        return (2 * parent + 2);
    }
    void heapify(vector<int> &arr, int i, int size)
    {
        int greater = i;
        int c1 = left(i);
        int c2 = right(i);
        if (c1 < size && arr[c1] > arr[greater])
            greater = c1;
        if (c2 < size && arr[c2] > arr[greater])
            greater = c2;
        if (greater != i)
        {
            swap(arr[greater], arr[i]);
            heapify(arr, greater, size);
        }
    }
    void buildHeap(vector<int> &arr, int size)
    {
        for (int i = (size - 2) / 2; i >= 0; i--)
            heapify(arr, i, size);
    }

public:
    vector<int> sortArray(vector<int> &arr)
    {
        buildHeap(arr, arr.size());
        for (int i = arr.size() - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, 0, i);
        }
        return arr;
    }
};