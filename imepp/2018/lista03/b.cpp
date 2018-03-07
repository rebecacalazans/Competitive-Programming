#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int coord[3][2];

bool is_right_angled() {
  vi squared_sides;

  for(int i=0; i<3; i++) {
    for(int j=i+1; j<3; j++) {
      int dx = coord[i][0] - coord[j][0], dy = coord[i][1] - coord[j][1];
      squared_sides.push_back(dx*dx + dy*dy);
    }
  }

  int sum = 0, ma = 0;

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
      db(i _ j _ 1);
      printf("ALMOST\n");
      return 0;
    }

    coord[i][j] -= 2;
    if(is_right_angled()) {
      db(i _ j _ -1);
      printf("ALMOST\n");
      return 0;
    }

    coord[i][j] += 1;
  }

  printf("NEITHER\n");

  return 0;
}
