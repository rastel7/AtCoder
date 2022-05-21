#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;
int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> fre_num(N);
  vector<int> cnt(N, 1);
  dsu uf(N);
  REP(i, M) {
    int a, b;
    cin >> a >> b, a--, b--;
    fre_num[a]++, fre_num[b]++;
    if(uf.same(a, b)) {
      continue;
    }
    int tmp = cnt[uf.leader(a)] + cnt[uf.leader(b)];
    cnt[uf.leader(a)] = tmp;
    cnt[uf.leader(b)] = tmp;
    uf.merge(a, b);
    
  }
  vector<int> ans(N);
  REP(i, N) {
    ans[i] = cnt[uf.leader(i)] - fre_num[i];
  }
  REP(i, K) {
    int a, b;
    cin >> a >> b, a--, b--;
    if(!uf.same(a, b))continue;
    ans[a]--;
    ans[b]--;
  }
  REP(i, N) {
    cout << ans[i] -1;
    if(i != N - 1) {
      cout << " ";
    }
  }
  cout << endl;
}