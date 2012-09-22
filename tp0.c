#include <stdio.h>
#include <stdlib.h>

#include "tp0.h"
void aloca
void kronecker(FILE *pFile)
{

    int pares_de_matrizes;

    fscanf(pFile, "%d", &pares_de_matrizes);

    int lin_mat1, col_mat1, lin_mat2, col_mat2;
    int **matriz_um, **matriz_dois, **matriz_result;
    int f;
    int l, c;
    int x, y, z, w;

    int par_itr;

    for (par_itr = 0; par_itr<pares_de_matrizes; par_itr++ )
    {
        //cria matriz_um
        fscanf(pFile, "%d", &lin_mat1);
        fscanf(pFile, "%d", &col_mat1);

        //aloca matriz 1
        matriz_um = (int**)malloc(lin_mat1*sizeof(int*));

        for (f=0; f<lin_mat1; f++){
            matriz_um[f] = (int*)malloc(col_mat1*sizeof(int));
        }
        //preenche matriz 1

        for(l=0; l < lin_mat1; l++)
        {
            for(c=0; c<col_mat1; c++)
            {
                fscanf(pFile, "%d", &matriz_um[l][c]);
            }
        }


        //cria matriz_dois
        fscanf(pFile, "%d", &lin_mat2);
        fscanf(pFile, "%d", &col_mat2);
        //aloca matriz 2
        matriz_dois = (int**)malloc(lin_mat2*sizeof(int*));

        for (f=0; f<lin_mat2; f++){
            matriz_dois[f] = (int*)malloc(col_mat2*sizeof(int));
        }

        //preenche matriz 2
        for(l=0; l < lin_mat2; l++)
        {
            for(c=0; c<col_mat2; c++)
            {
                fscanf(pFile, "%d", &matriz_dois[l][c]);
            }
        }

        //aloca matriz resultado
        matriz_result = (int**)malloc(lin_mat1*lin_mat2*sizeof(int*));

        for (f=0; f<lin_mat1*lin_mat2; f++){
            matriz_result[f] = (int*)malloc(col_mat1*col_mat2*sizeof(int));
        }




        //calcula
        for(x=0; x<lin_mat1; x++ )
        {
            for(y=0; y<col_mat1; y++)
            {
                for(z=0; z<lin_mat2; z++ )
                {
                    for (w=0; w<col_mat2; w++)
                    {
                        matriz_result[x*lin_mat2+z][y*col_mat2+w] = matriz_um[x][y]*matriz_dois[z][w];

                    }
                }
            }
        }

            for( z=0; z<lin_mat1*lin_mat2; z++ )
            {
                for (w=0; w<col_mat1*col_mat2; w++)
                {
                    printf("%d ", matriz_result[z][w]);

                }
                printf("\n");
              }



    //libera memoria das matrizes
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


