#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    string s;
    cin >> s;
    deque<char> que;
    bool rev = 0;
    for(auto &c : s) {
        if(c == 'R') {
            rev = !rev;
            continue;
        }
        if(rev) {
            que.push_front(c);
        } else {
            que.push_back(c);
        }
    }
    deque<char> ans;
    while(!que.empty()) {
        while(!ans.empty()) {
            if(ans.back() == que.front()) {
                ans.pop_back();
                que.pop_front();
            } else {
                break;
            }
        }
        if(que.empty())
            break;
        ans.push_back(que.front());
        que.pop_front();
    }
    string S = "";
    if(rev) {
        while(!ans.empty()) {
            S += ans.back();
            ans.pop_back();
        }
    } else {
        while(!ans.empty()) {
            S += ans.front();
            ans.pop_front();
        }
    }
    cout << S << endl;
}
