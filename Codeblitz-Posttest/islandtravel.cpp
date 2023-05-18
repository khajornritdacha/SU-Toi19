#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
const int INF = 1e9 + 7;

int cnt_disc, cnt_scc;
vector <int> graph[MAX_N];
vector <pair <int, int>> graph2[MAX_N];
int disc[MAX_N], low[MAX_N], scc[MAX_N];
bool on_stack[MAX_N];
stack <int> nodes;
int dist[MAX_N];
bool visited[MAX_N];

void dfs(int u) {
    disc[u] = low[u] = ++cnt_disc;
    on_stack[u] = true;
    nodes.push(u);
    for (auto v : graph[u]) {
        if (disc[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (on_stack[v] == true) low[u] = min(low[u], disc[v]);
    }

    if (disc[u] == low[u]) {
        cnt_scc++;
        int cur;
        do {
            cur = nodes.top();
            nodes.pop();
            scc[cur] = cnt_scc;
            on_stack[cur] = false;
        } while (cur != u);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, H;
    cin >> N >> M >> H;

    vector <tuple <int, int, int>> edges;
    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;

        edges.emplace_back(u, v, w);
        graph[u].push_back(v);
    }

    for (int i = 1; i <= N; i++) {
        if (disc[i] == 0) dfs(i);
    }

    for (auto [u, v, w] : edges) {
        if (scc[u] == scc[v]) continue;

        graph2[scc[u]].emplace_back(scc[v], w);
    }

    for (int i = 1; i <= N; i++) dist[i] = INF;

    priority_queue <pair <int, int>> pq;
    pq.emplace(0, scc[1]);
    dist[scc[1]] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u] == true) continue;
        visited[u] = true;

        for (auto [v, w] : graph2[u]) {
            if (visited[v] == false and dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(-dist[v], v);
            }
        }
    }

    if (dist[scc[N]] > H) dist[scc[N]] = H + 1;
    cout << H - dist[scc[N]];
    return 0;
}