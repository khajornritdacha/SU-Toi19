#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;
const int INF = 1e9 + 7;

int a[MAX_N];
int dp[MAX_N][2];

void testcase() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) cin >> a[i];

    dp[0][0] = INF;
    dp[0][1] = 0;
    dp[1][0] = a[1];
    dp[1][1] = INF;
    for (int i = 2; i <= N; i++) {
        dp[i][0] = min(dp[i - 1][1] + a[i], dp[i - 2][1] + a[i - 1] + a[i]);
        dp[i][1] = min(dp[i - 1][0], dp[i - 2][0]);
    }
    cout << min(dp[N][0], dp[N][1]) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) testcase();
    return 0;
}