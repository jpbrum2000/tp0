#include <stdio.h>
#include <stdlib.h>

#include "tp0.h"
int **aloca_matriz(int linhas,int colunas)
{
    int f; int **matriz;
        //aloca matriz 1
        matriz = (int**)malloc(linhas*sizeof(int*));

        for (f=0; f<linhas; f++){
            matriz[f] = (int*)malloc(colunas*sizeof(int));
        }

        return(matriz);
}

int **preenche(FILE *pFile, int lin_mat1, int col_mat1)
{
    int l, c;
    int ** matriz;
        //aloca matriz 1
        matriz = aloca_matriz(lin_mat1, col_mat1);

        for(l=0; l < lin_mat1; l++)
        {
            for(c=0; c<col_mat1; c++)
            {
                fscanf(pFile, "%d", &matriz[l][c]);
            }
        }

        return(matriz);
}

int **calcula_kronecker(int **matriz_um, int lin_mat1, int col_mat1, int **matriz_dois, int lin_mat2, int col_mat2)
{
        int **matriz;
        int x, y, z, w;

        matriz = aloca_matriz(lin_mat1*lin_mat2, col_mat1*col_mat2);


        //calcula
        for(x=0; x<lin_mat1; x++ )
        {
            for(y=0; y<col_mat1; y++)
            {
                for(z=0; z<lin_mat2; z++ )
                {
                    for (w=0; w<col_mat2; w++)
                    {
                        matriz[x*lin_mat2+z][y*col_mat2+w] = matriz_um[x][y]*matriz_dois[z][w];

                    }
                }
            }
        }

        return(matriz);

}

void save_file(FILE *pFile, int lin, int col, int **matriz)
{
    int i, j;
        for( i=0; i<lin; i++ )
        {
              for (j=0; j<col; j++)
              {
                  fprintf(pFile, "%d ", matriz[i][j]);
              }
              fprintf(pFile, "\n");
         }
}

void kronecker(FILE *arquivo_input, FILE *arquivo_output)
{

    int pares_de_matrizes;

    fscanf(arquivo_input, "%d", &pares_de_matrizes);
    fprintf(arquivo_output, "%d\n", pares_de_matrizes);

    int lin_mat1, col_mat1, lin_mat2, col_mat2;
    int **matriz_um, **matriz_dois, **matriz_result;

    int par_itr;

    for (par_itr = 0; par_itr<pares_de_matrizes; par_itr++ )
    {
        //cria matriz_um
        fscanf(arquivo_input, "%d", &lin_mat1);
        fscanf(arquivo_input, "%d", &col_mat1);

        //preenche matriz 1
        matriz_um = preenche(arquivo_input, lin_mat1, col_mat1);

        //cria matriz_dois
        fscanf(arquivo_input, "%d", &lin_mat2);
        fscanf(arquivo_input, "%d", &col_mat2);
        //aloca matriz 2
        matriz_dois = preenche(arquivo_input, lin_mat2, col_mat2);

        //calculo matematico kronecker
        fprintf(arquivo_output, "%d", lin_mat1*lin_mat2);
        fprintf(arquivo_output, " %d\n", col_mat1*col_mat2);
        matriz_result = calcula_kronecker(matriz_um, lin_mat1, col_mat1, matriz_dois, lin_mat2, col_mat2);


        save_file(arquivo_output, lin_mat1*lin_mat2, col_mat1*col_mat2, matriz_result);



    int i;
    for (i=0; i<lin_mat1; i++){
        free(matriz_um[i]);
    }
    free(matriz_um);

    for (i=0; i<lin_mat2; i++){
        free(matriz_dois[i]);
    }
   free(matriz_dois);

    for (i=0; i<lin_mat1*lin_mat2; i++){
        free(matriz_result[i]);
    }
        free(matriz_result);
    }


}


