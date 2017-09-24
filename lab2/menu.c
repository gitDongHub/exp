#include <stdio.h>

int main()
{
    char cmd[128] = "";
   
    printf("Hello,Welcome to menu world!\n");
   
    while(1)
    {
        scanf("%s", cmd);
        printf("echo:%s", cmd);
    }    
    return 0;
}
