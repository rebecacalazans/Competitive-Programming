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

int n, m;
ld r;
int ax, ay, bx, by;
ld ans;

ld dist(int d, int a, int b) {
  ld ans = (PI*abs(a-b))/m;
  ans *= d*r;

  //db(d _ a _ b _ ans);
  return ans;
}

int main() {
  scanf("%d%d%Lf", &m, &n,&r);
  scanf("%d%d%d%d", &ax, &ay, &bx, &by);

  r/=n;

  ans+=r*abs(ay-by);
  ld di = dist(min(ay, by), ax, bx);
  //db(di);
  int x = min(ay, by);

  for(int i=x; i>=0; i--) {
    ld aux = 2*(x-i)*r+dist(i, ax, bx);
    //db(aux _ i);
    di = min(aux, di);
  }

  printf("%.14Lf\n", ans+di);

  return 0;
}
