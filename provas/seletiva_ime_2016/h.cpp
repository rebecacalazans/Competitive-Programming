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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 505;

int b[N], vis[N];
int voc[N][26], l[26];
int n, m;
char s[40];
int x, ans;
vector<int> adj[N];

bool match(int u) {
  if(vis[u] == x) return 0;
  vis[u] = x;
  for(int v:adj[u]) {
    if(!b[v] or match(b[v])) return b[v] = u;
  }
  return 0;
}

int main() {
  while(~scanf("%d%d", &n, &m)) {
    cl(voc, 0); cl(b, 0); cl(vis, 0);
    x = ans = 0;
    for(int i=1; i<=n; i++) adj[i].clear();

    for(int i=1; i<=n; i++) {
      scanf("%s", s);
      for(int j=0; s[j]; j++) voc[i][s[j]-'a']++;
    }

    for(int i=1; i<=m; i++) {
      cl(l, 0);
      scanf("%s", s);
      for(int j=0; s[j]; j++) l[s[j]-'a']++;

      for(int j=1; j<=n; j++) {
        int ok=1;
        for(int k=0; k<26; k++) if(voc[j][k] < l[k]) ok=0;
        if(ok) adj[j].pb(i);
      }
    }

    for(int i=1; i<=n; i++) x++, ans+=match(i);
    printf("%d\n", ans);
  }
  return 0;
}
