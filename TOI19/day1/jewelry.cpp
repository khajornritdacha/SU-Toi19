#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6 + 5;

string S;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N >> S;

    S = '#' + S;

    long long ans = 0, cur_sum = 0;
    int cntT = 0, st = 0;
    stack <pair <int, int>> stk;
    stk.emplace(N, 0);
    for (int i = 1; i <= N; i++) {
        if (S[i] == 'F') cntT = st = 0;
        else {
            if (st == 0) st = i;

            cur_sum += ++cntT;
            while (!stk.empty() and stk.top().first < cntT) stk.pop();

            cur_sum += st - stk.top().second - 1;

            if (i + 1 <= N and S[i + 1] == 'F') {
                for (int j = cntT; j >= 1; j--) stk.emplace(j, i - j + 1);
            }
        }
        ans += cur_sum;
    }
    cout << ans;
    return 0;
}