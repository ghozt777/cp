#include<bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    priority_queue<pair< int, pair<int, int>>, vector<pair< int, pair<int, int>> >, greater<pair< int, pair<int, int>> >> pq;
    int k = input.size();
    for (int i = 0; i < k; i++) {
        pq.push(make_pair(input[i]->at(0), make_pair(i, 0)));
    }
    vector<int> res;
    while (!pq.empty()) {
        pair<int, pair<int, int>> toAdd = pq.top();
        pq.pop();
        res.push_back(toAdd.first);
        if (toAdd.second.second + 1 < input[toAdd.second.first]->size()) pq.push(make_pair(input[toAdd.second.first]->at(toAdd.second.second + 1), make_pair(toAdd.second.first, toAdd.second.second + 1)));
    }
    return res;
}

int main() {
    int k;
    cin >> k;

    vector<vector<int>*> input;

    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int>* current = new vector<int>;

        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}