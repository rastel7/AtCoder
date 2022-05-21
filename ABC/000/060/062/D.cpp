#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
vector<ll> f(vector<ll> const& a, bool b) {
  int N = a.size() / 3;
  vector<ll> wa(a.size(), 0);
  if(b == 0) {
    priority_queue<ll, vector<ll>, greater<ll>> que;
    ll sum = 0;
    REP(i, 3 * N) {
      sum += a[i];
      que.push(a[i]);
      if(que.size() > N) {
        sum -= que.top();
        que.pop();
      }
      if(que.size() == N)wa[i] = sum;
    }
  } else {
    priority_queue<ll> que;
    ll sum = 0;
    REP(i, 3 * N) {
      sum += a[i];
      que.push(a[i]);
      if(que.size() > N) {
        sum -= que.top();
        que.pop();
      }
      if(que.size() == N)wa[i] = sum;
    }
  }
  return wa;
}
int main() {
  int N;
  cin >> N;
  vector<ll> a(3 * N);
  REP(i, 3 * N)cin >> a[i];
  vector<ll> front, back;
  front = f(a, 0);
  reverse(a.begin(), a.end());
  back = f(a, 1);
  reverse(back.begin(), back.end());
  ll ans = -1e18;
  REP(i, 3 * N - 1) {
    if(front[i] == 0 || back[i + 1] == 0)continue;
    ans = max(ans, front[i] - back[i + 1]);
  }
  cout << ans << endl;
}