#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int N, M;
  cin >> N >> M;
  vector<set<int>> kanou(N);
  queue<int> hre;
  vector<vector<int>> A(M);
  REP(i, M) {
    int k;
    cin >> k;
    A[i].resize(k);
    REP(j, k) {
      cin >> A[i][j], A[i][j]--;
      if(j == k - 1) {
        kanou[A[i][j]].insert(i);
        if(kanou[A[i][j]].size() == 2) {
          hre.push(A[i][j]);
        }
      }
    }
  }
  while(!hre.empty()) {
    int id = hre.front();
    hre.pop();
    for(auto& i : kanou[id]) {
      A[i].pop_back();
      if(!A[i].empty()) {
        kanou[A[i].back()].insert(i);
        if(kanou[A[i].back()].size() == 2) {
          hre.push(A[i].back());
        }
      }
    }
  }
  REP(i, N) {
    if(kanou[i].size() != 2) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}