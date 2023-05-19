#include <bits/stdc++.h>
using namespace std;

const int MAX_K = 25;
const int MAX_N = 105;
const int MOD = 2009;

int N, K;
int A[MAX_K][MAX_K], a[MAX_N];
int dp[MAX_N][MAX_N][MAX_K];
bool visited[MAX_N][MAX_N];

void solve(int l, int r) {
    if (visited[l][r] == true) return;
    visited[l][r] = true;

    if (l == r) {
        dp[l][r][a[l]] = 1;
        return;
    }

    for (int k = l; k < r; k++) {
        solve(l, k), solve(k + 1, r);
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                dp[l][r][A[i][j]] += dp[l][k][i] * dp[k + 1][r][j];
                dp[l][r][A[i][j]] %= MOD;
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> K;

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            cin >> A[i][j];
        }
    }
    
    cin >> N;

    for (int i = 0; i < N; i++) cin >> a[i];

    solve(0, N - 1);

    for (int i = 0; i < K; i++) cout << dp[0][N - 1][i] << '\n';
    return 0;
}