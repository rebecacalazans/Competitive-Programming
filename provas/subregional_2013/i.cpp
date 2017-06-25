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
const int N = 2e3+5;

int n, c, t1, t2, ans;
int f[N];
int base;
int dp[N], ok[N];

int func(int i) {
  if(i >= n+base) return 0;
  if(ok[i] == base) return dp[i];
  int ans;
  int pos = upper_bound(f+base, f+base+n, f[i]+t1) - f;
  dp[i] = t1+func(pos);

  pos = upper_bound(f+base, f+base+n, f[i]+t2) - f;
  dp[i] = min(dp[i], t2+func(pos));

  ok[i] = base;
  return dp[i];

}


int main() {
  while(~scanf("%d%d%d%d", &n, &c, &t1, &t2)) {
    ans = INF;
    cl(dp, 63);
    cl(ok, -1);
    scanf("%d", &f[0]);
    for(int i=1; i<n; i++) {
      scanf("%d", &f[i]);
      f[i] -= f[0];
      f[i+n] = f[i]+c;
    }
    f[n] = c;
    f[0] = 0;


    for(base = 0; base<n; base++) {
      ans = min(ans, func(base));
    }
    printf("%d\n", ans);
  }
  return 0;
}
