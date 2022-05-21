#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    ll N;
    cin >> N;
    vector<ll> a(N), b(N);
    REP(i, N) cin >> a[i];
    REP(i, N) cin >> b[i];
    int Q;
    cin >> Q;
    vector<ll> x(Q), y(Q);
    REP(i, Q) {
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
    }
    map<ll, ll> s, sa;
    vector<ll> A(N), B(N);
    vector<ll> mx(N), mxb(N);

    REP(i, N) {
        if(s.count(b[i]))
            continue;
        s[b[i]] = i;
    }
    REP(i, N) {
        if(!s.count(a[i])) {
            A[i] = 1e9;
            continue;
        }
        A[i] = s[a[i]];
    }
    mx[0] = A[0];
    REP(i, N - 1) { mx[i + 1] = max(mx[i], A[i + 1]); }
    {

        REP(i, N) {
            if(sa.count(a[i]))
                continue;
            sa[a[i]] = i;
        }
        REP(i, N) {
            if(!sa.count(b[i])) {
                B[i] = 1e9;
                continue;
            }
            B[i] = sa[b[i]];
        }
        mxb[0] = B[0];
        REP(i, N - 1) { mxb[i + 1] = max(mxb[i], B[i + 1]); }
    }
    REP(i, Q) {
        bool ok = true;
        ok &= mx[x[i]] <= y[i];
        ok &= mxb[y[i]] <= x[i];
        if(ok) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}