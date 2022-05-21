#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int seen[2000000];
int d[2000000];
vector<vector<int>> G;
int index(int i, int j) {
  if(i < j) swap(i, j);
  return i * (i - 1) / 2 + j + 1;
}
int N;
template <class T>
void chmax(T& a, T b) {
  a = max(a, b);
}
int dfs(int now, int prev) {
  if(seen[now] == 2)return d[now];
  if(seen[now] == 1) {
    cout << -1 << endl;
    exit(0);
  }
  seen[now] = 1;
  int ret = 0;
  for(int nex : G[now]) {
    chmax(ret, dfs(nex, now));
  }
  seen[now] = 2;
  return d[now] = ret + 1;
}
int main() {
  cin >> N;
  G.resize(N * N);
  vector<vector<int>> A(N, vector<int>(N - 1));
  REP(i, N) {
    int now = 0;
    REP(j, N - 1) {
      cin >> A[i][j], A[i][j]--;
      int next = index(i, A[i][j]);
      G[now].emplace_back(next);
      now = next;
    }
  }
  cout << dfs(0, -1)-1 << endl;
}