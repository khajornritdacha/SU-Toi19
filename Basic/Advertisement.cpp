// Task: https://cses.fi/problemset/task/1142
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
    vector<int> leftMost(n + 5), rightMost(n + 5);
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
            leftMost[i] = st.top();
        else
            leftMost[i] = 0;
        st.push(i);
    }

    while (!st.empty())
        st.pop();
    for (int i = n; i >= 1; i--)
    {
        while (!st.empty() and arr[st.top()] >= arr[i])
            st.pop();
        if (!st.empty())
            rightMost[i] = st.top();
        else
            rightMost[i] = n + 1;
        st.push(i);
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, 1ll * (rightMost[i] - leftMost[i] - 1) * arr[i]);
    cout << ans << "\n";
}