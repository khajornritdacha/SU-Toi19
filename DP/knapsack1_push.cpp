#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 105;
const int MAX_M = 100005;
const long long INF = 1e18 + 7;

int W[MAX_N], V[MAX_N];
long long dp[MAX_N][MAX_M];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) cin >> W[i] >> V[i];

    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] = -INF;
        }
    }

    dp[1][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            // dp[i][j] = dp[i - 1][j - W[i]] + V[i];

            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j + W[i] <= M) {
                dp[i + 1][j + W[i]] = max(dp[i + 1][j + W[i]], dp[i][j] + V[i]);
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i <= M; i++) ans = max(ans, dp[N + 1][i]);
    cout << ans;
    // cout << dp[N][M];
    return 0;
}