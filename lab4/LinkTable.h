/*****************************************************************************/
/*	Name: LinkTable.h                                                        */
/*	Copyright: 2017-2021                                                     */
/*	Author: gitDongHub                                                       */
/*	Date: 2017/10/03                                                         */
/*	Description: the header file of LintkTable                               */
/*****************************************************************************/

#ifndef _LINK_TABLE_H_
#define _LINK_TABLE_H_

#define SUCCESS 0
#define FAILURE (-1)

#include <stdio.h>
#include <stdlib.h>

/*
 * LinkTable Node Type
 */
typedef struct LinkTableNode
{
     struct LinkTableNode *pNext;
}tLinkTableNode;

/*
 * LinkTable Type
 */
typedef struct LinkTable
{
     tLinkTableNode *pHead;
     tLinkTableNode *pTail;
     int         SumOfNode;
}tLinkTable;

/*
 * Create a LinkTable
 */
tLinkTable * CreateLinkTable();

/*
 * Add a LinkTableNode to LinkTable
 */
int AddLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode);

/*
 * Delete a LinkTableNode from LinkTable
 */
int DelLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode);

/*
 * Get LinkTableHead
 */
tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable);

/*
 * Get next LinkTableNode
 */
tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode);

#endif /* _LINK_TABLE_H_ */
