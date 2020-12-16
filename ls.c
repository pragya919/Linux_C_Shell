#include "header.h"
DIR *dir;
struct dirent *d;

void onlyls()
{
	//printf("in\n");
	dir = opendir(".");
	if(dir == NULL)
	{
		printf("Could not open directory\n");
		return;
	}
	while((d = readdir(dir))!=NULL)
	{
		if(d->d_name[0]=='.')
			continue;
		printf("%s\n", d->d_name);
	}
	closedir(dir);

}

void ls_a_l(int flag_a, int flag_l)
{

	if (dir == NULL)
    {
        perror("ls ");
        return;
    }

    while (d = readdir(dir))
    {
    	if(flag_a!=1)
    	{
    		if (d->d_name[0] == '.')
                continue;
    	}
    		//clear();
    	if(flag_l!=0)
    	{
    		struct stat s1;
            stat(d->d_name, &s1);
            (S_ISDIR(s1.st_mode)) ? printf("d") : printf("-");
            (s1.st_mode & S_IRUSR) ? printf("r") : printf("-");
            (s1.st_mode & S_IWUSR) ? printf("w") : printf("-");
            (s1.st_mode & S_IXUSR) ? printf("x") : printf("-");
            (s1.st_mode & S_IRGRP) ? printf("r") : printf("-");
            (s1.st_mode & S_IWGRP) ? printf("w") : printf("-");
            (s1.st_mode & S_IXGRP) ? printf("x") : printf("-");
            (s1.st_mode & S_IROTH) ? printf("r") : printf("-");
            (s1.st_mode & S_IWOTH) ? printf("w") : printf("-");
            (s1.st_mode & S_IXOTH) ? printf("x") : printf("-");
            printf(" ");
            printf("%ld ", s1.st_nlink);
            struct group *gr = getgrgid(s1.st_gid);
            struct passwd *pw = getpwuid(s1.st_uid);
            printf("%s ", pw->pw_name);
            printf("%s ", gr->gr_name);
            printf("%8zu ", s1.st_size);
            char tim[1000];
            strftime(tim, 50, "%b  %d %H:%M ", localtime(&s1.st_mtime));
            printf("%s", tim);
        }
	    printf("%s\n", d->d_name);
    	    

    }
    closedir(dir);

}

void ls(char *text)
{
	//printf("%s\n",text);
	char *args[1000];
	int i=0;
	int flag_a = 0, flag_l = 0, current_dir = 0;

	args[i] = strtok(text," ");
	//printf("abc%sabc\n",args[0]);
	if(args[0] == NULL)
	{
		//printf("in\n");
		onlyls();
	}

	while(args[i]!=NULL)
	{
		if(args[i][0] == '-')
		{
			for (int p = 1; p < strlen(args[i]); p++)
			{
				if(args[i][p] == 'a')
					flag_a = 1;
				else
					flag_l = 1;
			}

			args[i] = strtok(NULL, " ");
			if(args[i] == NULL)
			{
				current_dir = 1;
			}
			continue;
		}
		i++;
		args[i] = strtok(NULL, " ");
	}
	//printf("%d %d %d\n",flag_a, flag_l, current_dir );
	if(current_dir)
	{
		//printf("yo\n");
		dir = opendir(".");
		ls_a_l(flag_a,flag_l);
		return;
	}
	int k = 0;
	while(k<i)
	{
		if(strcmp(args[k],"~") == 0)
			dir = opendir(tilde);
		else
			dir = opendir(args[k]);
		printf("\n%s: \n",args[k]);
		ls_a_l(flag_a,flag_l);
		
		k++;
	}

}