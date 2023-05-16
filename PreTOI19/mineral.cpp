#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

long long A[MAX_N], B[MAX_N], qs[MAX_N];

long long solve(int l, int r) {
    if (l == r) return 0;

    int mid = (l + r) / 2;
    long long sum = solve(l, mid) + solve(mid + 1, r);

    vector <long long> L, R;
    for (int i = l; i <= mid; i++) L.push_back(qs[i]);
    for (int i = mid + 1; i <= r; i++) R.push_back(qs[i]);

    int i = 0, j = 0, k = l;
    while (i < L.size() and j < R.size()) {
        if (L[i] <= R[j]) {
            qs[k++] = L[i++];
        }
        else {
            sum += i;
            qs[k++] = R[j++];
        }
    }
    while (i < L.size()) qs[k++] = L[i++];
    while (j < R.size()) {
        qs[k++] = R[j++];
        sum += i;
    }
    return sum;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    long long K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> B[i];

    long long l = 0, r = 1e9, ans = -1;
    while (l <= r) {
        long long mid = (l + r) / 2;

        qs[0] = 0;
        for (int i = 1; i <= N; i++) qs[i] = qs[i - 1] + 1000 * A[i] - B[i] * mid;
        
        if (solve(0, N) >= K) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << fixed << setprecision(3) << ans / 1000.0;
    return 0;
}