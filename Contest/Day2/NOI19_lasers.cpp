#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int L, R;
    cin >> L >> R;
    vector <vector <int>> qs(R + 10);
    vector <int> sz(R + 10);
    for(int i = 1; i <= R; i++) {
        int X;
        cin >> X;
        sz[i] = X;
        qs[i].resize(X + 10, 0);
        for(int j = 1; j <= X; j++) {
            int a;
            cin >> a;
            qs[i][j] = qs[i][j - 1] + a;
        }
    }
 
    vector <pair <int, int>> vec;
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= sz[i]; j++) {
            int a = qs[i][j] - qs[i][j - 1];
            int pos_left = qs[i][j - 1] + 1;
            int pos_right = L - (qs[i][sz[i]] - qs[i][j]);
            
            if(pos_left + a - 1 < pos_right - a + 1) {
                continue;
            }
 
            vec.emplace_back(pos_right - a + 1, 1);
            vec.emplace_back(pos_left + a, -1);
        }
    }
 
    sort(vec.begin(), vec.end());
 
    int ans = 0, left = -1, sum = 0;
    for(auto [v, d] : vec) {
        sum += d;
        if(left == -1) {
            left = v;
        }
        if(sum == 0) {
            ans += v - left;
            left = -1;
        }
    }
    cout << ans;
    return 0;
}