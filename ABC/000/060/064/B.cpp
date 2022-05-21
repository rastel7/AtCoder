#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n)cin >> a[i];
    sort(a.begin(), a.end());
    cout << a.back() - a[0] << endl;
}