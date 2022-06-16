#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N, X;
  cin >> N >> X;
  vector<ll> A(N);
  REP(i, N) {
    ll x;
    cin >> x;
    A[i] = abs(x - X);
  }
  ll g = A[0];
  REP(i, N) { g =  __gcd(g, A[i]); }
  cout << g << endl;
}