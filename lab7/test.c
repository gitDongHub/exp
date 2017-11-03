#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "linktable.h"

int quit();

int main()
{
    MenuConfig("quit","quit from the menu program", quit);
    ExecuteMenu();

    return 0;
}

int quit()
{
    exit(0);
    
    return 0;
}

