#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    int N;
    cin >> N;
    vector<pair<int, string>> S(N);
    REP(i, N) cin >> S[i].second >> S[i].first;
    sort(S.begin(), S.end(), greater<>());
    cout << S[1].second << endl;
}