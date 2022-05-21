#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

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
  rational X(5, 3), Y(7, 4);
  cerr << (X * Y) << endl;
}