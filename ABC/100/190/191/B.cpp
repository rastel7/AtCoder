#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> A(n);
    REP(i, n)
    cin >> A[i];
    bool b = false;
    REP(i, n)
    {
        if (A[i] == x)
            continue;
        if (b)
        {
            cout << " " << A[i];
        }
        else
        {
            cout << A[i];
        }
        b = 1;
    }
    cout << endl;
}