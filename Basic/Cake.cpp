// Task: Kaek inspired by Cake(Plurm)
// Algo: Monotonic Stack
// Date: 15/5/2023
// Author: Jo

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;

    assert(n <= 5e6);
    int ans = 0;
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        assert(x <= 1e5);
        while (!st.empty() and st.top() > x)
        {
            ans++;
            st.pop();
        }
        if (st.empty() or (!st.empty() and x > st.top()))
            st.push(x);
    }
    ans += st.size();
    cout << ans << "\n";
}