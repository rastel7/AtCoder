#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll t[201010], k[201010];
ll p[201010];
int main() {
  ll N, K;
  cin >> N >> K;
  REP(i, N)cin >> t[i] >> k[i];
  vector<pair<int, int>> A(N);
  REP(i, N) {
    A[i] = { k[i],i };
  }
  sort(A.begin(), A.end(), greater<>());
  map<ll, ll> mp;
  ll sum = 0;
  vector<ll> can_pop;
  REP(i, K) {

    sum += A[i].first;
    if(mp.count(t[A[i].second]))can_pop.emplace_back(A[i].first);
    mp[t[A[i].second]]++;

  }
  p[mp.size()] = sum;
  sort(can_pop.begin(), can_pop.end(), greater<>());
  for(int i = K;i < N;++i) {
    if(can_pop.empty())continue;
    if(mp.count(t[A[i].second]))continue;
    sum -= can_pop.back();
    can_pop.pop_back();
    sum += A[i].first;
    mp[t[A[i].second]]++;
    p[mp.size()] = sum;
  }
  ll ans = 0;
  for(ll i=1;i<=K;++i){
    if(p[i]==0)continue;
    ans=max(ans,i*i+p[i]);
  }
  cout<<ans<<endl;
}