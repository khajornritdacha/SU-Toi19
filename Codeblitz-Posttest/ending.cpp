#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

vector <int> graph[MAX_N];

int cnt_edge;
bool visited[MAX_N];

void dfs(int u) {
    for (auto v : graph[u]) {
        if (visited[v] == true) continue;
        visited[v] = true;
        cnt_edge++;

        dfs(v);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, Cp, Cl;
    cin >> N >> M >> Cp >> Cl;    

    while (M--) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    long long ans = 0;
    if (Cp > Cl) {
        for (int i = 1; i <= N; i++) {
            if (visited[i] == true) continue;
            visited[i] = true;
            cnt_edge = 0;

            dfs(i);

            ans += Cp + 1ll * Cl * cnt_edge;
        }
    }
    else ans = 1ll * N * Cp;

    cout << ans;
    return 0;
}