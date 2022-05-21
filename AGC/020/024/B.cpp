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
int s(int l, int r) {
    return max(l, r);
}
int e() {
    return 0;
}
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N)cin >> A[i];
    segtree<int, s, e> seg(200100);
    REP(i, N) {
        int mx = seg.prod(A[i]-1, A[i]);
        seg.set(A[i], mx + 1);
    }
    cout << N  - seg.all_prod() << endl;
}