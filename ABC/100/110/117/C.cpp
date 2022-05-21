#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int n, m;
    cin >> n >> m;

    vector<int> A(m);
    REP(i, m)cin >> A[i];
    if(m == 1) {
        //cout << 0 << endl;
        //return 0;
    }
    sort(A.begin(), A.end());
    int sum = A.back() - A[0];
    vector<int> Wa(m - 1);
    REP(i, m - 1) {
        Wa[i] = A[i + 1] - A[i];
    }
    sort(Wa.begin(), Wa.end(), greater<int>());
    REP(i, min<int>(n - 1, Wa.size()))sum -= Wa[i];
    cout << sum << endl;
}