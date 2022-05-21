#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N)cin >> A[i];
    ll ans = 1e18;
    for(int i = 0;i < (1 << N);++i) {
        ll tmp = 0, now = A[0];
        for(int id = 1;id < N;++id) {
            if((1&(i >> id)) == (1&(i >> (id - 1)))) {
                now |= A[id];
            } else {
                tmp ^= now;
                now = A[id];
            }
        }
        tmp ^= now;
        ans = min(tmp, ans);
    }
    cout << ans << endl;
}