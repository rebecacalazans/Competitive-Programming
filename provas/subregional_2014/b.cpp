#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  n/=2;
  int i = 1, ans = 0;
  do {
    i=i<=n?i*2:(i-n)*2-1;
    ans++;
  } while (i != 1);
  printf("%d\n", ans);
  return 0;
}
