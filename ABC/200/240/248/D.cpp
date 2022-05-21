#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
using namespace atcoder;
using S = ll;
ll counts[210101];
int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    ll Q;
    cin >> Q;
    vector<pair<ll, ll>> B(Q);
    vector<ll> C(Q);
    REP(i, Q) {
        cin >> B[i].first >> B[i].second>>C[i];
        B[i].first--, B[i].second--;
    }
    vector<set<ll>> S(N);
    REP(i, Q) {
        if(B[i].first > 0)
            S[B[i].first-1].insert(C[i]);
    }
    REP(i, Q) {
            S[B[i].second].insert(C[i]);
    }
    vector<map<int, int>> mps(N);

    REP(i, N) {
        counts[A[i]]++;
        for(auto num : S[i]) {
            mps[i][num] = counts[num];
        }
    }

    REP(i, Q) {
        ll sum = mps[B[i].second][C[i]];
        if(B[i].first != 0) {
            sum -= mps[B[i].first - 1][C[i]];
        }
        cout << sum << endl;
    }
}