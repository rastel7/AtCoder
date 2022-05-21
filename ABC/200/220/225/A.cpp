#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  string S;
  cin >> S;
  int ans = 0;
  sort(S.begin(), S.end());
  set<string> s;
  do {
    s.insert(S);
  } while(next_permutation(S.begin(), S.end()));
  cout << s.size() << endl;
}