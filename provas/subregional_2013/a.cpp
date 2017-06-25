#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  while(scanf("%d%d%d", &a, &b, &c) != EOF) {
    if (a==b) {
      if (a==c) printf("*\n");
      else printf("C\n");
    }
    else {
      if (a == c) printf("B\n");
      else printf("A\n");
    }
  }
}
