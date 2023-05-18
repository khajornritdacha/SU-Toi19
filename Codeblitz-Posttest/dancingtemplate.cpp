#include <bits/stdc++.h>
using namespace std;

const double INF = DBL_MAX;

double distance(pair <double, double> a, pair <double, double> b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

double solve(vector <pair <double, double>> xsort, vector <pair <double, double>> ysort) {
    int N = xsort.size();
    if (N <= 1) return INF;
    if (N == 2) return distance(xsort[0], xsort[1]);

    int mid = N / 2;
    vector <pair <double, double>> xL, xR, yL, yR, strip;
    for (int i = 0; i < mid; i++) {
        xL.push_back(xsort[i]);
        xR.push_back(xsort[mid + i]);
    }
    for (auto [x, y] : ysort) {
        if (x <= xsort[mid].first) yL.emplace_back(x, y);
        else yR.emplace_back(x, y);
    }

    double min_dist = min(solve(xL, yL), solve(xR, yR));

    for (auto [x, y] : ysort) {
        if (abs(x - xsort[mid].first) < min_dist) strip.emplace_back(x, y);
    }

    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size(); j++) {
            if (strip[j].second - strip[i].second >= min_dist) break;

            min_dist = min(min_dist, distance(strip[i], strip[j]));
        }
    }
    return min_dist;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    double ans = 1e18;
    vector <pair <double, double>> xsort, ysort;
    for (int i = 1; i <= N; i++) {
        double x, y;
        cin >> x >> y;

        xsort.emplace_back(x, y);
        ysort.emplace_back(x, y);
    }   

    sort(xsort.begin(), xsort.end());
    sort(ysort.begin(), ysort.end(), [&](const pair <double, double> &a, const pair <double, double> &b) {
        return a.second < b.second;
    });

    cout << fixed << setprecision(2) << solve(xsort, ysort);
    return 0;
}