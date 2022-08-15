#include<bits/stdc++.h>
using namespace std;

string tostring(int a){
    char x=a;
    string s(1,x);
    return s;
}

int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        string x;
        if((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122)){
         if(s[i]<97){
                if(s[i]<='M')x=tostring(s[i]+13);
                else x=tostring(s[i]-13);
         }else{
                if(s[i]<='m')x=tostring(s[i]+13);
                else x=tostring(s[i]-13);
            }
        }
        else x=s[i];
        cout<<x;
    }
}
