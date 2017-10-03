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
 * modified by dong,2017/10/03
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkTable.h"

#define CMD_MAX_LEN 128

typedef struct DataNode
{
    tLinkTableNode* pNext;
    char* cmd;
    char* desc;
    void  (*handler)();
}tDataNode;

void version();
void help();
void printWorkDir();
void printSystemTime();
void list();
void showProcess();
void clearScreen();
void quit();

/* find the cmd of menu*/
tDataNode* findCmd(tLinkTable* head, char* cmd)
{
    tDataNode* pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        if(strcmp(pNode->cmd, cmd) == 0)
        {
            return pNode;
        }
        pNode = (tDataNode*)GetNextLinkTableNode(head, (tLinkTableNode*)pNode);
    }
    return NULL;
}

/* show all the cmd of menu*/
void showAllCmd(tLinkTable* head)
{
    tDataNode* pNode = (tDataNode*)GetLinkTableHead(head);
    int cnt = 0;
    pirntf("  Command\t\tDescription\n");
    while(pNode != NULL)
    {
         cnt++;
         printf("%02d ", cnt);
         printf("%s\t\t\t%s\n", pNode->cmd, pNode->desc);
         pNode = (tDataNode*)GetNextLinkTableNode(head, (tLinkTableNode*)pNode);
    }
}

/*initalize the data of head*/
InitMenuData(tLinkTable** ppLinkTable)
{
    *ppLinkTable = CreateLinkTable();
    tDataNode* pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "ver";
    pNode->desc = "show the version of menu";
    pNode->handler = version;
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode*)pNode);

    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "help";
    pNode->desc = "show the version of menu";
    pNode->handler = version;
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode*)pNode);

    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "pwd";
    pNode->desc = "print the working direct";
    pNode->handler = ;
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode*)pNode);

    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "time";
    pNode->desc = "print the System time and date";
    pNode->handler = printSystemTime;
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode*)pNode);

    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "ls";
    pNode->desc = "list all the current direct file";
    pNode->handler = list;
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode*)pNode);

    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "ps";
    pNode->desc = "show the process in the System";
    pNode->handler = showProcess;
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode*)pNode);

    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "clr";
    pNode->desc = "clear the screen";
    pNode->handler = clearScreen;
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode*)pNode); 

    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "quit";
    pNode->desc = "exit from the menu program";
    pNode->handler = quit;
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode*)pNode);
}

tLinkTable* head = NULL;

int main()
{
    char input[CMD_MAX_LEN];
    InitMenuData(&head);

    version();
    printf("gitDongHub@copyright at 2017/09/24\n");
    printf("If you need help, please type help\n");
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
    printf("gitDongHub menu [version 2.5]\n");
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