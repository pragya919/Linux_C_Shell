#include "header.h"

void others(char *text)
{
	//printf("%s\n",text);
	char *args[1000];
	for(int i=0;i<1000;i++)
		args[i]="";
	char *token = strtok(text, " ");
	int i=0;
	while(token!=NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = token;
	/*for(int j=0;j<i;j++)
		printf("%s\n",args[j]);*/
	int pid = fork();
	if(!pid)
	{
		int r = execvp(args[0],args);
		int p = getpid();
		if(r == -1)
		{
			//printf("in\n");
			if(strcmp(main_input, "quit")==0)
				return;
			printf("%s: Command not found\n", args[0]);
			return;
		}
		
	}
	else
		wait(NULL);
}