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
int v[N];
int ans[2];

int main() {
  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%d", &v[i]);

  sort(v, v+n);
  for(int i=n-1, j=0; i>=0; i--, j = 1-j) {
    ans[j] += v[i];
  }

  printf("%d %d\n", ans[0],  ans[1]);

  return 0;
}
