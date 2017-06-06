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
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e4+5;

int s, t, cont;
vi adj[N], adjw[N];
ll vis[N], cic[N], dist[N];
int q, x, m;
int b;
ll ans;

void dfs(int u, int pa, ll val) {
  vis[u] = val;
  for(int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i], w = adjw[u][i];
    if(!vis[v]) {
      //db(u _ v);
      dfs(v, u, val+w);
      if(b) {
        cic[u] = cic[v];
        //db(u _ cic[u]);
        if(u == b) b = 0;
        return;
      }
    }
    else if(v != pa and !cic[v]) {
      b = v;
      cic[u] = cic[v] = vis[u] - vis[v] + w;
      //db( u _ v _ cic[u]);
      return;
    }
  }
}

void dijkstra(int x) {
  priority_queue<pii> pq;
  pq.push(mp(0, x));
  cl(dist, INF);
  dist[x] = 0;

  while(!pq.empty()) {
    int u = pq.top().nd, d = -pq.top().st;
    pq.pop();
    if(d > dist[u]) continue;
    for(int i=0; i<adj[u].size(); i++) {
      int v = adj[u][i], w = adjw[u][i];
      if(dist[v] > w+d) {
        dist[v] = w+d;
        pq.push(mp(-dist[v], v));
      }
    }
  }
}

int main() {
  while(~scanf("%d%d", &s, &t)) {
  //scanf("%d%d", &s, &t);
    for(int i=0; i<= s; i++) adj[i].clear(), adjw[i].clear();
    cl(vis, 0), cl(cic, 0);
    for(int i=0; i<t; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b,&c);
      adj[a].pb(b);
      adj[b].pb(a);
      adjw[a].pb(c);
      adjw[b].pb(c);
      //db(a _ b _ c);
    }

    for(int i=1; i<=s; i++) if(!vis[i]) dfs(i, 0, 1);
    scanf("%d", &q);
    for(int i=0; i<q; i++) {
      scanf("%d%d", &x, &m);
      //db(m);
      ans = LINF;
      dijkstra(x);
      for(int j=1; j<=s; j++) {
        //if (i == 0) db(j _ dist[j] _ cic[j]);
        if(cic[j] >= m and dist[j] != LINF) ans = min(cic[j] + 2*dist[j], ans);
      }
      printf("%lld\n", ans == LINF? -1: ans);
    }

  }
  return 0;
}
