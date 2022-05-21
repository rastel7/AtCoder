#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
const ll INF = 1e18;
struct score {
  int y, x;
  ll dist;
};
int main() {
  ll H, W;
  cin >> H >> W;
  int C_y, C_x, H_x, H_y;
  cin >> C_y >> C_x >> H_y >> H_x, C_y--, C_x--, H_x--, H_y--;
  vector<string> S(H);
  REP(i, H)cin >> S[i];
  vector<vector<ll>> dis(H, vector<ll>(W, INF));
  deque<score> deq;

  deq.push_back(score{ C_y,C_x,0 });
  while(!deq.empty()) {
    auto front = deq.front();
    deq.pop_front();
    if(dis[front.y][front.x] <= front.dist)continue;
    dis[front.y][front.x] = front.dist;
    REP(i, 5)REP(j, 5) {
      int y = front.y - 2 + i;
      int x = front.x - 2 + j;
      if(y == front.y && x == front.x)continue;
      if(not(0 <= y && y < H && 0 <= x && x < W))continue;
      if(S[y][x] == '#')continue;
      if((abs(y - front.y) == 0 && abs(x - front.x) == 1) || (abs(x - front.x) == 0 && abs(y - front.y) == 1)) {
        if(dis[y][x] > front.dist)
          deq.push_front(score{ y,x,front.dist });
      } else {
        if(dis[y][x] > front.dist + 1)
          deq.push_back(score{ y,x,front.dist + 1 });
      }
    }
  }
  if(dis[H_y][H_x] == INF)dis[H_y][H_x] = -1;
  cout << dis[H_y][H_x] << endl;
}