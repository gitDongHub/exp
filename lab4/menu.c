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
#include "linklist.h"

void version();
void help();
void printWorkDir();
void printSystemTime();
void list();
void showProcess();
void clearScreen();
void quit();

tDataNode head[] = 
{
    {"ver", "show the system version", version, &head[1]},
    {"help", "list all the cmd", help, &head[2]},
    {"pwd", "print the working direct", printWorkDir, &head[3]},
    {"time","print the System time and date", printSystemTime, &head[4]},
    {"ls", "list all the current direct file", list, &head[5]},
    {"ps", "show the process in the System", showProcess, &head[6]},
    {"clr", "clear the screen", clearScreen, &head[7]},
    {"quit", "exit from the menu program", quit, NULL}
};

int main()
{
    int i;    
    char input[CMD_MAX_LEN];

    version();
    while(1)
    {
    	printf("cmd>>");
    	scanf("%s", input);
    	tDataNode* p = findCmd(head, input);
        if(p == NULL)
        {
            printf("the cmd you input isn't exist\n");
            continue;
        }
        if(p->handler != NULL)
        {
            p->handler();
        }   
    }
    return 0;
}

void version()
{
    printf("gitDongHub menu [version 1.0]\n");
    printf("gitDongHub@copyright at 2017/09/24\n");
    printf("If you need help, please type help\n");
}

void help()
{
    int i;
    printf("**************************help****************************\n");
    printf("List all the cmd of menu program:\n");
    showAllCmd(head);
    printf("**************************end*****************************\n");
}
void printWorkDir()
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
    printf("%4d-%02d-%02d  %d:%d:%d\n", ptr->tm_year+1900, ptr->tm_mon+1, ptr->                               tm_mday,ptr->tm_hour, ptr->tm_min, ptr->tm_sec);
}

void list()
{ 
    system("ls");
}

void showProcess()
{
    system("ps");
}

void clearScreen()
{
    system("clear");
}

void quit()
{
    exit(0);
}
