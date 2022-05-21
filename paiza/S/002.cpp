#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<char>> A(M, vector<char>(N));
  REP(i, M)REP(j, N) {
    cin >> A[i][j];
  }
  pair<int, int> start;
  REP(i, M)REP(j, N) {
    if(A[i][j] == 's')start = { i,j };
  }
  vector<vector<ll>> dis(M, vector<ll>(N, -1));
  dis[start.first][start.second] = 0;
  queue<pair<int, int>> que;
  que.push(start);
  while(!que.empty()) {
    auto [y, x] = que.front();que.pop();
    if(A[y][x] == 'g') {
      cout << dis[y][x] << endl;
      return 0;
    }
    int dy[4] = { 1,0,-1,0 };
    int dx[4] = { 0,-1,0,1 };
    REP(i, 4) {
      int ny = y + dy[i], nx = x + dx[i];
      if(ny < 0 || nx < 0 || ny >= M || nx >= N)continue;
      if(dis[ny][nx] != -1)continue;
      if(A[ny][nx] == '1')continue;
      dis[ny][nx] = dis[y][x] + 1;
      que.push({ ny,nx });
    }
  }
  cout << "Fail" << endl;
}