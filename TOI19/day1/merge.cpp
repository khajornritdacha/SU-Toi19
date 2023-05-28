#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

int X[MAX_N], S[MAX_N], Y[MAX_N], T[MAX_N];
int qsS[MAX_N], qsT[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, Q;
    cin >> N >> M >> Q;

    for (int i = 1; i <= N; i++) cin >> X[i];
    for (int i = 1; i <= N; i++) cin >> S[i];
    for (int i = 1; i <= M; i++) cin >> Y[i];
    for (int i = 1; i <= M; i++) cin >> T[i];

    for (int i = 1; i <= N; i++) qsS[i] = qsS[i - 1] + S[i];
    for (int i = 1; i <= M; i++) qsT[i] = qsT[i - 1] + T[i];

    while (Q--) {
        int a, b, k;
        cin >> a >> b >> k;

        int l1 = -1e9, r1 = 1e9, ans = -1e9;
        while (l1 <= r1) {
            int mid1 = (l1 + r1) / 2;

            int l2 = 1, r2 = N, sumS = 0, sumT = 0;
            while (l2 <= r2) {
                int mid2 = (l2 + r2) / 2;

                if (X[mid2] <= mid1) l2 = mid2 + 1, sumS = qsS[mid2];
                else r2 = mid2 - 1;
            }
            l2 = 1, r2 = M;
            while (l2 <= r2) {
                int mid2 = (l2 + r2) / 2;

                if (Y[mid2] * a + b <= mid1) l2 = mid2 + 1, sumT = qsT[mid2];
                else r2 = mid2 - 1;
            }

            if (sumS + sumT >= k) r1 = mid1 - 1, ans = mid1;
            else l1 = mid1 + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}