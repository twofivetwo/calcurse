/*	$calcurse: vars.h,v 1.8 2007/03/24 23:22:16 culot Exp $	*/

/*
 * Calcurse - text-based organizer
 * Copyright (c) 2004-2007 Frederic Culot
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * Send your feedback or comments to : calcurse@culot.org
 * Calcurse home page : http://culot.org/calcurse
 *
 */

#ifndef CALCURSE_VARS_H
#define CALCURSE_VARS_H

#include <ncurses.h> 
#include <pthread.h>
#include <stdbool.h>

#define DIR_NAME	".calcurse"
#define TODO_PATH 	".calcurse/todo"
#define APTS_PATH	".calcurse/apts"
#define CONF_PATH	".calcurse/conf"

#define MAX_LENGTH	512

#define CTRL(x)         ((x) & 0x1f)
#define ESCAPE		27

#define ATTR_FALSE	0
#define ATTR_TRUE	1
#define ATTR_LOWEST	2
#define ATTR_LOW	3
#define ATTR_MIDDLE	4
#define ATTR_HIGH	5
#define ATTR_HIGHEST	6

#define DAYINSEC  	86400 
#define HOURINSEC	3600
#define MININSEC	60

struct pad_s {
	int width;
	int length;
	int first_onscreen;	/* first line to be displayed inside window */
	WINDOW *ptrwin;		/* pointer to the pad window */
};

struct nbar_s {		
	int show;			/* display or hide the notify-bar */
	int cntdwn;			/* warn when time left before next app
					 * becomes lesser than cntdwn */  
	char datefmt[MAX_LENGTH];	/* format for displaying date */
	char timefmt[MAX_LENGTH];	/* format for displaying time */
	char cmd[MAX_LENGTH];		/* notification command */
	char *shell;			/* user shell to launch notif. cmd */
	pthread_mutex_t mutex;
};

/* General configuration variables */
typedef struct {
	bool auto_save;
	bool confirm_quit;
	bool confirm_delete;
	bool skip_system_dialogs;
	bool skip_progress_bar;
	bool week_begins_on_monday;
} conf_t;

extern int col, row;
extern bool colorize;
extern int days[12];
extern char *monthnames[12];
extern char *daynames[8];
extern char path_dir[MAX_LENGTH];
extern char path_todo[MAX_LENGTH];
extern char path_apts[MAX_LENGTH];
extern char path_conf[MAX_LENGTH];
extern WINDOW *awin, *cwin, *twin, *swin;
extern struct pad_s *apad;
extern struct nbar_s *nbar;

#endif /* CALCURSE_VARS_H */
