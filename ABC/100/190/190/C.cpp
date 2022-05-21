#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> X(m), Y(m);
    REP(i, m)
    cin >> X[i] >> Y[i],
        X[i]--, Y[i]--;
    int k;
    cin >> k;
    vector<int> A(k), B(k);
    REP(i, k)
    cin >> A[i] >> B[i],
        A[i]--, B[i]--;
    int ans = 0;
    for (int i = 0; i < (1 << k); ++i)
    {
        vector<int> dish(n, 0);
        REP(j, k)
        {
            if (i & (1 << j))
            {
                dish[A[j]]++;
            }
            else
            {
                dish[B[j]]++;
            }
        }
        int tmp = 0;
        REP(j, m)
        {
            if (dish[X[j]] > 0 && dish[Y[j]] > 0)
                tmp++;
        }
        ans = max(tmp, ans);
    }
    cout << ans << endl;
}