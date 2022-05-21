#include <atcoder/all>
#include <bits/stdc++.h>
using mint = atcoder::modint998244353;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll g(ll x) {
    ll ret = 0;
    REP(i, x + 1) {
        if(i == 0)
            continue;
        if(to_string(x).size() == to_string(i).size())
            ret++;
    }
    return ret;
}
mint f(ll x) {
    mint ret = 0;
    for(int i = 1; i <= x; ++i) {
        ret += g(i);
    }
    return ret;
}
int main() {
    ll N;
    cin >> N;
    if(N < 10) {
        cout << f(N).val() << endl;
        return 0;
    }
    string S = to_string(N);
    mint ans = 0;
    mint nine = 10;
    mint mae = 0;
    REP(i, S.size() - 1) {
        mint tmp = nine - nine / 10;
        ans += (tmp) * (tmp + 1) / 2;
        nine *= 10;
    }
    mint tmp = N - mint(10).pow(S.size() - 1) + 1;
    ans += tmp * (tmp + 1) / 2;
    cout << ans.val() << endl;
}