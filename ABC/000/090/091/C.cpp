#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
const int MAX_N = 2 * 100100;
int a[MAX_N], b[MAX_N], c[MAX_N], d[MAX_N];
int main() {
  int N, M;
  cin >> N;
  REP(i, N)cin >> a[i];
  REP(i, N)cin >> b[i];
  REP(i, M)cin >> c[i];
  REP(i, M)cin >> d[i];
  vector<pair<ll, ll>> B(N), R(M);
  REP(i, N)R[i] = { a[i],b[i] };
  REP(i, N)B[i] = { c[i],d[i] };
  sort(R.begin(), R.end());
  sort(B.begin(), B.end());
  int ans = 0;
  for(auto [x, y] : B) {
    int id = -1;
    REP(i, N) {
      if(x > R[i].first && y > R[i].second) {
        if(id == -1) {
          id = i; continue;
        }
        if(R[i].second > R[id].second) {
          id = i;
        }
      }
    }
    if(id == -1)continue;
    ans++;
    R[id] = { 1e9,1e9 };
  }
  cout << ans << endl;
}