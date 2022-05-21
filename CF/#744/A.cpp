#include<bits/stdc++.h>
using namespace std;
void solve() {
  string S;
  cin >> S;
  int a = 0, b = 0, c = 0;
  for(auto& C : S) {
    if(C == 'A')a++;
    else if(C == 'B') b++;
    else c++;
  }
  if(a + c == b) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}