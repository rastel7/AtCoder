#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
const int INF = 1e7;
int ch(vector<int> l, int obj) {
  if(l.size() == 0)return INF;
  sort(l.begin(), l.end());
  int ret = INF;
  for(int i = 1;i < (1 << l.size());++i) {
    int cp = i, id = 0;
    int tmp = -10;
    int sm = 0;
    while(cp != 0) {
      if(cp & 1) {
        sm += l[id];
        tmp += 10;
      }
      id++, cp /= 2;
    }
    ret = min(ret, tmp + abs(sm - obj));
  }
  return ret;
}
int dfs(vector<int> l, vector<int> X) {
  if(X.empty())return 0;
  int obj = X[0];
  X.erase(X.begin());
  int ret = INF;
  for(int i = 1;i < (1 << l.size());++i) {
    vector<int> now, next;
    REP(j, l.size()) {
      if((i >> j) & 1) {
        now.emplace_back(l[j]);
      } else {
        next.emplace_back(l[j]);
      }
      ret = min(ret, dfs(next, X) + ch(now, obj));
    }
  }
  return ret;
}
int main() {
  int N, A, B, C;
  cin >> N >> A >> B >> C;
  vector<int> X = { A,B,C };
  vector<int> l(N);
  REP(i, N)cin >> l[i];
  cout << dfs(l, X) << endl;
}