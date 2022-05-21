#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
typedef long double ld;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    ld N;
    cin >> N;
    ld ans = 0;
    for(ld i = 1;i < N;++i) {
        ans += N / (N - i);
    }
    cout << fixed << setprecision(10) << ans << endl;
}