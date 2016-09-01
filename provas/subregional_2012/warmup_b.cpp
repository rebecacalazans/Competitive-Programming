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
int d_, vf_, vg_;
double d, vf, vg;

int main() {
  while(~scanf("%d%d%d", &d_, &vf_, &vg_)) {
    d = d_, vf = vf_, vg = vg_;
    d = sqrt(12.0*12.0+d*d);
    vf = 12.0/vf;
    vg = d/vg;
    printf("%c\n", vg>vf?'N':'S');
  }
  return 0;
}
