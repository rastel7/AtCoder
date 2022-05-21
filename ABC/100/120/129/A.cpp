#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int p, q, r;
    cin >> p >> q >> r;
    cout << min(p + q, min(p + r, r + q)) << endl;
}