#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  REP(i, N)cin >> A[i];
  while(K--) {
    vector<int> prev = A, next(N + 1);
    REP(i, N) {
      int l = max(0, i - A[i]), r = min(N, i + A[i] + 1);
      next[l]++, next[r]--;
    }
    REP(i, N) {
      next[i + 1] += next[i];
    }
    next.pop_back();
    if(prev == next) {
      break;
    }
    swap(A, next);
  }
  REP(i, N) {
    cout << A[i];
    if(i != N - 1)cout << " ";
  }
  cout << endl;
}