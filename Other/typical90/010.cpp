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
  vector<int> A(N + 1), B(N + 1);
  REP(i, N) {
    int a, b;
    cin >> a >> b;
    if(a == 1) {
      A[i + 1] = b;
    } else {
      B[i + 1] = b;
    }
  }
  REP(i, N) {
    A[i + 1] += A[i];
    B[i + 1] += B[i];
  }
  int q;
  cin >> q;
  while(q--) {
    int l, r;cin >> l >> r, l--;
    cout << A[r] - A[l] << " " << B[r] - B[l] << endl;
  }
}