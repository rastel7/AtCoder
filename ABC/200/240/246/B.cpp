#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    long double A, B;
    cin >> A >> B;
    long double abs = sqrt(A * A + B * B);
    A /= abs, B /= abs;
    cout << fixed << setprecision(10) << A << " " << B << endl;
}