#include<bits/stdc++.h>
using namespace std;

int v;
int a[10];
int mi, ndig, cont;

int main() {
  scanf("%d", &v);
  for(int i=1; i<=9; i++) {
    scanf("%d", &a[i]);
    if(v/a[i] > ndig) {
      ndig = v/a[i];
      mi = a[i];
    }
  }

  if(ndig == 0) {
    printf("-1\n");
    return 0;
  }
  v -= ndig*mi;

  for(int i=9; i>=1; i--) {
    while(v >= a[i]-mi and cont < ndig) printf("%d", i), v-=a[i]-mi, cont++;
  }
  printf("\n");

  return 0;
}
