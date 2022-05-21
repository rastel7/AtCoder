#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    ll n, k;
    cin >> n >> k;
    string ans = to_string(n);
    REP(i, k) {
        string tmp = ans;
        sort(tmp.begin(), tmp.end());
        ll g2 = stoi(tmp);
        sort(tmp.begin(), tmp.end(), greater<>());
        ll g1 = stoi(tmp);
        ans = to_string(g1 - g2);
    }
    cout << ans << endl;
}