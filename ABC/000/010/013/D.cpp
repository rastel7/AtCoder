#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
ll doubeling[64][100100];
int main() {
    ll N, M, D;
    cin >> N >> M >> D;
    vector<ll> A(M);
    REP(i, M)cin >> A[i];
    REP(i, N) {
        doubeling[0][i] = i;
    }
    REP(i, M) {
        int id = A[M - 1 - i];
        swap(doubeling[0][id - 1], doubeling[0][id]);

    }
    REP(i, 64) {
        REP(j, N) {
            doubeling[i + 1][j] = doubeling[i][doubeling[i][j]];
        }
    }

    REP(i, N) {
        int here = i;
        REP(j, 64) {
            if(D & ((ll)1 << j)) {
                here = doubeling[j][here];
            }
        }
        cout << here + 1 << endl;
    }
}