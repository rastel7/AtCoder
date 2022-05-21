#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define rep(l,r, n) for (int l = r; l < (int)(n); l++)
using ll = long long;
using namespace std;
template<int VW, int VH> struct Ruisekiwa2D {
  int v[VH][VW];
  void set(int x, int y, int c) { v[y][x] = c; }
  void build() {
    rep(y, 0, VH) rep(x, 0, VW) {
      if(0 < y) v[y][x] += v[y - 1][x];
      if(0 < x) v[y][x] += v[y][x - 1];
      if(0 < y && 0 < x) v[y][x] -= v[y - 1][x - 1];
    }
  }
  int get(int sx, int sy, int tx, int ty) {
    assert(sx <= tx && sy <= ty);
    int rs = v[ty][tx];
    if(0 < sx) rs -= v[ty][sx - 1];
    if(0 < sy) rs -= v[sy - 1][tx];
    if(0 < sx && 0 < sy) rs += v[sy - 1][sx - 1];
    return rs;
  }
};
vector<vector<int>> B(4020, vector<int>(4020)), R(4020, vector<int>(4020));
Ruisekiwa2D<4020, 4020> BR, BW;
int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> Y(N), X(N);

  REP(i, N) {
    char c;
    cin >> Y[i] >> X[i];
    cin >> c;

    Y[i] %= (2 * K), X[i] %= (2 * K);
    if(c == 'B')
      B[Y[i]][X[i]]++;
    else
      R[Y[i]][X[i]]++;
  }
  REP(i, 4 * K) {
    REP(j, 4 * K) {
      BR.set(i, j, B[i % (2 * K)][j % (2 * K)]);
      BW.set(i, j, R[i % (2 * K)][j % (2 * K)]);
    }
  }
  BR.build();
  BW.build();
  int ans = 0;
  int KK=K*2;
  rep(y, 0, K*2) rep(x, 0, K*2) {
    int b = BR.get(x, y, x + K - 1, y + K - 1) + BR.get(x + K, y + K, x + KK - 1, y + KK - 1);
    int w = BW.get(x + K, y, x + KK - 1, y + K - 1) + BW.get(x, y + K, x + K - 1, y + KK - 1);
    int sm = b + w;
    ans = max(ans, sm);
  }
  cout << ans << endl;
}