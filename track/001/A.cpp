#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
struct Point {
    long double x, y, z;
    void normalize() {
        auto size = sqrtl(x * x + y * y + z * z);
        x /= size, y /= size, z /= size;
    }
};
Point operator-(const Point &l, const Point &r) {
    return Point{l.x - r.x, l.y - r.y, l.z - r.z};
}
Point operator+(const Point &l, const Point &r) {
    return Point{l.x + r.x, l.y + r.y, l.z + r.z};
}
long double dot(const Point &l, const Point &r) {
    return l.x * r.x + l.y * r.y + l.z * r.z;
}
long double dist(const Point &l, const Point &r) {
    return sqrtl((l.x - r.x) * (l.x - r.x) + (l.y - r.y) * (l.y - r.y) +
                 (l.z - r.z) * (l.z - r.z));
}
char Color[3] = {'R', 'G', 'B'};
Point A, B;
long double calc_dist(Point p) {
    auto vec1 = p - A;
    auto vec2 = B - A;
    auto v = vec2;
    v.normalize();
    auto keisuu = dot(vec1, v);
    v.x *= keisuu, v.y *= keisuu, v.z *= keisuu;
    auto P = A + v;
    if(dot(P - A, P - B) > 0) {
        return min(dist(p, A), dist(p, B));
    }
    return dist(P, p);
}
int main() {
    cin >> A.x >> A.y >> A.z;
    cin >> B.x >> B.y >> B.z;
    int N;
    cin >> N;
    map<char, long double> mp;
    REP(i, 3) mp[Color[i]] = 1e18;
    while(N--) {
        REP(i, 3) {
            auto &num = mp[Color[i]];
            Point p;
            cin >> p.x >> p.y >> p.z;
            num = min(num, calc_dist(p));
        }
    }
    char c = 'R';
    long double ans = mp[c];
    REP(i, 3) {
        if(ans > mp[Color[i]]) {
            c = Color[i];
            ans = mp[Color[i]];
        }
    }
    cout << c << endl;
    cout << fixed << setprecision(10) << ans << endl;
}