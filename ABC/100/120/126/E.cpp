#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int N, X;
  cin >> N >> X;
  dsu uf(N + 1);
  for(int i = 0;i < X;++i) {
    int a, b, c;
    cin >> a >> b >> c, a--, b--;
    uf.merge(a, b);
  }
  set<int> c;
  int ans = 0;
  for(int i = 0;i < N;++i) {
    if(c.count(uf.leader(i)))continue;
    ans++;
    c.insert(uf.leader(i));
  }
  cout << ans << endl;
}