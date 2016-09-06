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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e6+5;
long long tot[N];
long long  n, m;
int a;

int main() {
  scanf("%lld%lld", &n, &m);
  for(long long i=0; i<n; i++) scanf("%d", &a), tot[a]++;

  for(long long i=1; i<=m; i<<=1) {
    if(m&i and tot[i]>0) tot[i]--, m-=i;
  }
  printf("%c\n", m? 'N':'S');

  return 0;
}
