#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int n;
    cin >> n;
    vector<ll> A(3 * n);
    REP(i, 3 * n)cin >> A[i];
    sort(A.begin(), A.end());
    ll sm = 0;
    for(int i = 3 * n - 2;i >= n;i -= 2) {
        sm += A[i];
    }
    cout << sm << endl;
}