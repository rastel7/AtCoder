#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
vector<int> topological(const vector<vector<int>>& G) {
    vector<int> ans;
    int n = (int)G.size();
    vector<int> ind(n);//各頂点から出ている有向辺の次数
    for(int i = 0;i < n;++i) {
        for(auto& e : G[i]) {
            ind[e]++;
        }
    }
    queue<int> que;
    for(int i = 0;i < n;++i) {
        if(ind[i] == 0)que.push(i);
    }
    while(!que.empty()) {
        int now = que.front();
        ans.push_back(now);
        que.pop();
        for(auto& e : G[now]) {
            ind[e]--;
            if(ind[e] == 0) que.push(e);
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n), F(n);//Fは逆
    REP(i, n + m - 1) {
        int a, b;
        cin >> a >> b, a--, b--;
        G[a].push_back(b), F[b].push_back(a);
    }
    vector<int> tp=topological(G);
    vector<int> gyaku(n);//頂点iがトポロジカルソート後で何番目かを保存
    REP(i,n){
        gyaku[tp[i]]=i;
    }
    vector<int> ans(n);
    ans[tp[0]]=0;
    for(int i=1;i<n;++i){
        int v=tp[i];
        int dis=-1,id;
        for(auto &e:F[v]){
            if(dis<gyaku[e]){
                id=e;
                dis=gyaku[e];
            }
    
        }
        ans[tp[i]]=id+1;
    } 
    for(auto &i:ans){
        cout<<i<<endl;
    }
}