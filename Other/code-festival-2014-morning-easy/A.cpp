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
    vector<ll> A(n);
    REP(i, n)cin >> A[i];
    cout << fixed << setprecision(10) << (double(A[n - 1] - A[0])) / ((double)(n - 1)) << endl;
}