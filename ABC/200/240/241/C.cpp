#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int dy[] = { 0,-1,0,1,1,1,-1,-1 };
int dx[] = { -1,0,1,0,1,-1,-1,1 };
int N;
string S[1100];
bool OoR(int y, int x) {
  if(y < 0 || x < 0 || y >= N || x >= N) {
    return true;
  }
  return false;
}
int main() {
  cin >> N;
  REP(i, N)cin >> S[i];
  REP(i, N)REP(j, N) {
    REP(k, 8) {
      int cnt = 0;
      REP(l, 6) {
        int y = i, x = j;
        y = y + dy[k] * l, x = x + dx[k] * l;
        if(OoR(y, x)) {
          cnt = 10000;
          break;;
        }
        if(S[y][x] == '.') {
          cnt++;
        }
      }
      if(cnt > 2) {
        continue;
      } else {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}