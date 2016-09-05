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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 105;
long long x, y;

long long cont(long long n) {
  long long  d = 2, ans = 0;
  n++;
  while(d/2 < n) {
    ans+=(n/d)*(d/2);
    ans+=(n%d - min(d/2, n%d));
    d*=2;
  }
  return ans;
}

int main() {
  while(~scanf("%lld%lld", &x, &y)) {
    printf("%lld\n", cont(y) - cont(x-1));
  }
  return 0;
}
