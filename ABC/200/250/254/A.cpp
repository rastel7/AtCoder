#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
  int N;
  cin >> N;
  cout << to_string((N / 10) % 10 )+ to_string(N % 10) << endl;
}