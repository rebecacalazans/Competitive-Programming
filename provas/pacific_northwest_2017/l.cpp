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

int calcm(ld k, ld p, ld x) {
  ld m = sqrt((k*p)/x);
  return m;
};

ld func(ld k, ld p, ld x) {
  ld m = calcm(k, p, x);
  ld ans = (k*p)/m + x*m;
  m++;
  ans = min(ans, (k*p)/m + x*m);
  m -= 2;
  ans = min(ans, (k*p)/m + x*m);
  return ans;
}

int k, p, x;

int main() {
  scanf("%d%d%d", &k, &p, &x);
  printf("%.3Lf\n", func(k, p, x));

  return 0;
}
