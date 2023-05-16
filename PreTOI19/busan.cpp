#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2005;
const int MAX_M = 3005;

int L[MAX_N], R[MAX_N];
int dpL[MAX_N][MAX_M][2], dpR[MAX_N][MAX_M][2];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, S;
    cin >> N >> M >> S;

    for (int i = 1; i <= N; i++) cin >> L[i];
    for (int i = 1; i <= N; i++) cin >> R[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            dpL[i][j][0] = dpL[i - 1][j][0];
            if (L[i] < 0 and j + L[i] >= 0) dpL[i][j][0] = max(dpL[i][j][0], dpL[i - 1][j + L[i]][0] + R[i]);

            dpR[i][j][0] = dpR[i - 1][j][0];
            if (R[i] < 0 and j + R[i] >= 0) dpR[i][j][0] = max(dpR[i][j][0], dpR[i - 1][j + R[i]][0] + L[i]);
        }
    }
    for (int i = N; i >= 1; i--) {
        for (int j = 0; j <= M; j++) {
            dpL[i][j][1] = dpL[i + 1][j][1];
            if (L[i] < 0 and j + L[i] >= 0) dpL[i][j][1] = max(dpL[i][j][1], dpL[i + 1][j + L[i]][1] + R[i]);

            dpR[i][j][1] = dpR[i + 1][j][1];
            if (R[i] < 0 and j + R[i] >= 0) dpR[i][j][1] = max(dpR[i][j][1], dpR[i + 1][j + R[i]][1] + L[i]);
        }
    }

    int open_both = 0;
    for (int i = 1; i <= N; i++) {
        if (L[i] >= 0 and R[i] >= 0) open_both += L[i] + R[i];
    }

    if (S == 0) cout << open_both + dpL[N][M][0] + dpR[N][M][0];
    else {
        int max_people = 0;
        for (int i = 1; i <= N; i++) {
            int max_left = 0, max_right = 0;
            for (int j = 0; j <= M; j++) {
                max_left = max(max_left, dpL[i][j][0] + dpR[i + 1][M - j][1]);
                max_right = max(max_right, dpR[i][j][0] + dpL[i + 1][M - j][1]);
            }
            max_people = max(max_people, max_left + max_right);
        }
        cout << open_both + max_people;
    }
    return 0;
}