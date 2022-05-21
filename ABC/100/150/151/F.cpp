#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
struct P {
    double x, y;
};
const int INF = 1e9;
const ll MOD = 1000000007;
int n;
vector<P> p;
double distance(P a, P b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
double g(double x, double y) {
    double ret = 0;
    REP(i, n) {
        ret = max(ret, distance(P{ x, y }, p[i]));
    }
    return ret;
}
double f(double x) {
    double l = 0, r = 1000;
    REP(i, 100) {
        double m1 = l + (r - l) / 3, m2 = l + (r - l) * 2 / 3;
        if(g(x, m1) > g(x, m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }
    return g(x, l);
}
int main() {
    cin >> n;
    p.resize(n);
    REP(i, n)cin >> p[i].x >> p[i].y;
    double l = 0, r = 1000;
    REP(i, 100) {
        double m1 = l + (r - l) / 3, m2 = l + (r - l) * 2 / 3;
        if(f(m1) > f(m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }
    cout << fixed << setprecision(10) << f(l) << endl;
}