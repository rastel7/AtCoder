#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
const ll INF = 1e18;
int main() {
  int N, M;
  cin >> N >> M;
  const int NMAX = 1000 + 10;
  const int MMAX = 2000 + 10;
  vector<int> a(MMAX, 0), b(MMAX, 0);
  vector<ll>  c(MMAX, 0), dist(NMAX, 0);
  REP(i, M) {
    cin >> a[i] >> b[i] >> c[i], a[i]--, b[i]--, c[i] *= -1;
  }

  REP(i, N)dist[i] = INF;
  dist[0] = 0;
  REP(loop, N) {
    REP(i, M) {
      if(dist[a[i]] == INF)continue;
      if(dist[b[i]] > dist[a[i]] + c[i])dist[b[i]] = dist[a[i]] + c[i];
    }
  }
  ll ans = dist[N - 1];
  bool negative[NMAX];
  REP(i, NMAX)negative[i] = false;
  REP(loop, N) {
    REP(i, M) {
      if(dist[a[i]] == INF)continue;
      if(dist[b[i]] > dist[a[i]] + c[i]) {
        dist[b[i]] = dist[a[i]] + c[i];
        negative[b[i]] = 1;
      }
      negative[b[i]] |= negative[a[i]];
    }
  }
  if(negative[N - 1]) {
    cout << "inf" << endl;
  } else {
    cout << -ans << endl;
  }
}