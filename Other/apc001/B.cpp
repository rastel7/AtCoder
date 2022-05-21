#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  ll N;
  cin >> N;
  vector<ll> A(N), B(N);
  REP(i, N)cin >> A[i];
  REP(i, N)cin >> B[i];
  ll sm_A = 0, sm_B = 0;
  REP(i, N) {
    sm_A += A[i], sm_B += B[i];
  }
  ll cnt = 0,cnt2=0;
  REP(i, N) {
    if(A[i] > B[i]) {
      cnt2 += A[i] - B[i];
    } else {
      cnt += (B[i] - A[i] + 1) / 2;
    }
  }
  if(cnt-cnt2 <= sm_B - sm_A) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}