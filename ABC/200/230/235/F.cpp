#include <atcoder/all>
#include <bits/stdc++.h>
using mint = atcoder::modint998244353;
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
mint dp[2][10][2000];
int main() {
    string S;
    cin >> S;
    int M;
    cin >> M;
    vector<int> C(M);
    REP(i, M) cin >> C[i];
    
}