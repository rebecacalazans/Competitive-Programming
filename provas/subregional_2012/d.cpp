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
int n, v[N];

int main() {
  while(scanf("%d", &n)!=EOF){
    int tot, menor, maior;
    tot=menor=maior=0;
    for(int i=0; i<n; i++) scanf("%d", &v[i]), tot+=v[i];
    if(tot%n) {
      printf("-1\n");
      continue;
    }
    tot/=n;
    for(int i=0; i<n; i++) {
      if(v[i]>tot) maior+=v[i]-tot;
      else menor+=tot-v[i];
    }
    printf("%d\n", maior==menor? maior+1:-1);
  }
  return 0;
}
