#include<bits/stdc++.h>
using namespace std;

double a, b, c, d;

int main() {
  scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
  printf("%.4lf\n", sqrt((a-c)*(a-c)+(b-d)*(b-d)));
  return 0;
}
