// Task: https://cses.fi/problemset/task/1079/
// Algo: Inverse modulo
// Date: 14/5/2023

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int LIM = 1e6 + 10;

int fac[LIM], rfac[LIM], q;

inline int mul(int a, int b)
{
    return (1LL * a * b) % mod;
}

int pw(int a, int p)
{
    int res = 1;
    while (p)
    {
        if (p & 1)
            res = mul(res, a);
        p /= 2;
        a = mul(a, a);
    }
    return res;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    fac[0] = rfac[0] = 1;
    for (int i = 1; i < LIM; i++)
    {
        fac[i] = mul(fac[i - 1], i);
        rfac[i] = pw(fac[i], mod - 2);
    }

    cin >> q;
    while (q--)
    {
        int b, a;
        cin >> a >> b;
        cout << mul(mul(fac[a], rfac[b]), rfac[a - b]) << "\n";
    }
}