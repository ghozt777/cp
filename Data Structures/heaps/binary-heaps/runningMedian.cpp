// divide the array into two parts 
// track the max in the left half and min in the right half 
// at every step left half elements must be smaller than the right half elements



#include <iostream>
using namespace std;

#include<bits/stdc++.h>
void findMedian(int* arr, int n)
{
    // Write your code here
    if (n == 0) return;
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;
    max.push(arr[0]);
    cout << arr[0] << " ";
    for (int i = 1; i < n; i++) {
        if (arr[i] < max.top()) {
            max.push(arr[i]);
        }
        else {
            min.push(arr[i]);
        }
        if (max.size() > min.size() + 1) {
            min.push(max.top());
            max.pop();
        }
        else if (min.size() > max.size() + 1) {
            max.push(min.top());
            min.pop();
        }
        if ((max.size() + min.size()) % 2 == 0) cout << (max.top() + min.top()) / 2 << " ";
        else if (max.size() > min.size()) cout << max.top() << " ";
        else cout << min.top() << " ";
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
