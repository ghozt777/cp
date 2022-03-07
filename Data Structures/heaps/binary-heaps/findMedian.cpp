#include<bits/stdc++.h>
using namespace std;
void findMedian(int* arr, int n)
{
    // Write your code here
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    for (int i = 0; i < n; i++) {
        max_pq.push(arr[i]);
        min_pq.push(arr[i]);
        int median = floor((max_pq.top() + min_pq.top()) / 2);
        cout << median << endl;
    }
}



int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr, n);

    delete[] arr;
}
