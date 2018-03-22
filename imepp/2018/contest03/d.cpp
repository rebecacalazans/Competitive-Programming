#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int t;
int m, w, ans;
int v[N];

int main() {
  scanf("%d", &t);
  for(int tt=0; tt<t; tt++) {
    scanf("%d%d", &m, &w);
    ans = 0;

    for(int i=0; i<m; i++) scanf("%d", &v[i]);
    sort(v, v+m);

    for(int i=0; i<m; i++) {
      if(v[i] <= w) {
        ans++;
        w -= v[i];
      }
    }

    printf("%d\n", ans);
  }
  return 0;
}
