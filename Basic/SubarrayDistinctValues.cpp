// Task: https://cses.fi/problemset/task/2428/
// Algo: Two pointer
// Date: 14/5/2023

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, K;
    cin >> n >> K;
    vector<int> arr(n + 5);
    unordered_map<int, int> cnt;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    long long ans = 0;
    for (int l = 1, r = 1, ty = 0; r <= n; r++)
    {
        if (++cnt[arr[r]] == 1)
            ty++;
        while (l <= n and ty > K)
        {
            if (--cnt[arr[l]] == 0)
                ty--;
            l++;
        }
        ans += r - l + 1;
    }
    cout << ans << "\n";
}