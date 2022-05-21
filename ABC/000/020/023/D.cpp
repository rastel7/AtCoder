#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
bool f(vector<ll>& H, vector<ll>& S, ll x) {
    vector<int> T(H.size());
    REP(i, H.size()) {
        if(H[i] > x)return false;
        ll tmp = x - H[i];
        tmp = (tmp) / S[i];
        tmp = min<ll>(H.size() - 1, tmp);
        T[tmp]++;
    }
    int sm = 0;
    REP(i, H.size()) {
        sm += T[i];
        if(i + 1 < sm) {
            return false;
        }
    }
    return true;
}
int main() {
    int N;
    cin >> N;
    vector<ll> H(N), S(N);
    REP(i, N) {
        cin >> H[i] >> S[i];
    }
    ll l = 0, r = 1e18;
    while(r - l > 1) {
        ll mid = l + (r - l) / 2;
        if(f(H, S, mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
}