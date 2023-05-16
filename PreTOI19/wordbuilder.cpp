#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;

char S[MAX_N], T[MAX_N];
vector <int> graph[MAX_N];
int dist[MAX_N];
queue <int> alphas[26];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    cin >> (S + 1);

    while (M--) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(dist, -1, sizeof(dist));

    queue <int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        alphas[S[u] - 'A'].push(dist[u]);
        for (auto v : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 2;
                q.push(v);
            }
        }
    }

    cin >> (T + 1);

    long long ans = 0;
    for (int i = 1; i <= K; i++) {
        if (alphas[T[i] - 'A'].empty()) {
            ans = -1;
            break;
        }

        ans += alphas[T[i] - 'A'].front();
        alphas[T[i] - 'A'].pop();
    }
    cout << ans;
    return 0;
}