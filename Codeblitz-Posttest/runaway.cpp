#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 105;
const int MAX_K = 17;
const int D[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
const int INF = 1e9 + 7;

char table[MAX_N][MAX_N];
int X[MAX_N], Y[MAX_N];
int treasure[MAX_N][MAX_N], dist[MAX_N][MAX_N];
vector <pair <int, int>> graph[MAX_N];
bool same_side[MAX_K][MAX_K];
int dist2[MAX_K][1<<MAX_K][2];
bool visited[MAX_K][1<<MAX_K][2];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    cin >> X[0] >> Y[0] >> X[K + 1] >> Y[K + 1];

    memset(treasure, -1, sizeof(treasure));
    for (int i = 1; i <= N; i++) cin >> (table[i] + 1);
    for (int i = 1; i <= K; i++) {
        cin >> X[i] >> Y[i];

        treasure[X[i]][Y[i]] = i;
    }
    treasure[X[0]][Y[0]] = 0;
    treasure[X[K + 1]][Y[K + 1]] = K + 1;

    for (int k = 0; k <= K + 1; k++) {
        memset(dist, -1, sizeof(dist));

        queue <pair <int, int>> q;
        q.emplace(X[k], Y[k]);
        dist[X[k]][Y[k]] = 0;
        while (!q.empty()) {
            auto [ux, uy] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int vx = ux + D[i][0], vy = uy + D[i][1];
                if (vx < 1 or vx > N or vy < 1 or vy > M or table[vx][vy] == '0') continue;

                if (treasure[vx][vy] > 0) {
                    graph[k].emplace_back(treasure[vx][vy], dist[ux][uy] + 1);
                    graph[treasure[vx][vy]].emplace_back(k, dist[ux][uy] + 1);
                    same_side[k][treasure[vx][vy]] = true;
                    same_side[treasure[vx][vy]][k] = true;
                }
                if (dist[vx][vy] == -1) {
                    dist[vx][vy] = dist[ux][uy] + 1;
                    q.emplace(vx, vy);
                }
            }
        }
    }

    for (int k1 = 1; k1 <= K; k1++) {
        for (int k2 = k1 + 1; k2 <= K; k2++) {
            if (same_side[k1][k2] == true) continue;

            graph[k1].emplace_back(k2, -1);
            graph[k2].emplace_back(k1, -1);
        }
    }

    for (int u = 0; u <= K + 1; u++) {
        for (int s = 0; s < (1<<(K + 2)); s++) {
            dist2[u][s][0] = INF;
            dist2[u][s][1] = INF;
        }
    }

    priority_queue <tuple <int, int, int, int>> pq;
    pq.emplace(0, 0, 1, 0);
    dist2[0][1][0] = 0;
    while (!pq.empty()) {
        auto [d, u, s, k] = pq.top();
        pq.pop();

        if (visited[u][s][k] == true) continue;
        visited[u][s][k] = true;

        if (u == K + 1 and s == (1<<(K + 2)) - 1) {
            cout << -d;
            return 0;
        }
        for (auto [v, w] : graph[u]) {
            if ((1<<v) & s) continue;
            int nk = k, ns = s | (1<<v);
            if (w == -1) nk++, w = 1;

            if (nk < 2 and visited[v][ns][nk] == false and dist2[u][s][k] + w < dist2[v][ns][nk]) {
                dist2[v][ns][nk] = dist2[u][s][k] + w;
                pq.emplace(-dist2[v][ns][nk], v, ns, nk);
            }
        }
    }
    cout << -1;
    return 0;
}