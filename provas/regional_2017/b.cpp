#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

char s[N];
int n, a, b, cont;
int p[2], v[2];
int vogal[26];

int main(){
	ios_base::sync_with_stdio(false);
  v[0] = 1, v[1] = -1;
  vogal[0] = vogal['e'-'a'] = vogal['i'-'a'] = vogal['o'-'a'] = vogal['u'-'a'] = 1;

  while(~scanf("%s", s)) {
    n = strlen(s);
    cont = 0;
    a = 0, b = 1;
    p[0] = 0, p[1] = n-1;
    for(int i=0; s[i]; i++) if(vogal[s[i]-'a']) cont++;
    if(cont == 0) {
      printf("1\n");
      continue;
    }
    if(!vogal[s[0]-'a']) {
      printf("0\n");
      continue;
    }
    while(cont > 1) {
      while(!vogal[s[p[b]]-'a']) p[b]+=v[b];
      p[a]+=v[a];
      a = 1-a;
      b = 1-b;
      cont--;
    }
    printf("%d\n", abs(p[0]-p[1])+1);
  }
	return 0;
}

