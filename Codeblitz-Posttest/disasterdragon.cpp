#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

int tree[MAX_N];

void add(int x, int v) {
    for (int i = x; i < MAX_N; i += (i & -i)) tree[i] += v;
}

int get(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= (i & -i)) res += tree[i];
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, Q, A, B;
    cin >> N >> Q >> A >> B;

    while (Q--) {
        int D, X, C;
        cin >> D >> X >> C;

        if (D == 1) add(1, C), add(X + 1, -C);
        else add(X, -C);

        int l = 1, r = N, L = N, R = 1;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (get(mid) > B) l = mid + 1;
            else r = mid - 1, L = mid;
        }

        l = 1, r = N;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (get(mid) < A) r = mid - 1;
            else l = mid + 1, R = mid;
        }

        if (L > R) cout << "-1\n";
        else if (L == R) cout << L << '\n';
        else cout << L << ' ' << R << '\n';
    }
    return 0;
}