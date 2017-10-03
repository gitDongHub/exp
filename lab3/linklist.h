/******************************************************************/
/* Copyright (C) gitDongHub@github.com, 2017-2018                 */
/*                                                                */
/* File name                  : linklist.h                        */
/* Principal author           : gitDongHub                        */
/* Subsystem name             : menu                              */
/* Module name                : menu                              */
/* Language                   : C                                 */
/* Target environment         : ANY                               */
/* Date of first release      : 2017/10/03                        */
/* Deacription                : This is a linklist headfile       */
/******************************************************************/

/*
 * Revision log:
 *
 * created by dong, 2017/10/03
 * 
*/
#define CMD_MAX_LEN 128
#define DESC_MAX_LEN 1024

typedef struct DataNode
{
    char cmd[CMD_MAX_LEN];
    char desc[DESC_MAX_LEN];
    void (*handler)();
    struct DataNode* next;
} tDataNode;

/*find the cmd in linklist and return pointer point to the cmd found*/
tDataNode* findCmd(tDataNode* head, char* cmd);
/*print all the command in linklist*/
void showAllCmd(tDataNode* head);

