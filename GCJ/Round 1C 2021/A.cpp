#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int T;
    cin >> T;
    int wow = 1;
    while(T--) {
        ll N, K;
        cin >> N >> K;
        vector<ll> A(N);
        REP(i, N) cin >> A[i];
        A.erase(unique(A.begin(), A.end()), A.end());
        sort(A.begin(), A.end());
        ll mx = 0;
        vector<ll> Pos;
        if(A[0] != 1)
            Pos.push_back(A[0] - 1);
        if(A.back() != K)
            Pos.push_back(A.back() + 1);
        REP(i, A.size() - 1) {
            if(A[i + 1] - A[i] < 2)
                continue;
            Pos.push_back(A[i] + 1);
        }
        REP(i, Pos.size()) REP(j, Pos.size()) {
            ll sum = 0;
            auto f = [&](ll l, ll r) {
                if(l == -1)
                    return r - 1;
                if(l == K + 1)
                    return K + 1 - r;
                return ((r - l - 1) / 2) + 1;
            };
            auto m = [&](ll x) {
                ll l = 0, r = 0;
                REP(k, A.size()) {
                    if(A[k] > x) {
                        if(k == 0)
                            l = -1;
                        else
                            l = x;
                        r = A[k];
                        return P(l, r);
                    }
                }
                return P(K + 1, x);
            };
            P tmp = m(Pos[i]);
            sum += f(tmp.first, tmp.second);
            if(Pos[i] != Pos[j]) {
                P tmp = m(Pos[j]);
                sum += f(tmp.first, tmp.second);
            }
            if(mx < sum) {
                // cout << Pos[i] << " " << Pos[j] << i << " " << j << endl;
            }
            REP(i, A.size() - 1) {
                if(A[i + 1] - A[i] < 2)
                    continue;
                mx = max(mx, A[i + 1] - A[i]-1 );
            }
            mx = max(mx, sum);
        }
        printf("Case #%d: %0.6Lf\n", wow++, (long double)mx / (long double)K);
        cout << flush;
    }
}