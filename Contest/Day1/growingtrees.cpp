#include <bits/stdc++.h>
#define N 100010
#define DEBUG 0
using namespace std;
 
int h[N];
int fenwick[N+1];
int n;
const int INF = 2e9+7;
 
void update(int idx, int val) {
    while(idx <= N) {
        fenwick[idx] += val;
        idx += (idx&-idx);
    }
}
 
int query(int idx) {
    int res = 0;
    while(idx >= 1) {
        res += fenwick[idx];
        idx -= (idx&-idx);
    }
    return res;
}
 
int LowerBound(int x) {
    int l = 1, r = n, mid, idx = INF;
    while(l <= r) {
        mid = (l+r)/2;
        if(h[mid]+query(mid) < x) {
            l = mid+1;
        }
        else {
            idx = min(idx, mid);
            r = mid-1;
        }
    }
    return idx;
}
 
int UpperBound(int x) {
    int l = 1, r = n, mid, idx = -INF;
    while(l <= r) {
        mid = (l+r)/2;
        if(h[mid]+query(mid) > x) {
            r = mid-1;
        }
        else {
            idx = max(idx, mid);
            l = mid+1;
        }
    }
    return idx;
}
 
int main() {
    int m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }
    sort(h+1, h+n+1);
    char op;
    int a, b, idx, idx1, idx2;
    if(DEBUG) {
        cout << "Debug : ";
        for(int i = 1; i <= n; i++) {
            cout << h[i] << " ";
        }
        cout << endl;
    }
    while(m--) {
        scanf(" %c %d %d", &op, &a, &b);
        if(op == 'F') {
            idx = LowerBound(b);
            if(idx == INF) {
                continue;
            }
            if(idx+a-1 > n) {
                update(idx, 1);
                continue;
            }
            idx1 = LowerBound(h[idx+a-1]+query(idx+a-1));
            idx2 = UpperBound(h[idx+a-1]+query(idx+a-1));
            if(DEBUG) {
                cout << idx << " " << idx1 << endl;
            }
            update(idx, 1);
            update(idx1, -1);
            update(idx2-(a-(idx1-idx+1)), 1);
            update(idx2+1, -1);
        }
        else {
            idx1 = LowerBound(a);
            idx2 = UpperBound(b);
            if(idx1 == INF || idx2 == -INF) {
                idx1 = 1;
                idx2 = 0;
            }
            printf("%d\n", idx2-idx1+1);
        }
        if(DEBUG) {
            cout << "Debug : ";
            for(int i = 1; i <= n; i++) {
                cout << h[i]+query(i) << " ";
            }
            cout << endl;
        }
    }
    return 0;
}