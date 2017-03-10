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
const int INF = 0x3f3f3f3f, MOD = 2147483647;
const int N = 2e3+5;

int n;
ll l[N], r[N], v[N];


int main() {
  scanf("%d", &n);
  n++;
  for(int i=0; i<n; i++) scanf("%lld", &v[i]);
  l[v[0]] = 1;
  r[v[1]] = 1;
  for(int i=2; i<n; i++) {
    for(int j=1; j<=n; j++) {
      if(j<v[i]) {
        r[v[i]] = (r[v[i]] + l[j])%MOD;
        r[j] = 0;
      }
      if(j>v[i]) {
        l[v[i]] = (l[v[i]] + r[j])%MOD;
        l[j] = 0;
      }
    }
  }
  printf("%lld\n", (l[v[n-1]] + r[v[n-1]])%MOD);
  return 0;
}
