#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
const double PI = acos(-1);
pair<double, double>  rotation(pair<double, double> v, double ang) {
    double theta = ang;//(2.0 * PI * ang) / 360.0;
    return make_pair(v.first * cos(theta) - v.second * sin(theta), v.first * sin(theta) + v.second * cos(theta));
}
int main() {
    double N;
    cin >> N;
    double x_0, y_0, x_a, y_a;
    cin >> x_0 >> y_0 >> x_a >> y_a;
    double ang = (N / 2 + 1 - 2) * 180.0;
    double div = 180.0 * (N - 2) / N;
    ang -= ((N / 2) - 1) * div;
    ang = (2.0 * PI * (ang / 2.0)) / 360.0;
    double siz = sqrt(powl(x_0 - x_a, 2.0) + powl(y_0 - y_a, 2.0)) * cos(ang);
    double s = sqrt(powl(x_0 - x_a, 2.0) + powl(y_0 - y_a, 2.0));
    pair<double, double> v = make_pair((x_a - x_0) / s, (y_a - y_0) / s);
    v = rotation(v, -ang);
    double ans_x = x_0 + siz * v.first;
    double ans_y = y_0 + siz * v.second;
    cout << fixed << setprecision(10) << ans_x << " " << ans_y << endl;
}