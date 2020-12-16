#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <sys/utsname.h>
#include <libgen.h>
#include <termios.h>


// Clearing the shell using escape sequences 
#define clear() printf("\033[H\033[J") 

char tilde[1024];
char cwd[1024];
char prev_dir[1024];
char exe_part[1000];
char main_input[1000];

void prompt();
void takeinput();
void echo(char *text);
void pwd();
void cd(char *text);
void ls(char *text);
void setenvv(char *text);
void unsetenvv(char *text);
void others(char *text);   
void pinfo(char *pt);
