#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int A, B;
  cin >> A >> B;
  swap(A,B);
  vector<vector<char>> S(100, vector<char>(100, '.'));
  int w = 1, b = 1;
  REP(i, 100) {
    S[i][99] = '#';
  }
  int y = 1, x = 98;
  while(w < B) {
    w++;
    REP(i, 3)REP(j, 3) {
      if(i == 1 && j == 1)continue;
      S[y + i - 1][x + j - 1] = '#';
    }
    y += 2;
    if(y >= 99) {
      y = 1, x -= 3;
    }

  }
  y = 0, x = 0;
  while(b < A) {
    b++;
    S[y][x] = '#';
    y += 2;
    if(y >= 100)x += 2, y = 0;
  }
  cout << 100 << " " << 100 << endl;
  for(auto s : S) {
    REP(i, s.size()) {
      cout << s[i];
    }
    cout << "\n";
  }
}