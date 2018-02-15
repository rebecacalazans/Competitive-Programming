#include<bits/stdc++.h>
using namespace std;

int n;
long long a, b, aux;

int main() {
  a = 0; b = 1;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    printf("%lld%c", a, i==n-1?'\n':' ');
    aux = a;
    a = b;
    b += aux;
  }
  return 0;
}
