#include <bits/stdc++.h>
using namespace std;
using tu = tuple <int, int, int>;
const int INF = 1e9+7;
 
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char table[m+1];
    vector <tu> G[n+1][m+1];
    vector <vector <int>> dist(n+1, vector <int> (m+1, INF));
    vector <vector <bool>> visited(n+1, vector <bool> (m+1, 0));
    for(int i = 0; i < n; i++) {
        scanf("%s", table);
        for(int j = 0; j < m; j++) {
            bool tmp = 0;
            if(table[j] == '/') {
                tmp = 1;
            }
            G[i][j+1].emplace_back(i+1, j, tmp^1);
            G[i+1][j].emplace_back(i, j+1, tmp^1);
            G[i][j].emplace_back(i+1, j+1, tmp);
            G[i+1][j+1].emplace_back(i, j, tmp);
        }
    }
    priority_queue <tu, vector <tu>, greater <tu>> pq;
    pq.emplace(0, 0, 0);
    dist[0][0] = 0;
    while(!pq.empty()) {
        int d, ux, uy;
        tie(d, ux, uy) = pq.top();
        pq.pop();
        if(visited[ux][uy]) {
            continue;
        }
        visited[ux][uy] = 1;
        if(ux == n && uy == m) {
            printf("%d", dist[n][m]);
            return 0;
        }
        for(auto e : G[ux][uy]) {
            int vx, vy, w;
            tie(vx, vy, w) = e;
            if(!visited[vx][vy] && dist[ux][uy]+w < dist[vx][vy]) {
                dist[vx][vy] = dist[ux][uy]+w;
                pq.emplace(dist[vx][vy], vx, vy);
            }
        }
    }
    printf("NO SOLUTION");
    return 0;
}