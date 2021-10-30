
// link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;
typedef map<string , int> msi;

#define IN emplace
#define PBK pop_back
#define PB push_back
#define MP make_pair
#define f(n) for(int i = 0 ; i < n ; i++)
#define fr(itr, n) for(int itr = 0 ; itr < n ; itr++)


  vector<string> util(string p , string up) {
  if(size(up) == 0) {
    vector<string> last ;
    last.push_back(p) ;
    return last;
  }
  int digit = up[0] - '0' ;
  vector<string> ans ;
  for(int i = 0 ; i < 4 ; i++) {
    if(digit < 7) {
      if(i == 3) break ;
      char ch = 'a' + ((digit - 2)*3 + i) ;
      vector<string> ret = util(p + ch , up.substr(1)) ;
      ans.insert(ans.end() , ret.begin() , ret.end()) ; 
    }
    else if(digit == 7) {
      char ch = 'a' + (15 + i) ;
      vector<string> ret = util(p + ch , up.substr(1)) ;
      ans.insert(ans.end() , ret.begin() , ret.end()) ;
    }
    else if(digit == 8){
      if(i == 3) break ;
      char ch = 'a' + (19 + i) ;
      vector<string> ret = util(p + ch , up.substr(1)) ;
      ans.insert(ans.end() , ret.begin() , ret.end()) ;
    }
    else {
      char ch = 'a' + (22 + i) ;
      vector<string> ret = util(p + ch , up.substr(1)) ;
      ans.insert(ans.end() , ret.begin() , ret.end()) ;
    }
  }
  return ans ;
}
    vector<string> letterCombinations(string digits) {
        if(digits == ""){
    vector<string> shit ;
    return shit ;
  }
        return util("" , digits) ;
}



void Run();


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
	// run your code here
	string digits ;
	cin >> digits ;
	vector<string> ans = letterCombinations(digits) ;
	// printing the ans ;
	for(vector<string>::iterator x  = ans.begin() ; x != ans.end() ; x++)
		cout << *x << "\n" ;

	return ;
}


