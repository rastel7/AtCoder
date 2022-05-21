#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
ll N;
string func(ll x) {
    string S = "";
    int cnt = 0;
    while(x > 0) {
        cnt++;
        if(x & 1) {
            S.push_back('(');
        } else {
            S.push_back(')');
        }
        x /= 2;
    }
    for(cnt; cnt < N; ++cnt) {
        S.push_back(')');
    }
    return S;
}
int main() {

    cin >> N;
    vector<string> A;
    for(int i = 1; i < (1 << N); ++i) {
        int _i = i;
        int num = 0;
        bool f = true;
        int cnt = 0;
        while(_i > 0) {
            cnt++;
            if(_i & 1) {
                num++;
            } else {
                num--;
            }
            _i /= 2;
            if(num < 0) {
                f = 0;
                break;
            }
        }
        if(!f || num != N - cnt)
            continue;
        A.push_back(func(i));
    }
    sort(A.begin(), A.end());
    REP(i, A.size()) cout << A[i] << endl;
}