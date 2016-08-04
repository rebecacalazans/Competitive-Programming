#include <bits/stdc++.h>
using namespace std;

int n, l, s, t, m;
int ans[105][105], a[105][105];

void multiplicar(int a1[105][105], int a2[105][105]) {
  int aux[105][105];
  memset(aux, 0, sizeof(aux));
  for (int i=0; i<n; i++) for (int j=0; j<n; j++)
    for (int k=0; k<n; k++) aux[i][j]= (aux[i][j]+a1[i][k]*a2[k][j])%10000;

  for (int i=0; i<n; i++) for (int j=0; j<n; j++) a1[i][j] = aux[i][j];
}

void exp (int a[105][105], int k) {
  for (int i=0; i<n; i++) for (int j=0; j<n; j++) ans[i][j] = (i==j)? 1:0;

  while(k) {
    if(k%2) multiplicar(ans, a);
    k/=2;
    multiplicar(a, a);
  }
}

int main() {
  while (scanf("%d%d", &n, &l) != EOF) {
    scanf("%d%d", &s, &t);
    memset(a, 0, sizeof(a));
    for (int i=0; i<n; i++) for (int j=0; j<4; j++) {
      scanf("%d", &m);
      a[i][m-1]++;
    }
    exp(a,l);
    printf("%d\n", ans[s-1][t-1]);
  }
}
