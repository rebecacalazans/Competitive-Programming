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

int n, b, r;
int vis[N];
vi adj[N];
vector<ll> adjw[N];
int xb[N], yb[N], xr[N], yr[N];
ll ma;

int x;


bool match(int u, ll w, int m[N], int vis[N]) {
  if(vis[u] == x) return 0;
  vis[u] = x;

  for(int i=0; i<adj[u].size(); i++) {
    int v = adj[u][i];
    if(adjw[u][i] >= w) continue;

    //db(u _ v _ adjw[u][i]);
    if(!m[v] or match(m[v], w, m, vis)) return m[v] = u;
  }
  return 0;
}

bool kuhn(ll w) {
  int k = 0;
  int m[N] = {};
  int vis[N] = {};

  for(int i=1; i<=b; i++) x++, k+=match(i, w, m, vis);

  //db(w _ k);

  if(r+b-k >= n) return true;
  return false;
}

int bs(int l, int r) {
  while(l < r) {
    int m = (l+r+1)/2;
    //db(m);
    if(kuhn(m)) l = m;
    else r = m-1;
  }
  //db(r);
  return r;
}

int main() {
  scanf("%d%d%d", &n, &b, &r);

  for(int i=1; i<=b; i++) scanf("%d%d", &xb[i], &yb[i]);
  for(int i=1; i<=r; i++) scanf("%d%d", &xr[i], &yr[i]);

  for(int i=1; i<=b; i++) for(int j=1; j<=r; j++) {
    adj[i].pb(j);
    ll w = (xb[i]-xr[j])*(xb[i]-xr[j]) +
            (yb[i]-yr[j])*(yb[i]-yr[j]);
    ma = max(w, ma);

    adjw[i].pb(w);
  }

  printf("%.10Lf\n", sqrt((ld)bs(0, ma)));

  return 0;
}
