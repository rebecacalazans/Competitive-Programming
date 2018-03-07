#include <bits/stdc++.h>
using namespace std;

int coord[3][2];

bool is_right_angled() {
  vector<int> squared_sides;
  int sum = 0, ma = 0;

  for(int i=0; i<3; i++) {
    for(int j=i+1; j<3; j++) {
      int dx = coord[i][0] - coord[j][0], dy = coord[i][1] - coord[j][1];
      squared_sides.push_back(dx*dx + dy*dy);
    }
  }

  for(int s: squared_sides) {
    sum += s;
    ma = max(ma, s);
    if(s == 0) return false;
  }

  if(2*ma == sum) return true;
  return false;
}

int main() {
  for(int i=0; i<3; i++) for(int j=0; j<2; j++)
    scanf("%d", &coord[i][j]);

  if(is_right_angled()) {
    printf("RIGHT\n");
    return 0;
  }

  for(int i=0; i<3; i++) for(int j=0; j<2; j++) {
    coord[i][j] += 1;
    if(is_right_angled()) {
      printf("ALMOST\n");
      return 0;
    }
    coord[i][j] -= 2;
    if(is_right_angled()) {
      printf("ALMOST\n");
      return 0;
    }
    coord[i][j] += 1;
  }

  printf("NEITHER\n");

  return 0;
}
