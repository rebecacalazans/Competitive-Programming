#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+5;

ll v[N];
ll n, a;
double h;

int main() {
  while(scanf("%lld%lld", &n, &a), n) {
    ll sum = 0;
    for(int i=1; i<=n; i++) scanf("%lld", &v[i]), sum += v[i];
    v[n+1] = 0;

    if(sum == a) {
      printf(":D\n");
      continue;
    }
    if(sum < a) {
      printf("-.-\n");
      continue;
    }

    sort(v+1, v+n+1, greater<int>());

    h = v[1];
    for(int i=1; i<=n; i++) {
      long long aux = (v[i]-v[i+1])*i;
      if(aux < a) {
        a -= aux;
        h -= (v[i] - v[i+1]);
        continue;
      }
      h -= ((double)a)/i;
      printf("%.4lf\n", h);
      break;
    }
  }
}
