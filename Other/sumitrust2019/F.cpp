#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  ll T1, T2, A1, B1, A2, B2;
  cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
  ll P, Q;
  if(A1<B1){
    swap(A1,B1),swap(A2,B2);
  }
  P = (A1 - B1) * T1, Q = (A2 - B2) * T2;
  if(P + Q > 0) {
    cout << 0 << endl;
    return 0;
  }
  if(P + Q == 0) {
    cout << "infinity" << endl;
    return 0;
  }
  ll  S = (-P) / (P + Q), T = (-P ) % (P + Q);
  if(T == 0) {
    S *= 2;
  } else {
    S = S * 2 + 1;
  }
  cout << S << endl;
}