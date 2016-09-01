#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

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
int n, l, c;
int nlines;
int nc;
char s[100];

int main() {
  while(scanf("%d%d%d", &n, &l, &c)!=EOF) {
    nc=0;
    nlines=0;
    c++;
    for(int i=0; i<n; i++) {
      scanf(" %s", s);
      int aux=strlen(s)+1;
      nc+=aux;
      if(nc>c)nlines++, nc=aux;
    }
    if(nc)nlines++;
    printf("%d\n", (nlines+l-1)/l);
  }
  return 0;
}
