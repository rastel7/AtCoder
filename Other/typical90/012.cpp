#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
const int MAX_N = 2010;
int C[MAX_N][MAX_N];
int H, W;
int num(int y, int x) {
  return y * MAX_N + x;
}
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
bool OoR(int y, int x) {
  return x <= 0 || y <= 0 || x > W || y > H;
}
int main() {
  cin >> H >> W;
  dsu uf(MAX_N * MAX_N + 1);
  int Q;
  cin >> Q;
  while(Q--) {
    int a;
    cin >> a;
    if(a == 1) {
      int r, c;
      cin >> r >> c;
      C[r][c] = 1;
      REP(i, 4) {
        int ny = r + dy[i], nx = c + dx[i];
        if(OoR(ny, nx))continue;
        if(C[ny][nx] == 1) {
          uf.merge(num(r, c), num(ny, nx));
        }
      }
    } else {
      int r1, c1, r2, c2;
      cin >> r1 >> c1 >> r2 >> c2;
      if(!C[r1][c1] || !C[r2][c2]) {
        cout << "No" << endl;
        continue;
      }
      if(uf.same(num(r1, c1), num(r2, c2))) {
        int p1 = uf.leader(num(r1, c1)), p2 = uf.leader(num(r2, c2));
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
  int a;
  //cin >> a;
}