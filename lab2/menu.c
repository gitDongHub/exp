/******************************************************************/
/* Copyright (C) gitDongHub@github.com, 2017-2018                 */
/*                                                                */
/* File name                  : menu.c                            */
/* Principal author           : gitDongHub                        */
/* Subsystem name             : menu                              */
/* Module name                : menu                              */
/* Language                   : C                                 */
/* Target environment         : ANY                               */
/* Date of first release      : 2017/09/24                        */
/* Deacription                : This is a menu program            */
/******************************************************************/

/*
 * Revision log:
 *
 * created by dong, 2017/09/24
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct
{
    char name[128];
    void (*f)();
} Cmd;

void hello();
void help();
void pwd();
void printSystemTime();
void delete();
void run();
void echo();
void new();
void changedir();
void quit();

Cmd cmd[] = {
	        {"hello", hello},
	        {"help", help},
	        {"pwd", pwd},
	        {"time", printSystemTime},
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
    printf("gitDongHub menu [version 1.0]\n");
    printf("gitDongHub@copyright at 2017/09/24\n");
    printf("If you need help, please type help\n");
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
void pwd()
{
    char buf[256];
    getcwd(buf, sizeof(buf));
    printf("the current dir: %s\n", buf);
}

void printSystemTime()
{
    struct tm* ptr;
    time_t it;
    it = time(NULL);
    ptr = localtime(&it);
    printf("%4d-%02d-%02d  %d:%d:%d\n", ptr->tm_year+1900, ptr->tm_mon+1, ptr->tm_mday,
                                        ptr->tm_hour, ptr->tm_min, ptr->tm_sec);
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
