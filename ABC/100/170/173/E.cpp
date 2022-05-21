#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint1000000007;
int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    bool all_minus = 1;
    REP(i, N) { cin >> A[i];if(A[i] >= 0)all_minus = 0; }
    if(all_minus) {
        if(K % 2 == 0) {
            sort(A.begin(), A.end(), [](ll l, ll r) {
                return abs(l) > abs(r);
                });
            if(A.back() == 0) {
                sort(A.begin(), A.end(), [](ll l, ll r) {
                    return abs(l) < abs(r);
                    });
            }
        } else {
            sort(A.begin(), A.end(), [](ll l, ll r) {
                return abs(l) < abs(r);
                });
        }
        mint ans = 1;
        REP(i, K)ans *= A[i];
        cout << ans.val() << endl;
        return 0;
    }
    if(K % 2 == 1) {
        bool ng = 1;
        REP(i, N) {
            if(A[i] > 0)ng = 0;
        }
        if(ng && K % 2 == 1) {
            cout << 0 << endl;
            return 0;
        }
    }
    sort(A.begin(), A.end(), [](ll l, ll r) {
        return abs(l) > abs(r);
        });
    mint ans = 1;
    ll minus_cnt = 0;
    REP(i, K) {
        ans *= A[i];
        if(A[i] < 0)minus_cnt++;
        if(A[i] == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    if(minus_cnt % 2 == 0) {
        cout << ans.val() << endl;
        return 0;
    }
    if(K == N) {
        cout << ans.val() << endl;
        return 0;
    }
    ll a = 1e18, b = 1e18, c = 1e18, d = 1e18;
    {

        for(int i = K - 1;i >= 0;i--) {
            if(A[i] > 0) {
                a = A[i];
                break;
            }
        }
        for(int i = K;i < N;i++) {
            if(A[i] < 0) {
                b = A[i];
                break;
            }
        }
    }
    {

        for(int i = K - 1;i >= 0;i--) {
            if(A[i] < 0) {
                c = A[i];
                break;
            }
        }
        for(int i = K;i < N;i++) {
            if(A[i] > 0) {
                d = A[i];
                break;
            }
        }
    }
    if((a == 1e18 || b == 1e18)) {
        ans /= c;
        ans *= d;
        cout << ans.val() << endl;
        return 0;
    }
    if((c == 1e18 || d == 1e18)) {
        ans /= a;
        ans *= b;
        cout << ans.val() << endl;
        return 0;
    }
    if(b * c > a * d) {
        ans /= a;
        ans *= b;
    } else {
        ans /= c;
        ans *= d;
    }
    cout << ans.val() << endl;
}