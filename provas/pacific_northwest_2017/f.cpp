#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

typedef ld type;

int comp(type a, type b) {
  return (a > b + EPS) - (a < b - EPS);
}

struct dist {
  ld x;
  dist(ld d = 0):x(d) {}
  bool operator<(const dist d) const {
    return comp(x, d.x) < 0;
  }
};

struct point {
  type x, y;

  point(type x = 0, type y = 0) : x(x), y(y) {}

  point operator -() { return point(-x, -y); }
  point operator +(point p) { return point(x+p.x, y+p.y); }
  point operator -(point p) { return point(x-p.x, y-p.y); }

  point operator *(type k) { return point(k*x, k*y); }
  point operator /(type k) { return point(x/k, y/k); }

  type operator *(point p) { return x*p.x + y*p.y; }
  type operator %(point p) { return x*p.y - y*p.x; }
  type operator !() {return (*this)*(*this); };

  bool onSegment(point a, point b) {
    if(comp((*this-a)%(b-a), 0)) return 0;
    return (comp(x, min(a.x, b.x)) >= 0 and
            comp(x, max(a.x, b.x)) <= 0 and
            comp(y, min(a.y, b.y)) >= 0 and
            comp(y, max(a.y, b.y)) <= 0);
  }
};
ostream &operator<<(ostream &os, const point &p) {
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}

int n;
vector<point> v;

point rotateCCW(point p, ld t) {
  return point(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t)); 
}

bool linesParallel(point a, point b, point c, point d) {
  return abs((a-b)%(c-d)) < EPS;
}

bool linesCollinear(point a, point b, point c, point d) {
  return abs((a-b)%(c-d)) < EPS and
         abs((a-b)%(a-c)) < EPS;
}

point lineIntersection(point a, point b, point c, point d) {
  b = b-a; d = c-d; c = c-a;
  return a + b*(c%d)/(b%d);
}

int calc(point p) {
  set<dist> s;
  for(point p2: v) {
    //db(p2 _ !(p-p2));
    s.insert(!(p - p2));
  }
  //for(auto x: s) db(x.x);

  return s.size();
}

pair<point, point> calc_med(point a, point b) {
  point aux = a - b;
  //aux = rotateCCW(aux, PI/2);
  aux = {aux.y, -aux.x};
  return {(a+b)/2, ((a+b)/2)+aux};
}

int ans;

void test(int i, int j, int a, int b) {
  auto k = calc_med(v[i], v[j]),
       c = calc_med(v[a], v[b]);
  if(linesParallel(k.st, k.nd, c.st, c.nd)) return;

  ans = min(ans, calc(lineIntersection(k.st, k.nd, c.st, c.nd)));
}

int main() {
  scanf("%d", &n);
  ans = n;
  for(int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v.pb({(ld)x, (ld)y});
  }

  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      ans = min(ans, calc((v[i]+v[j])/2));
    }
  }

  for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++)
    for(int k = 0; k < n; k++) for(int l = k+1; l < n; l++) {
      test(i, j, k, l);
  }

  printf("%d\n", ans);

  return 0;
}
