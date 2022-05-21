#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  string S1, S2;
  cin >> S1 >> S2;
  if((S1 == "#." && S2 == ".#") || (S1 == ".#" && S2 == "#.")) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}