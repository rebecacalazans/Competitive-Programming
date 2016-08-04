#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, y) memset(x, y, sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e3+5;

vi adj[N], radj[N];
int vis[N];
stack<int> stk;
map<int, int> ord;
int n, m;

void pos(int u) {
  vis[u]=1;
  for(int v : radj[u]) if(vis[v]==-1) pos(v);
  stk.push(u);
}
void dfs(int u, int k) {
  vis[u]=k;
  for(int v:adj[u]) if(vis[v]==-1) dfs(v, k);
}

int main() {
  while(~scanf("%d%d", &n, &m)) {
    ord.clear();
    for(int i=0; i<=n; i++) adj[i].clear(), radj[i].clear();
    for(int i=0; i<m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      adj[a].pb(b);
      radj[b].pb(a);
    }
    cl(vis, -1);
    for(int i=0; i<=n; i++) if(vis[i]==-1) pos(i);

    int cont=0;
    cl(vis, -1);
    while(!stk.empty()) {
      int u=stk.top();
      stk.pop();
      if(vis[u]==-1) dfs(u, u), ord[u]=1, cont++;
    }
    for(int i=0; i<=n; i++) {
      for(int v:adj[i]) {
        if(vis[i]!=vis[v] and ord[vis[v]]==1) ord[vis[v]]=0, cont--;
      }
    }
    cont-=ord[vis[0]];
    printf("%d\n", cont);

  }
  return 0;
}
