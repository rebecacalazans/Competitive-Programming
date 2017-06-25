#include <bits/stdc++.h>
using namespace std;

int n, m, aux;
int b[10005];

int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(b, 0, sizeof(b));
    for (int i = 0; i<m; i++) {
      scanf("%d", &aux);
      if (!b[aux]) b[aux] = 1;
    }
    if (m==n) printf("*\n");
    else {
      for (int i = 1; i<= n; i++) {
        if (!b[i]) {
          printf("%d ", i);
        }
      }
      printf("\n");
    }
  }
  return 0;
}
