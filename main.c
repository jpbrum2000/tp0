#include <stdio.h>
#include <stdlib.h>

#include "tp0.h"

int main()
{

    FILE *arquivo = fopen("input.txt", "r");
    kronecker(arquivo);

return(0);
}
