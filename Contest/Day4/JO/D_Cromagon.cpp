// Task: Cromagon
// Tag: Range DP(MCM)
// Date: 19/5/2023
// Author: JO

#include <bits/stdc++.h>
using namespace std;

const int MXN = 25;
const int MXL = 105;
const int mod = 2009;

int n, L;
int mul[MXN][MXN];
int arr[MXL];
int dp[MXL][MXL][MXN];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mul[i][j];
        }
    }

    cin >> L;
    for (int i = 0; i < L; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < L; i++)
    {
        dp[i][i][arr[i]] = 1;
    }

    for (int sz = 2; sz <= L; sz++)
    {
        for (int l = 0, r = sz - 1; r < L; l++, r++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = l; k + 1 <= r; k++)
                    {
                        dp[l][r][mul[i][j]] = (dp[l][r][mul[i][j]] + (dp[l][k][i] * dp[k + 1][r][j]) % mod) % mod;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << dp[0][L - 1][i] << "\n";
}