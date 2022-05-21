#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int Q;
  cin >> Q;
  priority_queue<int, vector<int>, greater<>> que;
  queue<int> st;
  vector<int> ans;
  REP(i, Q) {
    int a;
    cin >> a;
    if(a == 1) {
      int c;
      cin >> c;
      st.push(c);
    } else if(a == 2) {
      if(!que.empty()) {
        ans.push_back(que.top());
        que.pop();
      } else {
        ans.push_back(st.front());
        st.pop();
      }
    } else {
      while(!st.empty()) {
        que.push(st.front());
        st.pop();
      }
    }
  }
  for(auto& o : ans)cout << o << endl;
}