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
map<string, ld> ma;
map<string, int> vis;
char s[20], t[20];
ld r;

int main() {
  vis["pink"] = 1;

  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%s%s%Lf", s, t, &r);
    if(vis[t]) {
      if(vis[s]) {
        ma[s] = max(ma[s], ma[t]+log(r));
      }
      else ma[s] = ma[t]+log(r), vis[s] = 1;


      if(!strcmp(s, "blue") and ma[s] > log(10.0)) {
        printf("10\n");
        return 0;
      }
    }
    //db(i _ vis["blue"]);
  }

  if(!vis["blue"]) printf("0\n");
  else printf("%.10Lf\n", exp(ma["blue"]));
  return 0;
}
