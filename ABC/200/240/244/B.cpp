#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int dy[] = { 0,-1,0,1 };
int dx[] = { 1,0,-1,0 };
int main() {
  int N;string S;
  cin >> N >> S;
  int y = 0, x = 0;
  int k = 0;
  REP(i, N) {
    if(S[i] == 'R') {
      k = (k + 1) % 4;
      continue;
    }
    y += dy[k], x += dx[k];
  }
  cout << x << " " << y << endl;
}