#include<bits/stdc++.h>
using namespace std;
// #define PB push_back 
#define PB emplace_back // emplace_back and push_back are identical in their functionality diff is that emplace_back takes lesser time 
#define PBK pop_back
#define f(n) for(int i = 0 ; i < n ; i++)
#define fr(itr, n) for(int itr = 0 ; itr < n ; itr++)
void Run();
void PushPop();
void Clear();
void Construct();
void _2DVectors();
void Triangle();
void BullShitCode();

typedef vector<int> vi;
typedef vector<vi> vii;

int main(){
  Run();
  return 0;
}

void Run(){
  cout << "\n Some of the functions that vectors provide are : \n";
  PushPop();
  Clear();
  Construct();
  _2DVectors();
}

void PushPop(){
  cout << "push_back() and pop_back() : \n";
  vector<int> arr;
  for(int i = 0 ; i < 5 ; i++)
  {  arr.PB(i); cout << arr.size(); cout << "\n"; }
  for(int i = 0 ; i < 5 ; i++)
  {  arr.PBK(); cout << arr.size(); cout << "\n"; }
}

void Clear() {
  cout << "\nclear() : \n";
  vi arr;
  for(int i = 0 ; i < 5 ; i++){
    arr.PB(i);
  }
  cout <<"initial size : " << arr.size() << "\n";
  arr.clear();
  cout << "size after clear : " << arr.size() << "\n";
}

void Construct() {
  cout << "creating vectors with an inital size and value \n";
  vi arr(10, 69); // (intial_size , initial_value)
  for(int x : arr)
    cout << x <<" " ;
  cout << "\n";
  cout << "creating a copy of the first vector\n";
  // using pointers
  vi v(arr.begin() , arr.end());
  for(int x : v)
    cout << x <<" " ;
  cout << "\n";
  cout << "another approach to create a copy of the first vector\n";
  vi v1(v);
  for(int x : v1)
    cout << x <<" " ;
  vi nums;
  cout << "\nOG Copy : \n";
  for(int i = 1 ; i < 10 ; i++)
    nums.PB(i);
  for (int x : nums)
    cout << x << " ";
  cout << "\n";
  cout << "subset of OG: \n";
  vi subNums(nums.begin() + 2 , nums.end() - 3);
  for(int x : subNums)
    cout << x << " ";
  vi numsRev(nums.rbegin() , nums.rend());
  cout << "\nreversed OG: \n";
  for(int x : numsRev)
    cout << x << " ";

}

void _2DVectors() {
  cout << "\n2D vectors: \n";
  // way 1 
  vector<vector<int>> v;
  vi v1;
  for(int i = 0 ; i < 5 ; i++)
    v1.PB(i);
  vi v2;
  for(int i = 5 ; i < 12 ; i++)
    v2.PB(i);
  v.PB(v1);
  v.PB(v2);
  for(vi x : v)
    {for(int y : x)
      cout << y << " " ;cout << "\n";}
  Triangle();
  BullShitCode();
}

void Triangle(){
  vector<vi> t;
  int n ; 
  // cout << "\nn ? : "; 
  // cin >> n; 
  n = 10;
  fr(k,n){
    vi v;
    f(k)
      v.PB(i);
    t.PB(v);
    v.clear();
  }
  for(vi v : t){
    for(int x : v)
      cout << x << " ";
    cout << "\n";
  }
  cout << "\nusing pointers in 2D vector to print: \n";
  for(auto v = t.begin() ; v < t.end() ; v++){
    for(auto itr = (*v).begin() ; itr < (*v).end() ; itr++){
      cout << *itr <<  " ";
    }
    cout << "\n";
  }
}

void BullShitCode(){
  cout << "\nUsing constructor for 2D vector (10x20)\n";
  vii v(10 , vi(20 , 0));
  cout << "\tsize of external vector : " << v.size() << "\n";
  cout << "\tsize of interval vector : " << v[0].size() << "\n";
}