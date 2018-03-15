#include<bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;

const int N = 2e5+5;

int T, n;
int v[N], t[N];

ll merge(int l, int r) {

  ll ans = 0;
  int m = (l+r)/2+1;

  for(int i=l; i<=r; i++) t[i] = v[i];

  for(int i=l, j=m, p=l; i<m or j<=r; p++) {
    if(i == m or (j != r+1 and t[j] < t[i])) {
      v[p] = t[j];
      ans+=m-i;
      j++;
    }
    else {
      v[p] = t[i];
      i++;
    }
  }
  return ans;
}

ll divide(int l, int r) {
  if(l == r) return 0;
  ll ans = 0;

  ans += divide(l, (l+r)/2);
  ans += divide((l+r)/2 + 1, r);

  ans += merge(l, r);

  return ans;
}

int main() {
  scanf("%d", &T);
  for(int tt = 0; tt < T; tt++) {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &v[i]);
    printf("%lld\n", divide(0, n-1));
  }

  return 0;
}
