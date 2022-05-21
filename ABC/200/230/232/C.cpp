#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G_A(N, vector<int>(N, 0));
  vector<vector<int>> G_B(N, vector<int>(N, 0));
  REP(i, M) {
    int a, b;
    cin >> a >> b, a--, b--;
    G_A[a][b] = 1;
    G_A[b][a] = 1;
  }
  REP(i, M) {
    int a, b;
    cin >> a >> b, a--, b--;
    G_B[a][b] = 1;
    G_B[b][a] = 1;
  }
  vector<int> p(N);
  REP(i, N)p[i] = i;
  do {
    bool d = 1;
    REP(i, N)REP(j, N) {
      if(G_A[i][j] == 1) {
        if(G_B[p[i]][p[j]] == 0)d = 0;
      }
    }
    if(d) {
      cout << "Yes" << endl;
      return 0;
    }
  } while(next_permutation(p.begin(), p.end()));
  cout << "No" << endl;
}