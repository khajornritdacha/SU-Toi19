#include <iostream>
using namespace std;
 
bool ck[201][201];
 
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b;
    while(m--) {
        scanf("%d %d", &a, &b);
        ck[a][b] = ck[b][a] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= n-2; i++) {
        for(int j = i+1; j <= n-1; j++) {
            for(int k = j+1; k <= n; k++) {
                if(!ck[i][j] && !ck[j][k] && !ck[i][k]) {
                    ans++;
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}