#include "header.h"
#include "takeinput.h"
size_t buf_size = 101;

void ignorespace(char *arr, size_t n)
{
	int space=0, k=0;

	for(int i=0; i<n; i++)
	{
		while(k==0 && i<n && ((arr[i] == ' ') || (arr[i] == '\t') || (arr[i] == '\r')))
		{
			i++;
		}

		if(arr[i] == ' ' || arr[i] == '\t' || arr[i] == '\r')
		{
			if(!space)
			{
				arr[k++] = ' ';
				space = 1;
			}
		}
		else
		{
			arr[k++] = arr[i];
			space = 0;
		}

        if(arr[i]=='\n')
        {
            arr[i] = '\0';
            break;
        }
	}
	arr[k-1] = '\0';
	int x = k-1;

	if(arr[k-2]==' ')
	{
		arr[k-2] = '\0';
		x=k-2;
	}

}


void takeinput()
{
	inp = (char *)malloc(buf_size * sizeof(char));
	printf("\n>>> ");
	getline(&inp, &buf_size, stdin);
	char *args[1000];
    int i = 0;
    args[i] = strtok(inp, ";");
    while (args[i] != NULL)
    {
        i++;
        args[i] = strtok(NULL, ";");
    }
    int k = 0;
    for(int k=0;k<i;k++)
    {
    	ignorespace(args[k], buf_size);
    	char *cmdline;
    	char temp[1000];
    	
    	/*int z = strlen(cmdline);
    		printf("%d\n",z);
    	*/	
    	/*int y = strlen(exe_part);
    		printf("%d\n",y);
    	printf("%s",exe_part);	
    	*/
    	strcpy(temp, args[k]);
    	cmdline = strtok(args[k]," ");
    	int p =0,flag=0;
    	while(cmdline[p] == temp[p])
    	{
    		p++;
    		if(temp[p] == '\0')
    			flag=1;
    	}
    	if(!flag)
    	{
    		strcpy(exe_part, &temp[p+1]);
    	}
        strcpy(main_input,temp);
    	//printf("%s\n",main_input);
    	if(strcmp(cmdline,"echo")==0)
    	{
    		echo(exe_part);
    	}
    	else if(strcmp(cmdline,"pwd")==0)
    	{
    		pwd();
    	}
    	else if(strcmp(cmdline,"cd")==0)
    	{
    		cd(exe_part);
    	}
    	else if(strcmp(cmdline,"ls")==0)
    	{
    		//printf("%s\n",exe_part);
    		ls(exe_part);
    	}
        else if(strcmp(cmdline,"setenv")==0)
        {
            setenvv(exe_part);
        }
        else if(strcmp(cmdline,"unsetenv")==0)
        {
            unsetenvv(exe_part);
        }
        else if(strcmp(cmdline,"pinfo")==0)
        {
            pinfo(exe_part);
        }
        else
        {
            others(main_input);

        }
    }
}