#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int K, T;
    cin >> K >> T;
    vector<int> A(T);
    REP(i, T)cin >> A[i];
    sort(A.begin(), A.end());
    ll sm = 0;
    REP(i, T - 1)sm -= A[i];
    sm += A[T - 1];
    sm = max<ll>(sm-1, 0);
    cout << sm << endl;
}