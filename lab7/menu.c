
/**************************************************************************************************/
/* Copyright (C) github.com, gitDongHub@Dong, 2017-2018                                           */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  gitDongHub                                                           */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2017/11/03                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Dong, 2017/11/03
 *
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linktable.h"
#include "menu.h"

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10


/* data struct and its operations */

typedef struct DataNode
{
    tLinkTableNode * pNext;
    char*   cmd;
    char*   desc;
    int     (*handler)();
} tDataNode;

tLinkTable * head = NULL;

int SearchCondition(tLinkTableNode * pLinkTableNode, void* args)
{
    tDataNode * pNode = (tDataNode *)pLinkTableNode;
    char* cmd = (char*)args;
    if(strcmp(pNode->cmd, cmd) == 0)
    {
        return  SUCCESS;  
    }
    return FAILURE;	       
}

/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(tLinkTable * head, char * cmd)
{
    return  (tDataNode*)SearchLinkTableNode(head,SearchCondition,(void*)cmd);
}

/* show all cmd in listlist */
int ShowAllCmd(tLinkTable * head)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return 0;
}

int help()
{
    ShowAllCmd(head);
    return 0; 
}

int MenuConfig(char* cmd, char* desc, int (*handler)())
{
    if(head == NULL)
    {
        head = CreateLinkTable();
        tDataNode* pNode = (tDataNode*)malloc(sizeof(tDataNode));
        pNode->cmd = "help";
        pNode->desc = "List all the cmd of menu";
        pNode->handler = help;
        AddLinkTableNode(head, (tLinkTableNode *)pNode);
    }
    tDataNode* pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = cmd;
    pNode->desc = desc;
    pNode->handler = handler; 
    AddLinkTableNode(head, (tLinkTableNode *)pNode);
 
    return 0; 
}

int ExecuteMenu()
{
   /* cmd line begins */
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd number > ");
        scanf("%s", cmd);
        tDataNode *p = FindCmd(head, cmd);
        if( p == NULL)
        {
            printf("This is a wrong cmd!\n ");
            continue;
        }
        printf("%s - %s\n", p->cmd, p->desc); 
        if(p->handler != NULL) 
        { 
            p->handler();
        }
   
    }
}
