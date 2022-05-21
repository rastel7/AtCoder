#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  string S;
  cin >> S;
  int N = S.size();
  map<char, ll> mp;
  ll kako = 1;
  stack<ll> st;
  REP(i, N) {
    if(S[i] == ')') {
      kako /= st.top();
      st.pop();
      continue;
    }
    ll jousuu = 0;
    while('0' <= S[i] && S[i] <= '9') {
      jousuu = jousuu * 10 + S[i++] - '0';
    }
    if(jousuu == 0)jousuu = 1;
    if(S[i] == '(') {
      kako *= jousuu;
      st.push(jousuu);
      continue;
    }
    mp[S[i]] += jousuu * kako;
  }
  for(char c = 'a';c <= 'z';++c) {
    cout << c << " " << mp[c] << endl;
  }
}