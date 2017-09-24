//menu.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[128];
    void (*f)();
} Cmd;

void hello();
void help();
void list();
void delete();
void run();
void echo();
void new();
void changedir();
void quit();

Cmd cmd[] = {
	        {"hello", hello},
	        {"help", help},
	        {"ls", list},
	        {"del", delete},
	        {"run", run},
	        {"echo", echo},
	        {"new", new},
	        {"cd", changedir},
                {"quit", quit}
            };

int main()
{
    int i;    
    char input[128] = "";

    hello();
    while(1)
    {
    	printf("cmd>>");
    	scanf("%s", input);
    	int cnt = 0;
    	for(i = 0; i < sizeof(cmd)/sizeof(cmd[0]); i++)
    	{
             if(strcmp(input, cmd[i].name) == 0)
             {
             	(*cmd[i].f)();
             	break;
             }
             else
             {
             	cnt ++;
             	if(cnt == sizeof(cmd)/sizeof(cmd[0]))
             	{
             	    printf("wrong cmd\n");
             	}
             }
    	}
    }
    return 0;
}

void hello()
{
    printf("Hello, Welcome to menu\n");
    printf("gitDongHub@copyright at 2017/09/24\n");
    printf("if you need help, please type help\n");
}

void help()
{
    int i;
    printf("List all the cmd:\n");
    for(i = 0; i < sizeof(cmd)/sizeof(cmd[0]); i++)
    {
    	printf("%s\t", cmd[i].name);
    	if(i == 4)
    	{
    	    printf("\n");
    	}
    }
    printf("\n");
}
void list()
{
    printf("this is the list cmd\n");
}

void delete()
{ 
    printf("this is the delete cmd\n");
}

void run()
{
    printf("this is the run cmd\n");
}
void echo()
{
    printf("this is the echo cmd\n");
}

void new()
{
    printf("this is the new cmd\n");
}
void changedir()
{
    printf("this is the cd cmd\n");
}

void quit()
{
    exit(0);
}
