#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint1000000007;
struct rational {
    ll a, b;
    //a:分子,b:分母
    rational(ll _a, ll _b) :a(_a), b(_b) {

        if(b == 0) {
            b = 0, a = 1;
            return;
        }
        if(b < 0) {
            a *= -1, b *= -1;
        }

    }
    bool operator==(const rational& r) {
        return a * r.a == b * r.b;
    }
    bool operator<(const rational& r) {
        //壊れてる
        if(a != r.a) {
            return a < r.a;
        }
        return b < r.b;
        return a * r.b < b* r.a;
    }
    bool operator>(const rational& r) {
        return a * r.b > b * r.a;
    }
    bool operator==(const rational& r) const {
        return rational(a, b) == r;
    }
    bool operator<(const rational& r) const {
        return rational(a, b) < r;
    }
    bool operator>(const rational& r) const {
        return rational(a, b) > r;
    }

    rational operator+(const rational& r) const {
        ll g = __gcd(b, r.b);
        ll lcm = b * r.b / g;
        rational ret(a * lcm / b + r.a * lcm / r.b, lcm);
        g = gcd(ret.a, ret.b);
        ret.a /= g, ret.b /= g;
        return ret;
    }
    rational operator-(const rational& r) const {
        ll g = __gcd(b, r.b);
        ll lcm = b * r.b / g;
        rational ret(a * lcm / b - r.a * lcm / r.b, lcm);
        g = gcd(ret.a, ret.b);
        ret.a /= g, ret.b /= g;
        return ret;
    }
    rational operator*(const rational& r) const {
        rational ret(a * r.a, b * r.b);
        return ret;
    }
    friend ostream& operator<<(ostream& os, const rational& r) {
        return (os << r.a << " / " << r.b);
    }
};
int main() {
    ll N;
    cin >> N;
    ll zero = 0;
    vector<ll> A(N), B(N);
    map<rational, pair<ll, ll> > mp;
    REP(i, N) {
        cin >> A[i] >> B[i];
        if(A[i] == 0 && B[i] == 0) {
            zero++;
            continue;
        }
        ll x = A[i], y = B[i];
        ll g = __gcd(x, y);
        x /= g, y /= g;
        if(y < 0)
            x = -x, y = -y;
        if(y == 0 && x < 0) {
            x = -x, y = -y;
        }
        bool rot90 = (x <= 0);
        if(rot90) {
            ll tmp = x;
            x = y, y = -tmp;
        }
        if(rot90)
            mp[rational(x, y)].first++;
        else
            mp[rational(x, y)].second++;
    }
    mint ans = 1;
    for(auto p : mp) {
        int s = p.second.first, t = p.second.second;
        mint now = 1;
        now += mint(2).pow(s) - 1;
        now += mint(2).pow(t) - 1;
        ans *= now;
    }
    ans -= 1;
    ans += zero;
    cout << ans.val() << endl;

}