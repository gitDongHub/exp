
/**************************************************************************************************/
/* Copyright (C) github.com, gitDongHub@Dong, 2017-2018                                           */
/*                                                                                                */
/*  FILE NAME             :  menu.h                                                               */
/*  PRINCIPAL AUTHOR      :  gitDongHub                                                           */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2017/11/03                                                           */
/*  DESCRIPTION           :  This is a head file of menu.c                                        */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Dong, 2017/11/03
 *
 */


#ifndef __MENU_H__
#define __MENU_H__

/*Config the Menu Engine*/
int MenuConfig(char* cmd, char* desc, int (*handler)());

/*Execute the menu*/
int ExecuteMenu();

#endif
