#include <bits/stdc++.h>
using namespace std;

int x, y, ans;
int main() {
  scanf("%d%d", &x, &y);
  printf("%d\n", (y+y-x-1)/(y-x));
  return 0;
}
