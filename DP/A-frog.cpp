#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
const int INF = 1e9 + 7;

int H[MAX_N];
int dp[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) cin >> H[i];

    dp[0] = INF;
    dp[1] = 0;
    for (int i = 2; i <= N; i++) {
        dp[i] = min(dp[i - 1] + abs(H[i] - H[i - 1]), 
                    dp[i - 2] + abs(H[i] - H[i - 2]));
    }
    cout << dp[N];
    return 0;
}