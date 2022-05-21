#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int m, n, N;
    cin >> m >> n >> N;
    int now = N;
    while(m <= now) {
        N += (now / m) * n;
        now = (now / m) * n + now % m;
    }
    cout << N << endl;
}