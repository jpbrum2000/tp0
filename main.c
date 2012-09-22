#include <stdio.h>
#include <stdlib.h>

#include "tp0.h"

int main()
{

    FILE *arquivo_input = fopen("input.txt", "r");
    FILE *arquivo_output = fopen("output.txt", "w");

    kronecker(arquivo_input, arquivo_output);

    fclose(arquivo_input);
    fclose(arquivo_output);

return(0);
}
