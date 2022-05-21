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
    vector<ll> Wa_l(N + 1), Wa_r(N + 1), Wa(N + 1);
    REP(i, N) {
        //Wa[i]: (0,i]
        if(i != 0)Wa[i]++;
        Wa[i + 1] = Wa[i] + A[i];
        Wa_l[i + 1] = Wa_l[i] + Wa[i] + A[i];


    }
    Wa = vector<ll>(N + 1, 0);
    REP(i, N) {
        if(i != 0)Wa[N - i]++;
        Wa[N - (i + 1)] = Wa[N - i] + A[N - i - 1];
        Wa_r[N - (i + 1)] = Wa_r[N - i] + Wa[N - i] + A[N - i - 1];
    }
    //OUT(Wa_l);
    //OUT(Wa_r);
    ll ans = 1LL << 62;
    for(int i = 0;i < N;i += 2) {
        ll tmp = Wa_l[i] + Wa_r[i + 1];
        ans = min(ans, tmp);
    }

    cout << ans << endl;
}