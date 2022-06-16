#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
vector<ll> mem(51), pt(51);
ll solve(ll k, ll x) {
  ll ret = 0;
  if(k == 0 && x == 1) {
    return 1;
  }
  if(x == 1) {
    return 0;
  }
  x--;
  if(x <= mem[k - 1]) {
    return solve(k - 1, x);
  }
  ret += pt[k - 1];
  x -= mem[k - 1];
  x--;
  ret++;
  if(x == 0)return ret;
  if(x <= mem[k - 1]) {
    return ret + solve(k - 1, x);
  }
  return ret + pt[k - 1];
}
int main() {
  ll N, X;
  cin >> N >> X;
  mem[0] = 1;
  pt[0] = 1;
  REP(i, 50) {
    mem[i + 1] = mem[i] * 2 + 3;
    pt[i + 1] = pt[i] * 2 + 1;
  }
  cout << solve(N, X) << endl;
}