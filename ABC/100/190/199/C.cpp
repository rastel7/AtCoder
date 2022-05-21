#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main()
{
    int N;
    cin >> N;
    string S, L, R;
    cin >> S;
    REP(i, N)
    {
        L.push_back(S[i]);
        R.push_back(S[i + N]);
    }
    int Q;
    cin >> Q;
    bool b = true;
    while (Q--)
    {
        int T, A, B;
        cin >> T >> A >> B;
        if (T == 2)
        {
            b = !b;
            continue;
        }
        A--, B--;
        char now_a, now_b;
        if (b)
        {
            if (A >= N)
                now_a = R[A % N];
            else
                now_a = L[A];
            if (B >= N)
                now_b = R[B % N];
            else
                now_b = L[B];
        }
        else
        {
            if (A >= N)
                now_a = L[A % N];
            else
                now_a = R[A];
            if (B >= N)
                now_b = L[B % N];
            else
                now_b = R[B];
        }
        if (b)
        {
            if (A >= N)
                R[A % N] = now_b;
            else
                L[A] = now_b;
            if (B >= N)
                R[B % N] = now_a;
            else
                L[B] = now_a;
        }
        else
        {
            if (A >= N)
                L[A % N] = now_b;
            else
                R[A] = now_b;
            if (B >= N)
                L[B % N] = now_a;
            else
                R[B] = now_a;
        }
    }
    if (b)
    {
        cout << L << R << endl;
    }
    else
    {
        cout << R << L << endl;
    }
}