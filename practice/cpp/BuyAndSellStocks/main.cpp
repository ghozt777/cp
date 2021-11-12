#include<bits/stdc++.h>
using namespace std ;
namespace myApproach { // takes up extra space
  int max_profit(int[] , int) ;
  int util(int[] ,int , int) ;
  int maxProfit ; 
}

namespace GFG { // faster and consumes less memory 
  int max_profit(int[] , int) ;
  int maxProfit ;
}

int main () {
  int arr[] = {7,1,5,3,6,4} ;
  myApproach::maxProfit = myApproach::max_profit(arr , sizeof(arr) / sizeof(arr[0])); // from my solution(using recursion)
  GFG::maxProfit  = GFG::max_profit(arr , sizeof(arr) / sizeof(arr[0])) ;// from GFG
  cout << "Total Profit(my sol): " << myApproach::maxProfit << "\n" ;
  cout << "Total Profit(GFG): " << GFG::maxProfit << "\n" ;
  return 0 ;
}

int myApproach::max_profit(int arr[] , int n) {
  return myApproach::util(arr , 0 , n - 1) ;
}

int myApproach::util(int arr[] , int start , int end) {
  if(start >= end) {
    return 0 ;
  }
  int i ;
  int profit = 0;
  for(i = start ; i < end ; i++) if(arr[i] > arr[i+1]) break ;
  cout << "Buy : " << arr[start] << " (Day " << start + 1 << ") " << " -> " << "Sell: " << arr[i] << " (Day " << i + 1 << ") "<< "\n" ;
  profit += arr[i] - arr[start] ;
  profit += util(arr , i + 1 , end) ;
  return profit ;
}

int GFG::max_profit(int arr[] , int n) {
  int profit = 0 ;
  for(int i = 1 ; i < n ; i++) if(arr[i] < arr[i+1]) profit += arr[i+1] - arr[i] ;
  return profit ;
}