#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N)cin >> A[i];
    ll ans = 0, sum = 0;
    REP(i, N) {
        ans += A[i] * A[i] * (N - 1);
        sum += A[i];
    }
    REP(i, N) {
        sum -= A[i];
        ans -= A[i] * sum * 2;
    }
    cout << ans << endl;
}