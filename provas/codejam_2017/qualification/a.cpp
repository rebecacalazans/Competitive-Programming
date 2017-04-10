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

char s[N];
int t, k, n;
int ans, ok;


int main() {
  scanf("%d", &t);
  for(int tt=1; tt<=t; tt++) {
    ans = 0; ok=1;
    scanf("%s%d", s, &k);
    n = strlen(s);

    for(int i=0; i<=n-k; i++) {
      if(s[i] == '-') {
        ans++;
        for(int j=0; j<k; j++) {
          if(s[i+j] ==  '-') s[i+j] = '+';
          else s[i+j] = '-';
        }
      }
    }
    for(int i=1; i<=k; i++) {
      if(s[n-i] == '-') ok=0;
    }

    printf("Case #%d: ", tt);
    if(!ok) printf("IMPOSSIBLE\n");
    else printf("%d\n", ans);
  }

  return 0;
}
