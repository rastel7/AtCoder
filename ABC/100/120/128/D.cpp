#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> L(N + 1), R(N + 1), V(N);
  REP(i, N)cin >> V[i];
  REP(i, N) {
    L[i + 1] = L[i] + V[i];
    R[N - i - 1] = R[N - i] + V[N - i - 1];
  }
  ll ans = 0;
  REP(i, K + 1) {
    for(int l = 0;l <= min(i, N);l++) {

      int r = i - l;
      if(r + l >= N) {
        r = N - l;
      }
      vector<ll> a;
      REP(k, l)a.emplace_back(V[k]);
      REP(k, r)a.emplace_back(V[N - 1 - k]);
      sort(a.begin(), a.end(), greater<>());
      {
        cerr << l << "," << r << ":";
        for(auto b : a)cerr << b << ",";
        cerr << endl;
      }
      REP(j, K - i) {
        if(a.empty())break;
        if(a.back() > 0)break;
        a.pop_back();
      }
      ll sum = 0;
      REP(k, a.size())sum += a[k];
      ans = max(ans, sum);
    }
  }
  cout << ans << endl;
}