#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 8e4 + 5;
const int MAX_V = 2e6 + 5;
const int MAX_S = 19;
const int INF = 1e9 + 7;

int W[MAX_N], P[MAX_N][MAX_S];
int cure[MAX_N], poison[MAX_N];

vector <pair <int, int>> graph[MAX_V];
int dist[MAX_V];
bool visited[MAX_V];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, S;
    cin >> N >> S;

    for (int i = 1; i <= N; i++) {
        cin >> W[i];

        for (int j = 0; j < S; j++) {
            cin >> P[i][j];
 
            if (P[i][j] == -1) poison[i] |= (1<<j);
            else if (P[i][j] == 1) cure[i] |= (1<<j);
        }
    }

    for (int mask = 0; mask < (1<<S); mask++) {
        for (int i = 0; i < S; i++) {
            if (mask & (1<<i)) graph[N + mask + 1].emplace_back(N + (mask ^ (1<<i)) + 1, 0);
        }
    }

    for (int i = 1; i <= N; i++) {
        graph[N + poison[i] + 1].emplace_back(i, 0);
        graph[i].emplace_back(N + cure[i] + 1, W[i]);
    }

    for (int i = 1; i < MAX_V; i++) dist[i] = INF;

    priority_queue <pair <int, int>> pq;
    for (int i = 1; i <= N; i++) {
        if (poison[i] == 0) {
            pq.emplace(0, i);
            dist[i] = 0;
        }
    }

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u] == true) continue;
        visited[u] = true;

        for (auto [v, w] : graph[u]) {
            if (visited[v] == false and dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(-dist[v], v);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] != INF) ans = max(ans, dist[i]);
    }
    cout << ans;
    return 0;
}