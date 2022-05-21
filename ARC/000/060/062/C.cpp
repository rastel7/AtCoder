#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
template <typename T>
ll gcd(T a, T b) {
  if(b == 0) {
    return a;
  }
  ll d = gcd(b, a % b);
  return d;
}

int main() {
  //cout << ((5 - 1) / 3 * 3 + 3) << endl;
  int N;
  cin >> N;
  vector<ll> A(N), T(N);
  REP(i, N)cin >> T[i] >> A[i];
  ll a = A[0], t = T[0];
  for(int i = 1;i < N;++i) {
    {
      ll n_a = (a - 1) / A[i] * A[i] + A[i];
      ll n_t = n_a / A[i] * T[i];
      if(a <= n_a && t <= n_t) {
        a = n_a, t = n_t;
        continue;
      }
    }
    ll n_t = (t - 1) / T[i] * T[i] + T[i];
    ll n_a = n_t / T[i] * A[i];

    a = n_a, t = n_t;
  }
  cout << t + a << endl;
}