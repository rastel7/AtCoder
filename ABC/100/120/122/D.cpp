#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
using mint = modint1000000007;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
const string C = "ACGT";
bool contain(string s) {
  if(s.substr(0, 3) == "AGC" || s.substr(1, 3) == "AGC")return 1;
  return false;
}
string add(string s, char c) {
  string ret = s + c;
  if(contain(ret))return "";
  REP(i, 3) {
    string tes = ret;
    swap(tes[i], tes[i + 1]);
    if(contain(tes))return "";
  }
  return ret.substr(1, 3);
}
int main() {
  int N;
  cin >> N;
  map<string, mint> mp;
  mp["###"] = 1;
  REP(i, N) {
    map<string, mint> pd;
    for(auto p : mp) {
      for(auto c : C) {
        string nxt = add(p.first, c);
        if(nxt != "")pd[nxt] += p.second;
      }
    }
    swap(mp, pd);
  }
  mint ans = 0;
  for(auto p : mp) {
    ans += p.second;
  }
  cout << ans.val() << endl;
}