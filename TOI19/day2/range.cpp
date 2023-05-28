#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 4e5 + 5;

int L[MAX_N], R[MAX_N], id[MAX_N], ans[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> L[i] >> R[i];

        L[i] *= -1;
    }

    iota(id + 1, id + N + 1, 1);
    sort(id + 1, id + N + 1, [&](const int &a, const int &b) {
        return make_pair(R[a], L[a]) < make_pair(R[b], L[b]);
    });

    vector <int> lis;
    for (int i = 1; i <= N; i++) {
        auto it = upper_bound(lis.begin(), lis.end(), L[id[i]]);

        ans[id[i]] = it - lis.begin() + 1;

        if (it == lis.end()) lis.push_back(L[id[i]]);
        else *it = L[id[i]];
    }

    cout << lis.size() << '\n';
    for (int i = 1; i <= N; i++) cout << ans[i] << ' ';
    return 0;
}