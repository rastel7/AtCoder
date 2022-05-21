#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b)
    {
        printf(c == 0 ? "Aoki\n" : "Takahashi\n");
    }
    else
    {
        printf(a < b ? "Aoki\n" : "Takahashi\n");
    }
}