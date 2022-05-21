#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pl;
const int INF = 1e9;
const long long INFll = 1e18;
const ll MOD = 1000000007;
struct input {
  int N, K, B;
  vector<P> point;
  vector<vector<string>> poly;
  vector<int> C;
};
struct poly {
  int id, y, x;
};
int calc(input const& in, vector<poly> const& ans) {
  double s = 0;
  for(auto const& x : ans) {
    s += in.C[x.id];
  }
  return round(1e8 / s);
}
pair<int, vector<poly>> calc_score(input const& in, vector<poly> const& ans) {
  //焼きなましするときは後ろの方にいれようね、
  vector<vector<int>> V(in.N, vector<int>(in.N, -1));
  vector<poly> ret;
  int score = 0;
  auto OoR = [&](int y, int x) {
    if(0 > y || y >= in.N || 0 > x || x >= in.N) return true;
    return false;
  };
  for(int i = ans.size() - 1;i >= 0;i--) {
    auto poly_ = ans[i];
    if(poly_.id == 0) {
      if(V[poly_.y][poly_.x] != -1)continue;
    }
    int y = poly_.y, x = poly_.x;
    for(int _y = 0;_y < in.poly[poly_.id].size();++_y) {
      for(int _x = 0;_x < in.poly[poly_.id][_y].size();++_x) {
        if(in.poly[poly_.id][_y][_x] == '.')continue;
        if(OoR(_y + y, _x + x)) {//だめ
          return make_pair(-1, vector<poly>());
        }
        if(V[_y + y][_x + x] != -1) {//もう埋まってる
          return make_pair(-1, vector<poly>());
        }
        V[_y + y][_x + x] = poly_.id;
      }
    }
    ret.emplace_back(poly_);
    score += in.C[poly_.id];
  }
  reverse(ret.begin(), ret.end());
  return make_pair(calc(in, ret), ret);
}
vector<poly> marge_point(input const& in) {
  vector<poly> ret;
  set<P> s;//もう入れたやつ
  REP(i, in.point.size() - 1) {
    auto now = in.point[i];
    auto next = in.point[i + 1];
    while(now.first < next.first) {
      if(!s.count(P(now.first, now.second))) {
        ret.emplace_back(poly{ 0, now.first, now.second });
        s.insert(now);
      }
      now.first++;
    }
    while(now.first > next.first) {
      if(!s.count(P(now.first, now.second))) {
        ret.emplace_back(poly{ 0, now.first, now.second });
        s.insert(now);
      }
      now.first--;
    }

    while(now.second < next.second) {
      if(!s.count(P(now.first, now.second))) {
        ret.emplace_back(poly{ 0, now.first, now.second });
        s.insert(now);
      }
      now.second++;
    }
    while(now.second > next.second) {
      if(!s.count(P(now.first, now.second))) {
        ret.emplace_back(poly{ 0, now.first, now.second });
        s.insert(now);
      }
      now.second--;
    }
    if(!s.count(P(next.first, next.second))) {
      ret.emplace_back(poly{ 0, next.first, next.second });
      s.insert(next);
    }
  }
  return ret;
}
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
void dfs(P now, vector<vector<int>>& V, set<P>& s, input const& in) {
  auto OoR = [&](int y, int x) {
    if(0 > y || y >= in.N || 0 > x || x >= in.N) return true;
    return false;
  };
  REP(i, 4) {
    int y = now.first + dy[i], x = now.second + dx[i];
    if(OoR(y, x) || s.count(P(y, x)))continue;
    if(V[y][x] != 1)continue;
    s.insert(P(y, x));
    dfs(P(y, x), V, s, in);
  }
}
bool linking(input const& in, vector<poly> const& ans) {
  vector<vector<int>> V(in.N, vector<int>(in.N, -1));
  for(auto& i : ans) {
    for(int y = 0;y < in.poly[i.id].size();++y) {
      for(int x = 0;x < in.poly[i.id][y].size();++x) {
        if(in.poly[i.id][y][x] == '.') continue;
        V[y + i.y][x + i.x] = 1;
      }
    }
  }

  set<P> s;
  dfs(P(ans.front().y, ans.front().x), V, s, in);
  for(auto const& x : in.point) {
    if(!s.count(x))return false;
  }
  return true;
}
vector<poly> solve(input const& in, clock_t const& start) {
  //まずは適当につなげる
  vector<poly> ret = marge_point(in);
  clock_t end = clock();
  auto tmp = calc_score(in, ret);
  random_device rnd;
  while(end - start < 1700000) {
    auto next_ans = tmp.second;
    REP(i, 3) {
      int id = rnd() % (in.B - 1) + 1;
      int poly_id = rnd() % tmp.second.size();
      int y = tmp.second[poly_id].y, x = tmp.second[poly_id].x;
      next_ans.emplace_back(poly{ id,y,x });
    }

    auto calc = calc_score(in, next_ans);
    //cerr << "prev:" << tmp.first << "next:" << calc.first << endl;
    if(calc.first > tmp.first) {
      tmp = calc;
    }
    end = clock();
  }
  return tmp.second;
  while(end - start < 1900000) {
    auto next_ans = tmp.second;
    REP(i, 5) {
      int poly_id = rnd() % next_ans.size();
      if(next_ans[poly_id].id == 1) {
        next_ans.erase(next_ans.begin() + poly_id);
      }
    }
    if(linking(in, next_ans)) {
      tmp.second = next_ans;
    }
    end = clock();
  }
  return tmp.second;
}
int main() {
  clock_t start = clock();
  input in;
  cin >> in.N >> in.K >> in.B;
  in.point.resize(in.K);
  REP(i, in.K)cin >> in.point[i].first >> in.point[i].second;
  sort(in.point.begin(), in.point.end());
  in.poly.resize(in.B);
  in.C.resize(in.B);
  REP(i, in.B) {
    int n, m;
    cin >> n >> m;
    cin >> in.C[i];
    in.poly[i].resize(n);
    REP(j, n)cin >> in.poly[i][j];
  }
  auto ans = solve(in, start);
  cout << ans.size() << endl;
  for(auto const& a : ans) {
    cout << a.id + 1 << " " << a.y << " " << a.x << "\n";
  }
}