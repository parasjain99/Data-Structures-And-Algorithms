#include <bits/stdc++.h>
using namespace std;
map<int, map<int, int>> dp;
int go(int sum, int n, vector<int> &a)
{
    if(sum==0) return 1;
    else if(n<0) return 0;
    else if(a[n]>sum) dp[sum][n]=go(sum,n-1,a);
    else dp[sum][n]=go(sum,n-1,a)+go(sum-a[n],n,a);
    return dp[sum][n];
}
int main()
{
    int sum, n;
    cin >> sum >> n;
    vector<int> a(n);
    //	map<int,map<int, bool> > dp;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << go(sum, n-1, a);
}
// 5 3
// 1 2 3