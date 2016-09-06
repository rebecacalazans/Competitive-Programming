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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e5+5;
int vis[N];
vi adj[N];
vector<ll> cost[N];
int n, m;
ll ans;
priority_queue<pair<ll, int> >pq;

void process(int u) {
  vis[u] = 1;
  for(int i=0; i<adj[u].size(); i++) {
    int v = adj[u][i];
    ll c = cost[u][i];
    if(!vis[v]) pq.push(mp(-c, v));
  }
}

int main() {
  scanf("%d%d", &n, &m);
  ans = 0;
  for(int i=0; i<m; i++) {
    int a, b;
    ll c;
    scanf("%d%d%lld", &a, &b, &c);
    adj[a].pb(b);
    adj[b].pb(a);
    cost[a].pb(c);
    cost[b].pb(c);
  }
  process(1);
  while(!pq.empty()) {
    int c = pq.top().st, u = pq.top().nd;
    pq.pop();
    if(!vis[u]) {
      ans-=c, process(u);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
