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

int n;
int xh, yh, xw, yw;
map<pii, int> s;
set<int> ys;
map<int, int> c;
int cont;

int BIT[N];

void update(int x, int v) {
  for(; x<N; x+=x&(-x)) BIT[x] = max(BIT[x], v);// db(x _ BIT[x]);
}
int query(int x) {
  int ans = 0;
  for(;x>0; x-=x&(-x)) ans = max(ans, BIT[x]);
  return ans;
}

int main() {
  scanf("%d", &n);
  scanf("%d%d%d%d", &xh, &yh, &xw, &yw);

  for(int i=0; i<n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if(xh > xw) x = -x;
    if(yh > yw) y = -y;
    s[mp(x, y)]++;
    ys.insert(y);
  }

  if(xh > xw) xh = -xh, xw = -xw;
  if(yh > yw) yh = -yh, yw = -yw;

  ys.insert(yh);
  ys.insert(yw);
  for(int y:ys) c[y] = ++cont;

  for(auto p:s) {
    int x = p.st.st, y = p.st.nd;
    int v = p.nd;
    //db(x _ y _ c[y]);
    if(x < xh or x > xw) continue;
    if(y < yh) continue;

    update(c[y], query(c[y])+v);
  }

  //db(c[yw]);
  printf("%d\n", query(c[yw]));

  return 0;
}
