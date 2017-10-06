/******************************************************************************/
/*	Name: LinkTable.c                                                         */
/*	Copyright: 2017-2021                                                      */
/*	Author: gitDongHub                                                        */
/*	Date: 2017/10/03                                                          */
/*	Description: source files Link Table                                      */
/******************************************************************************/

#include "LinkTable.h"
tLinkTable * CreateLinkTable()
{
    tLinkTable *pLinkTable = (tLinkTable*)malloc(sizeof(tLinkTable));
    if(pLinkTable == NULL)
    {
        return NULL;
    }
    pLinkTable->pHead = NULL;
    pLinkTable->pTail = NULL;
    pLinkTable->SumOfNode = 0;
    return pLinkTable;
}

int DeleteLinkTable(tLinkTable *pLinkTable)
{
    if(pLinkTable == NULL)
    {
        return 0;
    }
    while(pLinkTable->pHead != NULL)
    {
        tLinkTableNode *tmp = pLinkTable->pHead;
        pLinkTable->pHead = pLinkTable->pHead->pNext;
        free(tmp);
    }
    pLinkTable->pHead = NULL;
    pLinkTable->pTail = NULL;
    pLinkTable->SumOfNode = -1;
    free(pLinkTable);
    return 0;
}

int AddLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode)
{
    if(pLinkTable == NULL || pNode == NULL)
    {
        return -1;
    }
    pNode->pNext = NULL;
    if(pLinkTable->pHead == NULL)
    {
        pLinkTable->pHead = pNode;
    }
    if(pLinkTable->pTail==NULL)
    {
        pLinkTable->pTail = pNode;
    }
    else
    {
        pLinkTable->pTail->pNext = pNode;
        pLinkTable->pTail = pNode;
    }
    pLinkTable->SumOfNode++;
    return 0;
}

int DelLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode)
{
    if(pLinkTable == NULL || pNode == NULL)
    {
        return -1;
    }
    if(pLinkTable->pHead == pNode)
    {
        tLinkTableNode *tmp = pLinkTable->pHead;
        pLinkTable->pHead = pLinkTable->pHead->pNext;
        free(tmp);
        pLinkTable->SumOfNode--;
    }
    if(pLinkTable->SumOfNode == 0)
    {
        pLinkTable->pTail = NULL;
        return -1;
    }
    tLinkTableNode *tmp = pLinkTable->pHead;
    while(tmp != NULL)
    {
        if(tmp->pNext == pNode)
        {
            tmp->pNext = pNode->pNext;
            pLinkTable->SumOfNode--;
            if(pLinkTable->SumOfNode == 0)
            {
                pLinkTable->pTail = NULL;
            }
            return 0;
        }
        tmp = tmp->pNext;
    }
    return -1;
}

tLinkTableNode *GetLinkTableHead(tLinkTable *pLinkTable)
{
    if(pLinkTable == NULL || pLinkTable->pHead == NULL)
    {
        return NULL;
    }
    return pLinkTable->pHead;
}

tLinkTableNode *GetNextLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode)
{
    if(pLinkTable == NULL || pNode == NULL)
    {
        return NULL;
    }
    tLinkTableNode *tmp = pLinkTable->pHead;
    while(tmp != NULL)
    {
        if(tmp == pNode)
        {
            return tmp->pNext;
        }
        tmp = tmp->pNext;
    }
    return NULL;
}
