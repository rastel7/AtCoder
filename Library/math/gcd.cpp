#include <bits/stdc++.h>
#define ll int


// 返り値: a と b の最大公約数
template <typename T>
ll gcd(T a, T b) {
    if (b == 0)
    {
        return a;
    }
    ll d = gcd(b, a % b);
    return d;
}
