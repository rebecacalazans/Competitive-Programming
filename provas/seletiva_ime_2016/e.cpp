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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e2*2+5;

int t, n;
map<string, string> m;
char a[N], b[N];
char c;

int main() {
  scanf("%d", &t);
  for(int tt = 0; tt < t; tt++) {
    m.clear();
    while(1) {
      scanf("%s%c", a, &c);
      strcpy(b, a);
      n = strlen(b);
      if(n > 2) sort(b+1, b+n-1);
      if(m[b] != "") m[b] = min(m[b], string(a));
      else m[b] = a;

      if(c == '\n') break;
    }
    while(1) {
      scanf("%s%c", a, &c);
      strcpy(b, a);
      n = strlen(b);
      if(n > 2) sort(b+1, b+n-1);
      printf("%s%c", m[b] != ""? m[b].c_str():a, c);

      if(c == '\n') break;
    }
  }
  return 0;
}
