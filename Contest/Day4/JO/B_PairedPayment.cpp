// Task: https://codeforces.com/problemset/problem/1486/E
// Tag: Dijkstra with State(Must do)
// Author: JO
// Date: 18/5/2023

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int MXN = 1e5 + 10;
const int MXC = 55;

using tu = tuple<int, int, int>;

int n, m;
int dis[MXN][MXC];
vector<pair<int, int>> G[MXN];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    assert(n <= 5 && "n is too large");
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 50; j++)
            dis[i][j] = INF;
    dis[1][0] = 0;

    priority_queue<tu, vector<tu>, greater<tu>> pq;
    pq.emplace(0, 1, 0);

    while (!pq.empty())
    {
        auto [wa, u, x] = pq.top();
        pq.pop();

        if (dis[u][x] < wa)
            continue;

        for (auto [v, w] : G[u])
        {
            if (x == 0)
            {
                if (dis[u][0] < dis[v][w])
                {
                    dis[v][w] = dis[u][0];
                    pq.emplace(dis[v][w], v, w);
                }
            }
            else
            {
                if (dis[u][x] + (x + w) * (x + w) < dis[v][0])
                {
                    dis[v][0] = dis[u][x] + (x + w) * (x + w);
                    pq.emplace(dis[v][0], v, 0);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dis[i][0] == INF)
            dis[i][0] = -1;
        cout << dis[i][0] << " ";
    }
}