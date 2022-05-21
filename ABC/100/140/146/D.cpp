#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int N;
vector<vector<P>> G;
int color[(int)1e5 + 100];
void dfs(int id, int prev = -1, int col = 0) {
  set<int> s;
  s.insert(col);
  int c = 1;
  for(auto& g : G[id]) {
    if(g.first != prev) {
      while(s.count(c))c++;
      color[g.second] = c;
      dfs(g.first, id, c);
      c++;
    }
  }
}
int main() {
  cin >> N;
  G.resize(N);
  REP(i, N - 1) {
    int a, b;
    cin >> a >> b, a--, b--;
    G[a].emplace_back(P{ b,i }), G[b].emplace_back(P{ a,i });
  }
  dfs(0);
  int mx = 0;
  REP(i, N) {
    mx = max(mx, color[i]);
  }
  cout << mx << endl;
  REP(i, N - 1)cout << color[i] << endl;
}