#include "header.h"

void setenvv(char *text)
{
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
	if(i==0 || i>2)
	{
		printf("Too few arguments or too much arguments\n");
		return;
	}
	if(i==1)
	{
		setenv(args[0],"", 1);
		return;
	}
	setenv(args[0],args[1],1);
}

void unsetenvv(char *text)
{
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
	if(i==0 || i>1)
	{
		printf("Too few arguments or too much arguments\n");
		return;
	}
	unsetenv(args[0]);
}