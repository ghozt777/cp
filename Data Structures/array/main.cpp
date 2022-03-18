#include<bits/stdc++.h>
using namespace std;
void Fill();
void At();
void Other();
void Iterator();
array<int, 10> global;
int globalArr[10];
int main() {
  array<int, 10> n = { 1 }; // adding the first element causes the remaining elemets to be initialized with zerores , otherwise if the array is defined inside any scope other than the global scope causes it to be filled with garbage values
  array<char, 10> local;
  int localArr[10];
  cout << "local with first element initialized: ";
  for (int x : n)
    cout << x << " ";
  cout << "\n";
  cout << "global with no element initialized ";
  for (int g : global)
    cout << g << " "; // 0s
  cout << "\n";
  cout << "local with no element initialized : ";
  for (char c : local)
    cout << c << " "; // garbage
  cout << "\n";
  cout << "normal global array : ";
  for (int g : globalArr)
    cout << g << " ";
  cout << "\n";
  cout << "normal local array : ";
  for (int x : local)
    cout << x << " ";
  // array with some values initialized 
  array<int, 6> arrSome = { 3,2,1 };
  cout << "\n Array with the first three values initialized : ";
  for (int x : arrSome)
    cout << x << " ";
  cout << " <- rest of the values are initilized to 0";
  // proper way to create an array initilized to 0s
  array<int, 10> pro = { 0 }; // this initilizes the first element to 0 and causes the rest of the elemets to be initialized to 0
  cout << "\n proper array: ";
  for (int x : pro)
    cout << x << " ";
  // normal static array;
  static int arrStatic[10]; // sotred in heap on the otherhand noraml array local to a function is sotred in the stack
  arrStatic[5] = -1;
  cout << "\nnormal static array: ";
  for (int x : arrStatic)
    cout << x << " ";
  // another way to solve the problem of garbage values inside arrays local to a function
  int arrNewLocal[10] = { 0 };
  cout << "\nnormal array local to main function with the first element intialized to 0 :  ";
  for (int x : arrNewLocal)
    cout << x << " ";
  cout << "\n\n\n\n -----------------------------------------------------------------------------------------------------------------------------------\n";
  cout << "here are some of the functions that are assosiated with array container\n";
  // some of the functions of the array container 
  Fill(); // 
  At();
  Other();
  cout << "\n\n ---------- Array Iterators ---------------: \n";
  Iterator();
  return 0;
}


void Fill() {
  cout << "\nfill() :\n";
  array<int, 10> arr;
  arr.fill(69); // assigns every element with the provided value
  for (int x : arr)
    cout << x << " ";
  cout << "\n";
}

void At() {
  cout << "\nat(); -> arr.at(i) equivalent to arr[i]\n";
  array<int, 5> arr = { 1,2,3,4,5 };
  for (int i = 0; i < 5; i++)
    cout << arr.at(i) << " ";
  cout << "\n";
}

void Other() {
  cout << "\n Some of the other functions are : \n";
  cout << "size() \n";
  array<int, 10> arr = { 0 };
  arr[0] = -1;
  arr[arr.size() - 1] = 1;
  cout << "arr.size() : " << arr.size() << "\n";
  cout << "front() returns the first element : \n";
  cout << "arr.front() : " << arr.front() << "\n";
  cout << "back() returns the last element : \n ";
  cout << "arr.back() : " << arr.back() << "\n";
  return;
}

void Iterator() {
  cout << "\n The common iterators are : begin()  , rbegin() , end() , rend() <- these iterators can be used in all data structures \n";
  array<int, 5> arr_2 = { 1,2,3,4,5 };
  cout << *arr_2.begin() << " " << *arr_2.end() << " " << *arr_2.rbegin() << " " << *arr_2.rend() << "\n";
  cout << "using iterator to print elements in an array : \n";
  for (auto itr = arr_2.begin(); itr < arr_2.end(); itr++)
    cout << *itr << " ";
  cout << "\nusing iterators to print elements in reverse: \n";
  for (auto itr = arr_2.rbegin(); itr > arr_2.rend(); itr++)
    cout << *itr << " ";
  cout << "\n";
  // using for each  loop for a string
  string str = "ghozt777 says hi :) \n";
  string newString = "";
  for (char c : str) {
    cout << c;
    // newString += c + " " this line with produce an erronuous o/p
    newString += c;
    newString += " ";
  }
  for (auto c : newString)
    cout << c;
}

