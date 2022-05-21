#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
const int dy[4] = { 0,1,0,-1 };
const int dx[4] = { 1,0,-1,0 };
vector<string> S;
ll ans = 0;
int N, K;
bool OoR(int y, int x) {
  return y < 0 || x < 0 || x >= N || y >= N;
}
void dfs(int cnt = 0) {
  if(cnt >= K) {
    REP(i, N) {
      cout << S[i] << endl;
    }
    cout << endl;
    ans++;
    return;
  }
  for(int i = 0;i < N;++i) {
    for(int j = 0;j < N;++j) {
      if(OoR(i, j))continue;
      if(S[i][j] != '.')continue;
      if(cnt != 0) {
        bool ok = false;
        REP(k, 4) {
          int ny = i + dy[k], nx = j + dx[k];
          if(OoR(ny, nx))continue;
          ok = true;
        }
        if(!ok)continue;
      }
      S[i][j] = 'r';
      dfs(cnt + 1);
      S[i][j] = '#';
      dfs(cnt);
      S[i][j] = '.';
    }
  }
  return;
}
int main() {
  cin >> N >> K;
  S.resize(N);
  REP(i, N)cin >> S[i];
  dfs();
  cout << ans << endl;
}