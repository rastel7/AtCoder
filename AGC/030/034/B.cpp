#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    string S;
    cin >> S;
    ll ans = 0, cnt = 1;
    REP(i, S.size() - 2) {
        if(S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C') {
            ans += cnt;
            swap(S[i], S[i + 2]);
            i += 1;
        } else if(S[i] == 'A') {
            cnt++;
        } else {
            cnt = 1;
        }
    }
    cout << ans << endl;
}