// link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int total_profit = 0;         // to track the total profit
    int least_so_far = INT_MAX;   // points to the lowest stock price encountered so far in the loop
    int profit_if_sold_today = 0; // hypothetical situation where we measure the profit if we were to sell the stock today
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < least_so_far)
            least_so_far = prices[i];
        profit_if_sold_today = prices[i] - least_so_far;
        if (profit_if_sold_today > total_profit) // we want to maximize the profit
            total_profit = profit_if_sold_today;
    }
    return total_profit;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << maxProfit(v) << endl;
    return 0;
}