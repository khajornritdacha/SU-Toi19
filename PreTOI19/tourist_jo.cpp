// Task: CrackNCode Pretoi19 Tourists
// Tag: DSU, offline, Sqrt Decomposition
// Author: JO
// Date: 18/5/2023
// Note: The distinct number of group classified by size is at most sqrt(N)
//      So we can use sqrt decomposition and DSU to find the answer to each groupSize

#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 10;

int par[MXN];

int fi(int x)
{
    return par[x] = (par[x] == x ? x : fi(par[x]));
}

bool uni(int a, int b)
{
    a = fi(a), b = fi(b);
    if (a == b)
        return false;
    par[a] = b;
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, M, K, Q;
    cin >> n >> M >> K >> Q;
    unordered_map<int, int> rawGroup, groups;
    vector<pair<int, int>> edges;
    for (int i = 1; i <= K; i++)
    {
        int x;
        cin >> x;
        rawGroup[x]++;
    }

    for (auto &[groudNo, num] : rawGroup)
    {
        groups[num]++;
    }

    edges.emplace_back(0, 0);
    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
    }

    vector<tuple<int, int, int, int>> queries;
    vector<int> ans(Q);
    for (int q = 0; q < Q; q++)
    {
        int op;
        cin >> op;
        int a, b, c = 0;
        ans[q] = -1;
        if (op == 1)
        {
            cin >> a >> b >> c;
        }
        else
        {
            cin >> a >> b;
            ans[q] = 0;
        }
        queries.emplace_back(op, a, b, c);
    }

    vector<int> banEdge(edges.size());
    for (auto &[groupSize, num] : groups)
    {
        // cout << "GroupSize: " << groupSize << " " << num << "\n";
        for (int i = 0; i < banEdge.size(); i++)
            banEdge[i] = 0;
        for (auto &[op, a, b, c] : queries)
        {
            if (op == 1 and b <= groupSize and groupSize <= c)
            {
                banEdge[a]++;
            }
        }

        for (int i = 1; i <= n; i++)
            par[i] = i;
        for (int i = 1; i < edges.size(); i++)
        {
            if (banEdge[i])
                continue;
            uni(edges[i].first, edges[i].second);
        }

        for (int q = Q - 1; q >= 0; q--)
        {
            auto &[op, a, b, c] = queries[q];
            if (op == 1)
            {
                if (b <= groupSize and groupSize <= c and --banEdge[a] == 0)
                {
                    uni(edges[a].first, edges[a].second);
                }
            }
            else
            {
                ans[q] += (fi(a) == fi(b) ? num : 0);
            }
        }

        // cout << "In groupSize: " << groupSize << "\n";
        // for (int q = 0; q < Q; q++)
        //     if (ans[q] != -1)
        //         cout << ans[q] << ' ';
        // cout << "\n";
    }

    for (int q = 0; q < Q; q++)
        if (ans[q] != -1)
            cout << ans[q] << '\n';
}