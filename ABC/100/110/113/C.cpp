#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  vector<ll> P(M), Y(M);
  REP(i, M) cin >> P[i] >> Y[i];
  vector<tuple<int, int, int>> S(M);
  REP(i, M) S[i] = {Y[i], P[i], i};
  sort(S.begin(), S.end());
  map<int, int> mp;

  vector<int> ans(M);
  REP(i, M) {
    mp[get<1>(S[i])]++;
    ans[get<2>(S[i])] = mp[get<1>(S[i])];
  }
  REP(i, M) { printf("%06d%06d\n", P[i], ans[i]); }
}