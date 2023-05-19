#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 205;

vector <int> graph[MAX_N];

void testcase() {
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) graph[i].clear();
    while (M--) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    set <int> layer1, layer2, layer3;
    for (int i = 1; i <= N; i++) {
        if (graph[i].size() == 1) layer3.insert(i);
    }
    for (auto u : layer3) {
        for (auto v : graph[u]) {
            layer2.insert(v);
        }
    }
    for (auto u : layer2) {
        for (auto v : graph[u]) {
            if (!layer3.count(v)) layer1.insert(v);
        }
    }

    int center = *layer1.begin();
    int one_from_layer2 = graph[center][0];

    cout << graph[center].size() << ' ' << graph[one_from_layer2].size() - 1 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) testcase();
    return 0;
}