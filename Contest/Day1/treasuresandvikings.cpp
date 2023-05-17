
#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;
using pii = pair <int, int>;
 
int main() {
    int r[] = {-1, 0, 1, 0}, c[] = {0, -1, 0, 1};
    queue <pii> viking, you, tmp;
    int n, m;
    scanf("%d %d", &n, &m);
    char table[n][m+1];
    for(int i = 0; i < n; i++) {
        scanf("%s", table[i]);
        for(int j = 0; j < m; j++) {
            if(table[i][j] == 'V') {
                viking.emplace(i, j);
            }
            else if(table[i][j] == 'Y') {
                you.emplace(i, j);
            }
        }
    }
    while(!you.empty()) {
        while(!you.empty()) {
            int ux, uy;
            tie(ux, uy) = you.front();
            you.pop();
            if(table[ux][uy] == 'X') {
                continue;
            }
            if(table[ux][uy] == 'T') {
                printf("YES");
                return 0;
            }
            for(int d = 0; d < 4; d++) {
                int vx = ux+r[d], vy = uy+c[d];
                if(vx < 0 || vx >= n || vy < 0 || vy >= m) {
                    continue;
                }
                if(table[vx][vy] == '.') {
                    table[vx][vy] = 'Y';
                    tmp.emplace(vx, vy);
                }
                else if(table[vx][vy] == 'T') {
                    tmp.emplace(vx, vy);
                }
            }
        }
        swap(tmp, you);
        while(!viking.empty()) {
            int ux, uy;
            tie(ux, uy) = viking.front();
            viking.pop();
            for(int d = 0; d < 4; d++) {
                int vx = ux+r[d], vy = uy+c[d];
                if(vx < 0 || vx >= n || vy < 0 || vy >= m) {
                    continue;
                }
                if(table[vx][vy] == 'I' || table[vx][vy] == 'V') {
                    continue;
                }
                for(int d2 = 0; d2 < 4; d2++) {
                    int x = vx+r[d2], y = vy+c[d2];
                    while(x >= 0 && x < n && y >= 0 && y < m && table[x][y] != 'I' && table[x][y] != 'V') {
                        table[x][y] = 'X';
                        x += r[d2];
                        y += c[d2];
                    }
                }
                table[vx][vy] = 'V';
                tmp.emplace(vx, vy);
            }
        }
        swap(tmp, viking);
        if(DEBUG) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    cout << table[i][j];
                }
                cout << endl;
            }
        }
    }
    printf("NO");
    return 0;
}