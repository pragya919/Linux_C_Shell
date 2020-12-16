#include "header.h"

void pinfo(char *pt)
{
    int pid, i = 1;
    // printf("%s\n", pt);
    if (strcmp(pt, "") == 0)
    {
        pid = getpid();
    }
    else
    {
        pid = atoi(pt);
    }

    
    char status_path[1000], e_path[1000];
    char status[500], memory[500];
    char text[500];

    sprintf(status_path, "/proc/%d/status", pid);
    sprintf(e_path, "/proc/%d/exe", pid);
    FILE *fptr = fopen(status_path, "r");

    if (fptr == NULL)
    {
        printf("This process id does not exists.\n");
        return;
    }

    while (fgets(text, sizeof(text), fptr) != NULL)
    {
        if (i == 3)
        {
            strcpy(status, text);
        }
        else if (i == 18)
        {
            strcpy(memory, text);
        }
        i++;
    }

    char *s = strtok(status, ":\t");
    s = strtok(NULL, ":\t");
    char *m = strtok(memory, ":\t");
    m = strtok(NULL, ":\t");

    printf("pid -- %d\n", pid);
    printf("Process Status -- %s", s);
    printf("Memory -- %s", m);

    
    char exe_p[1000];
    int r = readlink(e_path, exe_p, 1000);

    if (r == -1)
    {
        printf("No path for executable\n");
        return;
    }
    char s1[1000];
    char s2[1000];
    char *p;
    strcpy(s1, exe_p);
    strcpy(s2, tilde);
    int k = strlen(s1);
    int l = strlen(s2);
    p = strstr(s1, s2);

    if (p)
    {
        printf("Executable Path -- ~%s\n", &p[l]);
    }
    else
    {
        printf("Executable Path -- %s\n", exe_p);
    }

    fclose(fptr);
}



