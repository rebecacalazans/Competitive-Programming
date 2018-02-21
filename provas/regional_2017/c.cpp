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

int n, k;
map<int, int> freq, val;
vi x;
int v[N];

int main() {
  scanf("%d%d", &k, &n);
  for(int i=0; i<n; i++) {
    int a;
    scanf("%d", &a);
    v[a]++;
  }
  for(int i=1; i<=k; i++) freq[v[i]]++, val[v[i]] = i;

  if(freq.size() > 3) {
    printf("*\n");
    return 0;
  }

  for(auto it =  freq.begin(); it != freq.end(); it++) x.pb(it->st);

  if(x.size() == 2) {
    if(freq[x[0]] == 1 and x[0] == x[1]-1) printf("+%d\n", val[x[0]]);
    else if(freq[x[1]] == 1 and x[0] == x[1]-1) printf("-%d\n", val[x[1]]);
    else printf("*\n");
    return 0;
  }
  if(x.size() == 3) {
    if(freq[x[0]] == 1 and freq[x[2]] == 1 and x[0] == x[1]-1 and x[2] == x[1]+1) printf("-%d +%d\n", val[x[2]], val[x[0]]);
    else printf("*\n");
    return 0;
  }

  return 0;
}
