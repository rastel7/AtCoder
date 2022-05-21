#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    ll A, B, N;
    cin >> A >> B >> N;
    ll x = min(N, B - 1);
    cout << floor(A * x / B) - A * floor(x / B) << endl;
}