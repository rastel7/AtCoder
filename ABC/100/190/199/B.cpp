#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main()
{
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    REP(i, N)
    cin >> A[i];
    REP(i, N)
    cin >> B[i];
    int a = *max_element(A.begin(), A.end()), b = *min_element(B.begin(), B.end());
    int diff = max(0, b - a + 1);
    cout << diff << endl;
}