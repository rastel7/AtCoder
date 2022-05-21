#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int n;
    cin >> n;
    vector<int> A(n), B;
    REP(i, n)cin >> A[i];
    B = A;
    map<int, int> mp;
    sort(B.begin(), B.end());
    REP(i, n) {
        mp[B[i]] = i;
    }
    int ans = 0;
    REP(i, n) {
        if(i % 2 != mp[A[i]] % 2) {
            ans++;
        }
    }
    cout << ans / 2 << endl;
}