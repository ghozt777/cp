#include<iostream>
#include<algorithm>
using namespace std;

int misplaced(string s, char check)
{
    int res = 0;
    int n = s.length();
    for(int i = 0; i < n; i += 2)
        if(s[i] != check) ++res;
    return res;
}

int solve(string s) {
    int cntB = count(s.begin(), s.end(), 'B');
    int cntG = count(s.begin(), s.end(), 'G');
    if(abs(cntB - cntG) > 1)
        return -1;
    if(cntB > cntG)
        return misplaced(s, 'B');
    else if(cntG > cntB)
        return misplaced(s, 'G');
    else
        return min(misplaced(s, 'B'), misplaced(s, 'G'));
}
int main(){

    string ip;
    cin >> ip;

    cout << solve(ip);

    return 0;
}

