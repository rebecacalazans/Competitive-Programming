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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e3+50;

long long r;
int n;
int prox[N], ans[N];

int main() {
  while(~scanf("%d%lld", &n, &r)) {
    cl(ans, 0);
    for(int i=1; i<=n; i++) scanf("%d", &prox[i]);
    for(int i=1; i<=n; i++) {
      if(ans[i]) continue;

      int cont = 1, a = i, b;

      while(prox[a] != i) cont++, a = prox[a];

      a = b = i;
      cont = r%cont;
      ans[i] = i;

      for(int j=0; j<cont; j++) b = prox[b];
      ans[a] = b;

      while(!ans[prox[a]]) ans[prox[a]] = prox[b], a=prox[a], b=prox[b];
    }
    for(int i=1; i<=n; i++) printf("%d%c", ans[i], i==n?'\n':' ');

  }
  return 0;
}
