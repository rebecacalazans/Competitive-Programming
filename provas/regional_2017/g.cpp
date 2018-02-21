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

int n;
int x[N], y[N], f[N];
ll dp[2][2][N];

void calc(int u) {
  if(u == 0) return;
  int a = x[u], b = y[u];

  calc(a);
  calc(b);

  dp[0][0][u] = (dp[1][1][a]*dp[1][1][b])%MOD;

  dp[0][1][u] = ((dp[1][0][a]*dp[1][1][b])%MOD + (dp[1][0][a]*dp[1][0][b])%MOD + (dp[1][1][a]*dp[1][0][b])%MOD)%MOD;

  dp[1][1][u] =((dp[1][0][a]*dp[0][0][b])%MOD + (dp[1][1][a]*dp[0][0][b])%MOD + (dp[1][0][a]*dp[0][1][b])%MOD + 
                (dp[0][0][a]*dp[0][0][b])%MOD + (dp[0][1][a]*dp[0][0][b])%MOD + (dp[0][0][a]*dp[0][1][b])%MOD + 
                (dp[0][0][a]*dp[1][0][b])%MOD + (dp[0][1][a]*dp[1][0][b])%MOD + (dp[0][0][a]*dp[1][1][b])%MOD)%MOD;

  dp[1][0][u] = ((dp[0][1][a]*dp[0][1][b])%MOD + (dp[0][1][a]*dp[1][1][b])%MOD + (dp[1][1][a]*dp[0][1][b])%MOD)%MOD;

  if(f[u] == 0) {
    dp[1][0][u] = (dp[1][0][u] + dp[1][1][u])%MOD;
    dp[0][0][u] = (dp[0][0][u] + dp[0][1][u])%MOD;
    dp[1][1][u] = 0;
    dp[0][1][u] = 0;
  }
  else if(f[u] == 1) {
    dp[1][1][u] = (dp[1][1][u] + dp[1][0][u])%MOD;
    dp[0][1][u] = (dp[0][1][u] + dp[0][0][u])%MOD;
    dp[1][0][u] = 0;
    dp[0][0][u] = 0;
  }
}

int main() {

  dp[0][0][0] = dp[1][1][0] =  1;

  scanf("%d", &n);

  for(int i=1; i<=n; i++) scanf("%d%d%d", &x[i], &y[i], &f[i]);

  calc(1);

  printf("%lld\n", (dp[0][1][1] + dp[1][0][1])%MOD);

  return 0;
}
