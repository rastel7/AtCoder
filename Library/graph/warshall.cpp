template <class T>
/*  ワーシャルフロイド
    O(V)，全店最短路
    dis[i][i]=0を入力しておく
    dis[i][j]に，辺i-jのコストを入力しておく
    辺がなかったらINF
    負の閉路があったらdis[i][i]が負になるものが存在する*/
void warshall_floyd(T& dis) {
    int V = dis.size();
    REP(k, V)
        REP(i, V) {
        if(dis[i][k] == INF) continue;
        REP(j, V) {
            if(dis[k][j] == INF) continue;
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
}
int main(){
  
}