#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5e6 + 5;

int P[MAX_N];
long long F[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, S, L;
    cin >> N >> S >> L;

    S--, L--;

    for (int i = 1; i <= N; i++) cin >> P[i];
    for (int i = 1; i <= N; i++) {
        cin >> F[i];

        F[i] += F[i - 1];
    }

    long long ans = 0;
    deque <pair <long long, int>> dq;
    for (int l = 1, r = 1; r <= N; r++) {
        while (!dq.empty() and P[r] - dq.front().second > L) dq.pop_front();
        while (l <= r and P[r] - P[l] > L) l++;
        while (l <= r and P[r] - P[l] >= S) {
            while (!dq.empty() and dq.back().first >= F[l - 1]) dq.pop_back();
            dq.emplace_back(F[l - 1], P[l]);
            l++;
        }

        if (!dq.empty()) ans = max(ans, F[r] - dq.front().first);
    }
    for (int i = 1; i <= N; i++) {
        if (P[i] - P[1] <= L) ans = max(ans, F[i]);
    }
    for (int i = N; i >= 1; i--) {
        if (P[N] - P[i] <= L) ans = max(ans, F[N] - F[i - 1]);
    }
    cout << ans;
    return 0;
}