#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    REP(i, N)cin >> A[i] >> B[i];
    int ans = INF;
    REP(i, N) {
        REP(j, N) {
            if(i == j) {
                ans = min(A[i] + B[j], ans);
            } else {
                ans = min(max(A[i], B[j]), ans);
            }
        }
    }
    cout << ans << endl;
}