#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 1;
const int MAX_R = 5001;

int qs[MAX_R][MAX_R];
int Tr[MAX_N], Tc[MAX_N], W[MAX_N];

int main() {
    int N, M, R, C;
    scanf(" %d %d %d %d", &N, &M, &R, &C);

    for (int i = 1; i <= N; i++) scanf(" %d %d %d", &Tr[i], &Tc[i], &W[i]);
    for (int i = 1; i <= M; i++) {
        int Sr, Sc;
        scanf(" %d %d", &Sr, &Sc);

        qs[Sr][Sc]++;
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            qs[i][j] += qs[i][j - 1] + qs[i - 1][j] - qs[i - 1][j - 1];
        }
    }

    int l = 1, r = max(R, C);
    while (l < r) {
        int mid = (l + r) / 2;

        bool ok = true;
        for (int i = 1; i <= N; i++) {
            int min_i = max(1, Tr[i] - mid), max_i = min(R, Tr[i] + mid);
            int min_j = max(1, Tc[i] - mid), max_j = min(C, Tc[i] + mid);
            int sum_water = qs[max_i][max_j] - qs[min_i - 1][max_j] - qs[max_i][min_j - 1] + qs[min_i - 1][min_j - 1];
            if (sum_water < W[i]) ok = false;
        }

        if (ok == true) r = mid;
        else l = mid + 1;
    }
    printf("%d", l);
    return 0;
}