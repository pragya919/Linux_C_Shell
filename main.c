#include "header.h"
#include "takeinput.h"
//#include "prompt.c"



// Greeting shell during startup 
void init_shell() 
{ 
    clear(); 
    printf("\n\n\n\n******************"
        "************************"); 
    printf("\n\n\n\t****Welcome to My Shell****"); 
    printf("\n\n\t-USE AT YOUR OWN RISK-"); 
    printf("\n\n\n\n*******************"
        "***********************"); 
    char* username = getenv("USER"); 
    printf("\n\n\nUSER is: @%s", username); 
    printf("\n"); 
    sleep(1); 
    clear(); 
}

void quit_shell() 
{ 
    clear(); 
    printf("\n\n\n\n******************"
        "************************"); 
    printf("\n\n\n\t****Thankyou for using! Hope you liked it!****"); 
    printf("\n\n\t\t******Terminating******"); 
    printf("\n\n\n\n*******************"
        "***********************"); 
    char* username = getenv("USER"); 
    printf("\n\n\nUSER is: @%s", username); 
    printf("\n"); 
    sleep(1); 
    clear(); 
} 


int main() 
{ 
    //char inputString[MAXCOM];
    
    init_shell(); 
    //char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    strcpy(tilde,cwd);
  
    while (1) { 
        // print shell line 
        prompt(); 
        strcpy(exe_part,"");
        takeinput(); 
        if(strcmp(main_input, "quit") == 0)
        {
            quit_shell();
            break;
        }
         
    }

}