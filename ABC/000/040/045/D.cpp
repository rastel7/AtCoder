#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using P = pair<int, int>;
int main() {
  ll H, W, N;
  cin >> H >> W >> N;
  map<P, bool> mp;
  vector<P> A(N);
  REP(i, N) {
    cin >> A[i].first >> A[i].second;
    mp[A[i]] = 1;
  }
  vector<ll> ans(10);
  sort(A.begin(), A.end());
  auto OoR = [&](ll y, ll x) {
    return y <= 0 || x <= 0 || x > W || y > H;
  };
  for(auto [y, x] : A) {
    for(int d_x = 0;d_x < 3;d_x++) {
      for(int d_y = 0;d_y < 3;d_y++) {
        int sum = 1;
        bool d = true;
        for(int i = -2;i <= 0;i++) {
          for(int j = -2;j <= 0;j++) {
            int _y = y + i + d_y, _x = x + j + d_x;
            if(_y == y && _x == x)continue;
            if(OoR(_y, _x)) {
              d = 0;
              break;
            }
            if(mp.count(P(_y, _x))) {
              if((_y <= y && _x <= x) || _y < y) {
                d = 0;
                break;
              }
              sum++;
            }
          }
        }
        if(!d)continue;
        ans[sum]++;
      }
    }
  }
  ans[0] = (H - 2) * (W - 2);
  for(int i = 1;i <= 9;++i) {
    ans[0] -= ans[i];
  }
  for(auto x : ans) {
    cout << x << endl;
  }
}