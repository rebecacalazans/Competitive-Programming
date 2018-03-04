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
vi adj[N];
vector<ll> adjw[N];
priority_queue<pair<ll, pii>> pq;

int nex[N], vis[N];
vi ans;

bool dfs(int u) {
  if(vis[u]) return false;
  vis[u] = 1;

  if(u == 1) {
    ans.pb(u);
    return true;
  }

  for(int v:adj[u]) {
    if(nex[u] == v) continue;
    if(dfs(v)) {
      ans.pb(u);
      return true;
    }
  }
  return false;
}


int main() {
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; i++) {
    int a, b;
    ll c;
    scanf("%d%d%lld", &a, &b, &c);
    adj[a].pb(b);
    adj[b].pb(a);
    adjw[a].pb(c);
    adjw[b].pb(c);
  }

  pq.push(mp(0, mp(1, 1)));

  while(!pq.empty()) {
    ll c = -pq.top().st;
    int a = pq.top().nd.st,
        b = pq.top().nd.nd;
    pq.pop();
    //db(a _ b _ c);

    if(vis[b]) continue;
    vis[b] = 1;
    nex[b] = a;

    for(int i=0; i<adj[b].size(); i++) {
      int v = adj[b][i];
      ll w = adjw[b][i];
      w+=c;
      pq.push(mp(-w, mp(b, v)));
    }
  }

  //for(int i=0; i<n; i++) db(i _ nex[i]);

  cl(vis, 0);
  if (!dfs(0)) {
    printf("impossible");
  }
  else {
    reverse(ans.begin(), ans.end());
    printf("%d", (int)ans.size());
    for(int u:ans) printf(" %d", u);
  }
  printf("\n");


  return 0;
}
