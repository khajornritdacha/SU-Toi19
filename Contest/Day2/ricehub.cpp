// Task: https://oj.uz/problem/view/IOI11_ricehub?locale=en
// Algo: Binary Search, Median, Prefix Sum
// Author: JO
// Date: 17/5/2023
// Note: It can be shown that sum of abs(x_m - x1) + abs(x_m - x2) + ... abs(x_m - x_n) = sum(x_i) - sum(x_j) where i > m and j < m

#include <bits/stdc++.h>
#include "ricehub.h"
using namespace std;

const int MXN = 1e5 + 10;
using ll = long long;

ll qs[MXN];

inline ll getSum(int l, int r)
{
  if (l > r)
    return 0;
  if (l <= 0)
    return qs[r];
  return qs[r] - qs[l - 1];
}

bool chk(int ws, int R, ll B)
{
  for (int i = (ws + 1) / 2; i + ws / 2 <= R; i++)
  {
    ll rightSum = getSum(i + 1, i + ws / 2);
    ll leftSum = getSum(i - ws / 2 + (ws % 2 == 0), i - 1 + (ws % 2 == 0));
    if (rightSum - leftSum <= B)
      return true;
  }
  return false;
}

int besthub(int R, int L, int X[], long long B)
{
  for (int i = 0; i < R; i++)
    qs[i + 1] = qs[i] + X[i];
  int l = 1, r = R, ans = -1;
  while (l <= r)
  {
    int mid = (l + r) >> 1;
    if (chk(mid, R, B))
    {
      ans = mid;
      l = mid + 1;
    }
    else
    {
      r = mid - 1;
    }
  }
  assert(ans != -1);
  return ans;
}
