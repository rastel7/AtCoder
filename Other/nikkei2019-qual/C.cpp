#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int N;
    cin >> N;
    vector<P> I(N);
    vector<P> A(N), B(N), S(N);
    ll sm = 0;
    REP(i, N) {
        int a, b;
        cin >> a >> b;
        sm += b;
        I[i] = P(a, b);
        S[i] = P(a + b, i);
    }
    sort(S.begin(), S.end(), greater<>());
    ll ans = 0;
    REP(i, N) {
        if(i % 2 == 0) {
            ans += S[i].first;
        }
    }
    cout << ans - sm << endl;
}