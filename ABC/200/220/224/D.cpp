#include<bits/stdc++.h>

using namespace std;
int main() {
  int M;
  cin >> M;
  vector<vector<int>> G(10);
  for(int i = 0;i < M;++i) {
    int u, v;
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  int p; string s = "999999999";
  for(int i = 1; i <= 8; i++) {
    cin >> p;
    s[p - 1] = i + '0';
  }
  //初期状態をsに
  queue<string> Q;
  Q.push(s);
  map<string, int> mp;
  mp[s] = 0;
  const string ANS = "123456789";
  while(!Q.empty()) {
    string s = Q.front();Q.pop();
    int v;
    for(int i = 1;i <= 9;++i)if(s[i - 1] == '9')v = i;
    for(auto& x : G[v]) {
      string t = s;
      swap(t[x - 1], t[v - 1]);
      if(mp.count(t))continue;
      mp[t] = mp[s] + 1;
      Q.push(t);
    }
  }
  if(!mp.count(ANS))mp[ANS] = -1;
  cout << mp[ANS] << endl;
}