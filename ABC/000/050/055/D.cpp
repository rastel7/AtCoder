#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
bool search(string const& S, vector<char>& now) {
  int N = S.size();
  char c = now[N - 1];
  for(int i = 1;i < N - 1;++i) {
    if(now[i] == 'S') {
      if(S[i] == 'o') {
        if(now[(i - 1 + N) % N] == 'S')  now[i + 1] = 'S';
        else         now[i + 1] = 'W';
      } else {
        if(now[(i - 1 + N) % N] == 'S')        now[i + 1] = 'W';
        else         now[i + 1] = 'S';
      }
    } else {
      if(S[i] == 'o') {
        if(now[(i - 1 + N) % N] == 'S')        now[i + 1] = 'W';
        else   now[i + 1] = 'S';
      } else {
        if(now[(i - 1 + N) % N] == 'S')        now[i + 1] = 'S';
        else   now[i + 1] = 'W';
      }
    }
  }
  if(now[N - 1] == 'S') {
    if(S[N - 1] == 'o') {
      if(now[N - 2] != now[0])return 0;
    } else {
      if(now[N - 2] == now[0])return 0;
    }
  } else {
    if(S[N - 1] == 'o') {
      if(now[N - 2] == now[0])return 0;
    } else {
      if(now[N - 2] != now[0])return 0;
    }

  }
  return c == now[N - 1];
}
string out(vector<char> C) {
  string ret = "";
  for(auto c : C)ret += c;
  return ret;
}
int main() {
  ll N;
  cin >> N;
  string S;
  cin >> S;
  vector<char> now(N, '0');
  {//0が羊
    if(S[0] == 'o') {
      now[0] = 'S';
      now[1] = 'S', now[N - 1] = 'S';
      if(search(S, now)) {
        cout << out(now) << endl;
        return 0;
      }
      S.resize(N, '0');
      now[0] = 'S';
      now[1] = 'W', now[N - 1] = 'W';
      if(search(S, now)) {
        cout << out(now) << endl;
        return 0;
      }
      S.resize(N, '0');
    } else {
      now[0] = 'S';
      now[1] = 'W', now[N - 1] = 'S';
      if(search(S, now)) {
        cout << out(now) << endl;
        return 0;
      }
      S.resize(N, '0');
      now[0] = 'S';
      now[1] = 'S', now[N - 1] = 'W';
      if(search(S, now)) {
        cout << out(now) << endl;
        return 0;
      }
      S.resize(N, '0');
    }
  }
  {//0が狼
    char c = 'W';
    if(S[0] == 'o') {
      now[0] = c;
      now[1] = 'W', now[N - 1] = 'S';
      if(search(S, now)) {
        cout << out(now) << endl;
        return 0;
      }
      S.resize(N, '0');
      now[0] = c;
      now[1] = 'S', now[N - 1] = 'W';
      if(search(S, now)) {
        cout << out(now) << endl;
        return 0;
      }
      S.resize(N, '0');
    } else {
      now[0] = c;
      now[1] = 'S', now[N - 1] = 'S';
      if(search(S, now)) {
        cout << out(now) << endl;
        return 0;
      }
      S.resize(N, '0');
      now[0] = c;
      now[1] = 'W', now[N - 1] = 'W';
      if(search(S, now)) {
        cout << out(now) << endl;
        return 0;
      }
      S.resize(N, '0');
    }
  }
  cout << -1 << endl;
}