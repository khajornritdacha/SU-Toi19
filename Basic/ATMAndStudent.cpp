// Task: https://codeforces.com/contest/1611/problem/F
// Algo: Two Pointer
// Date: 16/5/2023
// Author: JO
// Note: Find the longest subarray that ends at r which satisfy S + sum >= 0

#include <bits/stdc++.h>
using namespace std;

void test_case()
{
    long long n, S;
    cin >> n >> S;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    long long sum = 0;
    int ans = 0;
    int ansl = -1, ansr = -1;
    for (int l = 1, r = 1; r <= n; r++)
    {
        sum += arr[r];
        while (S + sum < 0 and l <= r)
        {
            sum -= arr[l];
            l++;
        }

        if (S + sum >= 0 and r - l + 1 > ans)
        {
            ans = r - l + 1;
            ansl = l;
            ansr = r;
        }
    }
    if (ans == 0)
        cout << "-1\n";
    else
        cout << ansl << " " << ansr << "\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int testCases;
    cin >> testCases;
    while (testCases--)
        test_case();
}