#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP_V(i, n) for (int i = n-1; i >= (int)(0); i--)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int calc_score(vector<vector<int>> const& input, vector<vector<int>> const& ans) {
  int ret = 0;
  const int N = input.size();
  REP(i, N)REP(j, N) {
    ret += ans[i][j] * input[i][j];
  }
  return ret;
}
bool yama(vector<vector<int>> const& input, vector<vector<int>>& ans) {

  set<pair<int, P>> diff;
  vector<P> atais;
  auto ans_search = [&](P x) {
    REP(i, atais.size()) {
      if(x == atais[i]) {
        return i;
      }
    }
    return -1;
  };
  int prev_score = calc_score(input, ans);
  const int  N = input.size();
  REP(i, N)REP(j, N) {
    if(ans[i][j] != 0)atais.emplace_back(P(i, j));
  }
  mt19937 mt;
  random_device rnd;
  mt.seed(rnd());
  auto c_random = [&](int x) {
    return (int)(mt() % x);
  };
  int basyo = c_random(atais.size());
  P id = atais[basyo];
  diff.insert(make_pair(ans[id.first][id.second], id));
  ans[id.first][id.second] -= ceil(ans[id.first][id.second] * 0.1);
  auto calc_dis = [](P i, P j) {
    return abs(i.first - j.first) + abs(i.second - j.second);
  };
  if(c_random(2) == 0) {
    REP(i, N)REP(j, N) {
      int max_N = N;
      for(auto& a : atais) {
        int dis = calc_dis(P(i, j), a);
        max_N = min(max_N, dis - ans[a.first][a.second]);
        if(max_N <= 0)break;
      }
      max_N = max(0, max_N);
      if(max_N != ans[i][j]) {
        diff.insert(make_pair(ans[i][j], P(i, j)));
        ans[i][j] = max_N;
        int ba = ans_search(P(i, j));
        if(ba == -1) {
          if(max_N != 0) {
            atais.emplace_back(P(i, j));
          }
        }
      }

    }
  }
  else {
    REP_V(i, N)REP_V(j, N) {
      int max_N = N;
      for(auto& a : atais) {
        int dis = calc_dis(P(i, j), a);
        max_N = min(max_N, dis - ans[a.first][a.second]);
        if(max_N <= 0)break;
      }
      max_N = max(0, max_N);
      if(max_N != ans[i][j]) {
        diff.insert(make_pair(ans[i][j], P(i, j)));
        ans[i][j] = max_N;
        int ba = ans_search(P(i, j));
        if(ba == -1) {
          if(max_N != 0) {
            atais.emplace_back(P(i, j));
          }
        }
      }
    }
  }
  if(calc_score(input, ans) >= prev_score) {
    return true;
  }
  else {
    for(auto& a : diff) {
      ans[a.second.first][a.second.second] = a.first;
    }
    return false;
  }
}
int main() {
  int N;
  cin >> N;
  vector<vector<int>> A(N, vector<int>(N));
  REP(i, N)REP(j, N)cin >> A[i][j];
  vector<pair<int, P>> G;
  REP(i, N)REP(j, N) G.emplace_back(make_pair(A[i][j], P(i, j)));
  sort(G.begin(), G.end(), greater<>());

  vector<vector<int>> ans(N, vector<int>(N, 0));
  vector<pair<int, P>> settei;
  for(auto& pai : G) {
    int max_size = N;
    int y = pai.second.first, x = pai.second.second;
    auto calc_dis = [](P i, P j) {
      return abs(i.first - j.first) + abs(i.second - j.second);
    };
    for(auto& sl : settei) {
      int dis = calc_dis(pai.second, sl.second);
      max_size = min(max_size, dis - sl.first);
      if(max_size <= 0)break;
    }
    if(max_size <= 0)continue;
    ans[y][x] = max_size;
    settei.push_back(make_pair(max_size, P(y, x)));
  }
  REP(i, 100) {
    yama(A, ans);
  }
  for(int i = 0;i < N;++i) {
    for(int j = 0;j < N;++j) {
      cout << ans[i][j];
      if(j != N - 1)cout << " ";
    }
    cout << endl;
  }
}