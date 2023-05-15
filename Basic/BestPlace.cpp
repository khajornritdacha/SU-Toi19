// Task: https://oj.uz/problem/view/NOI17_bestplace
// Algo: Median
// Date: 14/5/2023

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> xPos(n), yPos(n);
    for (int i = 0; i < n; i++)
        cin >> xPos[i] >> yPos[i];

    sort(xPos.begin(), xPos.end());
    sort(yPos.begin(), yPos.end());

    cout << xPos[n / 2] << " " << yPos[n / 2] << "\n";
}