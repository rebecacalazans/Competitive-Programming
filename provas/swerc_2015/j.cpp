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
const int N = 1e4+5;

struct point {
  ld x, y;
  point operator+(point p) {return {x+p.x, y+p.y};}
  point operator-(point p) {return {x-p.x, y-p.y};}
  point operator*(ld k) {return {x*k, y*k};}
  point operator/(ld k) {return {x/k, y/k};}
  ld operator*(point p) {return x*p.x+y*p.y;}
  ld operator%(point p) {return x*p.y - y*p.x;}
  ld mod() {return sqrt(x*x + y*y);}
  void operator=(point p) {x = p.x, y=p.y;}
  bool operator==(point p) {return abs(x-p.x) < EPS && abs(y-p.y) < EPS;}
};

point pt[N];
int ordem[N];
point base;
int pos;
int n, s;
vector<int> v;
int ans;

//Convex hull
bool ord(int a, int b) {
  if(pt[a] == base) return false;
  if(pt[b] == base) return true;
  ld prod = (pt[a]-base)%(pt[b]-base);
  if(prod> EPS) return true;
  if(prod< -EPS) return false;
  return (pt[a]-base).mod() >  (pt[b]-base).mod();
}

int bs(point p) {
  int m;
  int l = 0, r = v.size()-3;
  while(r>l) {
    m = (r+l+1)/2;
    point a = pt[v[m]];
    ld prod = (p-base)%(a-base);
    if(prod > -EPS) r=m-1;
    else l=m;
  }
  return l;
}

bool isinside(point p) {
  if((p-base)%(pt[v[0]]-base) > EPS) return false;
  else if((p-base)%(pt[v[v.size()-3]]-base) < -EPS) return false;
  int x = bs(p);
  point a = pt[v[x]], b = pt[v[x+1]];
  ld sum = abs((base-p)%(b-p)) + abs((base-p)%(a-p)) + abs((b-p)%(a-p));
  if(abs(sum-abs((a-base)%(b-base))) < EPS) return true;
  return false;
}


int main() {
  scanf("%d", &n);
  base.x = INF, base.y = INF;
  for(int i=0; i<n; i++) {
    double x, y;
    scanf("%lf%lf", &x, &y);
    pt[i].x = x, pt[i].y = y;
    if(pt[i].y < base.y) base = pt[i];
    else if(pt[i].y == base.x && pt[i].x < base.x) base = pt[i];
  }

  for(int i=0; i<=n; i++) ordem[i] = i;
  sort(ordem, ordem+n, ord);


  v.pb(ordem[n-1]);
  v.pb(ordem[0]);

  for(int i=1; i<n; i++) {
    int ok=0;
    do{
      point a=pt[v[v.size()-2]], b = pt[v[v.size()-1]], c = pt[ordem[i]];
      ld prod = (b-a)%(c-a);
      if(prod > EPS) v.pb(ordem[i]), ok=1;
      else if(prod < -EPS) v.pop_back();
      else {
        if((c-a).mod() > (b-a).mod()) {
          v.pop_back();
          v.pb(ordem[i]);
        }
        ok=1;
      }
    } while(!ok and v.size()>=2);
  }

  sort(v.begin(), v.end(), ord);




  scanf("%d", &s);
  for(int i=0; i<s; i++) {
    point p;
    double x, y;

    scanf("%lf%lf", &x, &y);
    p.x = x, p.y = y;
    if(isinside(p)) ans++;
  }

  printf("%d\n", ans);




  return 0;
}
