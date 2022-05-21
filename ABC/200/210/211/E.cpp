#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int N, K;
using vs = vector<string>;
int ans;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
void dfs(vs s) {
  int cnt = 0;
  REP(i, N) {
    REP(j, N) {
      if(s.at(i).at(j) == 'o')cnt++;
    }
  }
  if(cnt == K) {
    ans++;
    //REP(i, N) {
    //  cout << s[i] << endl;
    //}
    //cout << endl;
    return;
  }
  REP(i, N)REP(j, N) {
    if(s[i][j] != '.')continue;
    if(cnt != 0) {
      bool ok = 0;
      REP(k, 4) {
        int nx = j + dx[k], ny = i + dy[k];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
        if(s[ny][nx] == 'o')ok = 1;
      }
      if(!ok)continue;
    }
    s[i][j] = 'o';
    dfs(s);
    s[i][j] = '#';
    dfs(s);
    return;
  }
  return;
}
int main() {
  cin >> N >> K;
  vs S(N);
  REP(i, N)cin >> S[i];
  dfs(S);
  cout << ans << endl;
}