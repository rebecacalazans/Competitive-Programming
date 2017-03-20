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

queue<string> q[7];
char s[30];
int day;
map<string, int> m;
set<pair<int, string> > c;
int n;

int main() {

  while(~scanf("%s", s)) {
    if(!strcmp(s, "<text>")) {
      day = (day+1)%7;
      while(!(q[day]).empty()) {
        string aux = (q[day]).front();
        (q[day]).pop();

        c.erase(mp(-m[aux], aux));
        m[aux]--;
        c.insert(mp(-m[aux], aux));
      }

      while(1) {
        scanf("%s", s);
        if(!strcmp(s, "</text>")) break;
        if(strlen(s) < 4) continue;

        (q[day]).push(s);

        c.erase(mp(-m[s], s));
        m[s]++;
        c.insert(mp(-m[s], s));
      }
    }
    else {
      scanf("%d%s", &n, s);
      printf("<top %d>\n", n);
      int qnt = INF;
      for(auto it = c.begin(); it != c.end() and qnt > 0 and
         (n > 0 or (*it).st == -qnt) ; it++) {
        qnt = -(*it).st;
        n--;
        if(qnt == 0) break;
          printf("%s %d\n", ((*it).nd).c_str(), qnt);
      }
      printf("</top>\n");
    }
  }

  return 0;
}
