// Task: https://beta.programming.in.th/tasks/0019
// Algo: Complete Search with Bit manipulation
// Date: 14/5/2023

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> sours(n), bitters(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sours[i] >> bitters[i];
    }

    int ans = 1e9 + 10;
    for (int bit = 0, lim = (1 << n); bit < lim; bit++)
    {
        int totSour = 1;
        int totBitter = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (bit & (1 << i))
            {
                cnt += 1;
                totSour *= sours[i];
                totBitter += bitters[i];
            }
        }
        if (cnt > 0 and abs(totSour - totBitter) < ans)
            ans = abs(totSour - totBitter);
    }
    cout << ans << "\n";
}