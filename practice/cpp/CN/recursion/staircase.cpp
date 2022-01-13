#include <iostream>
using namespace std;

int staircase(int n)
{
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    if (n <= 0)
        return 1;
    int ans = 0;
    if (n - 1 >= 0)
        ans += staircase(n - 1);
    if (n - 2 >= 0)
        ans += staircase(n - 2);
    if (n - 3 >= 0)
        ans += staircase(n - 3);
    return ans;
}
int main()
{
    int n, output;
    cin >> n;
    output = staircase(n);
    cout << output << endl;
    return 0;
}