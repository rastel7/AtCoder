#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i];}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
char MOVE[] = { 'D','R','U','L' };
int N;
int sy, sx;
vector<string> S;
vector<P> intersection;//道路の交差点を全部列挙する
vector<int> checked;
vector<vector<int>> Graph;
bool OoR(int y, int x) {
  return y < 0 || x < 0 || x >= N || y >= N;
}
vector<int> dfs(int id) {
  checked[id] = 1;
  vector<int> ret = { id };
  REP(i, Graph[id].size()) {
    int nex = Graph[id][i];
    if(checked[nex])continue;
    vector<int> v = dfs(nex);
    REP(j, v.size()) {
      ret.emplace_back(v[j]);
    }
    ret.emplace_back(id);
  }
  return ret;
}
bool connect(int i, int j) {
  auto s = intersection[i], t = intersection[j];
  if(s.first == t.first) {
    for(int k = min(s.second, t.second) + 1;k < max(s.second, t.second);++k) {
      if(S[s.first][k] == '#')return false;
    }
  } else {
    for(int k = min(s.first, t.first) + 1;k < max(s.first, t.first);++k) {
      if(S[k][s.second] == '#')return false;
    }
  }
  return true;
}
int calc_cost(P s, P t) {//二点間のコスト
  int ret = 0;
  if(s.second == t.second) {
    for(int i = min(s.first, t.first) + 1; i <= max(s.first, t.first);++i) {
      ret += S[i][s.second] - '0';
    }
  } else {
    for(int i = min(s.second, t.second) + 1; i <= max(s.second, t.second);++i) {
      ret += S[s.first][i] - '0';
    }
  }
  return ret;
}
void fill_(vector<vector<int>>& V, P s) {
  auto f = [&](int dir) {
    int y = s.first, x = s.second;
    while(true) {
      if(OoR(y, x))break;
      if(S[y][x] == '#')break;
      V[y][x] = 1;
      y += dy[dir], x += dx[dir];
    }
  };
  REP(i, 4)f(i);
}
int fill_all(vector<vector<int>> const& A) {
  int ret = 0;
  REP(i, A.size()) {
    REP(j, A.size()) {
      if(S[i][j] == '#')continue;
      if(A[i][j] == 0)continue;
      ret++;
    }
  }
  return ret;
}
int square_cnt = 0;
int calculate_score(vector<int> const& A) {
  vector<vector<int>> B(N, vector<int>(N));
  int distance = 0;
  for(int i = 0;i < (int)A.size() - 1;++i) {
    auto s = intersection[A[i]], t = intersection[A[i + 1]];
    distance += calc_cost(s, t);
    if(s.second == t.second) {
      for(int i = min(s.first, t.first); i <= max(s.first, t.first);++i) {
        fill_(B, P(i, s.second));
      }
    } else {
      for(int i = min(s.second, t.second); i <= max(s.second, t.second);++i) {
        fill_(B, P(s.first, i));
      }
    }
  }
  int sum = fill_all(B);
  if(sum == square_cnt) {
    return round(10000 * double(sum) / double(square_cnt) + 1e7 * double(N) / double(distance));
  } else {
    return round(10000 * double(sum) / double(square_cnt));
  }
}
int main() {
  cin >> N >> sy >> sx;
  S.resize(N);
  REP(i, N)cin >> S[i];
  REP(i, N)REP(j, N)if(S[i][j] != '#')square_cnt++;
  REP(y, N)REP(x, N) {
    if(S[y][x] == '#')continue;
    int cnt = 0;
    REP(i, 4) {
      int nx = x + dx[i], ny = y + dy[i];
      if(OoR(ny, nx))continue;
      if(S[ny][nx] == '#')continue;
      cnt++;
    }
    if(cnt == 2) {
      REP(i, 4) {
        int nx = x + dx[i], ny = y + dy[i], nx2 = x + dx[(i + 1) % 4], ny2 = y + dy[(i + 1) % 4];
        if(OoR(ny, nx) || OoR(ny2, nx2))continue;
        if(S[ny][nx] != '#' && S[ny2][nx2] != '#') {
          intersection.emplace_back(P(y, x));
          break;
        }
      }
    }
    if(cnt >= 3)
      intersection.emplace_back(P(y, x));
  }
  int start = -1;
  REP(i, intersection.size()) {
    if(sy == intersection[i].first && sx == intersection[i].second) {
      start = i;
    }
  }
  if(start == -1) {
    start = intersection.size();
    intersection.emplace_back(P(sy, sx));
  }
  checked.resize(intersection.size());
  Graph.resize(intersection.size());
  for(int i = 0;i < intersection.size();++i) {
    for(int j = 0;j < intersection.size();++j) {
      if(i == j)continue;
      auto s = intersection[i], t = intersection[j];
      if(!(s.first == t.first || s.second == t.second))continue;
      if(connect(i, j)) {
        Graph[i].emplace_back(j);
      }
    }
  }
  vector<int> ans = dfs(start);
  for(int i = 0;i < ans.size() - 1;++i) {
    auto s = intersection[ans[i]], t = intersection[ans[i + 1]];
    int cnt;
    char c;
    if(s.first == t.first) {
      if(s.second > t.second) {
        c = 'L';
      } else {
        c = 'R';
      }
      cnt = abs(s.second - t.second);
    } else {
      if(s.first > t.first) {
        c = 'U';
      } else {
        c = 'D';
      }
      cnt = abs(s.first - t.first);
    }
    REP(k, cnt) {
      cout << c;
    }
  }
  cout << endl;
  cerr << calculate_score(ans) << endl;

}