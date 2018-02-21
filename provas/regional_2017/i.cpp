#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii; typedef pair<int, int> pii; 
const long double EPS = 1e-9;
const int N=1e5+5, M=25;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, r;
vector<int> adj[N], radj[N];
int h[N], vis[N];
int anc[M][N], ma[M][N];
int rt;
set<pii> roads;
map<pii, int> all;
int tot;

void mst() {
  priority_queue<pair<int, pii> > pq;
  pq.push(mp(0, mp(1, 1)));

  while(!pq.empty()) {
    int a, b, c;
    c = -pq.top().st;
    a = pq.top().nd.st;
    b = pq.top().nd.nd;
    pq.pop();

    if(vis[b]) continue;

    tot += c;
    roads.insert(mp(a, b));
    vis[b] = 1;

    h[b] = h[a]+1;
    anc[0][b] = a;
    ma[0][b] = c;

    for(int i=0; i<adj[b].size(); i++) {
      pq.push(mp(-radj[b][i], mp(b, adj[b][i])));
    }
  }
}

int lca(int u, int v) {
  int ans = 0;
  if(h[u] < h[v]) swap(u, v);

  for(int i=M-1; i>= 0; i--) if(h[u]-(1<<i) >= h[v])
    ans = max(ans, ma[i][u]), u = anc[i][u];

  if(u == v) return ans;

  for(int i=M-1; i>=0; i--) if(anc[i][u] != anc[i][v]) {
    ans = max(ans, ma[i][u]);
    ans = max(ans, ma[i][v]);
    u = anc[i][u];
    v = anc[i][v];
  }

  ans = max(ans, ma[0][u]);
  ans = max(ans, ma[0][v]);

  return ans;
}



int main(){

  rt = 1;
  scanf("%d%d", &n, &r);
  for(int i=1; i<=r; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    adj[a].pb(b);
    adj[b].pb(a);
    radj[a].pb(c);
    radj[b].pb(c);

    all[mp(a, b)] = c;
    all[mp(b, a)] = c;
  }

  mst();

  for(int i=1; i < M; i++) {
    for(int j=1; j<=n; j++) {
      anc[i][j] = anc[i-1][anc[i-1][j]];
      ma[i][j] = max(ma[i-1][j], ma[i-1][anc[i-1][j]]);
    }
  }

  int q;
  scanf("%d", &q);
  for(int i=0; i<q; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if(roads.count(mp(a, b)) + roads.count(mp(b, a))) {
      printf("%d\n", tot);
    }
    else {
      printf("%d\n", tot - lca(a, b) + all[mp(a, b)]);
    }
  }

  return 0;
}

