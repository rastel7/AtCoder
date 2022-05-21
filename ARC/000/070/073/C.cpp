#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    ll N, T;
    cin >> N >> T;
    vector<ll> t(N);
    REP(i, N)cin >> t[i];
    ll ans = 0, now = 0;
    for(int i = 1;i < N;++i) {
        ll dif = t[i] - t[i - 1];
        dif = min(T, dif);
        ans += dif;
    }
    ans += T;
    cout << ans << endl;
}