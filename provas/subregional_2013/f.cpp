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

int n, size, ans;
int v[N];

int main() {
  while(~scanf("%d", &n)) {
    ans = 0;
    cl(v, 0);
    for(int i=1; i<=n; i++) {
      scanf("%d", &v[i]);
      v[i]+=v[i-1];
    }
    size = v[n];
    if(size%3) {
      printf("0\n");
      continue;
    }
    size/=3;
    for(int i=0; v[i] <= size; i++) {
      if(binary_search(v, v+n, v[i]+size) and
         binary_search(v, v+n, v[i]+2*size)) ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
