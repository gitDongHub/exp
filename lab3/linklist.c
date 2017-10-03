/******************************************************************/
/* Copyright (C) gitDongHub@github.com, 2017-2018                 */
/*                                                                */
/* File name                  : linklist.c                        */
/* Principal author           : gitDongHub                        */
/* Subsystem name             : menu                              */
/* Module name                : menu                              */
/* Language                   : C                                 */
/* Target environment         : ANY                               */
/* Date of first release      : 2017/10/03                        */
/* Deacription                : This is a linklist sorcefile      */
/******************************************************************/

/*
 * Revision log:
 *
 * created by dong, 2017/10/03
 * 
 */

#include <stdio.h>
#include "linklist.h"

tDataNode* findCmd(tDataNode* head, char* cmd)
{
    if(head == NULL || cmd == NULL)
    {
        return NULL;
    }
    tDataNode* p = head;
    while(p != NULL)
    {
        if(strcmp(p->cmd, cmd) == 0)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void showAllCmd(tDataNode* head)
{
    tDataNode* p = head;
    printf("  Command\t\tDescription\n");
    int cnt = 0;
    while(p != NULL)
    {
        cnt ++;
        printf("%02d ", cnt);
        printf("%s\t\t\t%s\n", p->cmd, p->desc);
        p = p->next;
    }
}

