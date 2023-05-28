#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 305;
const int MAX_K = 10;
const int MOD = 1e9 + 7;

int N, K, D;
int A[MAX_N];
long long dp[MAX_N][MAX_N][MAX_K];

long long solve(int l, int r, int k) {
    if (dp[l][r][k] != -1) return dp[l][r][k];
    if (l > r) return dp[l][r][k] = 0;
    if (k == K - 1) return dp[l][r][k] = 1;

    dp[l][r][k] = 0;
    for (int i = l; i < r; i++) {
        if (abs((A[i] - A[l - 1]) - (A[r] - A[i])) <= D) {
            dp[l][r][k] = (dp[l][r][k] + solve(l, i, k + 1) * solve(i + 1, r, k + 1)) % MOD;
        }
    }
    return dp[l][r][k];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> K >> D;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];

        A[i] += A[i - 1];
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(1, N, 0);
    return 0;
}