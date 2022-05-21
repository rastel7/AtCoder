#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    REP(i, N)cin >> A[i];
    int cnt1 = 0, cnt2 = 0, cp = A[0];
    while(cp % 2 == 0) {
        cnt1++, cp /= 2;
    }
    REP(i,N){
        cnt2=0,cp=A[i];
        while(cp%2==0){
            cnt2++,cp/=2;
        }
        if(cnt2!=cnt1){
            cout<<0<<endl;
            return 0;
        }
    }
    ll lcm = 1;
    REP(i, N) {
        lcm = lcm / __gcd(lcm, A[i]/2) * A[i]/2;
    }
    cout << (1 + M / lcm) / 2 << endl;
}