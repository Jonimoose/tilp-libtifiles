/* Hey EMACS -*- linux-c -*- */
/* $Id: tifiles.c 920 2005-04-02 13:40:58Z roms $ */

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
  This unit contains memory allocators.
*/

#include <stdlib.h>

#ifdef __WIN32__
TIEXPORT void *TICALL tifiles_calloc(size_t nmemb, size_t size)
{
	return calloc(nmemb, size);
}

TIEXPORT void *TICALL tifiles_malloc(size_t size)
{
	return malloc(size);
}

TIEXPORT void TICALL tifiles_free(void *ptr)
{
	free(ptr);
}

TIEXPORT void *TICALL tifiles_realloc(void *ptr, size_t size)
{
	return realloc(ptr, size);
}
#endif
