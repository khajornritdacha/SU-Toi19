// Task: https://oj.uz/problem/view/CEOI12_jobs
// Tag: Greedy, Binary Search
// Author: JO
// Date: 17/5/2023

#include <bits/stdc++.h>
using namespace std;

int n, D, M;
vector<pair<int, int>> vec;
vector<vector<int>> ansDetail;

bool chk(int mid)
{
    int ptr = 0;
    for (int day = 1; day <= n; day++)
    {
        ansDetail[day].clear();
        for (int i = 1; i <= mid and ptr < M; i++)
        {
            if (day > vec[ptr].first + D)
                return false;

            if (day >= vec[ptr].first)
            {
                ansDetail[day].emplace_back(vec[ptr].second);
                ptr++;
            }

            if (ptr >= M or day < vec[ptr].first)
            {
                break;
            }
        }
    }
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> D >> M;
    ansDetail.resize(n + 1);
    for (int i = 1; i <= M; i++)
    {
        int x;
        cin >> x;
        vec.emplace_back(x, i);
    }

    sort(vec.begin(), vec.end());

    int l = 1, r = M, ans = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (chk(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans << "\n";
    for (int i = 1; i <= n; i++)
    {
        for (int v : ansDetail[i])
        {
            cout << v << " ";
        }
        cout << "0\n";
    }
}