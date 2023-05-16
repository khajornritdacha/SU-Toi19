#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

vector <int> graph[MAX_N];
int U[MAX_N], V[MAX_N], cmp[MAX_N], cnt[MAX_N], parent[MAX_N];
int broken[MAX_N];
int ans[MAX_N];

int root(int u) {
    if (parent[u] == u) return u;
    return parent[u] = root(parent[u]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, K, Q;
    cin >> N >> M >> K >> Q;

    for (int i = 1; i <= K; i++) {
        int A;
        cin >> A;

        cmp[A]++;
    }
    for (int i = 1; i < MAX_N; i++) cnt[cmp[i]]++;
    for (int i = 1; i <= M; i++) cin >> U[i] >> V[i];

    vector <tuple <int, int, int, int>> queries;
    for (int i = 1; i <= Q; i++) {
        int t, a, b, c = -1;
        cin >> t >> a >> b;

        if (t == 1) cin >> c;

        queries.emplace_back(t, a, b, c);
    }

    for (int n = 1; n < MAX_N; n++) {
        if (cnt[n] == 0) continue;

        for (int i = 1; i <= N; i++) parent[i] = i;

        for (auto [t, a, b, c] : queries) {
            if (t == 1) {
                if (b <= n and n <= c) broken[a]++;
            }
        }
        for (int i = 1; i <= M; i++) {
            if (broken[i] == 0) parent[root(U[i])] = root(V[i]);
        }

        for (int i = Q - 1; i >= 0; i--) {
            auto [t, a, b, c] = queries[i];
            if (t == 1 && b <= n and n <= c && --broken[a] == 0) {
                parent[root(U[a])] = root(V[a]);
            }
            else {
                if (root(a) == root(b)) ans[i] += cnt[n];
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        if (get<0>(queries[i]) == 2) cout << ans[i] << '\n';
    }
    return 0;
}