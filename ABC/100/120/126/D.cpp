#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct Edge {
  int to, cost;
};
int color[(int)1e5 + 100];
void dfs(int id, int prev_id, int prev_color, ll dist, vector<vector<Edge>> const& G) {
  if(dist % 2 == 0)color[id] = 1;
  for(auto& x : G[id]) {
    if(x.to == prev_id)continue;
    dfs(x.to, id, 1, dist + x.cost, G);
  }
}
int main() {
  int N;
  cin >> N;
  vector<vector<Edge>> G(N);
  for(int i = 0;i < N - 1;++i) {
    int a, b, c;
    cin >> a >> b >> c, a--, b--;
    G[a].emplace_back(Edge{ b,c });
    G[b].emplace_back(Edge{ a,c });
  }
  dfs(0, -1, 2, 0, G);
  for(int i = 0;i < N;++i) {
    cout << color[i] << endl;
  }
}