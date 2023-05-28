#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6 + 5;
const int MOD = 1e9 + 7;

int X[MAX_N];
set <int> graph[MAX_N];
long long fac[MAX_N], ans = 1;

void dfs(int u, int p) {
    int child = 0;
    for (auto v : graph[u]) {
        if (v != p) {
            child++;
            dfs(v, u);
        }
    }

    ans = ans * fac[child] % MOD;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    fac[0] = 1;
    for (int i = 1; i < MAX_N; i++) fac[i] = fac[i - 1] * i % MOD;

    int N;
    cin >> N;

    for (int i = 1; i <= 2 * N - 1; i++) cin >> X[i];

    for (int i = 1; i <= 2 * N - 2; i++) {
        graph[X[i]].insert(X[i + 1]);
        graph[X[i + 1]].insert(X[i]);
    }

    dfs(X[1], -1);

    cout << ans;
    return 0;
}