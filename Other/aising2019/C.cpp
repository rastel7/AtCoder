#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int H, W;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int Z[410][410];
vector<string> S;
pair<ll, ll> dfs(int y, int x) {
  Z[y][x] = 1;
  pair<ll, ll> p = { 0,0 };
  if(S[y][x] == '.') { p.first += 1; } else { p.second += 1; }

  REP(i, 4) {
    int ny = y + dy[i], nx = x + dx[i];
    if(ny < 0 || nx < 0 || nx >= W || ny >= H)continue;
    if(Z[ny][nx] == 1)continue;
    if(S[y][x] == S[ny][nx])continue;
    auto r = dfs(ny, nx);
    p.first += r.first, p.second += r.second;
  }
  return p;
}
int main() {

  cin >> H >> W;
  S.resize(H);
  REP(i, H)cin >> S[i];
  ll ans = 0;
  REP(i, W)REP(j, H) {
    auto p = dfs(j, i);
    ans += p.first * p.second;
  }
  cout << ans << endl;
}