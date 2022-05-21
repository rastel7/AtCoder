#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> A(n);
    REP(i, n)cin >> A[i];
    int ans = n;
    REP(i, n)x -= A[i];
    sort(A.begin(), A.end());
    ans += x / A[0];
    cout << ans << endl;
}