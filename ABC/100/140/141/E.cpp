#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;
template<class T>
void chmax(T& a, T b) {
  a = max(a, b);
}
int main() {
  int N;
  string S;
  cin >> N >> S;
  int ans = 0;
  while(!S.empty()) {
    vector<int>  z = z_algorithm(S);
    for(int i = 1;i < z.size();++i) {
      chmax(ans, min(i, z[i]));
    }
    S.erase(S.begin());
  }
  cout << ans << endl;
}