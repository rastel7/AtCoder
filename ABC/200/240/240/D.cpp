#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int MAX = 201010;
int b_count[210101];
stack<int> prev_num[210101];
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N)cin >> A[i];
  stack<int> st;
  st.push(MAX);

  prev_num[MAX].push(1);
  REP(i, N) {
    if(st.top() == A[i]) {
    } else {
      prev_num[st.top()].push(b_count[st.top()]);
      b_count[st.top()] = 0;
    }
    b_count[A[i]]++;
    st.push(A[i]);
    if(A[i] <= b_count[A[i]]) {
      //削除
      REP(j, b_count[A[i]]) {
        st.pop();
      }
      b_count[A[i]] = 0;
      b_count[st.top()] = prev_num[st.top()].top();
      prev_num[st.top()].pop();
    }
    cout << (int)st.size() - 1 << endl;
  }

}