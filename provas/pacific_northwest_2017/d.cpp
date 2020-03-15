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
const int N = 5e4+5;

int n;
map<int, int> cnt_colors[N];
int pa[N];
int cnt[N];
int not_rainbow[N];
int ans;

vector<pii> adj[N];

void dfs1(int u) {
  for(auto p: adj[u]) {
    int v = p.st;
    int c = p.nd;
    if(v == pa[u]) continue;
    pa[v] = u;
    dfs1(v);
    if(cnt[v] or cnt_colors[v][c] > 1) {
      cnt[u]++;
      not_rainbow[v] = 1;
    }
  }
}

void dfs2(int u) {
  for(auto p: adj[u]) {
    int v = p.st;
    int c = p.nd;
    if(v == pa[u]) continue;

    if(cnt[u] - not_rainbow[v]) {
      cnt[v]++;
    }
    else if(cnt_colors[u][c] > 1) {
      cnt[v]++;
    }
    dfs2(v);
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i < n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    adj[a].pb({b, c});
    adj[b].pb({a, c});
    cnt_colors[a][c]++;
    cnt_colors[b][c]++;
  }

  dfs1(1);
  dfs2(1);

  for(int i = 1; i <= n; i++) if(!cnt[i]) ans++;

  printf("%d\n", ans);
  for(int i = 1; i <= n; i++) if(!cnt[i]) printf("%d\n", i);

  return 0;
}
