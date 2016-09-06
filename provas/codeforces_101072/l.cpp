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
char s[N];
int n, a;
vector<pair<string, int> > v;

int main() {
  scanf("%d", &n);
  for(int i=1; i<=n; i++) {
    scanf("%d", &a);
    if(a) scanf("%s", s);
    sort(s, s+a);
    s[a] = 'A'+5;
    s[a+1] = 0;
    v.pb(mp(s,i));
  }
  sort(v.begin(), v.end());
  for(int i=0; i<v.size(); i++) {
    printf("%d\n", v[i].second);
  }

  return 0;
}
