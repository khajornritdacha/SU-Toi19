// Task: https://cses.fi/problemset/task/1645
// Algo: Monotonic Stack
// Date: 14/5/2023
// Author: Jo

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n + 5);
    vector<int> ans(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() and arr[st.top()] >= arr[i])
            st.pop();
        if (!st.empty())
            ans[i] = st.top();
        st.push(i);
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}