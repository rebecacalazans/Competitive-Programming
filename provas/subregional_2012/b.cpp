#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e5+5;

struct pt{
  ld x, y;
  pt(ld x=0, ld y=0):x(x), y(y){}
  pt operator+(pt p) {return pt(x+p.x, y+p.y);}
  pt operator-(pt p) {return pt(x-p.x, y-p.y);}
  pt operator*(ld k) {return pt(x*k, y*k);}
  pt operator/(ld k) {return pt(x/k, y/k);}
  ld operator*(pt p) {return (x*p.x + y*p.y);}
  ld operator%(pt p) {return (x*p.y - y*p.x);}
  ld mod() {return sqrt(x*x+y*y);}
};
double dist(pt a, pt b) {return (a-b).mod();}
double dist_seg(pt p, pt a, pt b) {
  ld d1 = (p-a)*(b-a);
  ld d2 = (p-b)*(a-b);
  if((d1>0)&&(d2>0)) {
    pt proj= (b-a)*( ((b-a)*(p-a))/((b-a)*(b-a)) ) + a;
    return dist(p, proj);
  }
  return min(dist(p,a), dist(p,b));
}

pt p, a, b;
int n;
double l, h;
double yi, xf, yf;
double ans;

int main() {
  while(~scanf("%d", &n)) {
    scanf("%lf%lf", &l, &h);
    scanf("%lf%lf%lf", &yi, &xf, &yf);
    a=pt(0, yi);
    b=pt(xf,yf);
    ans=l-xf;
    for(int i=1; i<n; i++) {
      p=b;
      scanf("%lf%lf%lf", &yi, &xf, &yf);
      a=pt((i%2)?l:0, yi);
      b=pt(xf,yf);
      double aux= (i%2)?xf:(l-xf);
      ans=min(ans, aux);
      ans=min(ans, dist_seg(p, a, b));
    }
    printf("%.2lf\n", ans);
  }
}
