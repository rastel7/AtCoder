#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll H, W, N;
map<pair<ll, ll>, ll> dp;

template <typename T>
struct compress {
  vector<T> origin, vals;
  compress(vector<T> vec) {
    origin = vec;
    vals = vec;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for(int i = 0;i < (int)origin.size();++i) {
      origin[i] = lower_bound(vals.begin(), vals.end(), origin[i]) - vals.begin();
    }
  }
  T ret_id(T val) {
    //値を入力すると何番目の値かを返す
    return lower_bound(vals.begin(), vals.end(), val) - vals.begin();
  }
  T ret_val(T id) {
    //何番目の値化を入力するとidを返す
    return vals[id];
  }
};
int main() {
  cin >> H >> W >> N;
  ll sy, sx, gy, gx;
  cin >> sy >> sx >> gy >> gx, sy--, sx--, gy--, gx--;
  vector<ll> Y(N), X(N), S;
  S.emplace_back(gy), S.emplace_back(gx);
  S.emplace_back(sy), S.emplace_back(sx);
  REP(i, N) {
    ll y, x;
    cin >> y >> x, y--, x--;
    X[i] = x, Y[i] = y;
    S.emplace_back(y), S.emplace_back(x);
    S.emplace_back(y - 1), S.emplace_back(x - 1);
    S.emplace_back(y + 1), S.emplace_back(x + 1);

  }
  auto comp = compress(S);

  vector<vector<ll>> Yoko(comp.vals.size()), Tate(comp.vals.size());
  REP(i, N) {
    auto y = comp.ret_id(Y[i]), x = comp.ret_id(X[i]);
    Yoko[y].emplace_back(x);
    Tate[x].emplace_back(y);
  }
  REP(i, comp.vals.size())sort(Yoko[i].begin(), Yoko[i].end());
  REP(i, comp.vals.size())sort(Tate[i].begin(), Tate[i].end());
  dp[{comp.ret_id(sy), comp.ret_id(sx)}] = 0;
  queue<pair<ll, ll>> que;
  que.push({ comp.ret_id(sy), comp.ret_id(sx) });
  gy = comp.ret_id(gy), gx = comp.ret_id(gx);
  while(!que.empty()) {
    auto [y, x] = que.front();que.pop();
    if(y == gy && x == gx) {
      cout << dp[{y, x}] << endl;
      return 0;
    }
    if(!Yoko[y].empty()) {
      auto itr = lower_bound(Yoko[y].begin(), Yoko[y].end(), x);
      if(x == *itr) {
        cout << -1 << endl;
        return 0;
      }
      if(itr != Yoko[y].end()) {
        pair<ll, ll> pos = make_pair(y, (*itr));
        pos.second -= 1;
        if(!dp.count(pos)) {
          dp[pos] = dp[{y, x}] + 1;
          que.push(pos);
        }
      }
      if(itr != Yoko[y].begin()) {
        itr--;
        pair<ll, ll> pos = pair<ll, ll>{ y, (*itr) };
        pos.second += 1;
        if(!dp.count(pos)) {
          dp[pos] = dp[{y, x}] + 1;
          que.push(pos);
        }
      }
    }
    if(!Tate[x].empty()) {
      auto itr = lower_bound(Tate[x].begin(), Tate[x].end(), y);
      if(y == *itr) {
        cout << -1 << endl;
        return 0;
      }
      if(itr != Tate[x].end()) {
        pair<ll, ll> pos = pair<ll, ll>{ (*itr), x };
        pos.first -= 1;
        if(!dp.count(pos)) {
          dp[pos] = dp[{y, x}] + 1;
          que.push(pos);
        }
      }
      if(itr != Tate[x].begin()) {
        itr--;
        pair<ll, ll> pos = pair<ll, ll>{ (*itr) , x };
        pos.first += 1;
        if(!dp.count(pos)) {
          dp[pos] = dp[{y, x}] + 1;
          que.push(pos);
        }
      }
    }
  }
  cout << -1 << endl;
}