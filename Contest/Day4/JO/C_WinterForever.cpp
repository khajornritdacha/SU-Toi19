// Task: https://codeforces.com/contest/1829/problem/F
// Tag: Observation, Graph theory
// Date: 19/5/2023
// Author: JO
// Note: Y nodes are always leaf

#include <bits/stdc++.h>
using namespace std;

void test_case()
{
    int n, m;
    vector<vector<int>> G;
    cin >> n >> m;
    G.resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    set<int> xNodes;
    int cntY = 0;
    for (int i = 1; i <= n; i++)
    {
        if (G[i].size() == 1)
        {
            cntY++;
            xNodes.insert(G[i][0]);
        }
    }

    assert(cntY % xNodes.size() == 0);
    cout << xNodes.size() << " " << cntY / xNodes.size() << "\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int testCases;
    cin >> testCases;
    while (testCases--)
        test_case();
}