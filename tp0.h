#ifndef TP0_H_INCLUDED
#define TP0_H_INCLUDED
//aloca matriz
int **aloca_matriz(int linhas, int colunas);

//preenche matriz com valores do arquivo
int **preenche(FILE *pFile, int lin_mat1, int col_mat1);

//calculos matematicos de kronecker
int **calcula_kronecker(int **matriz_um, int lin_mat1, int col_mat1, int **matriz_dois, int lin_mat2, int col_mat2);

//função kronecker
void kronecker(FILE *arquivo_input,FILE *arquivo_output);


#endif // TP0_H_INCLUDED
