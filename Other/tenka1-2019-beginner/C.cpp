#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int n;
    cin >> n;
    string S;
    cin >> S;
    vector<ll> White(n + 1), Black(n + 1);
    REP(i, n) {
        if(S[i] == '.')White[i + 1]++;
        if(S[n - 1 - i]=='#')Black[n - 1 - i]++;
        White[i + 1] += White[i], Black[n - 1 - i] += Black[n - i];
    }
    ll ans = INF;
    for(int i = 0;i < n + 1;++i) {
        ll tmp = (i - White[i]) + (n - i - Black[i]);
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}