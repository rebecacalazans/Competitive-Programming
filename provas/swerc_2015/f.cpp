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

struct edge {int v, c, f;};

int n, src, snk, h[N], ptr[N];
vector<edge> edgs;
vector<int> g[N];


void add_edge (int u, int v, int c, int d) {
  int k = edgs.size();
  edgs.push_back({v, c, 0});
  edgs.push_back({u, d, 0});
  g[u].push_back(k);
  g[v].push_back(k+1);
}

bool bfs() {
  memset(h, 0, sizeof h);
  queue<int> q;
  h[src] = 1;
  q.push(src);
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(int i : g[u]) {
      int v = edgs[i].v;
      if (!h[v] and edgs[i].f < edgs[i].c)
        q.push(v), h[v] = h[u] + 1;
    }
  }
  return h[snk];
}

int dfs (int u, int flow) {
  if (!flow or u == snk) return flow;
  for (int &i = ptr[u]; i < g[u].size(); ++i) {
    edge &dir = edgs[g[u][i]], &rev = edgs[g[u][i]^1];
    int v = dir.v;
    if (h[v] != h[u] + 1)  continue;
    int inc = min(flow, dir.c - dir.f);
    inc = dfs(v, inc);
    if (inc) {
      dir.f += inc, rev.f -= inc;
      return inc;
    }
  }
  return 0;
}

void getgraph() {
  int l, c, a, b;
  n = 2;
  src = 1;
  snk = 2;

  scanf("%d%d%d%d", &l, &c, &a, &b);
  for(int i=0; i<l; i++) for(int j=0; j<c; j++) {
    char tmp;
    scanf(" %c", &tmp);

    if(tmp == '.') add_edge(src, ++n, b, 0);
    else add_edge(++n, snk, b, 0);

  }

  for(int i=0; i<l; i++) for(int j=0; j<c; j++) {
      if(j) add_edge(c*i+j+3, c*i+j+2, a, a);
      if(i) add_edge(c*i+j+3, c*(i-1)+j+3, a, a);
  }
}

int dinic() {
  int flow = 0;
  while (bfs()) {
    memset(ptr, 0, sizeof ptr);
    while (int inc = dfs(src, INF)) flow += inc;
  }
  return flow;
}

int main() {
  getgraph();

  printf("%d\n", dinic());
  return 0;
}
