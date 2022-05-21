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

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> X(N + 1, 0);
    vector<int> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        X[A[i]]++;
    }
    set<int> s;
    REP(i, N + 1) {
        if(X[i] == 0) {
            s.insert(i);
        }
    }
    int ans = *s.begin();
    for(int i = M;i < N;++i) {
        X[A[i - M]]--;
        if(X[A[i - M]] == 0)s.insert(A[i - M]);
        X[A[i]]++;
        if(s.find(A[i]) != s.end()) {
            s.erase(A[i]);
        }
        ans = min(*s.begin(), ans);
    }
    cout << ans << endl;
}