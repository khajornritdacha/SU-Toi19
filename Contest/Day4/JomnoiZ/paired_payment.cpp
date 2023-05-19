#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
const int MAX_W = 55;
const int INF = 1e9 + 7;

vector <pair <int, int>> graph[MAX_N];
bool visited[MAX_N][MAX_W];
int dist[MAX_N][MAX_W];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 50; j++) {
            dist[i][j] = INF;
        }
    }

    priority_queue <tuple <int, int, int>> pq;
    pq.emplace(0, 1, 0);
    dist[1][0] = 0;
    while (!pq.empty()) {
        auto [d, u, w1] = pq.top();
        pq.pop();

        if (visited[u][w1] == true) continue;
        visited[u][w1] = true;
        
        for (auto [v, w2] : graph[u]) {
            if (w1 == 0) {
                if (visited[v][w2] == false and dist[u][0] < dist[v][w2]) {
                    dist[v][w2] = dist[u][0];
                    pq.emplace(-dist[v][w2], v, w2);
                }
            }
            else {
                if (visited[v][0] == false and dist[u][w1] + (w1 + w2) * (w1 + w2) < dist[v][0]) {
                    dist[v][0] = dist[u][w1] + (w1 + w2) * (w1 + w2);
                    pq.emplace(-dist[v][0], v, 0);
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (dist[i][0] == INF) dist[i][0] = -1;

        cout << dist[i][0] << ' ';
    }
    return 0; 
}