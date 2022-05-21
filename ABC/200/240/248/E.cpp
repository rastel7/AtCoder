#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> X(N), Y(N);
    REP(i, N) cin >> X[i] >> Y[i];
    if(K == 1) {
        cout << "Infinity" << endl;
        return 0;
    }
    ll ans = 0;
    set<T> s;
    set<ll> yoko, tate;
    for(int i = 0; i < N; ++i) {
        for(int j = i + 1; j < N; ++j) {
            if(X[i] == X[j]) {
                if(yoko.count(X[i]))
                    continue;
                yoko.insert(X[i]);
                ll cnt = 0;
                REP(k, N) if(X[k] == X[i]) cnt++;
                if(cnt >= K)
                    ans++;
                continue;
            }
            if(Y[i] == Y[j]) {
                if(tate.count(Y[i]))
                    continue;
                tate.insert(Y[i]);
                ll cnt = 0;
                REP(k, N) if(Y[k] == Y[i]) cnt++;
                if(cnt >= K)
                    ans++;
                continue;
            }
            ll a, b, c;
            a = Y[j] - Y[i];
            b = X[j] - X[i];
            ll g = __gcd(abs(a), abs(b));
            a /= g, b /= g;
            if(b < 0){
                a *= -1, b *= -1;
            }
            c = b * Y[i] - X[i]*a;
            if(s.count(make_tuple(a, b, c)))
                continue;
            s.insert(make_tuple(a, b, c));
            ll cnt = 0;
            REP(k, N) {
                if(b * (Y[k] - Y[i]) == a * (X[k] - X[i]))
                    cnt++;
            }
            if(cnt >= K)
                ans++;
        }
    }
    cout << ans << endl;
}