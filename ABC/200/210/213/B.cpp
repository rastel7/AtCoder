#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N)cin >> A[i];
  auto B = A;
  sort(A.begin(), A.end(), greater<>());
  REP(i, N) {
    if(B[i] == A[1]) {
      cout << i + 1 << endl;
      return 0;
    }
  }
}