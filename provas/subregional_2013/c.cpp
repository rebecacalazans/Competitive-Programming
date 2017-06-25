#include <bits/stdc++.h>
using namespace std;

int id[505], owner[505];
int age[505];
int bt[505];
vector<int> g[505];
int n, m, o;
int a, b;
char c;

int miniage(int k) {
  int aux = 105;
  if (bt[k]) return bt[k];

  for(vector<int>::iterator it = g[id[k]].begin(); it != g[id[k]].end(); it++) {
    aux = min(aux, age[owner[*it]]);
    aux = min(aux, miniage(owner[*it]));
  }
  return bt[k] = aux;
}

int main() {
  while (scanf("%d%d%d", &n, &m, &o) != EOF) {
    memset(age, 0, sizeof(age));
    memset(bt, 0, sizeof(bt));
    memset(owner, 0, sizeof(owner));
    memset(age, 0, sizeof(age));
    for (int i = 0; i<=n; i++) g[i].clear();

    for (int i = 1; i<=n; i++) scanf("%d", &age[i]), id[i] = i, owner[i] = i;
    for (int i = 1; i<=m; i++) scanf("%d%d", &a, &b), g[b].push_back(a);
    for (int i = 1; i<=o; i++) {
      scanf(" %c ", &c);
      if (c == 'T') {
        memset(bt, 0, sizeof(bt));
        scanf("%d%d", &a, &b);
        int aux = id[a];
        id[a] = id[b];
        id[b] = aux;
        owner[id[a]] = a;
        owner[id[b]] = b;
      }
      else {
        scanf("%d", &a);
        if (g[id[a]].empty()) printf("*\n");
        else {
          printf("%d\n", miniage(a));
        }
      }
    }
  }
}
