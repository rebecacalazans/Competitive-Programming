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

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7, N = 1e5+5;

int n, m;
ll x[N], y[N];
ll ans[4];

int main() {
  ans[0] = ans[3] = 0;
  ans[1] = ans[2] = INF;

  scanf("%d", &n);
  for(int i=0; i<n; i++) {

    scanf("%d", &m);

    for(int j=0; j<m; j++) scanf("%lld%lld", &x[j], &y[j]);

    sort(x, x+m);
    sort(y, y+m);

    ans[0] = max(ans[0], y[m/2-(!(m%2))]);
    ans[1] = min(ans[1], y[m/2]);
    ans[2] = min(ans[2], x[m/2]);
    ans[3] = max(ans[3], x[m/2-(!(m%2))]);
  }

  printf("%lld\n", (ans[0]<ans[1] || ans[3]<ans[2])? 0:(ans[0]-ans[1])*(ans[3]-ans[2]));

  return 0;
}
