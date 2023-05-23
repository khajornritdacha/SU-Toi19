// Task: https://codeforces.com/gym/444387/problem/A
// Tag: DP(NC)
// Date: 19/5/2023
// Author: JO

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

void test_case()
{
    int n;
    cin >> n;
    vector<int> arr(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    vector<vector<int>> dp(n + 10, vector<int>(2, INF));

    dp[1][1] = arr[1];
    dp[2][1] = arr[1] + arr[2];
    dp[2][0] = dp[1][1];
    for (int i = 3; i <= n; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 2][1]);
        dp[i][1] = min(dp[i - 1][0], dp[i - 2][0] + arr[i - 1]) + arr[i];
    }

    cout << min(dp[n][0], dp[n][1]) << "\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int testCases;
    cin >> testCases;
    while (testCases--)
        test_case();
}