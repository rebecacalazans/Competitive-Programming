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

int n, m, s;
int pa[N][30], mi[N][30], h[N];
vi adj[N], wadj[N];

vector<piii> edges;

int par[N], sz[N];
int vis[N];

int find(int a) {return par[a] == a? a: par[a] = find(par[a]); }
void unite(int a, int b) {
  if((a = find(a)) == (b = find(b))) return;
  if(sz[a] < sz[b]) swap(a, b);
  par[b] = a; sz[a] += sz[b];
}

void dfs(int u) {
  vis[u] = 1;
  for(int i=0; i<adj[u].size(); i++) {
    int v = adj[u][i], w = wadj[u][i];
    if(!vis[v]) {
      pa[v][0] = u;
      mi[v][0] = w;
      h[v] = h[u]+1;
      dfs(v);
    }
  }
}

int query(int a, int b) {
  if(h[a] < h[b]) swap(a, b);
  int m = INF;
  for(int i=20; i>=0; i--) {
    if((1<<i) <= (h[a]-h[b])) {
      m = min(mi[a][i], m);
      a = pa[a][i];
    }
  }

  if(a == b) return m;
  for(int i=20; i>=0; i--) {
    if(pa[a][i] != pa[b][i]) {
      m = min(mi[a][i], m);
      a = pa[a][i];
      m = min(mi[b][i], m);
      b = pa[b][i];
    }
  }

  m = min(m, mi[a][0]);
  m = min(m, mi[b][0]);
  return m;
}

int main() {
  while(~scanf("%d%d%d", &n, &m, &s)) {
    for(int i=0; i<=n; i++) adj[i].clear(), wadj[i].clear();
    edges.clear();
    cl(vis, 0);
    cl(pa, 0);
    cl(mi, 63);
    for(int i=1; i<=n; i++) par[i] = i, sz[i] = 1;

    for(int i=0; i<m; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      edges.pb(mp(c, mp(a,b)));
    }

    sort(edges.rbegin(), edges.rend());
    for(auto e: edges) {
      int a = e.nd.st, b = e.nd.nd, c = e.st;
      if(find(a) != find(b)) {
        adj[a].pb(b);
        adj[b].pb(a);
        wadj[a].pb(c);
        wadj[b].pb(c);
        unite(a, b);
      }
    }
    pa[1][0] = 1;
    dfs(1);

    for(int j=1; j<=20; j++) for(int i=1; i<=n; i++) {
      pa[i][j] = pa[pa[i][j-1]][j-1];
      mi[i][j] = min(mi[i][j-1], mi[pa[i][j-1]][j-1]);
    }

    for(int  i=0; i<s; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      printf("%d\n", query(a, b));
    }
  }
  return 0;
}
