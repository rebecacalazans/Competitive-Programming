#include <bits/stdc++.h>
using namespace std;

int n, m, ans, a;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i<n; i++) {
    int aux = 0;
    for (int j = 0; j<m; j++) {
      scanf("%d", &a);
      if (a) aux++;
    }
    if (aux==m) ans++;
  }
  printf("%d\n", ans);
}
