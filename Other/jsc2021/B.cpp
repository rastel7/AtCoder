#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main()
{
    int N, M;
    cin >> N >> M;
    set<int> A, B;
    REP(i, N)
    {
        int a;
        cin >> a;
        A.insert(a);
    }
    vector<int> Ans;
    REP(i, M)
    {
        int b;
        cin >> b;
        B.insert(b);
    }
    for (int i = 1; i < 1e4; ++i)
    {
        int cnt = 0;
        if (A.count(i))
            cnt++;
        if (B.count(i))
            cnt++;
        if (cnt == 1)
            Ans.push_back(i);
    }
    REP(i, Ans.size())
    {
        cout << Ans[i];
        if (i != Ans.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}