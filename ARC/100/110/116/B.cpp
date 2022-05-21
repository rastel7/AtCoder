#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
using mint = modint998244353;
int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    vector<mint> M(N);
    REP(i, N) {
        cin >> A[i];
    }
    mint ans = 0;
    sort(A.begin(), A.end(), greater<>());
    REP(i, N) {
        M[i] = A[i];
    }
    mint sum = 0;
    mint tmp = 1;
    for(int i = 1;i < N;++i) {
        sum += M[i] * tmp;
        tmp *= 2;
    }
    tmp = mint(2).pow(N - 1);
    for(int i = 0;i < N - 1;++i) {
        ans +=  M[i] * (M[i] + sum);
        sum -= M[i + 1];
        sum /= 2;
    }
    ans += M[N - 1] * M[N - 1];
    cout << ans.val() << endl;
}