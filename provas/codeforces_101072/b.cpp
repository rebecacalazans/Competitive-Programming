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

ll mdc(ll a, ll b){return b? mdc(b, a%b):a;}

int main() {
  ll n, a, v;
  int m;
  scanf("%lld%d", &n, &m);
  v = n;
  for(int i=0; i<m; i++) {
    scanf("%lld", &a);
    v = mdc(max(a, v), min(a, v));
  }
  printf("%lld\n", n-n/v);

  return 0;
}
