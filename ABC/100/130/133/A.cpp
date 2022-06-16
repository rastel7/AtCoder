#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N, A, B;
  cin >> N >> A >> B;
  cout << min(N * A, B) << endl;
}