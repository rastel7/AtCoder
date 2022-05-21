#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll N, T;
vector<ll> calc_vec(vector<ll> const& t) {
  vector<ll> ret;
  for(int i = 0;i < (1 << t.size());++i) {
    ll sum = 0, id = 0, cnt = i;
    while(cnt != 0) {
      if(cnt & 1 == 1) {
        sum += t[id];
      }
      ++id;
      cnt >>= 1;
    }
    if(sum > T)continue;
    ret.emplace_back(sum);
  }
  sort(ret.begin(), ret.end());
  return ret;
}
int main() {

  cin >> N >> T;
  vector<ll> A(N);
  REP(i, N) {
    cin >> A[i];
  }

  vector<ll> t1, t2;
  REP(i, N) {
    if(i % 2 == 0)
      t1.emplace_back(A[i]);
    else
      t2.emplace_back(A[i]);
  }
  t1 = calc_vec(t1);
  t2 = calc_vec(t2);
  ll ans = 0;
  for(auto const i : t1) {
    if(i == T) {
      ans = T;
      break;
    }
    auto itr = upper_bound(t2.begin(), t2.end(), T - i);
    ll cp = *(--itr);
    //cerr << i << "+" << cp << endl;
    ans = max(ans, i + cp);
    //cerr << ans << endl;
  }
  cout << ans << endl;
}