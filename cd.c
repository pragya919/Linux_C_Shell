#include "header.h"

void cd(char *text)
{
	getcwd(cwd, sizeof(cwd));
	
	if(strcmp(text, "") == 0 || strcmp(text, "~")==0)
    {
        getcwd(prev_dir, sizeof(prev_dir));
        chdir(tilde);
        return;
    }
    if(strcmp(text, "-")==0)
    {
    	char now[1024];
    	getcwd(now, sizeof(now));
    	printf("%s\n", prev_dir);
    	chdir(prev_dir);
    	strcpy(prev_dir,now);
    	return;
    }
    strcat(cwd, "/");
    strcat(cwd, text);
    getcwd(prev_dir, sizeof(prev_dir));
    if(chdir(cwd)<0)
    	{
			printf("Error Number %d\n", errno);
			perror("Directory");
		}
}