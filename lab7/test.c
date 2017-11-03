#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "linktable.h"

int quit();
int changeDir(int argc, char* argv[]);

int main(int argc, char* argv)
{
    MenuConfig("quit","quit from the menu program", quit);
    MenuConfig("cd","list the current files or the directory you want", changeDir);
    ExecuteMenu();

    return 0;
}

int quit()
{
    exit(0);
    
    return 0;
}

int changeDir(int argc, char* argv[])
{
    system("ls %s", argv);
    return 0;
}
