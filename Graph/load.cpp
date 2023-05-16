#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
const int MAX_M = 1e6 + 5;

int parent_dsu[MAX_N];
int U[MAX_M], V[MAX_M], C[MAX_M];
vector <pair <int, int>> tree[MAX_N];
int depth[MAX_N], parent[MAX_N], weight[MAX_N];

int find_parent(int u) {
    if (u == parent_dsu[u]) return u;
    return parent_dsu[u] = find_parent(parent_dsu[u]);
}

bool merge(int u, int v) {
    u = find_parent(u), v = find_parent(v);
    if (u == v) return false;

    parent_dsu[u] = v;
    return true;
}

void dfs(int u, int p) {
    for (auto [v, w] : tree[u]) {
        if (v == p) continue;

        depth[v] = depth[u] + 1;
        weight[v] = w;
        parent[v] = u;
        dfs(v, u);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector <tuple <int, int, int>> edges;
    for (int i = 1; i <= M; i++) {
        cin >> U[i] >> V[i] >> C[i];
        
        edges.emplace_back(C[i], U[i], V[i]);
    }

    sort(edges.begin(), edges.end());
    
    long long sum_weight = 0;
    iota(parent_dsu + 1, parent_dsu + N + 1, 1);
    for (auto [w, u, v] : edges) {
        if (merge(u, v) == true) {
            sum_weight += w;
            tree[u].emplace_back(v, w);
            tree[v].emplace_back(u, w);
        }
    }

    dfs(1, -1);

    int Q;
    cin >> Q;

    while (Q--) {
        int P;
        cin >> P;

        int u = U[P], v = V[P], max_weight = 0;
        if (depth[u] < depth[v]) swap(u, v);
        while (depth[u] > depth[v]) {
            max_weight = max(max_weight, weight[u]);
            u = parent[u];
        }
        while (u != v) {
            max_weight = max(max_weight, max(weight[u], weight[v]));
            u = parent[u], v = parent[v];
        }

        cout << sum_weight + C[P] - max_weight << '\n';
    }
    return 0;
}