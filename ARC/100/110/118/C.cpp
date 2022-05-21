#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
// 返り値: a と b の最大公約数
template <typename T> ll gcd(T a, T b) {
    if(b == 0) {
        return a;
    }
    ll d = gcd(b, a % b);
    return d;
}
int main() {
    int N;
    cin >> N;
    vector<int> Ans = {6, 10, 15};
    set<int> s;
    for(auto &x : Ans) {
        for(int i = 2; i * x <= 10000; ++i) {
            s.insert(i * x);
        }
    }
    for(auto x : s) {
        Ans.push_back(x);
        if(Ans.size() == N)
            break;
    }
    REP(i, N) {
        cout << Ans[i];
        if(i != N - 1)
            cout << " ";
    }
    cout << endl;
}