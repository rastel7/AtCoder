#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    if(A > B) {
        cout << "Takahashi" << endl;
        return 0;
    }
    if(A == B) {
        if(N %(A+1) == 0 && N > A) {
            cout << "Aoki" << endl;
        } else {
            cout << "Takahashi" << endl;
        }
        return 0;
    }
    if(N <= A) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }
}