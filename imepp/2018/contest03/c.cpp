#include<bits/stdc++.h>
using namespace std;

const int N = 10;

/*******************************************************************
* grid: tabuleiro da questão que quero preencher                   *
*                                                                  *
* lines, col e subgrid são variáveis auxiliares que dizem quais    *
* números já tem na linha, na coluna e no subgrid                  *
*                                                                  *
* a matriz do grid vai de 0 - 8 linhas e 0 - 8 colunas, se chegar  *
* na linha 10 significa que conseguiu resolver                     *
*                                                                  *
*******************************************************************/

int t;
int grid[N][N];

bool lines[N][N], col[N][N], subgrid[3][3][N];

void fill(int a, int b, int v) {
  grid[a][b] = v;
  lines[a][v] = true;
  col[b][v] = true;
  subgrid[a/3][b/3][v] =  true;
}

void empty(int a, int b, int v) {
  grid[a][b] = 0;
  lines[a][v] = false;
  col[b][v] = false;
  subgrid[a/3][b/3][v] = false;
}

bool backtracking(int a, int b) {

  if(a == 9) return true;
  if(b == 9) return backtracking(a+1, 0);

  if(grid[a][b] != 0) return backtracking(a, b+1);

  for(int i=1; i<N; i++) {
    if(!lines[a][i] and !col[b][i] and !subgrid[a/3][b/3][i]) {//Verifica se não tem o valor na linha, na coluna ou no subgrid

      fill(a, b, i);//preenche com o valor

      if (backtracking(a, b+1)) return true;//tenta preencher o

      empty(a, b, i);//remove, caso não dê certo
    }
  }
  return false;
}

int main() {

  scanf("%d", &t);

  for(int tt = 0; tt < t; tt++) {
    memset(lines, 0, sizeof(lines));
    memset(col, 0, sizeof(col));
    memset(subgrid, 0, sizeof(subgrid));

    //pegar input
    for(int i=0; i<9; i++) {
      for(int j = 0; j<9; j++) {
        scanf("%d", &grid[i][j]);
        if(grid[i][j] != 0) backtracking(i, j, grid[i][j]);
      }
    }

    if(fill_grid(0, 0)) {
      for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
          printf("%d%c", grid[i][j], j==8?'\n':' ');
        }
      }
    }
    else {
      printf("No solution\n");
    }
  }
  return 0;
}
