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
    vector<ll> A(n);
    REP(i, n)cin >> A[i];
    map<ll, int> mpl, mpr;
    ll ans = 0;
    REP(i, n) {
        ans += mpr[i - A[i]];
        mpr[i + A[i]]++;
    }
    cout << ans << endl;
}