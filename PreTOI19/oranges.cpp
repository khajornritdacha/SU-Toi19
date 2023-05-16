#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
const long long INF = 1e18 + 7;

int X1[MAX_N], Y1[MAX_N], X2[MAX_N], Y2[MAX_N], idx[MAX_N];
double M1[MAX_N], M2[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];

        if (X1[i] != 0) M1[i] = 1.0 * Y1[i] / X1[i];
        else M1[i] = INF;

        if (X2[i] != 0) M2[i] = 1.0 * Y2[i] / X2[i];
        else M2[i] = INF;

        if (M1[i] < M2[i]) swap(M1[i], M2[i]);

        idx[i] = i;
    }

    sort(idx + 1, idx + N + 1, [&](int x, int y) {
        return M2[x] > M2[y];
    });

    double minimum = INF + 1;
    int ans = N;
    for (int i = 1; i <= N; i++) {
        if (minimum > M1[idx[i]]) {
            minimum = M2[idx[i]];
            ans--;
        }
    }
    cout << ans;
    return 0;
}