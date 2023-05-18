#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;

vector <pair <int, int>> graph[MAX_N];
int dist1[MAX_N], dist2[MAX_N];

void dfs1(int u, int p) {
    for (auto [v, w] : graph[u]) {
        if (v != p) {
            dist1[v] = dist1[u] + w;
            dfs1(v, u);
        }
    }
}

void dfs2(int u, int p) {
    for (auto [v, w] : graph[u]) {
        if (v != p) {
            dist2[v] = dist2[u] + w;
            dfs2(v, u);
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    dfs1(1, -1);

    int max_dist = -1, furthest_node = -1;
    for (int i = 1; i <= N; i++) {
        if (max_dist < dist1[i]) {
            max_dist = dist1[i];
            furthest_node = i;
        }
    }
    dist1[furthest_node] = 0;
    dfs1(furthest_node, -1);
    
    max_dist = -1, furthest_node = -1;
    for (int i = 1; i <= N; i++) {
        if (max_dist < dist1[i]) {
            max_dist = dist1[i];
            furthest_node = i;
        }
    }
    dfs2(furthest_node, -1);

    vector <int> max_dist_all_nodes, T;
    for (int i = 1; i <= N; i++) max_dist_all_nodes.push_back(max(dist1[i], dist2[i]));
    
    sort(max_dist_all_nodes.begin(), max_dist_all_nodes.end());

    for (int i = 1; i <= M; i++) {
        int t;
        cin >> t;

        T.push_back(t);
    }

    sort(T.rbegin(), T.rend());

    long long ans = 0;
    for (int i = 0; i < M; i++) ans += 1ll * T[i] * max_dist_all_nodes[i];

    cout << ans;
    return 0;
}