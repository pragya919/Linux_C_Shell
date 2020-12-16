#include "header.h"

void prompt()
{ 
    getcwd(cwd, sizeof(cwd)); 
    printf("\nDir: %s", cwd); 
}