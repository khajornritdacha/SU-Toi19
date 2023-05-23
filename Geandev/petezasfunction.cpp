#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5e5 + 5;
const int MOD = 1e9 + 7;

unordered_map <int, int> cnt;
long long bi_power[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    bi_power[0] = 1;
    for (int i = 1; i < MAX_N; i++) bi_power[i] = bi_power[i - 1] * 2 % MOD;
    
    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;

        cnt[a]++;
    }

    vector <pair <int, int>> all_pairs;
    all_pairs.emplace_back(-MOD, 0);
    for (int i = -1000; i <= 1000; i++) {
        all_pairs.emplace_back(i * i, (bi_power[cnt[i]] - 1 + MOD) % MOD);
        int sum = 0;
        for (int j = i + 1; j <= 1000; j++) {
            all_pairs.emplace_back(i * j, (bi_power[cnt[i]] - 1 + MOD) % MOD * (bi_power[cnt[j]] - 1 + MOD) % MOD * bi_power[sum] % MOD);
            sum += cnt[j];
        }
    }

    sort(all_pairs.begin(), all_pairs.end());
    for (int i = 1; i < all_pairs.size(); i++) all_pairs[i].second = (all_pairs[i].second + all_pairs[i - 1].second) % MOD;

    while (Q--) {
        int l, r;
        cin >> l >> r;

        auto rb = --upper_bound(all_pairs.begin(), all_pairs.end(), make_pair(r, MOD));
        auto lb = --lower_bound(all_pairs.begin(), all_pairs.end(), make_pair(l, -1));

        cout << (rb->second - lb->second + MOD) % MOD << '\n';
    }
    return 0;
}