#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
long long longpow(long long n, long long a, long long mod) {
    if(a == 0) return 1;
    if(a == 1) return n % mod;
    if(a % 2 == 1) return (n * longpow(n, a - 1, mod)) % mod;
    ll t = longpow(n, a / 2, mod) % mod;
    return (t * t) % mod;
}
ll score(string x, char c) {
    ll ret = 0;
    map<int, ll> mp;
    REP(i, 4) {
        mp[x[i] - '0']++;
    }
    mp[c - '0']++;
    ll tmp = 1e18;
    for(int i = 1;i < 10;++i) {
        ret += i * longpow(10, mp[i], tmp);
    }
    return ret;
}
int main() {
    ll K;
    string S, T;
    cin >> K >> S >> T;
    vector<ll> nums(10, K);
    REP(i, 4) {
        nums[S[i] - '0']--, nums[T[i] - '0']--;
    }
    nums[0] = 0;
    ll bunsi = 0;
    for(int i = 1;i <= 9;++i) {
        for(int j = 1;j <= 9;++j) {
            if(nums[i] <= 0 || nums[j] <= 0)continue;
            if(i == j && nums[i] <= 1)continue;
            if(score(S, i + '0') <= score(T, j + '0'))continue;
            //cout << i << " " << j << endl;
            if(i != j) {
                bunsi += nums[i] * nums[j];
            } else {
                bunsi += nums[i] * (nums[j] - 1);
            }
        }
    }
    ll bunbo = 9 * K - 8;
    bunbo = bunbo * (bunbo - 1);
    cout << fixed << setprecision(10) << (double)bunsi / (double)bunbo << endl;
}