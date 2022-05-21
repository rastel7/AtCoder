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
template<class T> inline bool chmin(T& a, T b) { if(a > b) { a = b; return 1; } return 0; }
namespace lib {
  namespace etc {
    /*
      O(N):文字列Sの先頭と各位置iにおいて接頭辞が何文字一致するか
    */
    vector<int> z_algorithm(string const& S) {
      vector<int> A(S.size());
      A[0] = S.size();
      int i = 1, j = 0;
      while(i < S.size()) {
        while(i + j < S.size() && S[j] == S[i + j]) ++j;
        A[i] = j;
        if(j == 0) { ++i; continue; }
        int k = 1;
        while(i + k < S.size() && k + A[k] < j) A[i + k] = A[k], ++k;
        i += k; j -= k;
      }
      return A;
    }
  }
  namespace data_struct {
    /*  座標圧縮*/
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
    //一点加算、範囲和の
    template <typename T>
    struct BIT {
      //一点加算
      int n;
      vector<T> bit;
      BIT(int n_) :n(n_ + 1), bit(n, 0) {}
      void add(int i, T x) {
        for(int idx = i;idx < n;idx += (idx & -idx)) {
          bit[idx] += x;
        }
      }
      //(0,i]までの和
      T sum(int i) {
        T s(0);
        for(int idx = i;idx > 0;idx -= (idx & -idx)) {
          s += bit[idx];
        }
        return s;
      }
    };
  }
  namespace graph {

    struct Edge {
      ll to;
      ll cost;
    };
    /* dijkstra(G,s,dis)
        入力：グラフ G, 開始点 s, 距離を格納する dis
        計算量：O(|E|log|V|)
        副作用：dis が書き換えられる,負のコストの際利用できない
    */
    void dijkstra(const vector<vector<Edge>>& G, int s, vector<ll>& dis) {
      int N = G.size();
      dis.resize(N, INFll);
      priority_queue<Pl, vector<Pl>, greater<Pl>> pq;  //「仮の最短距離、頂点」が小さい順にならぶ
      dis[s] = 0;
      pq.emplace(dis[s], s);
      while(!pq.empty()) {
        Pl p = pq.top();
        pq.pop();
        int v = p.second;
        if(dis[v] < p.first) continue;  //最短経路でなければ無視
        for(auto& e : G[v]) {
          if(dis[e.to] > dis[v] + e.cost) {  //最短距離候補ならpriority_queueに追加
            dis[e.to] = dis[v] + e.cost;
            pq.emplace(dis[e.to], e.to);
          }
        }
      }
    }
    /* dijkstra(G,s,dis,prev)
        入力：グラフ G, 開始点 s, 距離を格納する dis, 最短経路の前の点を記録するprev
        計算量：O(|E|log|V|)
        副作用：dis, prevが書き換えられる
    */
    void dijkstraRestore(const vector<vector<Edge>>& G, int s, vector<ll>& dis,
      vector<int>& prev) {
      int N = G.size();
      dis.resize(N, INFll);
      prev.resize(N, -1);  // 初期化
      priority_queue<Pl, vector<Pl>, greater<Pl>>
        pq;  //「仮の最短距離、頂点」が小さい順にならぶ
      dis[s] = 0;
      pq.emplace(dis[s], s);
      while(!pq.empty()) {
        Pl p = pq.top();
        pq.pop();
        int v = p.second;
        if(dis[v] < p.first) continue;  //最短経路でなければ無視
        for(auto& e : G[v]) {
          if(dis[e.to] > dis[v] + e.cost) {  //最短距離候補ならpriority_queueに追加
            dis[e.to] = dis[v] + e.cost;
            prev[e.to] = v;  // 頂点 v を通って e.to にたどり着いた
            pq.emplace(dis[e.to], e.to);
          }
        }
      }
    }

    /* get_path(prev, t)
        dijkstraRestore で得た prev, ゴール t
        出力： t への最短路のパス
    */
    vector<int> get_path(const vector<int>& prev, int t) {
      vector<int> path;
      for(int cur = t; cur != -1; cur = prev[cur]) {
        path.push_back(cur);
      }
      reverse(path.begin(), path.end());//逆順なのでひっくり返す
      return path;
    }
    //参考:https://algo-logic.info/dijkstra/
    /* O(N):有効非巡回グラフを順序付けして、自身以降のノードへしか辺を出さないようにする
    */
    vector<int> topological(const vector<vector<int>>& G) {
      vector<int> ans;
      int n = (int)G.size();
      vector<int> ind(n);//各頂点から出ている有向辺の次数
      for(int i = 0;i < n;++i) {
        for(auto& e : G[i]) {
          ind[e]++;
        }
      }
      queue<int> que;
      for(int i = 0;i < n;++i) {
        if(ind[i] == 0)que.push(i);
      }
      while(!que.empty()) {
        int now = que.front();
        que.pop();
        for(auto& e : G[now]) {
          ind[e]--;
          if(ind[e] == 0) que.push(e);
        }
      }
      return ans;
    }
  }
  namespace math {
    //繰り返し二乗法
    long long pow(long long x, long long n) {
      long long ret = 1;
      while(n > 0) {
        if(n & 1) ret = ret * x % MOD;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x % MOD;
        n >>= 1;  // n を1bit 左にずらす
      }
      return ret;
    }
    // 返り値: a と b の最大公約数
    template <typename T>
    ll gcd(T a, T b) {
      if(b == 0) {
        return a;
      }
      ll d = gcd(b, a % b);
      return d;
    }

    //行列ライブラリ　間違っているかも？
    template <typename T> struct Mat {
      vector<vector<T>> mat;
      Mat() {}
      Mat(int x) : mat(1, vector<T>(x)) {}
      Mat(vector<T> x) : mat(1, vector<T>(x)) {}
      Mat(int y, int x) : mat(y, vector<T>(x)) {}
      Mat(vector<vector<T>> x) : mat(x) {}
      Mat operator+(const Mat& rb) const {
        assert(mat.size() == rb.mat.size());
        Mat<T> ret;
        vector<vector<T>> tmp(mat.size());
        ret.mat = tmp;
        for(int i = 0; i < (int)mat.size(); ++i) {
          ret.mat[i].resize(mat[i].size());
          for(int j = 0; j < (int)mat[i].size(); ++j) {

            ret.mat.at(i).at(j) = mat.at(i).at(j) + rb.mat.at(i).at(j);
          }
        }
        return ret;
      }
      Mat operator*(const Mat& rb) {
        assert(mat[0].size() == rb.mat.size());
        Mat<T> ret;
        ret.mat.resize(mat.size());
        for(int i = 0; i < (int)ret.mat.size(); ++i) {
          ret.mat[i].resize(rb.mat.size(), 0);
        }
        for(int i = 0; i < (int)mat.size(); ++i) {
          ret.mat[i].resize(mat[i].size());
          for(int j = 0; j < (int)mat[i].size(); ++j) {
            for(int k = 0; k < (int)mat.size(); ++k) {
              ret.mat[i][j] += mat[i][k] * rb.mat[k][j];
            }
          }
        }
        return ret;
      }
      void operator+=(const Mat& rb) {
        assert(mat.size() == rb.mat.size());

        for(int i = 0; i < (int)mat.size(); ++i) {

          for(int j = 0; j < (int)mat[i].size(); ++j) {

            mat.at(i).at(j) += rb.mat.at(i).at(j);
          }
        }
      }
      Mat matpow(int x) const {
        Mat ret = this->identity_element();
        Mat y = Mat(this->mat);
        while(x) {
          if(x % 2 == 1) {
            ret = ret * y;
          }
          y = y * y;
          x = x >> 1;
        }
        return ret;
      }
      Mat identity_element() const {
        Mat ret;
        ret.mat.resize(mat.size());
        for(int i = 0; i < (int)mat.size(); ++i) {
          ret.mat[i].resize(mat.size());
          ret.mat[i][i] = 1;
        }
        return ret;
      }
    };
  }
}
template<typename T>
void mapping(vector<T>& v, T(*func)(T)) {
  for(auto& x : v) {
    x = func(x);
  }
}
template<typename T>
void mapping(vector<T>& v, T(*func)(T, size_t)) {
  for(int i = 0;i < (int)v.size();++i) {
    v[i] = func(v[i], i);
  }
}
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<ll>> dp((1 << N) + 1, vector<ll>(M + 1, INFll));
  dp[0][0] = 0;
  REP(i, M) {
    int a, b;
    cin >> a >> b;
    int key = 0;
    REP(j, b) {
      int c;
      cin >> c, c--;
      key |= (1 << c);
    }
    REP(j, (1 << N)) {
      chmin(dp[j][i + 1], dp[j][i]);
      chmin(dp[j | key][i + 1], dp[j][i] + a);
    }
  }
  if(dp[(1 << N) - 1][M] >= INFll)dp[(1 << N) - 1][M] = -1;
  cout << dp[(1 << N) - 1][M] << endl;
}