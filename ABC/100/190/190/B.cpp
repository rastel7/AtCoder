#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main()
{
    int n, s, d;
    cin >> n >> s >> d;
    vector<int> X(n), Y(n);
    REP(i, n)
    cin >> X[i] >> Y[i];
    REP(i, n)
    {
        if (X[i] >= s)
            continue;
        if (Y[i] <= d)
            continue;
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}