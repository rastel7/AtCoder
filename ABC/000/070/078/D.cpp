#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
map<int, ll> memo[2];
ll solve(ll N, ll Z, ll id, bool now, vector<ll> const& a) {
    if(memo[now].count(id)) {
        return memo[now][id];
    }
    if(id == a.size()) {
        // cerr << N << ":" << Z << endl;
        return abs(N - Z);
    }
    ll ret;
    if(now == 1) {//最大化 
        ret = 0;
        for(int i = id;i < a.size();++i) {
            ret = max(solve(a[i], Z, i + 1, 0, a), ret);
        }
    } else {
        ret = 1e9 + 100;
        for(int i = id;i < a.size();++i) {
            ret = min(solve(N, a[i], i + 1, 1, a), ret);
        }
    }
    return memo[now][id] = ret;
}
int main() {
    int N, Z, W;
    cin >> N >> Z >> W;
    vector<ll> a(N);
    REP(i, N)cin >> a[i];
    cout << solve(Z, W, 0, 1, a) << endl;
}