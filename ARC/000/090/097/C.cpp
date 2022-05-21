#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    string s;
    int K;
    cin >> s >> K;
    set<string> sets;
    vector<string> subs(0);
    for(int i = 0;i < s.size();++i) {
        string tmp = "";
        for(int j = i;j < s.size();++j) {
            tmp += s[j];
            bool b = true;
            REP(k, subs.size()) {
                if(subs[k] == tmp)b = 0;
            }
            if(!b)continue;
            if(subs.size() < 10) {
                subs.push_back(tmp);
            } else {
                if(subs.back() > tmp) {
                    subs.push_back(tmp);
                    sort(subs.begin(), subs.end());
                    subs.pop_back();
                }
            }
        }

    }
    sort(subs.begin(), subs.end());
    cout << subs[K - 1] << endl;
}