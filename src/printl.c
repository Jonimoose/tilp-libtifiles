/* Hey EMACS -*- linux-c -*- */
/* $Id$ */

/*  libtifiles - Ti File Format library, a part of the TiLP project
 *  Copyright (C) 1999-2004  Romain Lievin
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

/*
  This unit contains the interface of the libtifiles library.
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "intl3.h"

#include "export.h"
#include "file_def.h"

/* 
   Print to stdout as default behaviour unless changed by tifiles_set_print 
   Level: such as "warning", "error", "information", etc. "" = nothing.
*/
static int default_printl(int level, const char *format, ...)
{
	va_list ap;
	int ret = 0;
#ifndef __WIN32__	
	switch(level) {
		case 1: fprintf(stdout, _("(warning)")); break;
		case 2: fprintf(stdout, _("(error)")); break;
	}
        fprintf(stdout, ": ");
	
	va_start(ap, format);
        ret = vfprintf(stdout, format, ap);
        va_end(ap);
#endif
	return ret;
}

TIFILES_PRINTL printl = default_printl;

/*
	Change print behaviour (callback).
*/
TIEXPORT TIFILES_PRINTL TICALL tifiles_set_printl(TIFILES_PRINTL new_printl)
{
  TIFILES_PRINTL old_printl = printl;

  //printf("printl = %p\n", printl);
  //printf("old_printl = %p\n", old_printl);
  //printf("new_printl = %p\n", new_printl);

  printl = new_printl;

  return old_printl;
}
