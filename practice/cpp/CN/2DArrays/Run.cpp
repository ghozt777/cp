#include <iostream>
#include <cstring>
#include<string>
using namespace std;

string getCompressedString(string &str) {
    // Write your code here.
    string ans = "" ;
    int n = size(str) ;
    for(int i = 0 ; i < n ; i++){
        int s = i ;
        while(str[i] == str[i+1]) ++i ;
        if(s == i) ans += str[s] ;
        else ans += str[s] + to_string(i - s + 1);
    }
    return ans ;
}

int main() {
    int size = 1e6;
    string str;
    cin >> str;
    str = getCompressedString(str);
    cout << str << endl;
}
// a3b2cd2e5