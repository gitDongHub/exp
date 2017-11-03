#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "linktable.h"

int quit();
int echo(int argc, char* argv[]);

int main(int argc, char* argv)
{
    MenuConfig("quit","quit from the menu program", quit);
    MenuConfig("echo","printf all you input in the terminal", echo);
    ExecuteMenu();

    return 0;
}

int quit()
{
    exit(0);
    
    return 0;
}

int echo(int argc, char* argv[])
{
    int i;
    if(argc == 1)
    {
        printf("echo on\n");
    }
    
    for(i = 1;i < argc;i ++)
    {
        printf("%d:%s\n",i, argv[i]);
    }
    return 0;
}



