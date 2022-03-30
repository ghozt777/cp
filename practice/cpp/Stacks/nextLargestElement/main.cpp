#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi ip(){
    int n;
    cin >> n;
    vi arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    return arr;
}

void bruteforce(vi& arr){
    const int n = arr.size();
    vi res(n);
    for(int i = 0; i < arr.size() - 1; i++){
        for(int j = i + 1; j < arr.size(); j++) if(arr[j] > arr[i]){ res[i] = arr[j]; break; }
    }
    res[arr.size() - 1] = -1;
    cout << "ans: ";
    for(int x : res) cout << x << " ";
}

void efficient(vi& arr){
    const int n = arr.size();
    stack<int> s;
    vi res(n);
    res[n - 1] = -1;
    for(int i = n - 1; i >= 0; --i){
        if(s.empty()) res[i] = -1;
        else {
            if(s.top() > arr[i]) res[i] = s.top();
            else{
                while(s.top() < arr[i]){
                    s.pop();
                    if(s.empty()) break;
                }
                res[i] = s.empty() ? -1 : s.top();
            }
        }
        s.push(arr[i]);
    }
    cout << "ans(eff): ";
    for(int x : res) cout << x << " ";
    cout << endl;
}


int main(){
    vi arr = ip();
    efficient(arr);
    bruteforce(arr);
    return 0;
}