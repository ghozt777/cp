#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi merge(vi& a, vi& b){
    vi c(a.size() + b.size());
    int i = 0, j = 0, k = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] <= b[j]) c[k++] = a[i++];
        else c[k++] = b[j++];
    }
    while(i < a.size()) c[k++] = a[i++];
    while(j < b.size()) c[k++] = b[j++];
    return c;
}

double bruteForce(vi a, vi b){
    vi c = merge(a, b);
    double res = c.size() % 2 == 0 ? (double)(c[c.size() / 2] + c[c.size() / 2 - 1]) / 2 : (double)c[c.size() / 2];
    return res;
}

double binarySearch(vi a, vi b){
    int n1 = a.size();
    int n2 = b.size();
    int start = 0;
    int end = a.size();
    while(start <= end){
        int cut1 = start + (end - start) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;
        int l1 = cut1 > 0 ? a[cut1 - 1] : INT_MIN;
        int l2 = cut2 > 0 ? b[cut2 - 1] : INT_MIN;
        int r1 = cut1 < n1 ? a[cut1] : INT_MAX;
        int r2 = cut2 < n2 ? b[cut2] : INT_MAX;
        if(l1 > r2) end = cut1 - 1;
        else if(l2 > r1) start = cut1 + 1;
        else{
            if((n1 + n2) % 2 == 0) return (double)(max(l1, l2) + min(r1, r2)) / 2;
            else return (double)max(l1, l2);
        }
    }
    return 0.00;
}

int main(){
    int n1, n2;
    cin >> n1;
    cin >> n2;
    vi a(n1);
    vi b(n2);
    for(int i = 0; i < n1; i++) cin >> a[i];
    for(int i = 0; i < n2; i++) cin >> b[i];
    cout << "ans(brute force -> O(m + n)): " << bruteForce(a, b) << endl;
    cout << "ans(binary search -> O(log(m + n))): " << binarySearch(a, b);
    return 0;
}