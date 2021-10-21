#include<bits/stdc++.h>
using namespace std;
// #define IN insert 
#define IN emplace // emplace is faster than insert

void Run();
void PrintNotes();
void Unique();
void EraseMoreThanOne();
void EraseUsingKey();
void Unordered();
void MultiSet();
set<int> Erase(set<int>);

int main() {
  Run();
  PrintNotes();
  return 0;
}

void Run() {
  Unique();
  EraseMoreThanOne();
  EraseUsingKey();
  Unordered();
  MultiSet();
}

void Unique() { // counts the number of quique of elements 
  set<int> s;
  int x;
  int n;
  cout << "Enter the number of elements (n): ";
  cin >> n;
  for(int i = 1 ; i <= n ; i++){
    cin >> x;
    s.IN(x); // insert takes log(n) time [n = size of set]
  }
  cout << "\nThere are " << s.size() << " unique elements : \n";
  cout << "\t";
  for(auto v = s.begin() ; v != s.end() ; v++)
    cout << *v << ", " ;
  cout << "\nProcess to erase started";
  char choice = 'y' ;
  while(choice == 'y' || choice == 'Y'){
    cout << "\nEnter (y to continue n to quit): ";
    cin >> choice;
    while(!(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N' )){
      cout << "\nwrong i/p ! (re-enter y/n) : ";
      cin >> choice;
    }
    if(choice == 'n' || choice == 'N') break;
    s = Erase(s);
  } 

}

set<int> Erase(set<int> s) {
  // this function erases the first element of the set
  if(s.size() == 0 ){
    cout << "\n Can't erase from an empty set";
    return s;
  }
  cout << "\n1st Element before erase : " << *s.begin() ;
  s.erase(s.begin());
  if(s.size() == 0 ){
    cout << "\nThe set is now empty";
    return s;
  }
  cout << "\nFirst Element after erase : " << *s.begin();
  return s;
}

void EraseMoreThanOne() {
  set<int> s ; 
  for(int i = 0 ; i <= 12 ; i++ ){
    s.IN(i);
    // this is to replicate redundant elements
    s.IN(i);
    s.IN(i);
    s.IN(i);
    s.IN(i);
  }
  cout << "\nSet before Erasing: \n";
  for(auto x = s.begin() ; x != s.end() ; x++){
    cout << *x << " ";
  }
  set<int>::iterator itr; // creating a variable of type set iterator
  itr = s.end();
  --itr;
  --itr;
  --itr; 
  s.erase(s.begin() , itr);// erasing format: erase(inclusive , exclusive)
  cout << "\nSet after Erasing: \n";
  for(auto x = s.begin() ; x != s.end() ; x++){
    cout << *x << " ";
  }
}


void EraseUsingKey() {
  cout << "\n\nErasing using Key : \n";
  set<int> s = {1,2,3,4,5};
  int key = 3 ;
  cout << "\nset : " ;
  for(auto x = s.begin() ; x != s.end() ; x++)
    cout << *x << " ";
  cout << "key : " << key << "\n";

  s.erase(key);

  cout << "after deletion : ";
  cout << "\nset : " ;
  for(auto x = s.begin() ; x != s.end() ; x++)
    cout << *x << " ";
}


void Unordered(){
  cout << "\nunorderd set : \n";
  unordered_set<int> us;
  set<int> s;
  us.IN(1); 
  us.IN(2);
  us.IN(3);
  s.IN(3);
  s.IN(2);
  s.IN(1);
  for(auto x = us.begin() ; x != us.end() ; x++)
    cout << *x << " ";
  cout << "\nhere is a normal set : \n"; // as from the output it sotres the result in a sorted fashion
  for(set<int>::iterator x = s.begin() ; x != s.end() ; x++){
    cout << *x << " ";
  }
}

void MultiSet(){
  cout << "\nmultiset stores redundant elements in sorted fashion\n";
  multiset<int> ms;
  ms.IN(3);
  ms.IN(2);
  ms.IN(1);
  ms.IN(1);
  ms.IN(2);
  ms.IN(1);
  for(multiset<int>::iterator x = ms.begin() ; x != ms.end() ; x++)
    cout << *x << " ";
  // to erase limited instances of an element
  // here as an example I am deleting first two instances of '1'
  multiset<int>::iterator itr = ms.find(1); // you can also use auto as the datatype , I am using this for clarity
  itr++;
  itr++;
  ms.erase(ms.find(1) , itr);
  cout << "\nafter deleting two instances of 1 the multiset becomes:\n";
  for(multiset<int>::iterator x = ms.begin() ; x != ms.end() ; x++)
    cout << *x << " ";
  /* this syntax can also be used to print the elements
  for (auto x : ms)
    cout << x << " ";
  */
}



void PrintNotes() {
  cout << "\n\n\n\n----------------NOTES : -------------\n";
  cout << "A SET ONLY STORES UNIQUE ELEMENTS IN A SORTED FASHION. Interally they use BSTs\n";
  cout << "\n\t1> TIME COMPLEXITY TO INSERT: log(n) , where n is the size of the set -> this is because the height of the tree is log(n)";
  cout << "\n\n\t2> ACCESS TO ELEMENTS:  to access elements inside a set we cannot use something like s[0] : we need to use iterators to access elements inside a set";
  cout << "\n\n\t3> Erase : To erase a single element use s.erase(set<int>::iterator) and to erase in a range use : erase(set<int>::iterator , set<int>::iterator) the first argument is inclusive and the second one is exclusive i.e. [) Time Complexity : log(n) n = length of the deleted elements, also to Erase Using key foramt : .erase(key)";
  cout << "\n\n\t4> .find(key) returns iterator to the location of the key , Time Complexity : log(n) Note: If the key is not preset it returns s.end() which points to the location right after the last element in the set";
  cout << "\n\n\t5> Unordered Set: all the above operations were performed on a ordered set, but there is something known as 'unordered set' . The difference between unorder set and ordered set is that in unordered set the average time complexity is O(1) or constant time whereas for ordered set it is log(n), but the worst case in linear or O(n) where n is the size of the set.";
  cout << "\n\n\t6> In cases where there is no requirement to have a sorted set use the unsorted_set as almost in all cases it takes O(1) time. In case you get a TLE(Time Limit Error) use set.";
  cout << "\n\n\t7> Multi Sets allow to store multiple instances of the element in a sorted fashion.";
}
