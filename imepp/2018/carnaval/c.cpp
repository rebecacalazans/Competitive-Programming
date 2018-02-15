#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;

int n;
int v[N];
int ans;

int main() {
  while(~scanf("%d", &n)) {
    ans = 0;
    for(int i=0; i<n; i++) scanf("%d", &v[i]);
    sort(v, v+n);
    for(int i=0; i<(n/2); i++) {
      ans+= v[n-i-1]-v[i];
    }
    printf("%d\n",ans);
  }
  return 0;
}
