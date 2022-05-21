#include <iostream>
#include <string>
#include<cmath>
using namespace std;
const double EPS = 1e-6;
struct V3 {
  double x, y, z;
  void normalize() {
    double _abs = sqrt(x * x + y * y + z * z);
    x /= _abs, y /= _abs, z /= _abs;
  }
};
double calc_dist(V3 l, V3 r) {
  double ret = pow(l.x - r.x, 2) + pow(l.y - r.y, 2) + pow(l.z - r.z, 2);
  return sqrt(ret);
}
//lをdir方向へ絶対値distだけ加算
V3 add(V3 l, V3 dir, float dist) {
  dir.normalize();
  l.x += dir.x * dist;
  l.y += dir.y * dist;
  l.z += dir.z * dist;
  return l;
}
//lにrを加算
V3 add(V3 l, V3 r) {
  l.x += r.x;
  l.y += r.y;
  l.z += r.z;
  return l;
}
//lからrを減算
V3 sub(V3 l, V3 r) {
  l.x -= r.x;
  l.y -= r.y;
  l.z -= r.z;
  return l;
}
//ベクトルlをr倍
V3 mul(V3 l, double r) {
  l.x *= r;
  l.y *= r;
  l.z *= r;
  return l;
}
//lとrの内積
double dot(V3 l, V3 r) {
  return l.x * r.x + l.y * r.y + l.z * r.z;
}
//lからrへの向き
V3 calc_dir(V3 l, V3 r) {
  double x = r.x - l.x;
  double y = r.y - l.y;
  double z = r.z - l.z;
  V3 ret(V3{ x,y,z });
  ret.normalize();
  return ret;
}
//pからtargetまでが，ベクトルdirの正方向に進んでいるか確認
double is_forward(V3 p, V3 target, V3 dir) {
  dir.normalize();
  target.x -= p.x;
  target.y -= p.y;
  target.z -= p.z;
  double ret = target.x / dir.x;
  if(ret == 0) ret = target.y / dir.y;
  if(ret == 0) ret = target.z / dir.z;
  return ret;
}

string solve() {
  double q, r;
  V3 e, p, v;
  cin >> q >> e.x >> e.y >> e.z;
  cin >> r >> p.x >> p.y >> p.z;
  cin >> v.x >> v.y >> v.z;
  v.normalize();//vを正規化
  V3 target = mul(v, dot(sub(e, p), v));
  target = add(p, target);//球eからベクトルvに垂線を出した場合に，vと交差する点
  //球qから見てvとは逆方向に垂線を出していた場合は，pとeの距離が半径の和より小さいときのみ命中
  if(is_forward(p, target, v) < 0) {
    if(calc_dist(p, e) <= r + q + EPS) {
      return "YES";
    } else {
      return "NO";
    }
  }
  //球eと交点targetの距離が半径の合計以下なら命中
  if(calc_dist(target, e) <= r + q + EPS) {
    return "YES";
  } else {
    return "NO";
  }
}

int main(int argc, char* argv[]) {
  cout << solve() << endl;
}
